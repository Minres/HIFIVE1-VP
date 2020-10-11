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

#include "scc/signal_initiator_mixin.h"
#include "scc/time2tick.h"
#include "sysc/SiFive/spi.h"
#include "sysc/rtl/tl_uh_bfm.h"
#include <VTLSPI.h>
#include <scc/utilities.h>
#include <tlm.h>
#include <tlm/tlm_signal_conv.h>

namespace sysc {
namespace spi_impl {
using namespace sc_core;

class rtl : public spi {
public:
    SC_HAS_PROCESS(beh);// NOLINT

    rtl(sc_module_name nm);
    ~rtl() override;

    //    void trace( sc_trace_file* tf ) const override {
    //    }

private:
    sc_signal<bool> clock;
    sc_signal<uint32_t> a_bits_address;
    sc_signal<uint32_t> a_bits_data;
    sc_signal<bool> a_ready;
    sc_signal<bool> a_valid;
    sc_signal<uint32_t> a_bits_opcode;
    sc_signal<uint32_t> a_bits_param;
    sc_signal<uint32_t> a_bits_size;
    sc_signal<uint32_t> a_bits_source;
    sc_signal<uint32_t> a_bits_mask;
    sc_signal<bool> a_bits_corrupt;
    sc_signal<uint32_t> d_bits_data;
    sc_signal<bool> d_ready;
    sc_signal<bool> d_valid;
    sc_signal<uint32_t> d_bits_opcode;
    sc_signal<uint32_t> d_bits_size;
    sc_signal<uint32_t> d_bits_source;
    sc_signal<bool> sck;
    sc_signal<bool> dq_0_i;
    sc_signal<bool> dq_0_o;
    sc_signal<bool> dq_0_oe;
    sc_signal<bool> dq_1_i;
    sc_signal<bool> dq_1_o;
    sc_signal<bool> dq_1_oe;
    sc_signal<bool> dq_2_i;
    sc_signal<bool> dq_3_i;
    sc_signal<bool> cs_0;
    sc_signal<bool> cs_2;
    sc_signal<bool> cs_3;

