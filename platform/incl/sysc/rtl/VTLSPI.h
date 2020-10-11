// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VTLSPI_H_
#define _VTLSPI_H_

#include "systemc.h"
#include "verilated_heavy.h"
#include "verilated_sc.h"

class VTLSPI__Syms;

//----------

SC_MODULE(VTLSPI) {
public:
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    sc_in<bool> clock;
    sc_in<bool> reset;
    sc_out<bool> auto_int_xing_out_sync_0;
    sc_out<bool> auto_control_xing_in_a_ready;
    sc_in<bool> auto_control_xing_in_a_valid;
    sc_in<uint32_t> auto_control_xing_in_a_bits_opcode;
    sc_in<uint32_t> auto_control_xing_in_a_bits_param;
    sc_in<uint32_t> auto_control_xing_in_a_bits_size;
    sc_in<uint32_t> auto_control_xing_in_a_bits_source;
    sc_in<uint32_t> auto_control_xing_in_a_bits_mask;
    sc_in<bool> auto_control_xing_in_a_bits_corrupt;
    sc_in<bool> auto_control_xing_in_d_ready;
    sc_out<bool> auto_control_xing_in_d_valid;
    sc_out<uint32_t> auto_control_xing_in_d_bits_opcode;
    sc_out<uint32_t> auto_control_xing_in_d_bits_size;
    sc_out<uint32_t> auto_control_xing_in_d_bits_source;
    sc_out<bool> auto_io_out_sck;
    sc_in<bool> auto_io_out_dq_0_i;
    sc_out<bool> auto_io_out_dq_0_o;
    sc_out<bool> auto_io_out_dq_0_oe;
    sc_in<bool> auto_io_out_dq_1_i;
    sc_out<bool> auto_io_out_dq_1_o;
    sc_out<bool> auto_io_out_dq_1_oe;
    sc_in<bool> auto_io_out_dq_2_i;
    sc_in<bool> auto_io_out_dq_3_i;
    sc_out<bool> auto_io_out_cs_0;
    sc_out<bool> auto_io_out_cs_2;
    sc_out<bool> auto_io_out_cs_3;
    sc_in<uint32_t> auto_control_xing_in_a_bits_address;
    sc_in<uint32_t> auto_control_xing_in_a_bits_data;
    sc_out<uint32_t> auto_control_xing_in_d_bits_data;

    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_SIG8(TLSPI__DOT__fifo_io_tx_valid, 0, 0);
        VL_SIG8(TLSPI__DOT__fifo_io_ip_txwm, 0, 0);
        VL_SIG8(TLSPI__DOT__fifo_io_ip_rxwm, 0, 0);
        VL_SIG8(TLSPI__DOT__mac_io_link_tx_ready, 0, 0);
        VL_SIG8(TLSPI__DOT__ctrl_fmt_proto, 1, 0);
        VL_SIG8(TLSPI__DOT__ctrl_fmt_endian, 0, 0);
        VL_SIG8(TLSPI__DOT__ctrl_fmt_iodir, 0, 0);
        VL_SIG8(TLSPI__DOT__ctrl_fmt_len, 3, 0);
        VL_SIG8(TLSPI__DOT__ctrl_sck_pol, 0, 0);
        VL_SIG8(TLSPI__DOT__ctrl_sck_pha, 0, 0);
        VL_SIG8(TLSPI__DOT__ctrl_cs_id, 1, 0);
        VL_SIG8(TLSPI__DOT__ctrl_cs_dflt_0, 0, 0);
        VL_SIG8(TLSPI__DOT__ctrl_cs_dflt_1, 0, 0);
        VL_SIG8(TLSPI__DOT__ctrl_cs_dflt_2, 0, 0);
        VL_SIG8(TLSPI__DOT__ctrl_cs_dflt_3, 0, 0);
        VL_SIG8(TLSPI__DOT__ctrl_cs_mode, 1, 0);
        VL_SIG8(TLSPI__DOT__ctrl_dla_cssck, 7, 0);
        VL_SIG8(TLSPI__DOT__ctrl_dla_sckcs, 7, 0);
        VL_SIG8(TLSPI__DOT__ctrl_dla_intercs, 7, 0);
        VL_SIG8(TLSPI__DOT__ctrl_dla_interxfr, 7, 0);
        VL_SIG8(TLSPI__DOT__ctrl_wm_tx, 3, 0);
        VL_SIG8(TLSPI__DOT__ctrl_wm_rx, 3, 0);
        VL_SIG8(TLSPI__DOT__ie_txwm, 0, 0);
        VL_SIG8(TLSPI__DOT__ie_rxwm, 0, 0);
        VL_SIG8(TLSPI__DOT___T_426, 7, 0);
        VL_SIG8(TLSPI__DOT___T_1495, 0, 0);
        VL_SIG8(TLSPI__DOT___T_1732, 0, 0);
        VL_SIG8(TLSPI__DOT___T_1766, 0, 0);
        VL_SIG8(TLSPI__DOT___T_1796, 0, 0);
        VL_SIG8(TLSPI__DOT___T_1742, 0, 0);
        VL_SIG8(TLSPI__DOT___T_1904, 0, 0);
        VL_SIG8(TLSPI__DOT___T_1844, 0, 0);
        VL_SIG8(TLSPI__DOT___T_1832, 0, 0);
        VL_SIG8(TLSPI__DOT___T_1802, 0, 0);
        VL_SIG8(TLSPI__DOT___GEN_155, 0, 0);
        VL_SIG8(TLSPI__DOT___GEN_162, 0, 0);
        VL_SIG8(TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_52, 0, 0);
        VL_SIG8(TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_55, 0, 0);
        VL_SIG8(TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_73, 3, 0);
        VL_SIG8(TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_97, 0, 0);
        VL_SIG8(TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_167, 0, 0);
        VL_SIG8(TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_181, 0, 0);
        VL_SIG8(TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_245, 0, 0);
        VL_SIG8(TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_486, 0, 0);
        VL_SIG8(TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_496, 0, 0);
        VL_SIG8(TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_499, 0, 0);
        VL_SIG8(TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_500, 0, 0);
        VL_SIG8(TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_509, 2, 0);
        VL_SIG8(TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_511, 2, 0);
        VL_SIG8(TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_513, 1, 0);
        VL_SIG8(TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_515, 5, 0);
        VL_SIG8(TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_522, 0, 0);
        VL_SIG8(TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_526, 0, 0);
        VL_SIG8(TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_530, 0, 0);
        VL_SIG8(TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_534, 0, 0);
        VL_SIG8(TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_538, 0, 0);
        VL_SIG8(TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_541, 0, 0);
        VL_SIG8(TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_542, 0, 0);
        VL_SIG8(TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_551, 0, 0);
        VL_SIG8(TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_554, 0, 0);
        VL_SIG8(TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_555, 0, 0);
        VL_SIG8(TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_564, 2, 0);
        VL_SIG8(TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_568, 1, 0);
        VL_SIG8(TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_570, 5, 0);
    };
    struct {
        VL_SIG8(TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_579, 0, 0);
        VL_SIG8(TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_587, 0, 0);
        VL_SIG8(TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_591, 0, 0);
        VL_SIG8(TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_602, 0, 0);
        VL_SIG8(TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_615, 0, 0);
        VL_SIG8(TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_618, 0, 0);
        VL_SIG8(TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_619, 0, 0);
        VL_SIG8(TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_636, 0, 0);
        VL_SIG8(TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_639, 0, 0);
        VL_SIG8(TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_640, 0, 0);
        VL_SIG8(TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_658, 0, 0);
        VL_SIG8(TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_673, 0, 0);
        VL_SIG8(TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_687, 0, 0);
        VL_SIG8(TLSPI__DOT__intsource__DOT__AsyncResetRegVec_w1_i0__DOT__reg_0_q, 0, 0);
        VL_SIG8(TLSPI__DOT__TLMonitor__DOT___T_52, 0, 0);
        VL_SIG8(TLSPI__DOT__TLMonitor__DOT___T_55, 0, 0);
        VL_SIG8(TLSPI__DOT__TLMonitor__DOT___T_73, 3, 0);
        VL_SIG8(TLSPI__DOT__TLMonitor__DOT___T_97, 0, 0);
        VL_SIG8(TLSPI__DOT__TLMonitor__DOT___T_167, 0, 0);
        VL_SIG8(TLSPI__DOT__TLMonitor__DOT___T_181, 0, 0);
        VL_SIG8(TLSPI__DOT__TLMonitor__DOT___T_245, 0, 0);
        VL_SIG8(TLSPI__DOT__TLMonitor__DOT___T_486, 0, 0);
        VL_SIG8(TLSPI__DOT__TLMonitor__DOT___T_496, 0, 0);
        VL_SIG8(TLSPI__DOT__TLMonitor__DOT___T_499, 0, 0);
        VL_SIG8(TLSPI__DOT__TLMonitor__DOT___T_500, 0, 0);
        VL_SIG8(TLSPI__DOT__TLMonitor__DOT___T_509, 2, 0);
        VL_SIG8(TLSPI__DOT__TLMonitor__DOT___T_511, 2, 0);
        VL_SIG8(TLSPI__DOT__TLMonitor__DOT___T_513, 1, 0);
        VL_SIG8(TLSPI__DOT__TLMonitor__DOT___T_515, 5, 0);
        VL_SIG8(TLSPI__DOT__TLMonitor__DOT___T_522, 0, 0);
        VL_SIG8(TLSPI__DOT__TLMonitor__DOT___T_526, 0, 0);
        VL_SIG8(TLSPI__DOT__TLMonitor__DOT___T_530, 0, 0);
        VL_SIG8(TLSPI__DOT__TLMonitor__DOT___T_534, 0, 0);
        VL_SIG8(TLSPI__DOT__TLMonitor__DOT___T_538, 0, 0);
        VL_SIG8(TLSPI__DOT__TLMonitor__DOT___T_541, 0, 0);
        VL_SIG8(TLSPI__DOT__TLMonitor__DOT___T_542, 0, 0);
        VL_SIG8(TLSPI__DOT__TLMonitor__DOT___T_551, 0, 0);
        VL_SIG8(TLSPI__DOT__TLMonitor__DOT___T_554, 0, 0);
        VL_SIG8(TLSPI__DOT__TLMonitor__DOT___T_555, 0, 0);
        VL_SIG8(TLSPI__DOT__TLMonitor__DOT___T_564, 2, 0);
        VL_SIG8(TLSPI__DOT__TLMonitor__DOT___T_568, 1, 0);
        VL_SIG8(TLSPI__DOT__TLMonitor__DOT___T_570, 5, 0);
        VL_SIG8(TLSPI__DOT__TLMonitor__DOT___T_579, 0, 0);
        VL_SIG8(TLSPI__DOT__TLMonitor__DOT___T_587, 0, 0);
        VL_SIG8(TLSPI__DOT__TLMonitor__DOT___T_591, 0, 0);
        VL_SIG8(TLSPI__DOT__TLMonitor__DOT___T_602, 0, 0);
        VL_SIG8(TLSPI__DOT__TLMonitor__DOT___T_615, 0, 0);
        VL_SIG8(TLSPI__DOT__TLMonitor__DOT___T_618, 0, 0);
        VL_SIG8(TLSPI__DOT__TLMonitor__DOT___T_619, 0, 0);
        VL_SIG8(TLSPI__DOT__TLMonitor__DOT___T_636, 0, 0);
        VL_SIG8(TLSPI__DOT__TLMonitor__DOT___T_639, 0, 0);
        VL_SIG8(TLSPI__DOT__TLMonitor__DOT___T_640, 0, 0);
        VL_SIG8(TLSPI__DOT__TLMonitor__DOT___T_658, 0, 0);
        VL_SIG8(TLSPI__DOT__TLMonitor__DOT___T_673, 0, 0);
        VL_SIG8(TLSPI__DOT__TLMonitor__DOT___T_687, 0, 0);
        VL_SIG8(TLSPI__DOT__fifo__DOT__rxq_io_enq_valid, 0, 0);
        VL_SIG8(TLSPI__DOT__fifo__DOT__rxen, 0, 0);
        VL_SIG8(TLSPI__DOT__fifo__DOT___T_57, 3, 0);
        VL_SIG8(TLSPI__DOT__fifo__DOT__cs_mode, 1, 0);
        VL_SIG8(TLSPI__DOT__fifo__DOT__txq__DOT___T_35___05FT_58_data, 7, 0);
        VL_SIG8(TLSPI__DOT__fifo__DOT__txq__DOT__value, 2, 0);
        VL_SIG8(TLSPI__DOT__fifo__DOT__txq__DOT__value_1, 2, 0);
        VL_SIG8(TLSPI__DOT__fifo__DOT__txq__DOT___T_39, 0, 0);
        VL_SIG8(TLSPI__DOT__fifo__DOT__txq__DOT___T_40, 0, 0);
    };
    struct {
        VL_SIG8(TLSPI__DOT__fifo__DOT__txq__DOT___T_42, 0, 0);
        VL_SIG8(TLSPI__DOT__fifo__DOT__txq__DOT___T_43, 0, 0);
        VL_SIG8(TLSPI__DOT__fifo__DOT__txq__DOT___T_44, 0, 0);
        VL_SIG8(TLSPI__DOT__fifo__DOT__txq__DOT___T_47, 0, 0);
        VL_SIG8(TLSPI__DOT__fifo__DOT__txq__DOT___T_52, 2, 0);
        VL_SIG8(TLSPI__DOT__fifo__DOT__txq__DOT___T_54, 2, 0);
        VL_SIG8(TLSPI__DOT__fifo__DOT__rxq__DOT__value, 2, 0);
        VL_SIG8(TLSPI__DOT__fifo__DOT__rxq__DOT__value_1, 2, 0);
        VL_SIG8(TLSPI__DOT__fifo__DOT__rxq__DOT___T_39, 0, 0);
        VL_SIG8(TLSPI__DOT__fifo__DOT__rxq__DOT___T_40, 0, 0);
        VL_SIG8(TLSPI__DOT__fifo__DOT__rxq__DOT___T_42, 0, 0);
        VL_SIG8(TLSPI__DOT__fifo__DOT__rxq__DOT___T_43, 0, 0);
        VL_SIG8(TLSPI__DOT__fifo__DOT__rxq__DOT___T_44, 0, 0);
        VL_SIG8(TLSPI__DOT__fifo__DOT__rxq__DOT___T_47, 0, 0);
        VL_SIG8(TLSPI__DOT__fifo__DOT__rxq__DOT___T_52, 2, 0);
        VL_SIG8(TLSPI__DOT__fifo__DOT__rxq__DOT___T_54, 2, 0);
        VL_SIG8(TLSPI__DOT__mac__DOT__phy_io_op_valid, 0, 0);
        VL_SIG8(TLSPI__DOT__mac__DOT__phy_io_op_bits_fn, 0, 0);
        VL_SIG8(TLSPI__DOT__mac__DOT__phy_io_op_bits_stb, 0, 0);
        VL_SIG8(TLSPI__DOT__mac__DOT__phy_io_op_bits_cnt, 7, 0);
        VL_SIG8(TLSPI__DOT__mac__DOT__cs_id, 1, 0);
        VL_SIG8(TLSPI__DOT__mac__DOT__cs_dflt_0, 0, 0);
        VL_SIG8(TLSPI__DOT__mac__DOT__cs_dflt_1, 0, 0);
        VL_SIG8(TLSPI__DOT__mac__DOT__cs_dflt_2, 0, 0);
        VL_SIG8(TLSPI__DOT__mac__DOT__cs_dflt_3, 0, 0);
        VL_SIG8(TLSPI__DOT__mac__DOT__cs_set, 0, 0);
        VL_SIG8(TLSPI__DOT__mac__DOT___T_69, 3, 0);
        VL_SIG8(TLSPI__DOT__mac__DOT___T_88, 3, 0);
        VL_SIG8(TLSPI__DOT__mac__DOT__clear, 0, 0);
        VL_SIG8(TLSPI__DOT__mac__DOT__cs_assert, 0, 0);
        VL_SIG8(TLSPI__DOT__mac__DOT__cs_deassert, 0, 0);
        VL_SIG8(TLSPI__DOT__mac__DOT___T_94, 0, 0);
        VL_SIG8(TLSPI__DOT__mac__DOT__state, 1, 0);
        VL_SIG8(TLSPI__DOT__mac__DOT___T_97, 0, 0);
        VL_SIG8(TLSPI__DOT__mac__DOT___T_99, 0, 0);
        VL_SIG8(TLSPI__DOT__mac__DOT___T_102, 0, 0);
        VL_SIG8(TLSPI__DOT__mac__DOT___T_107, 3, 0);
        VL_SIG8(TLSPI__DOT__mac__DOT__phy__DOT__ctrl_sck_pol, 0, 0);
        VL_SIG8(TLSPI__DOT__mac__DOT__phy__DOT__ctrl_sck_pha, 0, 0);
        VL_SIG8(TLSPI__DOT__mac__DOT__phy__DOT__ctrl_fmt_proto, 1, 0);
        VL_SIG8(TLSPI__DOT__mac__DOT__phy__DOT__ctrl_fmt_endian, 0, 0);
        VL_SIG8(TLSPI__DOT__mac__DOT__phy__DOT__ctrl_fmt_iodir, 0, 0);
        VL_SIG8(TLSPI__DOT__mac__DOT__phy__DOT__setup_d, 0, 0);
        VL_SIG8(TLSPI__DOT__mac__DOT__phy__DOT___T_42, 0, 0);
        VL_SIG8(TLSPI__DOT__mac__DOT__phy__DOT___T_43, 0, 0);
        VL_SIG8(TLSPI__DOT__mac__DOT__phy__DOT__sample_d, 0, 0);
        VL_SIG8(TLSPI__DOT__mac__DOT__phy__DOT___T_44, 0, 0);
        VL_SIG8(TLSPI__DOT__mac__DOT__phy__DOT___T_45, 0, 0);
        VL_SIG8(TLSPI__DOT__mac__DOT__phy__DOT__last_d, 0, 0);
        VL_SIG8(TLSPI__DOT__mac__DOT__phy__DOT__scnt, 7, 0);
        VL_SIG8(TLSPI__DOT__mac__DOT__phy__DOT__sched, 0, 0);
        VL_SIG8(TLSPI__DOT__mac__DOT__phy__DOT__sck, 0, 0);
        VL_SIG8(TLSPI__DOT__mac__DOT__phy__DOT__cref, 0, 0);
        VL_SIG8(TLSPI__DOT__mac__DOT__phy__DOT__cinv, 0, 0);
        VL_SIG8(TLSPI__DOT__mac__DOT__phy__DOT__rxd, 3, 0);
        VL_SIG8(TLSPI__DOT__mac__DOT__phy__DOT__buffer, 7, 0);
        VL_SIG8(TLSPI__DOT__mac__DOT__phy__DOT___T_71, 7, 0);
        VL_SIG8(TLSPI__DOT__mac__DOT__phy__DOT__shift, 0, 0);
        VL_SIG8(TLSPI__DOT__mac__DOT__phy__DOT___T_96, 7, 0);
        VL_SIG8(TLSPI__DOT__mac__DOT__phy__DOT__txd, 3, 0);
        VL_SIG8(TLSPI__DOT__mac__DOT__phy__DOT___T_154, 0, 0);
        VL_SIG8(TLSPI__DOT__mac__DOT__phy__DOT___T_155, 0, 0);
        VL_SIG8(TLSPI__DOT__mac__DOT__phy__DOT__accept, 0, 0);
        VL_SIG8(TLSPI__DOT__mac__DOT__phy__DOT__txd_in, 3, 0);
    };
    struct {
        VL_SIG8(TLSPI__DOT__mac__DOT__phy__DOT___T_102, 1, 0);
        VL_SIG8(TLSPI__DOT__mac__DOT__phy__DOT__done, 0, 0);
        VL_SIG8(TLSPI__DOT__mac__DOT__phy__DOT___T_156, 0, 0);
        VL_SIG8(TLSPI__DOT__mac__DOT__phy__DOT__xfr, 0, 0);
        VL_SIG8(TLSPI__DOT__mac__DOT__phy__DOT___GEN_15, 0, 0);
        VL_SIG8(TLSPI__DOT__mac__DOT__phy__DOT___GEN_22, 0, 0);
        VL_SIG8(TLSPI__DOT__mac__DOT__phy__DOT___T_111, 0, 0);
        VL_SIG8(TLSPI__DOT__mac__DOT__phy__DOT__txen_2, 0, 0);
        VL_SIG8(TLSPI__DOT__mac__DOT__phy__DOT___T_128, 0, 0);
        VL_SIG8(TLSPI__DOT__mac__DOT__phy__DOT___T_148, 0, 0);
        VL_SIG8(TLSPI__DOT__mac__DOT__phy__DOT___GEN_13, 0, 0);
        VL_SIG16(TLSPI__DOT__ctrl_sck_div, 11, 0);
        VL_SIG16(TLSPI__DOT__mac__DOT__phy__DOT__ctrl_sck_div, 11, 0);
        VL_SIG16(TLSPI__DOT__mac__DOT__phy__DOT__tcnt, 11, 0);
        VL_SIG16(TLSPI__DOT__mac__DOT__phy__DOT___T_47, 11, 0);
        VL_SIG16(TLSPI__DOT__mac__DOT__phy__DOT___GEN_16, 11, 0);
        VL_SIG(TLSPI__DOT___T_626, 31, 0);
        VL_SIG(TLSPI__DOT___GEN_172, 31, 0);
        VL_SIG(TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_517, 28, 0);
        VL_SIG(TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_679, 31, 0);
        VL_SIG(TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_690, 31, 0);
        VL_SIG(TLSPI__DOT__buffer__DOT__TLMonitor__DOT__plusarg_reader__DOT__myplus, 31, 0);
        VL_SIG(TLSPI__DOT__TLMonitor__DOT___T_517, 28, 0);
        VL_SIG(TLSPI__DOT__TLMonitor__DOT___T_679, 31, 0);
        VL_SIG(TLSPI__DOT__TLMonitor__DOT___T_690, 31, 0);
        VL_SIG(TLSPI__DOT__TLMonitor__DOT__plusarg_reader__DOT__myplus, 31, 0);
        VL_SIG64(TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_604, 63, 0);
        VL_SIG64(TLSPI__DOT__buffer__DOT__TLMonitor__DOT___GEN_15, 63, 0);
        VL_SIG64(TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_677, 63, 0);
        VL_SIG64(TLSPI__DOT__TLMonitor__DOT___T_604, 63, 0);
        VL_SIG64(TLSPI__DOT__TLMonitor__DOT___GEN_15, 63, 0);
        VL_SIG64(TLSPI__DOT__TLMonitor__DOT___T_677, 63, 0);
        VL_SIG8(TLSPI__DOT__fifo__DOT__txq__DOT___T_35[8], 7, 0);
        VL_SIG8(TLSPI__DOT__fifo__DOT__rxq__DOT___T_35[8], 7, 0);
    };

    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    VL_SIG8(__Vcellinp__TLSPI__reset, 0, 0);
    VL_SIG8(__Vcellinp__TLSPI__clock, 0, 0);
    VL_SIG8(__Vcellinp__TLSPI__auto_io_out_dq_3_i, 0, 0);
    VL_SIG8(__Vcellinp__TLSPI__auto_io_out_dq_2_i, 0, 0);
    VL_SIG8(__Vcellinp__TLSPI__auto_io_out_dq_1_i, 0, 0);
    VL_SIG8(__Vcellinp__TLSPI__auto_io_out_dq_0_i, 0, 0);
    VL_SIG8(__Vcellinp__TLSPI__auto_control_xing_in_d_ready, 0, 0);
    VL_SIG8(__Vcellinp__TLSPI__auto_control_xing_in_a_bits_corrupt, 0, 0);
    VL_SIG8(__Vcellinp__TLSPI__auto_control_xing_in_a_bits_mask, 3, 0);
    VL_SIG8(__Vcellinp__TLSPI__auto_control_xing_in_a_bits_source, 5, 0);
    VL_SIG8(__Vcellinp__TLSPI__auto_control_xing_in_a_bits_size, 1, 0);
    VL_SIG8(__Vcellinp__TLSPI__auto_control_xing_in_a_bits_param, 2, 0);
    VL_SIG8(__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode, 2, 0);
    VL_SIG8(__Vcellinp__TLSPI__auto_control_xing_in_a_valid, 0, 0);
    VL_SIG8(__VinpClk__TOP____Vcellinp__TLSPI__reset, 0, 0);
    VL_SIG8(__Vclklast__TOP____Vcellinp__TLSPI__clock, 0, 0);
    VL_SIG8(__Vclklast__TOP____VinpClk__TOP____Vcellinp__TLSPI__reset, 0, 0);
    VL_SIG8(__Vchglast__TOP____Vcellinp__TLSPI__reset, 0, 0);
    VL_SIG(__Vcellinp__TLSPI__auto_control_xing_in_a_bits_data, 31, 0);
    VL_SIG(__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address, 28, 0);

    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VTLSPI__Syms *__VlSymsp; // Symbol table

    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code

    // CONSTRUCTORS
