/*******************************************************************************
 * Copyright (C) 2017, 2018 MINRES Technologies GmbH
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 *******************************************************************************/

#include "CLIParser.h"
#include <sysc/top/system.h>
#include <iss/log_categories.h>

#include <scc/configurable_tracer.h>
#include <scc/configurer.h>
#include <scc/perf_estimator.h>
#include <scc/report.h>
#include <scc/scv/scv_tr_db.h>
#include <scc/tracer.h>
#include <scc/perf_estimator.h>

#include <cci_utils/broker.h>

#include <boost/program_options.hpp>
#ifdef WITH_LLVM
#include <iss/llvm/jit_helper.h>
#endif
#include <fstream>
#include <sstream>
#ifdef HAS_VERILATOR
#include <verilated.h>
inline void configure_verilator() {
    Verilated::commandArgs(sc_core::sc_argc(), const_cast<char **>(sc_core::sc_argv()));
}
#else
inline void configure_verilator() {}
#endif
const std::string core_path{"i_system.i_hifive1.i_fe310.i_core_complex"};

using namespace sc_core;
using namespace sysc;
namespace po = boost::program_options;

namespace {
const size_t ERROR_IN_COMMAND_LINE = 1;
const size_t SUCCESS = 0;
const size_t ERROR_UNHANDLED_EXCEPTION = 2;
} // namespace

int sc_main(int argc, char *argv[]) {
    ///////////////////////////////////////////////////////////////////////////
    // SystemC >=2.2 got picky about multiple drivers so disable check
    ///////////////////////////////////////////////////////////////////////////
    sc_report_handler::set_actions(SC_ID_MORE_THAN_ONE_SIGNAL_DRIVER_, SC_DO_NOTHING);
    ///////////////////////////////////////////////////////////////////////////
    // Setup verilator infrastructure (if used)
    ///////////////////////////////////////////////////////////////////////////
    configure_verilator();
    ///////////////////////////////////////////////////////////////////////////
    // CLI argument parsing & logging setup
    ///////////////////////////////////////////////////////////////////////////
    CLIParser parser(argc, argv);
    scc::stream_redirection cout_redir(std::cout, scc::log::INFO);
    scc::stream_redirection cerr_redir(std::cerr, scc::log::ERROR);
    sc_report_handler::set_actions(SC_ERROR, SC_LOG | SC_CACHE_REPORT | SC_DISPLAY | SC_STOP);
    if (!parser.is_valid()) return ERROR_IN_COMMAND_LINE;
    ///////////////////////////////////////////////////////////////////////////
    // set up infrastructure
    ///////////////////////////////////////////////////////////////////////////
#ifdef WITH_LLVM
    iss::init_jit_debug(argc, argv);
#endif
    ///////////////////////////////////////////////////////////////////////////
    // set up configuration
    ///////////////////////////////////////////////////////////////////////////
    scc::configurer cfg(parser.get<std::string>("config-file"));
    ///////////////////////////////////////////////////////////////////////////
    // set up tracing & transaction recording
    ///////////////////////////////////////////////////////////////////////////
    auto trace_level = parser.get<unsigned>("trace-level");
    scc::configurable_tracer trace(parser.get<std::string>("trace-file"),
            static_cast<scc::tracer::file_type>(trace_level >> 1), // bit3-bit1 define the kind of transaction trace
            (trace_level&0x1) != 0, // bit0 enables vcd
            parser.is_set("trace-default-on"));
    ///////////////////////////////////////////////////////////////////////////
    // instantiate top level
    ///////////////////////////////////////////////////////////////////////////
    auto estimator = scc::make_unique<scc::perf_estimator>(parser.is_set("heart-beat") ? 10_us : SC_ZERO_TIME);
    auto i_system = scc::make_unique<sysc::system>("i_system");
    ///////////////////////////////////////////////////////////////////////////
    // add non-implemented 'enableTracing' properties
    ///////////////////////////////////////////////////////////////////////////
    trace.add_control();
    ///////////////////////////////////////////////////////////////////////////
    // dump configuration if requested
    ///////////////////////////////////////////////////////////////////////////
    if (parser.get<std::string>("dump-config").size() > 0) {
        std::ofstream of{parser.get<std::string>("dump-config")};
        if (of.is_open()) cfg.dump_configuration(of);
    }
    cfg.configure();
    ///////////////////////////////////////////////////////////////////////////
    // overwrite config with command line settings
    ///////////////////////////////////////////////////////////////////////////
    cfg.set_value("i_system.i_hifive1.i_fe310.i_core_complex.backend", parser.get<std::string>("backend"));
	cfg.set_value("i_system.i_hifive1.i_fe310.i_core_complex.gdb_server_port", parser.get<unsigned short>("gdb-port"));
    cfg.set_value("i_system.i_hifive1.i_fe310.i_core_complex.dump_ir", parser.is_set("dump-ir"));
    if (parser.is_set("elf"))
        cfg.set_value("i_system.i_hifive1.i_fe310.i_core_complex.elf_file", parser.get<std::string>("elf"));
    else if (parser.is_set("argv")){
        auto args = parser.get<std::vector<std::string>>("argv");
        if(args.size())
            cfg.set_value("i_system.i_hifive1.i_fe310.i_core_complex.elf_file", args[0]);
    }
    if (parser.is_set("quantum"))
        tlm::tlm_global_quantum::instance().set(sc_time(parser.get<unsigned>("quantum"), SC_NS));
    if (parser.is_set("reset")) {
        auto str = parser.get<std::string>("reset");
        uint64_t start_address = str.find("0x") == 0 ? std::stoull(str.substr(2), nullptr, 16) : std::stoull(str, nullptr, 10);
        cfg.set_value("i_system.i_hifive1.i_fe310.i_core_complex.reset_address", start_address);
    }
    if (parser.is_set("disass")) {
        cfg.set_value("i_system.i_hifive1.i_fe310.i_core_complex.enable_disass", true);
        LOGGER(disass)::reporting_level() = logging::INFO;
        auto file_name = parser.get<std::string>("disass");
        if (file_name.length() > 0) {
            LOG_OUTPUT(disass)::stream() = fopen(file_name.c_str(), "w");
            LOGGER(disass)::print_time() = false;
            LOGGER(disass)::print_severity() = false;
        }
    }
    ///////////////////////////////////////////////////////////////////////////
    // run simulation
    ///////////////////////////////////////////////////////////////////////////
    try {
        if (parser.is_set("max_time")) {
            sc_start(scc::parse_from_string(parser.get<std::string>("max_time")));
        } else
            sc_start();
    } catch(sc_report& e) {
        SCCERR() << "Caught sc_report exception during simulation: " << e.what() << ":" << e.get_msg();
    } catch(std::exception& e) {
        SCCERR() << "Caught exception during simulation: " << e.what();
    } catch(...) {
        SCCERR() << "Caught unspecified exception during simulation";
    }
    if(sc_is_running()) {
        SCCERR() << "Simulation timeout!"; // calls sc_stop
    }
    auto errcnt = sc_report_handler::get_count(SC_ERROR);
    auto warncnt = sc_report_handler::get_count(SC_WARNING);
    SCCINFO() << "Finished, there were " << errcnt << " error" << (errcnt == 1 ? "" : "s") << " and " << warncnt << " warning"
              << (warncnt == 1 ? "" : "s");
    return errcnt + warncnt;
}