    VTLSPI i_vtlspi;
    tl_uh_bfm i_tlbfm;
    scc::time2tick i_time2tick;
    tlm::sc_signal2tlm_signal<bool> i_sck_conv;
    tlm::sc_signal2tlm_signal<bool> i_mosi_conv;
    tlm::tlm_signal2sc_signal<bool> i_miso_conv;
    tlm::sc_signal2tlm_signal<bool> i_scs0_conv, i_scs2_conv, i_scs3_conv;
    scc::tlm_signal_bool_opt_out scs_1;
};

rtl::rtl(sc_module_name nm)
: spi(nm)
, NAMED(a_bits_address)
, NAMED(a_bits_data)
, NAMED(a_ready)
, NAMED(a_valid)
, NAMED(a_bits_opcode)
, NAMED(a_bits_param)
, NAMED(a_bits_size)
, NAMED(a_bits_source)
, NAMED(a_bits_mask)
, NAMED(a_bits_corrupt)
, NAMED(d_bits_data)
, NAMED(d_ready)
, NAMED(d_valid)
, NAMED(d_bits_opcode)
, NAMED(d_bits_size)
, NAMED(d_bits_source)
, NAMED(sck)
, NAMED(dq_0_i)
, NAMED(dq_0_o)
, NAMED(dq_0_oe)
, NAMED(dq_1_i)
, NAMED(dq_1_o)
, NAMED(dq_1_oe)
, NAMED(dq_2_i)
, NAMED(dq_3_i)
, NAMED(cs_0)
, NAMED(cs_2)
, NAMED(cs_3)
, NAMED(i_vtlspi)
, NAMED(i_tlbfm, 0x10024000)
, NAMED(i_time2tick)
, NAMED(i_sck_conv)
, NAMED(i_mosi_conv)
, NAMED(i_miso_conv)
, NAMED(i_scs0_conv)
, NAMED(i_scs2_conv)
, NAMED(i_scs3_conv)
, NAMED(scs_1) {
    i_vtlspi.clock(clock);
    i_vtlspi.reset(rst_i);
    i_vtlspi.auto_int_xing_out_sync_0(irq_o);
    i_vtlspi.auto_control_xing_in_a_ready(a_ready);
    i_vtlspi.auto_control_xing_in_a_valid(a_valid);
    i_vtlspi.auto_control_xing_in_a_bits_address(a_bits_address);
    i_vtlspi.auto_control_xing_in_a_bits_data(a_bits_data);
    i_vtlspi.auto_control_xing_in_a_bits_opcode(a_bits_opcode);
    i_vtlspi.auto_control_xing_in_a_bits_param(a_bits_param);
    i_vtlspi.auto_control_xing_in_a_bits_size(a_bits_size);
    i_vtlspi.auto_control_xing_in_a_bits_source(a_bits_source);
    i_vtlspi.auto_control_xing_in_a_bits_mask(a_bits_mask);
    i_vtlspi.auto_control_xing_in_a_bits_corrupt(a_bits_corrupt);
    i_vtlspi.auto_control_xing_in_d_ready(d_ready);
    i_vtlspi.auto_control_xing_in_d_valid(d_valid);
    i_vtlspi.auto_control_xing_in_d_bits_data(d_bits_data);
    i_vtlspi.auto_control_xing_in_d_bits_opcode(d_bits_opcode);
    i_vtlspi.auto_control_xing_in_d_bits_size(d_bits_size);
    i_vtlspi.auto_control_xing_in_d_bits_source(d_bits_source);
    i_vtlspi.auto_io_out_sck(sck);
    i_vtlspi.auto_io_out_dq_0_i(dq_0_i);
    i_vtlspi.auto_io_out_dq_0_o(dq_0_o);
    i_vtlspi.auto_io_out_dq_0_oe(dq_0_oe);
    i_vtlspi.auto_io_out_dq_1_i(dq_1_i);
    i_vtlspi.auto_io_out_dq_1_o(dq_1_o);
    i_vtlspi.auto_io_out_dq_1_oe(dq_1_oe);
    i_vtlspi.auto_io_out_dq_2_i(dq_2_i);
    i_vtlspi.auto_io_out_dq_3_i(dq_3_i);
    i_vtlspi.auto_io_out_cs_0(cs_0);
    i_vtlspi.auto_io_out_cs_2(cs_2);
    i_vtlspi.auto_io_out_cs_3(cs_3);

    i_tlbfm.clock(clock);
    i_tlbfm.reset(rst_i);
    spi::socket(i_tlbfm.socket);
    i_tlbfm.a_ready(a_ready);
    i_tlbfm.a_valid(a_valid);
    i_tlbfm.a_bits_address(a_bits_address);
    i_tlbfm.a_bits_data(a_bits_data);
    i_tlbfm.d_bits_data(d_bits_data);
    i_tlbfm.a_bits_opcode(a_bits_opcode);
    i_tlbfm.a_bits_param(a_bits_param);
    i_tlbfm.a_bits_size(a_bits_size);
    i_tlbfm.a_bits_source(a_bits_source);
    i_tlbfm.a_bits_mask(a_bits_mask);
    i_tlbfm.a_bits_corrupt(a_bits_corrupt);
    i_tlbfm.d_ready(d_ready);
    i_tlbfm.d_valid(d_valid);
    i_tlbfm.d_bits_opcode(d_bits_opcode);
    i_tlbfm.d_bits_size(d_bits_size);
    i_tlbfm.d_bits_source(d_bits_source);

    i_time2tick.clk_i(clk_i);
    i_time2tick.clk_o(clock);
    i_sck_conv.s_i(sck);
    i_sck_conv.t_o(sck_o);
    i_mosi_conv.s_i(dq_0_o);
    i_mosi_conv.t_o(mosi_o);
    miso_i(i_miso_conv.t_i);
    i_miso_conv.s_o(dq_0_i);
    i_scs0_conv.s_i(cs_0);
    i_scs0_conv.t_o(scs_o[0]);
    i_scs2_conv.s_i(cs_2);
    i_scs2_conv.t_o(scs_o[2]);
    scs_1(scs_o[1]); // dummy to drive port
    i_scs3_conv.s_i(cs_3);
    i_scs3_conv.t_o(scs_o[3]);
}

rtl::~rtl() = default;
}

template <> std::unique_ptr<spi> spi::create<sysc::spi_impl::rtl>(sc_core::sc_module_name nm) {
    auto *res = new sysc::spi_impl::rtl(nm);
    return std::unique_ptr<spi>(res);
}

} /* namespace sysc */