private:
    VL_UNCOPYABLE(VTLSPI); ///< Copying not allowed
public:
    SC_CTOR(VTLSPI);
    virtual ~VTLSPI();

    // API METHODS
private:
    void eval();

public:
    void final();

    // INTERNAL METHODS
private:
    static void _eval_initial_loop(VTLSPI__Syms * __restrict vlSymsp);

public:
    void __Vconfigure(VTLSPI__Syms * symsp, bool first);

private:
    static QData _change_request(VTLSPI__Syms * __restrict vlSymsp);

public:
    static void _combo__TOP__2(VTLSPI__Syms * __restrict vlSymsp);
    static void _combo__TOP__6(VTLSPI__Syms * __restrict vlSymsp);
    static void _combo__TOP__8(VTLSPI__Syms * __restrict vlSymsp);

private:
    void _ctor_var_reset();

public:
    static void _eval(VTLSPI__Syms * __restrict vlSymsp);

private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif // VL_DEBUG
public:
    static void _eval_initial(VTLSPI__Syms * __restrict vlSymsp);
    static void _eval_settle(VTLSPI__Syms * __restrict vlSymsp);
    static void _initial__TOP__1(VTLSPI__Syms * __restrict vlSymsp);
    static void _sequent__TOP__4(VTLSPI__Syms * __restrict vlSymsp);
    static void _sequent__TOP__5(VTLSPI__Syms * __restrict vlSymsp);
    static void _sequent__TOP__7(VTLSPI__Syms * __restrict vlSymsp);
    static void _settle__TOP__3(VTLSPI__Syms * __restrict vlSymsp);
}
VL_ATTR_ALIGNED(128);

#endif // guard
