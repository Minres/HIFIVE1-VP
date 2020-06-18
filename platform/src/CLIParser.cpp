/*******************************************************************************
 * Copyright (C) 2018 MINRES Technologies GmbH
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
#include <scc/report.h>
#include <iostream>
#include <iss/log_categories.h>
#include <stdexcept>

namespace po = boost::program_options;
using namespace sc_core;

CLIParser::CLIParser(int argc, char *argv[])
: desc("Options")
, valid(false) {
    build();
    try {
        // Variant 1: no non-options
        //po::store(po::parse_command_line(argc, argv, desc), vm_); // can throw
        // Variant 2: collect unrecognized options
        //auto parsed = po::command_line_parser(argc, argv).options(desc).allow_unregistered().run();
        //po::store(parsed, vm_); // can throw
        // Variant 3: collect options in string vector
        po::options_description hidden;
        hidden.add_options()("argv", po::value<std::vector<std::string>>(), "arguments");

        po::options_description all_opt;
        po::positional_options_description posopt;
        po::store(po::command_line_parser(argc, argv).
                options(all_opt.add(desc).add(hidden)).
                //allow_unregistered().
                positional(posopt.add("argv", -1)).
//              style(
//                    po::command_line_style::default_style |
//                    po::command_line_style::allow_slash_for_short).
                run(),
                vm_); // can throw

        // --help option
        if (vm_.count("help")) {
            std::cout << "DBT-RISE-RiscV simulator for RISC-V" << std::endl << desc << std::endl;
        }
        po::notify(vm_); // throws on error, so do after help in case there are any problems
        valid = true;
    } catch (po::error &e) {
        std::cerr << "ERROR: " << e.what() << std::endl << std::endl;
        std::cerr << desc << std::endl;
    }

    auto verbosity = !vm_["Verbose"].defaulted() ? vm_["Verbose"].as<unsigned>() : vm_["verbose"].as<unsigned>();
    auto colored_output = vm_["Verbose"].defaulted();
    auto dbg_level = vm_.count("debug-level")
                         ? vm_["debug-level"].as<scc::log>()
                         : static_cast<scc::log>(std::min<unsigned>(static_cast<unsigned>(scc::log::DBGTRACE), verbosity));

    auto log_regex       = vm_["log-filter"].as<std::string>();

    if (vm_.count("log-file")) {
        auto log_file_name   = vm_["log-file"].as<std::string>();
        scc::init_logging(scc::LogConfig()
        .logFileName(log_file_name)
        .logLevel(dbg_level)
        .logFilterRegex(log_regex)
        .coloredOutput(colored_output)
        );
    } else {
        scc::init_logging(scc::LogConfig()
        .logLevel(dbg_level)
        .logFilterRegex(log_regex)
        .coloredOutput(colored_output)
        );
    }
    LOGGER(DEFAULT)::reporting_level()=static_cast<logging::log_level>(dbg_level);
    LOGGER(DEFAULT)::print_time()=false;
    LOGGER(DEFAULT)::print_severity()=false;
    LOG_OUTPUT(DEFAULT)::ostream() = &std::cout;
}

void CLIParser::build() {
    // clang-format off
    desc.add_options()
            ("help,h",        "Print help message")
            ("verbose,v",      po::value<unsigned>()->implicit_value(3), "Sets logging verbosity")
            ("Verbose,V",      po::value<unsigned>()->default_value(logging::INFO), "Debug output level as with --verbose but print non-colored")
            ("debug-level,D",  po::value<scc::log>(), "Debug output level (textual) as with --verbose")
            ("log-file",       po::value<std::string>(), "Sets default log file.")
            ("log-filter",     po::value<std::string>()->default_value(""), "log filter regular expression name")
            ("disass,d",       po::value<std::string>()->implicit_value(""), "Enables disassembly")
            ("elf,l",          po::value<std::string>(), "ELF file to load")
            ("gdb-port,g",     po::value<unsigned short>()->default_value(0), "enable gdb server and specify port to use")
            ("ir-dump",        "dump the intermediate representation")
            ("quantum",        po::value<unsigned>(), "SystemC quantum time in ns")
            ("reset,r",        po::value<std::string>(), "reset address")
            ("trace-level,t",  po::value<unsigned>()->default_value(0), "enable tracing, or combination of 1=signals and 2=TX text, 4=TX compressed text, 6=TX in SQLite")
            ("trace-default-on", "enables tracing for all unspecified modules")
            ("trace-file",     po::value<std::string>()->default_value("system"), "set th ename of the trace file")
            ("max_time,m",     po::value<std::string>(), "maximum time to run")
            ("backend",        po::value<std::string>()->default_value("tcc"), "ISS engine to use")
            ("heart-beat,b",   "Enable heartbeat printing")
            ("config-file,c",  po::value<std::string>()->default_value(""), "read configuration from file")
            ("dump-config,dc", po::value<std::string>()->default_value(""), "dump configuration to file file");
    // clang-format on
}

CLIParser::~CLIParser() = default;
