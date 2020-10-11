// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTLSPI.h for the primary calling header

#include "VTLSPI.h" // For This
#include "VTLSPI__Syms.h"

//--------------------
// STATIC VARIABLES

//--------------------

VL_SC_CTOR_IMP(VTLSPI)
#if (SYSTEMC_VERSION > 20011000)
: clock("clock")
, reset("reset")
, auto_int_xing_out_sync_0("auto_int_xing_out_sync_0")
, auto_control_xing_in_a_ready("auto_control_xing_in_a_ready")
, auto_control_xing_in_a_valid("auto_control_xing_in_a_valid")
, auto_control_xing_in_a_bits_opcode("auto_control_xing_in_a_bits_opcode")
, auto_control_xing_in_a_bits_param("auto_control_xing_in_a_bits_param")
, auto_control_xing_in_a_bits_size("auto_control_xing_in_a_bits_size")
, auto_control_xing_in_a_bits_source("auto_control_xing_in_a_bits_source")
, auto_control_xing_in_a_bits_mask("auto_control_xing_in_a_bits_mask")
, auto_control_xing_in_a_bits_corrupt("auto_control_xing_in_a_bits_corrupt")
, auto_control_xing_in_d_ready("auto_control_xing_in_d_ready")
, auto_control_xing_in_d_valid("auto_control_xing_in_d_valid")
, auto_control_xing_in_d_bits_opcode("auto_control_xing_in_d_bits_opcode")
, auto_control_xing_in_d_bits_size("auto_control_xing_in_d_bits_size")
, auto_control_xing_in_d_bits_source("auto_control_xing_in_d_bits_source")
, auto_io_out_sck("auto_io_out_sck")
, auto_io_out_dq_0_i("auto_io_out_dq_0_i")
, auto_io_out_dq_0_o("auto_io_out_dq_0_o")
, auto_io_out_dq_0_oe("auto_io_out_dq_0_oe")
, auto_io_out_dq_1_i("auto_io_out_dq_1_i")
, auto_io_out_dq_1_o("auto_io_out_dq_1_o")
, auto_io_out_dq_1_oe("auto_io_out_dq_1_oe")
, auto_io_out_dq_2_i("auto_io_out_dq_2_i")
, auto_io_out_dq_3_i("auto_io_out_dq_3_i")
, auto_io_out_cs_0("auto_io_out_cs_0")
, auto_io_out_cs_2("auto_io_out_cs_2")
, auto_io_out_cs_3("auto_io_out_cs_3")
, auto_control_xing_in_a_bits_address("auto_control_xing_in_a_bits_address")
, auto_control_xing_in_a_bits_data("auto_control_xing_in_a_bits_data")
, auto_control_xing_in_d_bits_data("auto_control_xing_in_d_bits_data")
#endif
{
    VTLSPI__Syms *__restrict vlSymsp = __VlSymsp = new VTLSPI__Syms(this, name());
    VTLSPI *__restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Sensitivities on all clocks and combo inputs
    SC_METHOD(eval);
    sensitive << clock;
    sensitive << reset;
    sensitive << auto_control_xing_in_a_valid;
    sensitive << auto_control_xing_in_a_bits_opcode;
    sensitive << auto_control_xing_in_a_bits_param;
    sensitive << auto_control_xing_in_a_bits_size;
    sensitive << auto_control_xing_in_a_bits_source;
    sensitive << auto_control_xing_in_a_bits_address;
    sensitive << auto_control_xing_in_a_bits_mask;
    sensitive << auto_control_xing_in_a_bits_data;
    sensitive << auto_control_xing_in_a_bits_corrupt;
    sensitive << auto_control_xing_in_d_ready;
    sensitive << auto_io_out_dq_0_i;
    sensitive << auto_io_out_dq_1_i;
    sensitive << auto_io_out_dq_2_i;
    sensitive << auto_io_out_dq_3_i;

    // Reset internal values

    // Reset structure values
    _ctor_var_reset();
}

void VTLSPI::__Vconfigure(VTLSPI__Syms *vlSymsp, bool first) {
    if (false && first) {
    } // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VTLSPI::~VTLSPI() {
    delete __VlSymsp;
    __VlSymsp = nullptr;
}

//--------------------

void VTLSPI::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VTLSPI::eval\n"););
    VTLSPI__Syms *__restrict vlSymsp = this->__VlSymsp; // Setup global symbol table
    VTLSPI *__restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT(__FILE__, __LINE__, __FILE__, "Verilated model didn't converge");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VTLSPI::_eval_initial_loop(VTLSPI__Syms *__restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT(__FILE__, __LINE__, __FILE__, "Verilated model didn't DC converge");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

//--------------------
// Internal Methods

void VTLSPI::_initial__TOP__1(VTLSPI__Syms *__restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTLSPI::_initial__TOP__1\n"););
    VTLSPI *__restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIGW(__Vtemp1, 159, 0, 5);
    VL_SIGW(__Vtemp2, 159, 0, 5);
    // Body
    // INITIAL at ../git/freedom/rocket-chip/src/main/resources/vsrc/AsyncResetReg.v:57
    if (vlTOPp->__Vcellinp__TLSPI__reset) {
        vlTOPp->TLSPI__DOT__intsource__DOT__AsyncResetRegVec_w1_i0__DOT__reg_0_q = 0U;
    }
    // INITIAL at ../git/freedom/rocket-chip/src/main/resources/vsrc/plusarg_reader.v:17
    __Vtemp1[0U] = 0x743d2564U;
    __Vtemp1[1U] = 0x6d656f75U;
    __Vtemp1[2U] = 0x6b5f7469U;
    __Vtemp1[3U] = 0x656c696eU;
    __Vtemp1[4U] = 0x74696cU;
    if ((!VL_VALUEPLUSARGS_INI(32, VL_CVT_PACK_STR_NW(5, __Vtemp1),
                               vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT__plusarg_reader__DOT__myplus))) {
        vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT__plusarg_reader__DOT__myplus = 0U;
    }
    // INITIAL at ../git/freedom/rocket-chip/src/main/resources/vsrc/plusarg_reader.v:17
    __Vtemp2[0U] = 0x743d2564U;
    __Vtemp2[1U] = 0x6d656f75U;
    __Vtemp2[2U] = 0x6b5f7469U;
    __Vtemp2[3U] = 0x656c696eU;
    __Vtemp2[4U] = 0x74696cU;
    if ((!VL_VALUEPLUSARGS_INI(32, VL_CVT_PACK_STR_NW(5, __Vtemp2),
                               vlTOPp->TLSPI__DOT__TLMonitor__DOT__plusarg_reader__DOT__myplus))) {
        vlTOPp->TLSPI__DOT__TLMonitor__DOT__plusarg_reader__DOT__myplus = 0U;
    }
}

VL_INLINE_OPT void VTLSPI::_combo__TOP__2(VTLSPI__Syms *__restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTLSPI::_combo__TOP__2\n"););
    VTLSPI *__restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    VL_ASSIGN_ISI(1, vlTOPp->__Vcellinp__TLSPI__auto_io_out_dq_3_i, vlTOPp->auto_io_out_dq_3_i);
    VL_ASSIGN_ISI(1, vlTOPp->__Vcellinp__TLSPI__auto_io_out_dq_2_i, vlTOPp->auto_io_out_dq_2_i);
    VL_ASSIGN_ISI(1, vlTOPp->__Vcellinp__TLSPI__auto_io_out_dq_1_i, vlTOPp->auto_io_out_dq_1_i);
    VL_ASSIGN_ISI(1, vlTOPp->__Vcellinp__TLSPI__auto_io_out_dq_0_i, vlTOPp->auto_io_out_dq_0_i);
    VL_ASSIGN_ISI(1, vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_d_ready, vlTOPp->auto_control_xing_in_d_ready);
    VL_ASSIGN_ISI(1, vlTOPp->__Vcellinp__TLSPI__clock, vlTOPp->clock);
    vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__rxd = ((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_io_out_dq_3_i) << 3U) |
                                                    ((IData)(vlTOPp->__Vcellinp__TLSPI__auto_io_out_dq_2_i) << 2U)) |
                                                   (((IData)(vlTOPp->__Vcellinp__TLSPI__auto_io_out_dq_1_i) << 1U) |
                                                    (IData)(vlTOPp->__Vcellinp__TLSPI__auto_io_out_dq_0_i)));
    VL_ASSIGN_SII(1, vlTOPp->auto_control_xing_in_a_ready, vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_d_ready);
}

void VTLSPI::_settle__TOP__3(VTLSPI__Syms *__restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTLSPI::_settle__TOP__3\n"););
    VTLSPI *__restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    VL_ASSIGN_ISI(1, vlTOPp->__Vcellinp__TLSPI__auto_io_out_dq_3_i, vlTOPp->auto_io_out_dq_3_i);
    VL_ASSIGN_ISI(1, vlTOPp->__Vcellinp__TLSPI__auto_io_out_dq_2_i, vlTOPp->auto_io_out_dq_2_i);
    VL_ASSIGN_ISI(1, vlTOPp->__Vcellinp__TLSPI__auto_io_out_dq_1_i, vlTOPp->auto_io_out_dq_1_i);
    VL_ASSIGN_ISI(1, vlTOPp->__Vcellinp__TLSPI__auto_io_out_dq_0_i, vlTOPp->auto_io_out_dq_0_i);
    VL_ASSIGN_ISI(1, vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_d_ready, vlTOPp->auto_control_xing_in_d_ready);
    VL_ASSIGN_ISI(1, vlTOPp->__Vcellinp__TLSPI__clock, vlTOPp->clock);
    VL_ASSIGN_ISI(1, vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_corrupt,
                  vlTOPp->auto_control_xing_in_a_bits_corrupt);
    VL_ASSIGN_ISI(4, vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_mask,
                  vlTOPp->auto_control_xing_in_a_bits_mask);
    VL_ASSIGN_ISI(1, vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid, vlTOPp->auto_control_xing_in_a_valid);
    VL_ASSIGN_ISI(3, vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_param,
                  vlTOPp->auto_control_xing_in_a_bits_param);
    VL_ASSIGN_ISI(3, vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode,
                  vlTOPp->auto_control_xing_in_a_bits_opcode);
    VL_ASSIGN_ISI(6, vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_source,
                  vlTOPp->auto_control_xing_in_a_bits_source);
    VL_ASSIGN_ISI(2, vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_size,
                  vlTOPp->auto_control_xing_in_a_bits_size);
    VL_ASSIGN_SII(1, vlTOPp->auto_io_out_dq_1_o, (1U & ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__txd) >> 1U)));
    VL_ASSIGN_SII(1, vlTOPp->auto_io_out_dq_0_o, (1U & (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__txd)));
    VL_ASSIGN_SII(1, vlTOPp->auto_io_out_sck, vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__sck);
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_690 =
        ((IData)(1U) + vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_679);
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_690 = ((IData)(1U) + vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_679);
    vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_54 =
        (7U & ((IData)(1U) + (IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT__value_1)));
    vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT___T_54 =
        (7U & ((IData)(1U) + (IData)(vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT__value_1)));
    vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_111 =
        ((1U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__ctrl_fmt_proto)) &
         (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__ctrl_fmt_iodir));
    vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__txen_2 =
        ((2U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__ctrl_fmt_proto)) &
         (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__ctrl_fmt_iodir));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_499 =
        (1U & ((IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_496) - (IData)(1U)));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_500 =
        (1U & (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_496)));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_554 =
        (1U & ((IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_551) - (IData)(1U)));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_555 =
        (1U & (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_551)));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_618 =
        (1U & ((IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_615) - (IData)(1U)));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_619 =
        (1U & (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_615)));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_639 =
        (1U & ((IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_636) - (IData)(1U)));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_640 =
        (1U & (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_636)));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_499 =
        (1U & ((IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_496) - (IData)(1U)));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_500 = (1U & (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_496)));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_554 =
        (1U & ((IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_551) - (IData)(1U)));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_555 = (1U & (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_551)));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_618 =
        (1U & ((IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_615) - (IData)(1U)));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_619 = (1U & (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_615)));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_639 =
        (1U & ((IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_636) - (IData)(1U)));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_640 = (1U & (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_636)));
    vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_35___05FT_58_data =
        vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_35[vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT__value_1];
    VL_ASSIGN_SII(1, vlTOPp->auto_io_out_cs_3, vlTOPp->TLSPI__DOT__mac__DOT__cs_dflt_3);
    VL_ASSIGN_SII(1, vlTOPp->auto_io_out_cs_2, vlTOPp->TLSPI__DOT__mac__DOT__cs_dflt_2);
    VL_ASSIGN_SII(1, vlTOPp->auto_io_out_cs_0, vlTOPp->TLSPI__DOT__mac__DOT__cs_dflt_0);
    vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_52 =
        (7U & ((IData)(1U) + (IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT__value)));
    vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT___T_52 =
        (7U & ((IData)(1U) + (IData)(vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT__value)));
    vlTOPp->TLSPI__DOT__mac__DOT___T_97 = (0U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__state));
    vlTOPp->TLSPI__DOT__mac__DOT___T_99 = (1U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__state));
    vlTOPp->TLSPI__DOT__mac__DOT___T_102 = (2U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__state));
    vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_128 = ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__done) |
                                                      (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__last_d));
    vlTOPp->TLSPI__DOT__fifo__DOT__rxq_io_enq_valid =
        ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__done) & (IData)(vlTOPp->TLSPI__DOT__fifo__DOT__rxen));
    vlTOPp->TLSPI__DOT__fifo__DOT___T_57 =
        (0xfU &
         (((((0U == (IData)(vlTOPp->TLSPI__DOT__ctrl_fmt_proto)) ? (IData)(vlTOPp->TLSPI__DOT__ctrl_fmt_len) : 0U) |
            (7U &
             ((1U == (IData)(vlTOPp->TLSPI__DOT__ctrl_fmt_proto)) ? ((IData)(vlTOPp->TLSPI__DOT__ctrl_fmt_len) >> 1U)
                                                                  : 0U))) |
           (3U &
            ((2U == (IData)(vlTOPp->TLSPI__DOT__ctrl_fmt_proto)) ? ((IData)(vlTOPp->TLSPI__DOT__ctrl_fmt_len) >> 2U)
                                                                 : 0U))) +
          (((1U == (IData)(vlTOPp->TLSPI__DOT__ctrl_fmt_proto)) & (IData)(vlTOPp->TLSPI__DOT__ctrl_fmt_len)) |
           ((2U == (IData)(vlTOPp->TLSPI__DOT__ctrl_fmt_proto)) &
            (0U != (3U & (IData)(vlTOPp->TLSPI__DOT__ctrl_fmt_len)))))));
    vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__cinv = ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__ctrl_sck_pha) ^
                                                    (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__ctrl_sck_pol));
    vlTOPp->TLSPI__DOT__mac__DOT___T_88 =
        ((((IData)(vlTOPp->TLSPI__DOT__mac__DOT__cs_dflt_3) << 3U) |
          ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__cs_dflt_2) << 2U)) |
         (((IData)(vlTOPp->TLSPI__DOT__mac__DOT__cs_dflt_1) << 1U) | (IData)(vlTOPp->TLSPI__DOT__mac__DOT__cs_dflt_0)));
    vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT___T_40 = ((IData)(vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT__value) ==
                                                      (IData)(vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT__value_1));
    vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_40 = ((IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT__value) ==
                                                      (IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT__value_1));
    vlTOPp->TLSPI__DOT__mac__DOT___T_69 =
        (0xfU &
         (((((IData)(vlTOPp->TLSPI__DOT__ctrl_cs_dflt_3) << 3U) | ((IData)(vlTOPp->TLSPI__DOT__ctrl_cs_dflt_2) << 2U)) |
           (((IData)(vlTOPp->TLSPI__DOT__ctrl_cs_dflt_1) << 1U) | (IData)(vlTOPp->TLSPI__DOT__ctrl_cs_dflt_0))) ^
          ((3U != (IData)(vlTOPp->TLSPI__DOT__fifo__DOT__cs_mode)) << (IData)(vlTOPp->TLSPI__DOT__ctrl_cs_id))));
    vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_154 = (1U & (~(IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__cref)));
    vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__sched = ((0U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__scnt)) |
                                                     (0U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__tcnt)));
    vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_47 = ((0U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__tcnt))
                                                         ? (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__scnt)
                                                         : (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__tcnt));
    vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___GEN_15 = ((0U != (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__scnt)) &
                                                       ((0U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__tcnt)) &
                                                        ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__xfr) &
                                                         (~(IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__cref)))));
    vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__shift = ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__setup_d) |
                                                     ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__sample_d) &
                                                      (0U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__scnt))));
    vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_155 = ((0U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__tcnt)) &
                                                      (~(IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__cref)));
    VL_ASSIGN_ISI(1, vlTOPp->__Vcellinp__TLSPI__reset, vlTOPp->reset);
    VL_ASSIGN_ISI(32, vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_data,
                  vlTOPp->auto_control_xing_in_a_bits_data);
    VL_ASSIGN_ISI(29, vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address,
                  vlTOPp->auto_control_xing_in_a_bits_address);
    VL_ASSIGN_SII(1, vlTOPp->auto_int_xing_out_sync_0,
                  vlTOPp->TLSPI__DOT__intsource__DOT__AsyncResetRegVec_w1_i0__DOT__reg_0_q);
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_687 =
        ((((VL_ULL(0) == vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_604) |
           (0U == vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT__plusarg_reader__DOT__myplus)) |
          (vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_679 <
           vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT__plusarg_reader__DOT__myplus)) |
         (IData)(vlTOPp->__Vcellinp__TLSPI__reset));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_687 =
        ((((VL_ULL(0) == vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_604) |
           (0U == vlTOPp->TLSPI__DOT__TLMonitor__DOT__plusarg_reader__DOT__myplus)) |
          (vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_679 <
           vlTOPp->TLSPI__DOT__TLMonitor__DOT__plusarg_reader__DOT__myplus)) |
         (IData)(vlTOPp->__Vcellinp__TLSPI__reset));
    vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__rxd = ((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_io_out_dq_3_i) << 3U) |
                                                    ((IData)(vlTOPp->__Vcellinp__TLSPI__auto_io_out_dq_2_i) << 2U)) |
                                                   (((IData)(vlTOPp->__Vcellinp__TLSPI__auto_io_out_dq_1_i) << 1U) |
                                                    (IData)(vlTOPp->__Vcellinp__TLSPI__auto_io_out_dq_0_i)));
    VL_ASSIGN_SII(1, vlTOPp->auto_control_xing_in_a_ready, vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_d_ready);
    vlTOPp->TLSPI__DOT___T_626 =
        (((((8U & (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_mask)) ? 0xffU : 0U) << 0x18U) |
          (((4U & (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_mask)) ? 0xffU : 0U) << 0x10U)) |
         ((((2U & (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_mask)) ? 0xffU : 0U) << 8U) |
          ((1U & (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_mask)) ? 0xffU : 0U)));
    VL_ASSIGN_SII(1, vlTOPp->auto_control_xing_in_d_valid, vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid);
    vlTOPp->TLSPI__DOT___T_1495 = ((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                                   (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_d_ready));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_542 =
        ((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_d_ready) &
         (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_542 = ((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_d_ready) &
                                                  (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_486 =
        ((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_d_ready) &
         (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_486 = ((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_d_ready) &
                                                  (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_526 =
        (((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_param) ==
          (IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_511)) |
         (IData)(vlTOPp->__Vcellinp__TLSPI__reset));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_526 =
        (((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_param) ==
          (IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_511)) |
         (IData)(vlTOPp->__Vcellinp__TLSPI__reset));
    VL_ASSIGN_SII(3, vlTOPp->auto_control_xing_in_d_bits_opcode,
                  (4U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode)));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_522 =
        (((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode) ==
          (IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_509)) |
         (IData)(vlTOPp->__Vcellinp__TLSPI__reset));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_579 =
        (((4U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode)) ==
          (IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_564)) |
         (IData)(vlTOPp->__Vcellinp__TLSPI__reset));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_522 =
        (((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode) ==
          (IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_509)) |
         (IData)(vlTOPp->__Vcellinp__TLSPI__reset));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_579 =
        (((4U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode)) ==
          (IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_564)) |
         (IData)(vlTOPp->__Vcellinp__TLSPI__reset));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_534 =
        (((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_source) ==
          (IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_515)) |
         (IData)(vlTOPp->__Vcellinp__TLSPI__reset));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_658 =
        (1U & ((~(IData)((vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_604 >>
                          (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_source)))) |
               (IData)(vlTOPp->__Vcellinp__TLSPI__reset)));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_534 =
        (((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_source) ==
          (IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_515)) |
         (IData)(vlTOPp->__Vcellinp__TLSPI__reset));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_658 =
        (1U & ((~(IData)((vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_604 >>
                          (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_source)))) |
               (IData)(vlTOPp->__Vcellinp__TLSPI__reset)));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_530 =
        (((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_size) ==
          (IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_513)) |
         (IData)(vlTOPp->__Vcellinp__TLSPI__reset));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_530 =
        (((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_size) ==
          (IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_513)) |
         (IData)(vlTOPp->__Vcellinp__TLSPI__reset));
    vlTOPp->TLSPI__DOT___T_426 = (((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_source) << 2U) |
                                  (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_size));
    VL_ASSIGN_SII(1, vlTOPp->auto_io_out_dq_1_oe, ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_111) |
                                                   (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__txen_2)));
    VL_ASSIGN_SII(1, vlTOPp->auto_io_out_dq_0_oe,
                  ((0U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__ctrl_fmt_proto)) |
                   ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_111) |
                    (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__txen_2))));
    vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_71 =
        ((((0x80U & ((IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_35___05FT_58_data) << 7U)) |
           (0x40U & ((IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_35___05FT_58_data) << 5U))) |
          ((0x20U & ((IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_35___05FT_58_data) << 3U)) |
           (0x10U & ((IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_35___05FT_58_data) << 1U)))) |
         (((8U & ((IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_35___05FT_58_data) >> 1U)) |
           (4U & ((IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_35___05FT_58_data) >> 3U))) |
          ((2U & ((IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_35___05FT_58_data) >> 5U)) |
           (1U & ((IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_35___05FT_58_data) >> 7U)))));
    vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_148 =
        ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__cref) ^ (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__cinv));
    vlTOPp->TLSPI__DOT__mac__DOT___T_107 =
        (0xfU & ((IData)(vlTOPp->TLSPI__DOT__mac__DOT___T_88) ^
                 ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__cs_set) << (IData)(vlTOPp->TLSPI__DOT__mac__DOT__cs_id))));
    vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT___T_43 = ((IData)(vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT___T_40) &
                                                      (IData)(vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT___T_39));
    vlTOPp->TLSPI__DOT__fifo_io_ip_rxwm = (((((IData)(vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT___T_39) &
                                              (IData)(vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT___T_40))
                                             << 3U) |
                                            (7U & ((IData)(vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT__value) -
                                                   (IData)(vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT__value_1)))) >
                                           (IData)(vlTOPp->TLSPI__DOT__ctrl_wm_rx));
    vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT___T_42 = ((IData)(vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT___T_40) &
                                                      (~(IData)(vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT___T_39)));
    vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_42 = ((IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_40) &
                                                      (~(IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_39)));
    vlTOPp->TLSPI__DOT__fifo_io_ip_txwm = (((((IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_39) &
                                              (IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_40))
                                             << 3U) |
                                            (7U & ((IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT__value) -
                                                   (IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT__value_1)))) <
                                           (IData)(vlTOPp->TLSPI__DOT__ctrl_wm_tx));
    vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_43 = ((IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_40) &
                                                      (IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_39));
    vlTOPp->TLSPI__DOT__mac__DOT__cs_deassert =
        ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__clear) |
         ((IData)(vlTOPp->TLSPI__DOT__mac__DOT___T_69) != (IData)(vlTOPp->TLSPI__DOT__mac__DOT___T_88)));
    vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___GEN_16 =
        (0xfffU & ((0U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__scnt))
                       ? (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__scnt)
                       : ((0U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__tcnt))
                              ? ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__cref)
                                     ? (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__scnt)
                                     : ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_47) - (IData)(1U)))
                              : (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__scnt))));
    vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___GEN_22 =
        ((1U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__scnt))
             ? ((~(IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_155)) &
                (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___GEN_15))
             : (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___GEN_15));
    vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__accept =
        ((1U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__scnt))
             ? ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_155) |
                (0U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__scnt)))
             : (0U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__scnt)));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_97 =
        ((0U ==
          (3U & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address &
                 (~(0x1fU & ((IData)(3U) << (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_size))))))) |
         (IData)(vlTOPp->__Vcellinp__TLSPI__reset));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_167 =
        (((2U >= (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_size)) &
          (0U == (0x3ffff000U & (0x10024000U ^ vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address)))) |
         (IData)(vlTOPp->__Vcellinp__TLSPI__reset));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_538 =
        ((vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address ==
          vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_517) |
         (IData)(vlTOPp->__Vcellinp__TLSPI__reset));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_97 =
        ((0U ==
          (3U & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address &
                 (~(0x1fU & ((IData)(3U) << (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_size))))))) |
         (IData)(vlTOPp->__Vcellinp__TLSPI__reset));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_167 =
        (((2U >= (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_size)) &
          (0U == (0x3ffff000U & (0x10024000U ^ vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address)))) |
         (IData)(vlTOPp->__Vcellinp__TLSPI__reset));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_538 = ((vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address ==
                                                   vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_517) |
                                                  (IData)(vlTOPp->__Vcellinp__TLSPI__reset));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_52 =
        (1U &
         ((2U <= (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_size)) |
          (1U & ((((IData)(1U) << (1U & (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_size))) >> 1U) &
                 (~(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 1U))))));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_55 =
        (1U &
         ((2U <= (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_size)) |
          (1U & ((((IData)(1U) << (1U & (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_size))) >> 1U) &
                 (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 1U)))));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_52 =
        (1U &
         ((2U <= (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_size)) |
          (1U & ((((IData)(1U) << (1U & (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_size))) >> 1U) &
                 (~(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 1U))))));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_55 =
        (1U &
         ((2U <= (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_size)) |
          (1U & ((((IData)(1U) << (1U & (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_size))) >> 1U) &
                 (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 1U)))));
    vlTOPp->TLSPI__DOT___GEN_155 =
        ((0x10U == (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
             ? (0U == (0x3e0U & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
             : ((0x12U == (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
                    ? (0U == (0x3e0U & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
                    : ((0x13U == (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
                           ? (0U == (0x3e0U & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
                           : ((0x14U ==
                               (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
                                  ? (0U ==
                                     (0x3e0U & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
                                  : ((0x15U ==
                                      (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
                                         ? (0U ==
                                            (0x3e0U &
                                             (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
                                         : ((0x1cU ==
                                             (0x1fU &
                                              (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
                                                ? (0U ==
                                                   (0x3e0U &
                                                    (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >>
                                                     2U)))
                                                : ((0x1dU !=
                                                    (0x1fU &
                                                     (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >>
                                                      2U))) |
                                                   (0U ==
                                                    (0x3e0U &
                                                     (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >>
                                                      2U))))))))));
    vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_96 =
        ((((0U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__ctrl_fmt_proto))
               ? ((0xfeU & (((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__shift)
                                 ? (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__buffer)
                                 : ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__buffer) >> 1U))
                            << 1U)) |
                  (1U & ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__sample_d)
                             ? ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__rxd) >> 1U)
                             : (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__buffer))))
               : 0U) |
          ((1U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__ctrl_fmt_proto))
               ? ((0xfcU & (((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__shift)
                                 ? (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__buffer)
                                 : ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__buffer) >> 2U))
                            << 2U)) |
                  (3U & ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__sample_d)
                             ? (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__rxd)
                             : (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__buffer))))
               : 0U)) |
         ((2U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__ctrl_fmt_proto))
              ? ((0xf0U & (((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__shift)
                                ? (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__buffer)
                                : ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__buffer) >> 4U))
                           << 4U)) |
                 (0xfU & ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__sample_d)
                              ? (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__rxd)
                              : (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__buffer))))
              : 0U));
    vlTOPp->TLSPI__DOT___T_1732 = ((IData)(vlTOPp->TLSPI__DOT___T_1495) &
                                   (4U != (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode)));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_602 =
        ((IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_542) &
         (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_551)));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_602 =
        ((IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_542) & (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_551)));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_541 =
        ((IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_486) &
         (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_496)));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___GEN_15 =
        (((IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_486) &
          (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_615)))
             ? (VL_ULL(1) << (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_source))
             : VL_ULL(0));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_541 =
        ((IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_486) & (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_496)));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___GEN_15 =
        (((IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_486) & (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_615)))
             ? (VL_ULL(1) << (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_source))
             : VL_ULL(0));
    VL_ASSIGN_SII(6, vlTOPp->auto_control_xing_in_d_bits_source, (0x3fU & ((IData)(vlTOPp->TLSPI__DOT___T_426) >> 2U)));
    VL_ASSIGN_SII(2, vlTOPp->auto_control_xing_in_d_bits_size, (3U & (IData)(vlTOPp->TLSPI__DOT___T_426)));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_587 =
        (((3U & (IData)(vlTOPp->TLSPI__DOT___T_426)) ==
          (IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_568)) |
         (IData)(vlTOPp->__Vcellinp__TLSPI__reset));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_591 =
        (((0x3fU & ((IData)(vlTOPp->TLSPI__DOT___T_426) >> 2U)) ==
          (IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_570)) |
         (IData)(vlTOPp->__Vcellinp__TLSPI__reset));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_587 =
        (((3U & (IData)(vlTOPp->TLSPI__DOT___T_426)) == (IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_568)) |
         (IData)(vlTOPp->__Vcellinp__TLSPI__reset));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_591 = (((0x3fU & ((IData)(vlTOPp->TLSPI__DOT___T_426) >> 2U)) ==
                                                   (IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_570)) |
                                                  (IData)(vlTOPp->__Vcellinp__TLSPI__reset));
    vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___GEN_13 =
        ((0U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__scnt))
             ? (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__sck)
             : ((0U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__tcnt))
                    ? ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__xfr)
                           ? (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_148)
                           : (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__sck))
                    : (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__sck)));
    vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT___T_44 = ((~(IData)(vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT___T_43)) &
                                                      (IData)(vlTOPp->TLSPI__DOT__fifo__DOT__rxq_io_enq_valid));
    vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT___T_47 =
        ((((((IData)(vlTOPp->TLSPI__DOT___T_1495) &
             (4U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
            (((IData)(1U) << (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U))) >>
             0x13U)) &
           (0U == (0x3e0U & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))) &
          (0U != (0xffU & vlTOPp->TLSPI__DOT___T_626))) &
         (~(IData)(vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT___T_42)));
    vlTOPp->TLSPI__DOT___GEN_172 =
        ((6U == (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
             ? (IData)(vlTOPp->TLSPI__DOT__ctrl_cs_mode)
             : ((0xaU == (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
                    ? (((IData)(vlTOPp->TLSPI__DOT__ctrl_dla_sckcs) << 0x10U) |
                       (IData)(vlTOPp->TLSPI__DOT__ctrl_dla_cssck))
                    : ((0xbU == (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
                           ? (((IData)(vlTOPp->TLSPI__DOT__ctrl_dla_interxfr) << 0x10U) |
                              (IData)(vlTOPp->TLSPI__DOT__ctrl_dla_intercs))
                           : ((0x10U ==
                               (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
                                  ? (((IData)(vlTOPp->TLSPI__DOT__ctrl_fmt_len) << 0x10U) |
                                     (((IData)(vlTOPp->TLSPI__DOT__ctrl_fmt_iodir) << 3U) |
                                      (((IData)(vlTOPp->TLSPI__DOT__ctrl_fmt_endian) << 2U) |
                                       (IData)(vlTOPp->TLSPI__DOT__ctrl_fmt_proto))))
                                  : ((0x12U ==
                                      (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
                                         ? ((IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_43) << 0x1fU)
                                         : ((0x13U ==
                                             (0x1fU &
                                              (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
                                                ? (((IData)(vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT___T_42) << 0x1fU) |
                                                   vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT___T_35
                                                       [vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT__value_1])
                                                : ((0x14U ==
                                                    (0x1fU &
                                                     (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >>
                                                      2U)))
                                                       ? (IData)(vlTOPp->TLSPI__DOT__ctrl_wm_tx)
                                                       : ((0x15U ==
                                                           (0x1fU &
                                                            (vlTOPp
                                                                 ->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >>
                                                             2U)))
                                                              ? (IData)(vlTOPp->TLSPI__DOT__ctrl_wm_rx)
                                                              : ((0x1cU ==
                                                                  (0x1fU &
                                                                   (vlTOPp
                                                                        ->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >>
                                                                    2U)))
                                                                     ? (((IData)(vlTOPp->TLSPI__DOT__ie_rxwm) << 1U) |
                                                                        (IData)(vlTOPp->TLSPI__DOT__ie_txwm))
                                                                     : ((0x1dU ==
                                                                         (0x1fU &
                                                                          (vlTOPp
                                                                               ->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >>
                                                                           2U)))
                                                                            ? (((IData)(
                                                                                    vlTOPp->TLSPI__DOT__fifo_io_ip_rxwm)
                                                                                << 1U) |
                                                                               (IData)(
                                                                                   vlTOPp->TLSPI__DOT__fifo_io_ip_txwm))
                                                                            : 0U))))))))));
    vlTOPp->TLSPI__DOT__mac__DOT__phy_io_op_bits_cnt =
        ((0U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__state))
             ? ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__cs_assert)
                    ? ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__cs_deassert)
                           ? (IData)(vlTOPp->TLSPI__DOT__ctrl_dla_sckcs)
                           : (IData)(vlTOPp->TLSPI__DOT__fifo__DOT___T_57))
                    : ((IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_42)
                           ? 0U
                           : (IData)(vlTOPp->TLSPI__DOT__ctrl_dla_cssck)))
             : ((1U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__state))
                    ? (IData)(vlTOPp->TLSPI__DOT__ctrl_dla_interxfr)
                    : ((2U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__state))
                           ? (IData)(vlTOPp->TLSPI__DOT__ctrl_dla_intercs)
                           : (IData)(vlTOPp->TLSPI__DOT__fifo__DOT___T_57))));
    vlTOPp->TLSPI__DOT__mac__DOT__phy_io_op_bits_fn =
        (1U &
         ((0U != (IData)(vlTOPp->TLSPI__DOT__mac__DOT__state)) |
          ((~(IData)(vlTOPp->TLSPI__DOT__mac__DOT__cs_assert)) | (IData)(vlTOPp->TLSPI__DOT__mac__DOT__cs_deassert))));
    vlTOPp->TLSPI__DOT__mac__DOT__phy_io_op_bits_stb =
        (1U & ((0U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__state))
                   ? ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__cs_assert)
                          ? (~(IData)(vlTOPp->TLSPI__DOT__mac__DOT__cs_deassert))
                          : (IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_42))
                   : ((1U != (IData)(vlTOPp->TLSPI__DOT__mac__DOT__state)) &
                      (2U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__state)))));
    vlTOPp->TLSPI__DOT__mac__DOT__phy_io_op_valid =
        (1U & ((0U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__state))
                   ? ((~(IData)(vlTOPp->TLSPI__DOT__mac__DOT__cs_assert)) |
                      ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__cs_deassert) |
                       (~(IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_42))))
                   : ((1U != (IData)(vlTOPp->TLSPI__DOT__mac__DOT__state)) |
                      (0U != (IData)(vlTOPp->TLSPI__DOT__ctrl_dla_interxfr)))));
    vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_102 =
        ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__accept)
             ? (IData)(vlTOPp->TLSPI__DOT__ctrl_fmt_proto)
             : (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__ctrl_fmt_proto));
    vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__txd_in =
        (0xfU & ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__accept)
                     ? (((IData)(vlTOPp->TLSPI__DOT__ctrl_fmt_endian)
                             ? (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_71)
                             : (IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_35___05FT_58_data)) >>
                        4U)
                     : ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__buffer) >> 4U)));
    vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_156 = ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__accept) &
                                                      (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__done));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_73 =
        (((8U & (((IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_55) << 3U) |
                 (0xfffffff8U & ((vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address << 2U) &
                                 (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address << 3U))))) |
          (4U & (((IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_55) << 2U) |
                 (0xfffffffcU & ((vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address << 1U) &
                                 ((~vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address) << 2U)))))) |
         ((2U & (((IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_52) |
                  ((~(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 1U)) &
                   vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address))
                 << 1U)) |
          (1U & ((IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_52) |
                 ((~(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 1U)) &
                  (~vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address))))));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_73 =
        (((8U & (((IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_55) << 3U) |
                 (0xfffffff8U & ((vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address << 2U) &
                                 (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address << 3U))))) |
          (4U & (((IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_55) << 2U) |
                 (0xfffffffcU & ((vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address << 1U) &
                                 ((~vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address) << 2U)))))) |
         ((2U & (((IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_52) |
                  ((~(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 1U)) &
                   vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address))
                 << 1U)) |
          (1U & ((IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_52) |
                 ((~(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 1U)) &
                  (~vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address))))));
    vlTOPp->TLSPI__DOT___GEN_162 =
        ((0U == (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
             ? (0U == (0x3e0U & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
             : ((1U == (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
                    ? (0U == (0x3e0U & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
                    : ((4U == (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
                           ? (0U == (0x3e0U & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
                           : ((5U == (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
                                  ? (0U ==
                                     (0x3e0U & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
                                  : ((6U ==
                                      (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
                                         ? (0U ==
                                            (0x3e0U &
                                             (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
                                         : ((0xaU ==
                                             (0x1fU &
                                              (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
                                                ? (0U ==
                                                   (0x3e0U &
                                                    (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >>
                                                     2U)))
                                                : ((0xbU ==
                                                    (0x1fU &
                                                     (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >>
                                                      2U)))
                                                       ? (0U ==
                                                          (0x3e0U &
                                                           (vlTOPp
                                                                ->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >>
                                                            2U)))
                                                       : (IData)(vlTOPp->TLSPI__DOT___GEN_155))))))));
    vlTOPp->TLSPI__DOT___T_1766 =
        (((IData)(vlTOPp->TLSPI__DOT___T_1732) &
          (((IData)(1U) << (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U))) >> 5U)) &
         (0U == (0x3e0U & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U))));
    vlTOPp->TLSPI__DOT___T_1796 =
        (((IData)(vlTOPp->TLSPI__DOT___T_1732) &
          (((IData)(1U) << (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U))) >> 0xaU)) &
         (0U == (0x3e0U & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U))));
    vlTOPp->TLSPI__DOT___T_1742 =
        (((IData)(vlTOPp->TLSPI__DOT___T_1732) &
          (((IData)(1U) << (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U))) >> 1U)) &
         (0U == (0x3e0U & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U))));
    vlTOPp->TLSPI__DOT___T_1904 =
        (((IData)(vlTOPp->TLSPI__DOT___T_1732) &
          (((IData)(1U) << (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U))) >>
           0x1cU)) &
         (0U == (0x3e0U & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U))));
    vlTOPp->TLSPI__DOT___T_1832 =
        (((IData)(vlTOPp->TLSPI__DOT___T_1732) &
          (((IData)(1U) << (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U))) >>
           0x10U)) &
         (0U == (0x3e0U & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U))));
    vlTOPp->TLSPI__DOT___T_1802 =
        (((IData)(vlTOPp->TLSPI__DOT___T_1732) &
          (((IData)(1U) << (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U))) >> 0xbU)) &
         (0U == (0x3e0U & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U))));
    vlTOPp->TLSPI__DOT___T_1844 =
        (((IData)(vlTOPp->TLSPI__DOT___T_1732) &
          (((IData)(1U) << (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U))) >>
           0x12U)) &
         (0U == (0x3e0U & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U))));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_673 =
        (1U & ((IData)(((vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___GEN_15 |
                         vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_604) >>
                        (0x3fU & ((IData)(vlTOPp->TLSPI__DOT___T_426) >> 2U)))) |
               (IData)(vlTOPp->__Vcellinp__TLSPI__reset)));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_677 =
        ((vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_604 |
          vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___GEN_15) &
         (~(((IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_542) &
             (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_636)))
                ? (VL_ULL(1) << (0x3fU & ((IData)(vlTOPp->TLSPI__DOT___T_426) >> 2U)))
                : VL_ULL(0))));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_673 =
        (1U & ((IData)(((vlTOPp->TLSPI__DOT__TLMonitor__DOT___GEN_15 | vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_604) >>
                        (0x3fU & ((IData)(vlTOPp->TLSPI__DOT___T_426) >> 2U)))) |
               (IData)(vlTOPp->__Vcellinp__TLSPI__reset)));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_677 =
        ((vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_604 | vlTOPp->TLSPI__DOT__TLMonitor__DOT___GEN_15) &
         (~(((IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_542) &
             (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_636)))
                ? (VL_ULL(1) << (0x3fU & ((IData)(vlTOPp->TLSPI__DOT___T_426) >> 2U)))
                : VL_ULL(0))));
    vlTOPp->TLSPI__DOT__mac_io_link_tx_ready = ((0U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__state)) &
                                                ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__cs_assert) &
                                                 ((~(IData)(vlTOPp->TLSPI__DOT__mac__DOT__cs_deassert)) &
                                                  (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_156))));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_181 =
        (((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_mask) ==
          (IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_73)) |
         (IData)(vlTOPp->__Vcellinp__TLSPI__reset));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_245 =
        ((0U == ((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_mask) &
                 (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_73)))) |
         (IData)(vlTOPp->__Vcellinp__TLSPI__reset));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_181 =
        (((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_mask) ==
          (IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_73)) |
         (IData)(vlTOPp->__Vcellinp__TLSPI__reset));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_245 =
        ((0U == ((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_mask) &
                 (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_73)))) |
         (IData)(vlTOPp->__Vcellinp__TLSPI__reset));
    VL_ASSIGN_SII(
        32, vlTOPp->auto_control_xing_in_d_bits_data,
        ((IData)(vlTOPp->TLSPI__DOT___GEN_162)
             ? ((0U == (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
                    ? (IData)(vlTOPp->TLSPI__DOT__ctrl_sck_div)
                    : ((1U == (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
                           ? (((IData)(vlTOPp->TLSPI__DOT__ctrl_sck_pol) << 1U) |
                              (IData)(vlTOPp->TLSPI__DOT__ctrl_sck_pha))
                           : ((4U == (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
                                  ? (IData)(vlTOPp->TLSPI__DOT__ctrl_cs_id)
                                  : ((5U ==
                                      (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
                                         ? (((IData)(vlTOPp->TLSPI__DOT__ctrl_cs_dflt_3) << 3U) |
                                            (((IData)(vlTOPp->TLSPI__DOT__ctrl_cs_dflt_2) << 2U) |
                                             (((IData)(vlTOPp->TLSPI__DOT__ctrl_cs_dflt_1) << 1U) |
                                              (IData)(vlTOPp->TLSPI__DOT__ctrl_cs_dflt_0))))
                                         : vlTOPp->TLSPI__DOT___GEN_172))))
             : 0U));
    vlTOPp->TLSPI__DOT__fifo_io_tx_valid =
        (((IData)(vlTOPp->TLSPI__DOT___T_1844) & (0U == (0xffU & (~vlTOPp->TLSPI__DOT___T_626)))) &
         (~(((IData)(vlTOPp->TLSPI__DOT___T_1844) & (vlTOPp->TLSPI__DOT___T_626 >> 0x1fU)) &
            (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_data >> 0x1fU))));
    vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_47 = ((IData)(vlTOPp->TLSPI__DOT__mac_io_link_tx_ready) &
                                                      (~(IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_42)));
    vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_44 =
        ((~(IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_43)) & (IData)(vlTOPp->TLSPI__DOT__fifo_io_tx_valid));
    vlTOPp->TLSPI__DOT__mac__DOT___T_94 =
        ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__clear) |
         ((((IData)(vlTOPp->TLSPI__DOT__fifo__DOT__cs_mode) != (IData)(vlTOPp->TLSPI__DOT__ctrl_cs_mode)) |
           ((IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_47) &
            (~((2U == (IData)(vlTOPp->TLSPI__DOT__fifo__DOT__cs_mode)) |
               (3U == (IData)(vlTOPp->TLSPI__DOT__fifo__DOT__cs_mode)))))) &
          (IData)(vlTOPp->TLSPI__DOT__mac__DOT__cs_assert)));
}

VL_INLINE_OPT void VTLSPI::_sequent__TOP__4(VTLSPI__Syms *__restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTLSPI::_sequent__TOP__4\n"););
    VTLSPI *__restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdlyvdim0__TLSPI__DOT__fifo__DOT__txq__DOT___T_35__v0, 2, 0);
    VL_SIG8(__Vdlyvval__TLSPI__DOT__fifo__DOT__txq__DOT___T_35__v0, 7, 0);
    VL_SIG8(__Vdlyvset__TLSPI__DOT__fifo__DOT__txq__DOT___T_35__v0, 0, 0);
    VL_SIG8(__Vdlyvdim0__TLSPI__DOT__fifo__DOT__rxq__DOT___T_35__v0, 2, 0);
    VL_SIG8(__Vdlyvval__TLSPI__DOT__fifo__DOT__rxq__DOT___T_35__v0, 7, 0);
    VL_SIG8(__Vdlyvset__TLSPI__DOT__fifo__DOT__rxq__DOT___T_35__v0, 0, 0);
    VL_SIG8(__Vdly__TLSPI__DOT__mac__DOT__cs_assert, 0, 0);
    // Body
    __Vdlyvset__TLSPI__DOT__fifo__DOT__txq__DOT___T_35__v0 = 0U;
    __Vdlyvset__TLSPI__DOT__fifo__DOT__rxq__DOT___T_35__v0 = 0U;
    // ALWAYS at verilog/TLMonitor_60.v:510
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (6U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->__Vcellinp__TLSPI__reset))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel carries AcquireBlock type unsupported by manager "
                                "(connected at CrossingHelper.scala:17:44)\n    at Monitor.scala:41 assert "
                                "(edge.manager.supportsAcquireBSafe(edge.address(bundle), bundle.size), \"'A' channel "
                                "carries AcquireBlock type unsupported by manager\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (6U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->__Vcellinp__TLSPI__reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_60.v:630: Assertion failed in %NTLSPI.buffer.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_60.v", 630, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (6U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->__Vcellinp__TLSPI__reset))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel carries AcquireBlock from a client which does not "
                                "support Probe (connected at CrossingHelper.scala:17:44)\n    at Monitor.scala:42 "
                                "assert (edge.client.supportsProbe(edge.source(bundle), bundle.size), \"'A' channel "
                                "carries AcquireBlock from a client which does not support Probe\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (6U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->__Vcellinp__TLSPI__reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_60.v:652: Assertion failed in %NTLSPI.buffer.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_60.v", 652, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (6U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((2U <= (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_size)) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel AcquireBlock smaller than a beat (connected at "
                                "CrossingHelper.scala:17:44)\n    at Monitor.scala:44 assert (bundle.size >= "
                                "UInt(log2Ceil(edge.manager.beatBytes)), \"'A' channel AcquireBlock smaller than a "
                                "beat\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (6U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((2U <= (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_size)) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_60.v:696: Assertion failed in %NTLSPI.buffer.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_60.v", 696, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (6U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_97))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel AcquireBlock address not aligned to size (connected at "
                                "CrossingHelper.scala:17:44)\n    at Monitor.scala:45 assert (is_aligned, \"'A' "
                                "channel AcquireBlock address not aligned to size\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (6U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_97))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_60.v:718: Assertion failed in %NTLSPI.buffer.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_60.v", 718, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (6U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((2U >= (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_param)) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel AcquireBlock carries invalid grow param (connected at "
                                "CrossingHelper.scala:17:44)\n    at Monitor.scala:46 assert "
                                "(TLPermissions.isGrow(bundle.param), \"'A' channel AcquireBlock carries invalid grow "
                                "param\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (6U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((2U >= (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_param)) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_60.v:740: Assertion failed in %NTLSPI.buffer.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_60.v", 740, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (6U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((0U == (0xfU & (~(IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_mask)))) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel AcquireBlock contains invalid mask (connected at "
                                "CrossingHelper.scala:17:44)\n    at Monitor.scala:47 assert (~bundle.mask === "
                                "UInt(0), \"'A' channel AcquireBlock contains invalid mask\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (6U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((0U == (0xfU & (~(IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_mask)))) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_60.v:762: Assertion failed in %NTLSPI.buffer.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_60.v", 762, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (6U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((~(IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_corrupt)) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel AcquireBlock is corrupt (connected at "
                                "CrossingHelper.scala:17:44)\n    at Monitor.scala:48 assert (!bundle.corrupt, \"'A' "
                                "channel AcquireBlock is corrupt\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (6U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((~(IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_corrupt)) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_60.v:784: Assertion failed in %NTLSPI.buffer.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_60.v", 784, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (7U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->__Vcellinp__TLSPI__reset))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel carries AcquirePerm type unsupported by manager "
                                "(connected at CrossingHelper.scala:17:44)\n    at Monitor.scala:52 assert "
                                "(edge.manager.supportsAcquireBSafe(edge.address(bundle), bundle.size), \"'A' channel "
                                "carries AcquirePerm type unsupported by manager\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (7U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->__Vcellinp__TLSPI__reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_60.v:806: Assertion failed in %NTLSPI.buffer.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_60.v", 806, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (7U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->__Vcellinp__TLSPI__reset))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel carries AcquirePerm from a client which does not "
                                "support Probe (connected at CrossingHelper.scala:17:44)\n    at Monitor.scala:53 "
                                "assert (edge.client.supportsProbe(edge.source(bundle), bundle.size), \"'A' channel "
                                "carries AcquirePerm from a client which does not support Probe\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (7U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->__Vcellinp__TLSPI__reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_60.v:828: Assertion failed in %NTLSPI.buffer.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_60.v", 828, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (7U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((2U <= (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_size)) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel AcquirePerm smaller than a beat (connected at "
                                "CrossingHelper.scala:17:44)\n    at Monitor.scala:55 assert (bundle.size >= "
                                "UInt(log2Ceil(edge.manager.beatBytes)), \"'A' channel AcquirePerm smaller than a "
                                "beat\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (7U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((2U <= (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_size)) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_60.v:872: Assertion failed in %NTLSPI.buffer.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_60.v", 872, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (7U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_97))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel AcquirePerm address not aligned to size (connected at "
                                "CrossingHelper.scala:17:44)\n    at Monitor.scala:56 assert (is_aligned, \"'A' "
                                "channel AcquirePerm address not aligned to size\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (7U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_97))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_60.v:894: Assertion failed in %NTLSPI.buffer.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_60.v", 894, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (7U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((2U >= (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_param)) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel AcquirePerm carries invalid grow param (connected at "
                                "CrossingHelper.scala:17:44)\n    at Monitor.scala:57 assert "
                                "(TLPermissions.isGrow(bundle.param), \"'A' channel AcquirePerm carries invalid grow "
                                "param\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (7U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((2U >= (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_param)) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_60.v:916: Assertion failed in %NTLSPI.buffer.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_60.v", 916, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (7U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((0U != (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_param)) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel AcquirePerm requests NtoB (connected at "
                                "CrossingHelper.scala:17:44)\n    at Monitor.scala:58 assert (bundle.param =/= "
                                "TLPermissions.NtoB, \"'A' channel AcquirePerm requests NtoB\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (7U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((0U != (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_param)) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_60.v:938: Assertion failed in %NTLSPI.buffer.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_60.v", 938, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (7U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((0U == (0xfU & (~(IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_mask)))) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel AcquirePerm contains invalid mask (connected at "
                                "CrossingHelper.scala:17:44)\n    at Monitor.scala:59 assert (~bundle.mask === "
                                "UInt(0), \"'A' channel AcquirePerm contains invalid mask\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (7U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((0U == (0xfU & (~(IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_mask)))) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_60.v:960: Assertion failed in %NTLSPI.buffer.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_60.v", 960, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (7U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((~(IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_corrupt)) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel AcquirePerm is corrupt (connected at "
                                "CrossingHelper.scala:17:44)\n    at Monitor.scala:60 assert (!bundle.corrupt, \"'A' "
                                "channel AcquirePerm is corrupt\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (7U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((~(IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_corrupt)) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_60.v:982: Assertion failed in %NTLSPI.buffer.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_60.v", 982, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (4U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_167))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel carries Get type unsupported by manager (connected at "
                                "CrossingHelper.scala:17:44)\n    at Monitor.scala:64 assert "
                                "(edge.manager.supportsGetSafe(edge.address(bundle), bundle.size), \"'A' channel "
                                "carries Get type unsupported by manager\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (4U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_167))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_60.v:1004: Assertion failed in %NTLSPI.buffer.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_60.v", 1004, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (4U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_97))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel Get address not aligned to size (connected at "
                                "CrossingHelper.scala:17:44)\n    at Monitor.scala:66 assert (is_aligned, \"'A' "
                                "channel Get address not aligned to size\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (4U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_97))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_60.v:1048: Assertion failed in %NTLSPI.buffer.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_60.v", 1048, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (4U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((0U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_param)) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel Get carries invalid param (connected at "
                                "CrossingHelper.scala:17:44)\n    at Monitor.scala:67 assert (bundle.param === "
                                "UInt(0), \"'A' channel Get carries invalid param\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (4U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((0U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_param)) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_60.v:1070: Assertion failed in %NTLSPI.buffer.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_60.v", 1070, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (4U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_181))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel Get contains invalid mask (connected at "
                                "CrossingHelper.scala:17:44)\n    at Monitor.scala:68 assert (bundle.mask === mask, "
                                "\"'A' channel Get contains invalid mask\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (4U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_181))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_60.v:1092: Assertion failed in %NTLSPI.buffer.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_60.v", 1092, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (4U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((~(IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_corrupt)) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel Get is corrupt (connected at "
                                "CrossingHelper.scala:17:44)\n    at Monitor.scala:69 assert (!bundle.corrupt, \"'A' "
                                "channel Get is corrupt\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (4U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((~(IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_corrupt)) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_60.v:1114: Assertion failed in %NTLSPI.buffer.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_60.v", 1114, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (0U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_167))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel carries PutFull type unsupported by manager (connected "
                                "at CrossingHelper.scala:17:44)\n    at Monitor.scala:73 assert "
                                "(edge.manager.supportsPutFullSafe(edge.address(bundle), bundle.size), \"'A' channel "
                                "carries PutFull type unsupported by manager\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (0U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_167))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_60.v:1136: Assertion failed in %NTLSPI.buffer.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_60.v", 1136, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (0U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_97))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel PutFull address not aligned to size (connected at "
                                "CrossingHelper.scala:17:44)\n    at Monitor.scala:75 assert (is_aligned, \"'A' "
                                "channel PutFull address not aligned to size\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (0U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_97))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_60.v:1180: Assertion failed in %NTLSPI.buffer.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_60.v", 1180, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (0U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((0U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_param)) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel PutFull carries invalid param (connected at "
                                "CrossingHelper.scala:17:44)\n    at Monitor.scala:76 assert (bundle.param === "
                                "UInt(0), \"'A' channel PutFull carries invalid param\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (0U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((0U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_param)) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_60.v:1202: Assertion failed in %NTLSPI.buffer.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_60.v", 1202, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (0U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_181))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel PutFull contains invalid mask (connected at "
                                "CrossingHelper.scala:17:44)\n    at Monitor.scala:77 assert (bundle.mask === mask, "
                                "\"'A' channel PutFull contains invalid mask\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (0U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_181))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_60.v:1224: Assertion failed in %NTLSPI.buffer.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_60.v", 1224, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (1U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_167))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel carries PutPartial type unsupported by manager "
                                "(connected at CrossingHelper.scala:17:44)\n    at Monitor.scala:81 assert "
                                "(edge.manager.supportsPutPartialSafe(edge.address(bundle), bundle.size), \"'A' "
                                "channel carries PutPartial type unsupported by manager\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (1U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_167))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_60.v:1246: Assertion failed in %NTLSPI.buffer.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_60.v", 1246, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (1U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_97))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel PutPartial address not aligned to size (connected at "
                                "CrossingHelper.scala:17:44)\n    at Monitor.scala:83 assert (is_aligned, \"'A' "
                                "channel PutPartial address not aligned to size\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (1U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_97))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_60.v:1290: Assertion failed in %NTLSPI.buffer.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_60.v", 1290, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (1U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((0U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_param)) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel PutPartial carries invalid param (connected at "
                                "CrossingHelper.scala:17:44)\n    at Monitor.scala:84 assert (bundle.param === "
                                "UInt(0), \"'A' channel PutPartial carries invalid param\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (1U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((0U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_param)) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_60.v:1312: Assertion failed in %NTLSPI.buffer.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_60.v", 1312, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (1U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_245))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel PutPartial contains invalid mask (connected at "
                                "CrossingHelper.scala:17:44)\n    at Monitor.scala:85 assert ((bundle.mask & ~mask) "
                                "=== UInt(0), \"'A' channel PutPartial contains invalid mask\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (1U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_245))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_60.v:1334: Assertion failed in %NTLSPI.buffer.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_60.v", 1334, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (2U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->__Vcellinp__TLSPI__reset))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel carries Arithmetic type unsupported by manager "
                                "(connected at CrossingHelper.scala:17:44)\n    at Monitor.scala:89 assert "
                                "(edge.manager.supportsArithmeticSafe(edge.address(bundle), bundle.size), \"'A' "
                                "channel carries Arithmetic type unsupported by manager\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (2U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->__Vcellinp__TLSPI__reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_60.v:1356: Assertion failed in %NTLSPI.buffer.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_60.v", 1356, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (2U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_97))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel Arithmetic address not aligned to size (connected at "
                                "CrossingHelper.scala:17:44)\n    at Monitor.scala:91 assert (is_aligned, \"'A' "
                                "channel Arithmetic address not aligned to size\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (2U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_97))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_60.v:1400: Assertion failed in %NTLSPI.buffer.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_60.v", 1400, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (2U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((4U >= (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_param)) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel Arithmetic carries invalid opcode param (connected at "
                                "CrossingHelper.scala:17:44)\n    at Monitor.scala:92 assert "
                                "(TLAtomics.isArithmetic(bundle.param), \"'A' channel Arithmetic carries invalid "
                                "opcode param\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (2U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((4U >= (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_param)) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_60.v:1422: Assertion failed in %NTLSPI.buffer.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_60.v", 1422, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (2U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_181))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel Arithmetic contains invalid mask (connected at "
                                "CrossingHelper.scala:17:44)\n    at Monitor.scala:93 assert (bundle.mask === mask, "
                                "\"'A' channel Arithmetic contains invalid mask\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (2U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_181))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_60.v:1444: Assertion failed in %NTLSPI.buffer.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_60.v", 1444, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (3U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->__Vcellinp__TLSPI__reset))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel carries Logical type unsupported by manager (connected "
                                "at CrossingHelper.scala:17:44)\n    at Monitor.scala:97 assert "
                                "(edge.manager.supportsLogicalSafe(edge.address(bundle), bundle.size), \"'A' channel "
                                "carries Logical type unsupported by manager\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (3U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->__Vcellinp__TLSPI__reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_60.v:1466: Assertion failed in %NTLSPI.buffer.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_60.v", 1466, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (3U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_97))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel Logical address not aligned to size (connected at "
                                "CrossingHelper.scala:17:44)\n    at Monitor.scala:99 assert (is_aligned, \"'A' "
                                "channel Logical address not aligned to size\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (3U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_97))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_60.v:1510: Assertion failed in %NTLSPI.buffer.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_60.v", 1510, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (3U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((3U >= (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_param)) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel Logical carries invalid opcode param (connected at "
                                "CrossingHelper.scala:17:44)\n    at Monitor.scala:100 assert "
                                "(TLAtomics.isLogical(bundle.param), \"'A' channel Logical carries invalid opcode "
                                "param\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (3U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((3U >= (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_param)) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_60.v:1532: Assertion failed in %NTLSPI.buffer.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_60.v", 1532, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (3U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_181))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel Logical contains invalid mask (connected at "
                                "CrossingHelper.scala:17:44)\n    at Monitor.scala:101 assert (bundle.mask === mask, "
                                "\"'A' channel Logical contains invalid mask\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (3U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_181))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_60.v:1554: Assertion failed in %NTLSPI.buffer.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_60.v", 1554, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (5U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->__Vcellinp__TLSPI__reset))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel carries Hint type unsupported by manager (connected at "
                                "CrossingHelper.scala:17:44)\n    at Monitor.scala:105 assert "
                                "(edge.manager.supportsHintSafe(edge.address(bundle), bundle.size), \"'A' channel "
                                "carries Hint type unsupported by manager\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (5U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->__Vcellinp__TLSPI__reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_60.v:1576: Assertion failed in %NTLSPI.buffer.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_60.v", 1576, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (5U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_97))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel Hint address not aligned to size (connected at "
                                "CrossingHelper.scala:17:44)\n    at Monitor.scala:107 assert (is_aligned, \"'A' "
                                "channel Hint address not aligned to size\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (5U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_97))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_60.v:1620: Assertion failed in %NTLSPI.buffer.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_60.v", 1620, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (5U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_181))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel Hint contains invalid mask (connected at "
                                "CrossingHelper.scala:17:44)\n    at Monitor.scala:108 assert (bundle.mask === mask, "
                                "\"'A' channel Hint contains invalid mask\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (5U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_181))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_60.v:1642: Assertion failed in %NTLSPI.buffer.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_60.v", 1642, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (5U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((~(IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_corrupt)) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel Hint is corrupt (connected at "
                                "CrossingHelper.scala:17:44)\n    at Monitor.scala:109 assert (!bundle.corrupt, \"'A' "
                                "channel Hint is corrupt\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (5U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((~(IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_corrupt)) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_60.v:1664: Assertion failed in %NTLSPI.buffer.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_60.v", 1664, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_496)) &
                     (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_522))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel opcode changed within multibeat operation (connected at "
                                "CrossingHelper.scala:17:44)\n    at Monitor.scala:343 assert (a.bits.opcode === "
                                "opcode, \"'A' channel opcode changed within multibeat operation\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_496)) &
                     (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_522))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_60.v:2456: Assertion failed in %NTLSPI.buffer.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_60.v", 2456, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_496)) &
                     (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_526))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel param changed within multibeat operation (connected at "
                                "CrossingHelper.scala:17:44)\n    at Monitor.scala:344 assert (a.bits.param  === "
                                "param,  \"'A' channel param changed within multibeat operation\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_496)) &
                     (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_526))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_60.v:2478: Assertion failed in %NTLSPI.buffer.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_60.v", 2478, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_496)) &
                     (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_530))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel size changed within multibeat operation (connected at "
                                "CrossingHelper.scala:17:44)\n    at Monitor.scala:345 assert (a.bits.size   === size, "
                                "  \"'A' channel size changed within multibeat operation\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_496)) &
                     (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_530))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_60.v:2500: Assertion failed in %NTLSPI.buffer.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_60.v", 2500, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_496)) &
                     (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_534))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel source changed within multibeat operation (connected at "
                                "CrossingHelper.scala:17:44)\n    at Monitor.scala:346 assert (a.bits.source === "
                                "source, \"'A' channel source changed within multibeat operation\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_496)) &
                     (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_534))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_60.v:2522: Assertion failed in %NTLSPI.buffer.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_60.v", 2522, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_496)) &
                     (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_538))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel address changed with multibeat operation (connected at "
                                "CrossingHelper.scala:17:44)\n    at Monitor.scala:347 assert (a.bits.address=== "
                                "address,\"'A' channel address changed with multibeat operation\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_496)) &
                     (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_538))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_60.v:2544: Assertion failed in %NTLSPI.buffer.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_60.v", 2544, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_551)) &
                     (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_579))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'D' channel opcode changed within multibeat operation (connected at "
                                "CrossingHelper.scala:17:44)\n    at Monitor.scala:413 assert (d.bits.opcode === "
                                "opcode, \"'D' channel opcode changed within multibeat operation\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_551)) &
                     (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_579))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_60.v:2566: Assertion failed in %NTLSPI.buffer.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_60.v", 2566, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_551)) &
                     (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_587))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'D' channel size changed within multibeat operation (connected at "
                                "CrossingHelper.scala:17:44)\n    at Monitor.scala:415 assert (d.bits.size   === size, "
                                "  \"'D' channel size changed within multibeat operation\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_551)) &
                     (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_587))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_60.v:2610: Assertion failed in %NTLSPI.buffer.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_60.v", 2610, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_551)) &
                     (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_591))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'D' channel source changed within multibeat operation (connected at "
                                "CrossingHelper.scala:17:44)\n    at Monitor.scala:416 assert (d.bits.source === "
                                "source, \"'D' channel source changed within multibeat operation\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_551)) &
                     (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_591))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_60.v:2632: Assertion failed in %NTLSPI.buffer.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_60.v", 2632, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_486) &
                      (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_615))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_658))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel re-used a source ID (connected at "
                                "CrossingHelper.scala:17:44)\n    at Monitor.scala:448 "
                                "assert(!inflight(bundle.a.bits.source), \"'A' channel re-used a source ID\" + "
                                "extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_486) &
                      (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_615))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_658))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_60.v:2698: Assertion failed in %NTLSPI.buffer.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_60.v", 2698, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_542) &
                      (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_636))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_673))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'D' channel acknowledged for nothing inflight (connected at "
                                "CrossingHelper.scala:17:44)\n    at Monitor.scala:455 assert((a_set | "
                                "inflight)(bundle.d.bits.source), \"'D' channel acknowledged for nothing inflight\" + "
                                "extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_542) &
                      (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_636))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_673))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_60.v:2720: Assertion failed in %NTLSPI.buffer.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_60.v", 2720, "");
    }
    if (VL_UNLIKELY((1U & (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_687))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: TileLink timeout expired (connected at "
                                "CrossingHelper.scala:17:44)\n    at Monitor.scala:467 assert (!inflight.orR || limit "
                                "=== UInt(0) || watchdog < limit, \"TileLink timeout expired\" + extra)\n");
    }
    if (VL_UNLIKELY((1U & (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_687))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_60.v:2742: Assertion failed in %NTLSPI.buffer.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_60.v", 2742, "");
    }
    // ALWAYS at verilog/TLMonitor_61.v:510
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (6U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->__Vcellinp__TLSPI__reset))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel carries AcquireBlock type unsupported by manager "
                                "(connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:41 assert "
                                "(edge.manager.supportsAcquireBSafe(edge.address(bundle), bundle.size), \"'A' channel "
                                "carries AcquireBlock type unsupported by manager\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (6U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->__Vcellinp__TLSPI__reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_61.v:630: Assertion failed in %NTLSPI.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_61.v", 630, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (6U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->__Vcellinp__TLSPI__reset))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel carries AcquireBlock from a client which does not "
                                "support Probe (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:42 "
                                "assert (edge.client.supportsProbe(edge.source(bundle), bundle.size), \"'A' channel "
                                "carries AcquireBlock from a client which does not support Probe\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (6U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->__Vcellinp__TLSPI__reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_61.v:652: Assertion failed in %NTLSPI.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_61.v", 652, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (6U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((2U <= (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_size)) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel AcquireBlock smaller than a beat (connected at "
                                "CrossingHelper.scala:17:14)\n    at Monitor.scala:44 assert (bundle.size >= "
                                "UInt(log2Ceil(edge.manager.beatBytes)), \"'A' channel AcquireBlock smaller than a "
                                "beat\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (6U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((2U <= (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_size)) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_61.v:696: Assertion failed in %NTLSPI.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_61.v", 696, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (6U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_97))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel AcquireBlock address not aligned to size (connected at "
                                "CrossingHelper.scala:17:14)\n    at Monitor.scala:45 assert (is_aligned, \"'A' "
                                "channel AcquireBlock address not aligned to size\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (6U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_97))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_61.v:718: Assertion failed in %NTLSPI.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_61.v", 718, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (6U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((2U >= (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_param)) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel AcquireBlock carries invalid grow param (connected at "
                                "CrossingHelper.scala:17:14)\n    at Monitor.scala:46 assert "
                                "(TLPermissions.isGrow(bundle.param), \"'A' channel AcquireBlock carries invalid grow "
                                "param\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (6U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((2U >= (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_param)) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_61.v:740: Assertion failed in %NTLSPI.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_61.v", 740, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (6U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((0U == (0xfU & (~(IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_mask)))) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel AcquireBlock contains invalid mask (connected at "
                                "CrossingHelper.scala:17:14)\n    at Monitor.scala:47 assert (~bundle.mask === "
                                "UInt(0), \"'A' channel AcquireBlock contains invalid mask\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (6U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((0U == (0xfU & (~(IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_mask)))) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_61.v:762: Assertion failed in %NTLSPI.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_61.v", 762, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (6U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((~(IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_corrupt)) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel AcquireBlock is corrupt (connected at "
                                "CrossingHelper.scala:17:14)\n    at Monitor.scala:48 assert (!bundle.corrupt, \"'A' "
                                "channel AcquireBlock is corrupt\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (6U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((~(IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_corrupt)) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_61.v:784: Assertion failed in %NTLSPI.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_61.v", 784, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (7U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->__Vcellinp__TLSPI__reset))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel carries AcquirePerm type unsupported by manager "
                                "(connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:52 assert "
                                "(edge.manager.supportsAcquireBSafe(edge.address(bundle), bundle.size), \"'A' channel "
                                "carries AcquirePerm type unsupported by manager\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (7U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->__Vcellinp__TLSPI__reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_61.v:806: Assertion failed in %NTLSPI.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_61.v", 806, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (7U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->__Vcellinp__TLSPI__reset))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel carries AcquirePerm from a client which does not "
                                "support Probe (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:53 "
                                "assert (edge.client.supportsProbe(edge.source(bundle), bundle.size), \"'A' channel "
                                "carries AcquirePerm from a client which does not support Probe\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (7U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->__Vcellinp__TLSPI__reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_61.v:828: Assertion failed in %NTLSPI.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_61.v", 828, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (7U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((2U <= (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_size)) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel AcquirePerm smaller than a beat (connected at "
                                "CrossingHelper.scala:17:14)\n    at Monitor.scala:55 assert (bundle.size >= "
                                "UInt(log2Ceil(edge.manager.beatBytes)), \"'A' channel AcquirePerm smaller than a "
                                "beat\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (7U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((2U <= (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_size)) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_61.v:872: Assertion failed in %NTLSPI.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_61.v", 872, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (7U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_97))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel AcquirePerm address not aligned to size (connected at "
                                "CrossingHelper.scala:17:14)\n    at Monitor.scala:56 assert (is_aligned, \"'A' "
                                "channel AcquirePerm address not aligned to size\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (7U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_97))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_61.v:894: Assertion failed in %NTLSPI.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_61.v", 894, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (7U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((2U >= (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_param)) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel AcquirePerm carries invalid grow param (connected at "
                                "CrossingHelper.scala:17:14)\n    at Monitor.scala:57 assert "
                                "(TLPermissions.isGrow(bundle.param), \"'A' channel AcquirePerm carries invalid grow "
                                "param\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (7U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((2U >= (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_param)) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_61.v:916: Assertion failed in %NTLSPI.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_61.v", 916, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (7U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((0U != (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_param)) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel AcquirePerm requests NtoB (connected at "
                                "CrossingHelper.scala:17:14)\n    at Monitor.scala:58 assert (bundle.param =/= "
                                "TLPermissions.NtoB, \"'A' channel AcquirePerm requests NtoB\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (7U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((0U != (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_param)) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_61.v:938: Assertion failed in %NTLSPI.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_61.v", 938, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (7U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((0U == (0xfU & (~(IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_mask)))) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel AcquirePerm contains invalid mask (connected at "
                                "CrossingHelper.scala:17:14)\n    at Monitor.scala:59 assert (~bundle.mask === "
                                "UInt(0), \"'A' channel AcquirePerm contains invalid mask\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (7U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((0U == (0xfU & (~(IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_mask)))) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_61.v:960: Assertion failed in %NTLSPI.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_61.v", 960, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (7U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((~(IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_corrupt)) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel AcquirePerm is corrupt (connected at "
                                "CrossingHelper.scala:17:14)\n    at Monitor.scala:60 assert (!bundle.corrupt, \"'A' "
                                "channel AcquirePerm is corrupt\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (7U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((~(IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_corrupt)) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_61.v:982: Assertion failed in %NTLSPI.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_61.v", 982, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (4U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_167))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel carries Get type unsupported by manager (connected at "
                                "CrossingHelper.scala:17:14)\n    at Monitor.scala:64 assert "
                                "(edge.manager.supportsGetSafe(edge.address(bundle), bundle.size), \"'A' channel "
                                "carries Get type unsupported by manager\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (4U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_167))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_61.v:1004: Assertion failed in %NTLSPI.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_61.v", 1004, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (4U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_97))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel Get address not aligned to size (connected at "
                                "CrossingHelper.scala:17:14)\n    at Monitor.scala:66 assert (is_aligned, \"'A' "
                                "channel Get address not aligned to size\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (4U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_97))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_61.v:1048: Assertion failed in %NTLSPI.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_61.v", 1048, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (4U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((0U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_param)) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel Get carries invalid param (connected at "
                                "CrossingHelper.scala:17:14)\n    at Monitor.scala:67 assert (bundle.param === "
                                "UInt(0), \"'A' channel Get carries invalid param\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (4U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((0U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_param)) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_61.v:1070: Assertion failed in %NTLSPI.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_61.v", 1070, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (4U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_181))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel Get contains invalid mask (connected at "
                                "CrossingHelper.scala:17:14)\n    at Monitor.scala:68 assert (bundle.mask === mask, "
                                "\"'A' channel Get contains invalid mask\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (4U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_181))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_61.v:1092: Assertion failed in %NTLSPI.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_61.v", 1092, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (4U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((~(IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_corrupt)) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel Get is corrupt (connected at "
                                "CrossingHelper.scala:17:14)\n    at Monitor.scala:69 assert (!bundle.corrupt, \"'A' "
                                "channel Get is corrupt\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (4U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((~(IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_corrupt)) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_61.v:1114: Assertion failed in %NTLSPI.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_61.v", 1114, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (0U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_167))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel carries PutFull type unsupported by manager (connected "
                                "at CrossingHelper.scala:17:14)\n    at Monitor.scala:73 assert "
                                "(edge.manager.supportsPutFullSafe(edge.address(bundle), bundle.size), \"'A' channel "
                                "carries PutFull type unsupported by manager\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (0U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_167))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_61.v:1136: Assertion failed in %NTLSPI.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_61.v", 1136, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (0U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_97))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel PutFull address not aligned to size (connected at "
                                "CrossingHelper.scala:17:14)\n    at Monitor.scala:75 assert (is_aligned, \"'A' "
                                "channel PutFull address not aligned to size\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (0U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_97))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_61.v:1180: Assertion failed in %NTLSPI.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_61.v", 1180, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (0U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((0U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_param)) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel PutFull carries invalid param (connected at "
                                "CrossingHelper.scala:17:14)\n    at Monitor.scala:76 assert (bundle.param === "
                                "UInt(0), \"'A' channel PutFull carries invalid param\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (0U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((0U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_param)) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_61.v:1202: Assertion failed in %NTLSPI.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_61.v", 1202, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (0U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_181))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel PutFull contains invalid mask (connected at "
                                "CrossingHelper.scala:17:14)\n    at Monitor.scala:77 assert (bundle.mask === mask, "
                                "\"'A' channel PutFull contains invalid mask\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (0U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_181))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_61.v:1224: Assertion failed in %NTLSPI.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_61.v", 1224, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (1U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_167))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel carries PutPartial type unsupported by manager "
                                "(connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:81 assert "
                                "(edge.manager.supportsPutPartialSafe(edge.address(bundle), bundle.size), \"'A' "
                                "channel carries PutPartial type unsupported by manager\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (1U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_167))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_61.v:1246: Assertion failed in %NTLSPI.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_61.v", 1246, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (1U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_97))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel PutPartial address not aligned to size (connected at "
                                "CrossingHelper.scala:17:14)\n    at Monitor.scala:83 assert (is_aligned, \"'A' "
                                "channel PutPartial address not aligned to size\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (1U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_97))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_61.v:1290: Assertion failed in %NTLSPI.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_61.v", 1290, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (1U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((0U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_param)) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel PutPartial carries invalid param (connected at "
                                "CrossingHelper.scala:17:14)\n    at Monitor.scala:84 assert (bundle.param === "
                                "UInt(0), \"'A' channel PutPartial carries invalid param\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (1U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((0U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_param)) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_61.v:1312: Assertion failed in %NTLSPI.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_61.v", 1312, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (1U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_245))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel PutPartial contains invalid mask (connected at "
                                "CrossingHelper.scala:17:14)\n    at Monitor.scala:85 assert ((bundle.mask & ~mask) "
                                "=== UInt(0), \"'A' channel PutPartial contains invalid mask\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (1U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_245))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_61.v:1334: Assertion failed in %NTLSPI.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_61.v", 1334, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (2U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->__Vcellinp__TLSPI__reset))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel carries Arithmetic type unsupported by manager "
                                "(connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:89 assert "
                                "(edge.manager.supportsArithmeticSafe(edge.address(bundle), bundle.size), \"'A' "
                                "channel carries Arithmetic type unsupported by manager\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (2U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->__Vcellinp__TLSPI__reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_61.v:1356: Assertion failed in %NTLSPI.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_61.v", 1356, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (2U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_97))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel Arithmetic address not aligned to size (connected at "
                                "CrossingHelper.scala:17:14)\n    at Monitor.scala:91 assert (is_aligned, \"'A' "
                                "channel Arithmetic address not aligned to size\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (2U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_97))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_61.v:1400: Assertion failed in %NTLSPI.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_61.v", 1400, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (2U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((4U >= (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_param)) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel Arithmetic carries invalid opcode param (connected at "
                                "CrossingHelper.scala:17:14)\n    at Monitor.scala:92 assert "
                                "(TLAtomics.isArithmetic(bundle.param), \"'A' channel Arithmetic carries invalid "
                                "opcode param\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (2U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((4U >= (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_param)) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_61.v:1422: Assertion failed in %NTLSPI.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_61.v", 1422, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (2U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_181))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel Arithmetic contains invalid mask (connected at "
                                "CrossingHelper.scala:17:14)\n    at Monitor.scala:93 assert (bundle.mask === mask, "
                                "\"'A' channel Arithmetic contains invalid mask\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (2U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_181))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_61.v:1444: Assertion failed in %NTLSPI.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_61.v", 1444, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (3U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->__Vcellinp__TLSPI__reset))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel carries Logical type unsupported by manager (connected "
                                "at CrossingHelper.scala:17:14)\n    at Monitor.scala:97 assert "
                                "(edge.manager.supportsLogicalSafe(edge.address(bundle), bundle.size), \"'A' channel "
                                "carries Logical type unsupported by manager\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (3U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->__Vcellinp__TLSPI__reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_61.v:1466: Assertion failed in %NTLSPI.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_61.v", 1466, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (3U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_97))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel Logical address not aligned to size (connected at "
                                "CrossingHelper.scala:17:14)\n    at Monitor.scala:99 assert (is_aligned, \"'A' "
                                "channel Logical address not aligned to size\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (3U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_97))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_61.v:1510: Assertion failed in %NTLSPI.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_61.v", 1510, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (3U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((3U >= (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_param)) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel Logical carries invalid opcode param (connected at "
                                "CrossingHelper.scala:17:14)\n    at Monitor.scala:100 assert "
                                "(TLAtomics.isLogical(bundle.param), \"'A' channel Logical carries invalid opcode "
                                "param\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (3U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((3U >= (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_param)) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_61.v:1532: Assertion failed in %NTLSPI.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_61.v", 1532, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (3U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_181))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel Logical contains invalid mask (connected at "
                                "CrossingHelper.scala:17:14)\n    at Monitor.scala:101 assert (bundle.mask === mask, "
                                "\"'A' channel Logical contains invalid mask\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (3U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_181))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_61.v:1554: Assertion failed in %NTLSPI.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_61.v", 1554, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (5U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->__Vcellinp__TLSPI__reset))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel carries Hint type unsupported by manager (connected at "
                                "CrossingHelper.scala:17:14)\n    at Monitor.scala:105 assert "
                                "(edge.manager.supportsHintSafe(edge.address(bundle), bundle.size), \"'A' channel "
                                "carries Hint type unsupported by manager\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (5U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->__Vcellinp__TLSPI__reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_61.v:1576: Assertion failed in %NTLSPI.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_61.v", 1576, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (5U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_97))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel Hint address not aligned to size (connected at "
                                "CrossingHelper.scala:17:14)\n    at Monitor.scala:107 assert (is_aligned, \"'A' "
                                "channel Hint address not aligned to size\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (5U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_97))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_61.v:1620: Assertion failed in %NTLSPI.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_61.v", 1620, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (5U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_181))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel Hint contains invalid mask (connected at "
                                "CrossingHelper.scala:17:14)\n    at Monitor.scala:108 assert (bundle.mask === mask, "
                                "\"'A' channel Hint contains invalid mask\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (5U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_181))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_61.v:1642: Assertion failed in %NTLSPI.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_61.v", 1642, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (5U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((~(IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_corrupt)) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel Hint is corrupt (connected at "
                                "CrossingHelper.scala:17:14)\n    at Monitor.scala:109 assert (!bundle.corrupt, \"'A' "
                                "channel Hint is corrupt\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (5U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
                     (~((~(IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_corrupt)) |
                        (IData)(vlTOPp->__Vcellinp__TLSPI__reset)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_61.v:1664: Assertion failed in %NTLSPI.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_61.v", 1664, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_496)) &
                     (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_522))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel opcode changed within multibeat operation (connected at "
                                "CrossingHelper.scala:17:14)\n    at Monitor.scala:343 assert (a.bits.opcode === "
                                "opcode, \"'A' channel opcode changed within multibeat operation\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_496)) &
                     (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_522))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_61.v:2456: Assertion failed in %NTLSPI.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_61.v", 2456, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_496)) &
                     (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_526))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel param changed within multibeat operation (connected at "
                                "CrossingHelper.scala:17:14)\n    at Monitor.scala:344 assert (a.bits.param  === "
                                "param,  \"'A' channel param changed within multibeat operation\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_496)) &
                     (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_526))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_61.v:2478: Assertion failed in %NTLSPI.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_61.v", 2478, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_496)) &
                     (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_530))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel size changed within multibeat operation (connected at "
                                "CrossingHelper.scala:17:14)\n    at Monitor.scala:345 assert (a.bits.size   === size, "
                                "  \"'A' channel size changed within multibeat operation\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_496)) &
                     (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_530))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_61.v:2500: Assertion failed in %NTLSPI.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_61.v", 2500, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_496)) &
                     (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_534))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel source changed within multibeat operation (connected at "
                                "CrossingHelper.scala:17:14)\n    at Monitor.scala:346 assert (a.bits.source === "
                                "source, \"'A' channel source changed within multibeat operation\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_496)) &
                     (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_534))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_61.v:2522: Assertion failed in %NTLSPI.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_61.v", 2522, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_496)) &
                     (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_538))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel address changed with multibeat operation (connected at "
                                "CrossingHelper.scala:17:14)\n    at Monitor.scala:347 assert (a.bits.address=== "
                                "address,\"'A' channel address changed with multibeat operation\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_496)) &
                     (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_538))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_61.v:2544: Assertion failed in %NTLSPI.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_61.v", 2544, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_551)) &
                     (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_579))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'D' channel opcode changed within multibeat operation (connected at "
                                "CrossingHelper.scala:17:14)\n    at Monitor.scala:413 assert (d.bits.opcode === "
                                "opcode, \"'D' channel opcode changed within multibeat operation\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_551)) &
                     (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_579))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_61.v:2566: Assertion failed in %NTLSPI.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_61.v", 2566, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_551)) &
                     (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_587))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'D' channel size changed within multibeat operation (connected at "
                                "CrossingHelper.scala:17:14)\n    at Monitor.scala:415 assert (d.bits.size   === size, "
                                "  \"'D' channel size changed within multibeat operation\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_551)) &
                     (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_587))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_61.v:2610: Assertion failed in %NTLSPI.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_61.v", 2610, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_551)) &
                     (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_591))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'D' channel source changed within multibeat operation (connected at "
                                "CrossingHelper.scala:17:14)\n    at Monitor.scala:416 assert (d.bits.source === "
                                "source, \"'D' channel source changed within multibeat operation\" + extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                      (IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_551)) &
                     (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_591))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_61.v:2632: Assertion failed in %NTLSPI.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_61.v", 2632, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_486) &
                      (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_615))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_658))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'A' channel re-used a source ID (connected at "
                                "CrossingHelper.scala:17:14)\n    at Monitor.scala:448 "
                                "assert(!inflight(bundle.a.bits.source), \"'A' channel re-used a source ID\" + "
                                "extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_486) &
                      (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_615))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_658))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_61.v:2698: Assertion failed in %NTLSPI.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_61.v", 2698, "");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_542) &
                      (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_636))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_673))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: 'D' channel acknowledged for nothing inflight (connected at "
                                "CrossingHelper.scala:17:14)\n    at Monitor.scala:455 assert((a_set | "
                                "inflight)(bundle.d.bits.source), \"'D' channel acknowledged for nothing inflight\" + "
                                "extra)\n");
    }
    if (VL_UNLIKELY((((IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_542) &
                      (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_636))) &
                     (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_673))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_61.v:2720: Assertion failed in %NTLSPI.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_61.v", 2720, "");
    }
    if (VL_UNLIKELY((1U & (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_687))))) {
        VL_FWRITEF(0x80000002U, "Assertion failed: TileLink timeout expired (connected at "
                                "CrossingHelper.scala:17:14)\n    at Monitor.scala:467 assert (!inflight.orR || limit "
                                "=== UInt(0) || watchdog < limit, \"TileLink timeout expired\" + extra)\n");
    }
    if (VL_UNLIKELY((1U & (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_687))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_61.v:2742: Assertion failed in %NTLSPI.TLMonitor\n", 64, VL_TIME_Q(),
                  vlSymsp->name());
        VL_STOP_MT("verilog/TLMonitor_61.v", 2742, "");
    }
    __Vdly__TLSPI__DOT__mac__DOT__cs_assert = vlTOPp->TLSPI__DOT__mac__DOT__cs_assert;
    // ALWAYS at verilog/TLMonitor_60.v:510
    if (vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_541) {
        vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_511 =
            vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_param;
    }
    // ALWAYS at verilog/TLMonitor_61.v:510
    if (vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_541) {
        vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_511 = vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_param;
    }
    // ALWAYS at verilog/TLMonitor_60.v:510
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_604 =
        ((IData)(vlTOPp->__Vcellinp__TLSPI__reset) ? VL_ULL(0)
                                                   : vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_677);
    // ALWAYS at verilog/TLMonitor_61.v:510
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_604 =
        ((IData)(vlTOPp->__Vcellinp__TLSPI__reset) ? VL_ULL(0) : vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_677);
    // ALWAYS at verilog/TLMonitor_60.v:510
    if (vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_602) {
        vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_568 = (3U & (IData)(vlTOPp->TLSPI__DOT___T_426));
    }
    // ALWAYS at verilog/TLMonitor_60.v:510
    if (vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_602) {
        vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_570 = (0x3fU & ((IData)(vlTOPp->TLSPI__DOT___T_426) >> 2U));
    }
    // ALWAYS at verilog/TLMonitor_61.v:510
    if (vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_602) {
        vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_568 = (3U & (IData)(vlTOPp->TLSPI__DOT___T_426));
    }
    // ALWAYS at verilog/TLMonitor_61.v:510
    if (vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_602) {
        vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_570 = (0x3fU & ((IData)(vlTOPp->TLSPI__DOT___T_426) >> 2U));
    }
    // ALWAYS at verilog/TLMonitor_60.v:510
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_679 =
        ((IData)(vlTOPp->__Vcellinp__TLSPI__reset)
             ? 0U
             : (((IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_486) |
                 (IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_542))
                    ? 0U
                    : vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_690));
    // ALWAYS at verilog/TLMonitor_61.v:510
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_679 =
        ((IData)(vlTOPp->__Vcellinp__TLSPI__reset) ? 0U : (((IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_486) |
                                                            (IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_542))
                                                               ? 0U
                                                               : vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_690));
    // ALWAYS at verilog/SPIPhysical_1.v:429
    if (vlTOPp->__Vcellinp__TLSPI__reset) {
        vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__txd = 0U;
    } else {
        if ((1U & ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_156)
                       ? ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy_io_op_valid)
                              ? ((~(IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy_io_op_bits_fn)) |
                                 (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___GEN_22))
                              : (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___GEN_22))
                       : (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___GEN_22)))) {
            vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__txd =
                ((3U & (((0U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_102)) &
                         ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__txd_in) >> 3U)) |
                        ((1U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_102))
                             ? ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__txd_in) >> 2U)
                             : 0U))) |
                 ((2U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_102))
                      ? (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__txd_in)
                      : 0U));
        }
    }
    // ALWAYS at verilog/TLSPI.v:962
    if (vlTOPp->__Vcellinp__TLSPI__reset) {
        vlTOPp->TLSPI__DOT__ctrl_dla_cssck = 1U;
    } else {
        if (((IData)(vlTOPp->TLSPI__DOT___T_1796) & (0U == (0xffU & (~vlTOPp->TLSPI__DOT___T_626))))) {
            vlTOPp->TLSPI__DOT__ctrl_dla_cssck = (0xffU & vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_data);
        }
    }
    // ALWAYS at verilog/TLSPI.v:962
    if (vlTOPp->__Vcellinp__TLSPI__reset) {
        vlTOPp->TLSPI__DOT__ctrl_dla_sckcs = 1U;
    } else {
        if (((IData)(vlTOPp->TLSPI__DOT___T_1796) & (0U == (0xffU & (~(vlTOPp->TLSPI__DOT___T_626 >> 0x10U)))))) {
            vlTOPp->TLSPI__DOT__ctrl_dla_sckcs =
                (0xffU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_data >> 0x10U));
        }
    }
    // ALWAYS at verilog/TLSPI.v:962
    if (vlTOPp->__Vcellinp__TLSPI__reset) {
        vlTOPp->TLSPI__DOT__ctrl_dla_intercs = 1U;
    } else {
        if (((IData)(vlTOPp->TLSPI__DOT___T_1802) & (0U == (0xffU & (~vlTOPp->TLSPI__DOT___T_626))))) {
            vlTOPp->TLSPI__DOT__ctrl_dla_intercs =
                (0xffU & vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_data);
        }
    }
    // ALWAYS at verilog/TLMonitor_60.v:510
    if (vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_602) {
        vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_564 =
            (4U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode));
    }
    // ALWAYS at verilog/TLMonitor_61.v:510
    if (vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_602) {
        vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_564 =
            (4U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode));
    }
    // ALWAYS at verilog/TLMonitor_60.v:510
    if (vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_541) {
        vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_509 =
            vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode;
    }
    // ALWAYS at verilog/TLMonitor_61.v:510
    if (vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_541) {
        vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_509 = vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode;
    }
    // ALWAYS at verilog/TLSPI.v:962
    if (vlTOPp->__Vcellinp__TLSPI__reset) {
        vlTOPp->TLSPI__DOT__ctrl_fmt_len = 8U;
    } else {
        if (((IData)(vlTOPp->TLSPI__DOT___T_1832) & (0U == (0xfU & (~(vlTOPp->TLSPI__DOT___T_626 >> 0x10U)))))) {
            vlTOPp->TLSPI__DOT__ctrl_fmt_len =
                (0xfU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_data >> 0x10U));
        }
    }
    // ALWAYS at verilog/TLMonitor_60.v:510
    if (vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_541) {
        vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_515 =
            vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_source;
    }
    // ALWAYS at verilog/TLMonitor_61.v:510
    if (vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_541) {
        vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_515 = vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_source;
    }
    // ALWAYS at verilog/SPIPhysical_1.v:429
    if (vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_156) {
        if (vlTOPp->TLSPI__DOT__mac__DOT__phy_io_op_valid) {
            if (vlTOPp->TLSPI__DOT__mac__DOT__phy_io_op_bits_fn) {
                if (vlTOPp->TLSPI__DOT__mac__DOT__phy_io_op_bits_fn) {
                    if (vlTOPp->TLSPI__DOT__mac__DOT__phy_io_op_bits_stb) {
                        vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__ctrl_sck_pha = vlTOPp->TLSPI__DOT__ctrl_sck_pha;
                    }
                }
            }
        }
    }
    // ALWAYS at verilog/SPIPhysical_1.v:429
    if (vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_156) {
        if (vlTOPp->TLSPI__DOT__mac__DOT__phy_io_op_valid) {
            if (vlTOPp->TLSPI__DOT__mac__DOT__phy_io_op_bits_stb) {
                vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__ctrl_fmt_iodir = vlTOPp->TLSPI__DOT__ctrl_fmt_iodir;
            }
        }
    }
    // ALWAYS at verilog/Queue_11.v:110
    if (vlTOPp->__Vcellinp__TLSPI__reset) {
        vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT___T_39 = 0U;
    } else {
        if (((IData)(vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT___T_44) !=
             (IData)(vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT___T_47))) {
            vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT___T_39 = vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT___T_44;
        }
    }
    // ALWAYS at verilog/SPIPhysical_1.v:429
    if (vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_156) {
        if (vlTOPp->TLSPI__DOT__mac__DOT__phy_io_op_valid) {
            if (vlTOPp->TLSPI__DOT__mac__DOT__phy_io_op_bits_stb) {
                vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__ctrl_fmt_proto = vlTOPp->TLSPI__DOT__ctrl_fmt_proto;
            }
        }
    }
    // ALWAYS at verilog/TLMonitor_60.v:510
    if (vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_541) {
        vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_513 =
            vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_size;
    }
    // ALWAYS at verilog/TLMonitor_61.v:510
    if (vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_541) {
        vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_513 = vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_size;
    }
    // ALWAYS at verilog/Queue_11.v:110
    if (vlTOPp->__Vcellinp__TLSPI__reset) {
        vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_39 = 0U;
    } else {
        if (((IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_44) !=
             (IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_47))) {
            vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_39 = vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_44;
        }
    }
    // ALWAYS at verilog/SPIFIFO.v:195
    if (vlTOPp->__Vcellinp__TLSPI__reset) {
        vlTOPp->TLSPI__DOT__fifo__DOT__rxen = 0U;
    } else {
        if (vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_47) {
            vlTOPp->TLSPI__DOT__fifo__DOT__rxen = (1U & (~(IData)(vlTOPp->TLSPI__DOT__ctrl_fmt_iodir)));
        } else {
            if (vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__done) {
                vlTOPp->TLSPI__DOT__fifo__DOT__rxen = 0U;
            }
        }
    }
    // ALWAYS at verilog/TLMonitor_60.v:510
    if (vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_541) {
        vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_517 =
            vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address;
    }
    // ALWAYS at verilog/TLMonitor_61.v:510
    if (vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_541) {
        vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_517 = vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address;
    }
    // ALWAYS at verilog/TLSPI.v:962
    if (vlTOPp->__Vcellinp__TLSPI__reset) {
        vlTOPp->TLSPI__DOT__ctrl_wm_tx = 0U;
    } else {
        if (((((IData)(vlTOPp->TLSPI__DOT___T_1732) &
               (((IData)(1U) << (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U))) >>
                0x14U)) &
              (0U == (0x3e0U & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))) &
             (0U == (0xfU & (~vlTOPp->TLSPI__DOT___T_626))))) {
            vlTOPp->TLSPI__DOT__ctrl_wm_tx = (0xfU & vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_data);
        }
    }
    // ALWAYS at verilog/TLSPI.v:962
    if (vlTOPp->__Vcellinp__TLSPI__reset) {
        vlTOPp->TLSPI__DOT__ctrl_wm_rx = 0U;
    } else {
        if (((((IData)(vlTOPp->TLSPI__DOT___T_1732) &
               (((IData)(1U) << (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U))) >>
                0x15U)) &
              (0U == (0x3e0U & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))) &
             (0U == (0xfU & (~vlTOPp->TLSPI__DOT___T_626))))) {
            vlTOPp->TLSPI__DOT__ctrl_wm_rx = (0xfU & vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_data);
        }
    }
    // ALWAYS at verilog/Queue_11.v:110
    if (vlTOPp->__Vcellinp__TLSPI__reset) {
        vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT__value_1 = 0U;
    } else {
        if (vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT___T_47) {
            vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT__value_1 = vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT___T_54;
        }
    }
    // ALWAYS at verilog/Queue_11.v:110
    if (vlTOPp->__Vcellinp__TLSPI__reset) {
        vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT__value_1 = 0U;
    } else {
        if (vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_47) {
            vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT__value_1 = vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_54;
        }
    }
    // ALWAYS at verilog/Queue_11.v:110
    if (((~(IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_43)) & (IData)(vlTOPp->TLSPI__DOT__fifo_io_tx_valid))) {
        __Vdlyvval__TLSPI__DOT__fifo__DOT__txq__DOT___T_35__v0 =
            (0xffU & vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_data);
        __Vdlyvset__TLSPI__DOT__fifo__DOT__txq__DOT___T_35__v0 = 1U;
        __Vdlyvdim0__TLSPI__DOT__fifo__DOT__txq__DOT___T_35__v0 = vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT__value;
    }
    // ALWAYS at verilog/Queue_11.v:110
    if (((~(IData)(vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT___T_43)) &
         (IData)(vlTOPp->TLSPI__DOT__fifo__DOT__rxq_io_enq_valid))) {
        __Vdlyvval__TLSPI__DOT__fifo__DOT__rxq__DOT___T_35__v0 =
            ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__ctrl_fmt_endian)
                 ? ((((0x80U & ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__buffer) << 7U)) |
                      (0x40U & ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__buffer) << 5U))) |
                     ((0x20U & ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__buffer) << 3U)) |
                      (0x10U & ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__buffer) << 1U)))) |
                    (((8U & ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__buffer) >> 1U)) |
                      (4U & ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__buffer) >> 3U))) |
                     ((2U & ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__buffer) >> 5U)) |
                      (1U & ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__buffer) >> 7U)))))
                 : (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__buffer));
        __Vdlyvset__TLSPI__DOT__fifo__DOT__rxq__DOT___T_35__v0 = 1U;
        __Vdlyvdim0__TLSPI__DOT__fifo__DOT__rxq__DOT___T_35__v0 = vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT__value;
    }
    // ALWAYS at verilog/SPIPhysical_1.v:486
    if (vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_156) {
        if (vlTOPp->TLSPI__DOT__mac__DOT__phy_io_op_valid) {
            if (vlTOPp->TLSPI__DOT__mac__DOT__phy_io_op_bits_fn) {
                if (vlTOPp->TLSPI__DOT__mac__DOT__phy_io_op_bits_fn) {
                    if (vlTOPp->TLSPI__DOT__mac__DOT__phy_io_op_bits_stb) {
                        vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__sck = vlTOPp->TLSPI__DOT__ctrl_sck_pol;
                    } else {
                        if ((1U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__scnt))) {
                            if (vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_155) {
                                vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__sck =
                                    vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__ctrl_sck_pol;
                            } else {
                                if ((0U != (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__scnt))) {
                                    if ((0U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__tcnt))) {
                                        if (vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__xfr) {
                                            vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__sck =
                                                vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_148;
                                        }
                                    }
                                }
                            }
                        } else {
                            if ((0U != (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__scnt))) {
                                if ((0U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__tcnt))) {
                                    if (vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__xfr) {
                                        vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__sck =
                                            vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_148;
                                    }
                                }
                            }
                        }
                    }
                } else {
                    if ((1U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__scnt))) {
                        if (vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_155) {
                            vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__sck =
                                vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__ctrl_sck_pol;
                        } else {
                            if ((0U != (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__scnt))) {
                                if ((0U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__tcnt))) {
                                    if (vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__xfr) {
                                        vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__sck =
                                            vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_148;
                                    }
                                }
                            }
                        }
                    } else {
                        if ((0U != (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__scnt))) {
                            if ((0U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__tcnt))) {
                                if (vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__xfr) {
                                    vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__sck =
                                        vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_148;
                                }
                            }
                        }
                    }
                }
            } else {
                vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__sck = vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__cinv;
            }
        } else {
            vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__sck =
                ((1U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__scnt))
                     ? ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_155)
                            ? (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__ctrl_sck_pol)
                            : (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___GEN_13))
                     : (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___GEN_13));
        }
    } else {
        vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__sck =
            ((1U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__scnt))
                 ? ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_155)
                        ? (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__ctrl_sck_pol)
                        : (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___GEN_13))
                 : (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___GEN_13));
    }
    // ALWAYS at verilog/SPIPhysical_1.v:429
    vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__last_d =
        ((~(IData)(vlTOPp->__Vcellinp__TLSPI__reset)) & (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_45));
    // ALWAYS at verilog/SPIPhysical_1.v:429
    vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__sample_d =
        ((~(IData)(vlTOPp->__Vcellinp__TLSPI__reset)) & (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_43));
    // ALWAYS at verilog/SPIPhysical_1.v:486
    vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__setup_d =
        (1U & ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_156)
                   ? ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy_io_op_valid)
                          ? ((~(IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy_io_op_bits_fn)) |
                             ((1U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__scnt))
                                  ? ((~(IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_155)) &
                                     ((0U != (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__scnt)) &
                                      ((0U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__tcnt)) &
                                       ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__xfr) &
                                        (~(IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__cref))))))
                                  : ((0U != (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__scnt)) &
                                     ((0U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__tcnt)) &
                                      ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__xfr) &
                                       (~(IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__cref)))))))
                          : ((1U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__scnt))
                                 ? ((~(IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_155)) &
                                    ((0U != (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__scnt)) &
                                     ((0U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__tcnt)) &
                                      ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__xfr) &
                                       (~(IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__cref))))))
                                 : ((0U != (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__scnt)) &
                                    ((0U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__tcnt)) &
                                     ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__xfr) &
                                      (~(IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__cref)))))))
                   : ((1U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__scnt))
                          ? ((~(IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_155)) &
                             (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___GEN_15))
                          : (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___GEN_15))));
    // ALWAYS at verilog/SPIMedia_1.v:303
    vlTOPp->TLSPI__DOT__mac__DOT__clear = ((~(IData)(vlTOPp->__Vcellinp__TLSPI__reset)) &
                                           ((0U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__state))
                                                ? (IData)(vlTOPp->TLSPI__DOT__mac__DOT___T_94)
                                                : ((1U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__state))
                                                       ? (IData)(vlTOPp->TLSPI__DOT__mac__DOT___T_94)
                                                       : ((2U != (IData)(vlTOPp->TLSPI__DOT__mac__DOT__state)) &
                                                          (IData)(vlTOPp->TLSPI__DOT__mac__DOT___T_94)))));
    // ALWAYSPOST at verilog/Queue_11.v:111
    if (__Vdlyvset__TLSPI__DOT__fifo__DOT__txq__DOT___T_35__v0) {
        vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_35[__Vdlyvdim0__TLSPI__DOT__fifo__DOT__txq__DOT___T_35__v0] =
            __Vdlyvval__TLSPI__DOT__fifo__DOT__txq__DOT___T_35__v0;
    }
    // ALWAYSPOST at verilog/Queue_11.v:111
    if (__Vdlyvset__TLSPI__DOT__fifo__DOT__rxq__DOT___T_35__v0) {
        vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT___T_35[__Vdlyvdim0__TLSPI__DOT__fifo__DOT__rxq__DOT___T_35__v0] =
            __Vdlyvval__TLSPI__DOT__fifo__DOT__rxq__DOT___T_35__v0;
    }
    // ALWAYS at verilog/TLMonitor_60.v:510
    if (vlTOPp->__Vcellinp__TLSPI__reset) {
        vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_551 = 0U;
    } else {
        if (vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_542) {
            vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_551 =
                ((~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_555)) &
                 (IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_554));
        }
    }
    // ALWAYS at verilog/TLMonitor_60.v:510
    if (vlTOPp->__Vcellinp__TLSPI__reset) {
        vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_636 = 0U;
    } else {
        if (vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_542) {
            vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_636 =
                ((~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_640)) &
                 (IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_639));
        }
    }
    // ALWAYS at verilog/TLMonitor_60.v:510
    if (vlTOPp->__Vcellinp__TLSPI__reset) {
        vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_496 = 0U;
    } else {
        if (vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_486) {
            vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_496 =
                ((~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_500)) &
                 (IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_499));
        }
    }
    // ALWAYS at verilog/TLMonitor_60.v:510
    if (vlTOPp->__Vcellinp__TLSPI__reset) {
        vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_615 = 0U;
    } else {
        if (vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_486) {
            vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_615 =
                ((~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_619)) &
                 (IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_618));
        }
    }
    // ALWAYS at verilog/TLMonitor_61.v:510
    if (vlTOPp->__Vcellinp__TLSPI__reset) {
        vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_551 = 0U;
    } else {
        if (vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_542) {
            vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_551 = ((~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_555)) &
                                                          (IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_554));
        }
    }
    // ALWAYS at verilog/TLMonitor_61.v:510
    if (vlTOPp->__Vcellinp__TLSPI__reset) {
        vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_636 = 0U;
    } else {
        if (vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_542) {
            vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_636 = ((~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_640)) &
                                                          (IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_639));
        }
    }
    // ALWAYS at verilog/TLMonitor_61.v:510
    if (vlTOPp->__Vcellinp__TLSPI__reset) {
        vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_496 = 0U;
    } else {
        if (vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_486) {
            vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_496 = ((~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_500)) &
                                                          (IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_499));
        }
    }
    // ALWAYS at verilog/TLMonitor_61.v:510
    if (vlTOPp->__Vcellinp__TLSPI__reset) {
        vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_615 = 0U;
    } else {
        if (vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_486) {
            vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_615 = ((~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_619)) &
                                                          (IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_618));
        }
    }
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_690 =
        ((IData)(1U) + vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_679);
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_690 = ((IData)(1U) + vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_679);
    VL_ASSIGN_SII(1, vlTOPp->auto_io_out_dq_1_o, (1U & ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__txd) >> 1U)));
    VL_ASSIGN_SII(1, vlTOPp->auto_io_out_dq_0_o, (1U & (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__txd)));
    // ALWAYS at verilog/TLSPI.v:962
    if (vlTOPp->__Vcellinp__TLSPI__reset) {
        vlTOPp->TLSPI__DOT__ctrl_sck_pha = 0U;
    } else {
        if (((IData)(vlTOPp->TLSPI__DOT___T_1742) & vlTOPp->TLSPI__DOT___T_626)) {
            vlTOPp->TLSPI__DOT__ctrl_sck_pha = (1U & vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_data);
        }
    }
    vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_111 =
        ((1U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__ctrl_fmt_proto)) &
         (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__ctrl_fmt_iodir));
    vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__txen_2 =
        ((2U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__ctrl_fmt_proto)) &
         (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__ctrl_fmt_iodir));
    // ALWAYS at verilog/TLSPI.v:962
    if (vlTOPp->__Vcellinp__TLSPI__reset) {
        vlTOPp->TLSPI__DOT__ctrl_fmt_proto = 0U;
    } else {
        if (((IData)(vlTOPp->TLSPI__DOT___T_1832) & (0U == (3U & (~vlTOPp->TLSPI__DOT___T_626))))) {
            vlTOPp->TLSPI__DOT__ctrl_fmt_proto = (3U & vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_data);
        }
    }
    // ALWAYS at verilog/TLSPI.v:962
    if (vlTOPp->__Vcellinp__TLSPI__reset) {
        vlTOPp->TLSPI__DOT__ctrl_fmt_iodir = 0U;
    } else {
        if (((IData)(vlTOPp->TLSPI__DOT___T_1832) & (vlTOPp->TLSPI__DOT___T_626 >> 3U))) {
            vlTOPp->TLSPI__DOT__ctrl_fmt_iodir =
                (1U & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_data >> 3U));
        }
    }
    // ALWAYS at verilog/SPIPhysical_1.v:429
    vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__done =
        ((IData)(vlTOPp->__Vcellinp__TLSPI__reset) |
         ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_156)
              ? ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy_io_op_valid)
                     ? ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy_io_op_bits_fn)
                            ? (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_128)
                            : (0U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy_io_op_bits_cnt)))
                     : (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_128))
              : (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_128)));
    vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT___T_54 =
        (7U & ((IData)(1U) + (IData)(vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT__value_1)));
    vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_54 =
        (7U & ((IData)(1U) + (IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT__value_1)));
    // ALWAYS at verilog/Queue_11.v:110
    if (vlTOPp->__Vcellinp__TLSPI__reset) {
        vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT__value = 0U;
    } else {
        if (vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_44) {
            vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT__value = vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_52;
        }
    }
    // ALWAYS at verilog/SPIPhysical_1.v:429
    if (vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_156) {
        if (vlTOPp->TLSPI__DOT__mac__DOT__phy_io_op_valid) {
            if (vlTOPp->TLSPI__DOT__mac__DOT__phy_io_op_bits_stb) {
                vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__ctrl_fmt_endian = vlTOPp->TLSPI__DOT__ctrl_fmt_endian;
            }
        }
    }
    // ALWAYS at verilog/SPIPhysical_1.v:429
    vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__buffer =
        ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_156)
             ? ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy_io_op_valid)
                    ? ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy_io_op_bits_fn)
                           ? (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_96)
                           : ((IData)(vlTOPp->TLSPI__DOT__ctrl_fmt_endian)
                                  ? (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_71)
                                  : (IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_35___05FT_58_data)))
                    : (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_96))
             : (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_96));
    // ALWAYS at verilog/Queue_11.v:110
    if (vlTOPp->__Vcellinp__TLSPI__reset) {
        vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT__value = 0U;
    } else {
        if (vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT___T_44) {
            vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT__value = vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT___T_52;
        }
    }
    VL_ASSIGN_SII(1, vlTOPp->auto_io_out_sck, vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__sck);
    // ALWAYS at verilog/SPIPhysical_1.v:429
    if (vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_156) {
        if (vlTOPp->TLSPI__DOT__mac__DOT__phy_io_op_valid) {
            if (vlTOPp->TLSPI__DOT__mac__DOT__phy_io_op_bits_fn) {
                if (vlTOPp->TLSPI__DOT__mac__DOT__phy_io_op_bits_fn) {
                    if (vlTOPp->TLSPI__DOT__mac__DOT__phy_io_op_bits_stb) {
                        vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__ctrl_sck_pol = vlTOPp->TLSPI__DOT__ctrl_sck_pol;
                    }
                }
            }
        }
    }
    // ALWAYS at verilog/SPIPhysical_1.v:429
    vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_45 =
        ((~(IData)(vlTOPp->__Vcellinp__TLSPI__reset)) & (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_44));
    // ALWAYS at verilog/SPIPhysical_1.v:429
    vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_43 =
        ((~(IData)(vlTOPp->__Vcellinp__TLSPI__reset)) & (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_42));
    // ALWAYS at verilog/SPIMedia_1.v:303
    if (vlTOPp->TLSPI__DOT__mac__DOT___T_97) {
        if ((1U & (~(IData)(vlTOPp->TLSPI__DOT__mac__DOT__cs_assert)))) {
            if (vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_42) {
                vlTOPp->TLSPI__DOT__mac__DOT__cs_id = vlTOPp->TLSPI__DOT__ctrl_cs_id;
            }
        }
    }
    if (vlTOPp->TLSPI__DOT__mac__DOT___T_97) {
        if ((1U & (~(IData)(vlTOPp->TLSPI__DOT__mac__DOT__cs_assert)))) {
            if (vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_42) {
                vlTOPp->TLSPI__DOT__mac__DOT__cs_dflt_0 = vlTOPp->TLSPI__DOT__ctrl_cs_dflt_0;
            } else {
                if (vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_156) {
                    vlTOPp->TLSPI__DOT__mac__DOT__cs_dflt_0 = (1U & (IData)(vlTOPp->TLSPI__DOT__mac__DOT___T_69));
                }
            }
        }
    } else {
        if ((1U & (~(IData)(vlTOPp->TLSPI__DOT__mac__DOT___T_99)))) {
            if (vlTOPp->TLSPI__DOT__mac__DOT___T_102) {
                if (vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_156) {
                    vlTOPp->TLSPI__DOT__mac__DOT__cs_dflt_0 = (1U & (IData)(vlTOPp->TLSPI__DOT__mac__DOT___T_107));
                }
            }
        }
    }
    if (vlTOPp->TLSPI__DOT__mac__DOT___T_97) {
        if ((1U & (~(IData)(vlTOPp->TLSPI__DOT__mac__DOT__cs_assert)))) {
            if (vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_42) {
                vlTOPp->TLSPI__DOT__mac__DOT__cs_dflt_1 = vlTOPp->TLSPI__DOT__ctrl_cs_dflt_1;
            } else {
                if (vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_156) {
                    vlTOPp->TLSPI__DOT__mac__DOT__cs_dflt_1 =
                        (1U & ((IData)(vlTOPp->TLSPI__DOT__mac__DOT___T_69) >> 1U));
                }
            }
        }
    } else {
        if ((1U & (~(IData)(vlTOPp->TLSPI__DOT__mac__DOT___T_99)))) {
            if (vlTOPp->TLSPI__DOT__mac__DOT___T_102) {
                if (vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_156) {
                    vlTOPp->TLSPI__DOT__mac__DOT__cs_dflt_1 =
                        (1U & ((IData)(vlTOPp->TLSPI__DOT__mac__DOT___T_107) >> 1U));
                }
            }
        }
    }
    if (vlTOPp->TLSPI__DOT__mac__DOT___T_97) {
        if ((1U & (~(IData)(vlTOPp->TLSPI__DOT__mac__DOT__cs_assert)))) {
            if (vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_42) {
                vlTOPp->TLSPI__DOT__mac__DOT__cs_dflt_2 = vlTOPp->TLSPI__DOT__ctrl_cs_dflt_2;
            } else {
                if (vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_156) {
                    vlTOPp->TLSPI__DOT__mac__DOT__cs_dflt_2 =
                        (1U & ((IData)(vlTOPp->TLSPI__DOT__mac__DOT___T_69) >> 2U));
                }
            }
        }
    } else {
        if ((1U & (~(IData)(vlTOPp->TLSPI__DOT__mac__DOT___T_99)))) {
            if (vlTOPp->TLSPI__DOT__mac__DOT___T_102) {
                if (vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_156) {
                    vlTOPp->TLSPI__DOT__mac__DOT__cs_dflt_2 =
                        (1U & ((IData)(vlTOPp->TLSPI__DOT__mac__DOT___T_107) >> 2U));
                }
            }
        }
    }
    if (vlTOPp->TLSPI__DOT__mac__DOT___T_97) {
        if ((1U & (~(IData)(vlTOPp->TLSPI__DOT__mac__DOT__cs_assert)))) {
            if (vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_42) {
                vlTOPp->TLSPI__DOT__mac__DOT__cs_dflt_3 = vlTOPp->TLSPI__DOT__ctrl_cs_dflt_3;
            } else {
                if (vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_156) {
                    vlTOPp->TLSPI__DOT__mac__DOT__cs_dflt_3 =
                        (1U & ((IData)(vlTOPp->TLSPI__DOT__mac__DOT___T_69) >> 3U));
                }
            }
        }
    } else {
        if ((1U & (~(IData)(vlTOPp->TLSPI__DOT__mac__DOT___T_99)))) {
            if (vlTOPp->TLSPI__DOT__mac__DOT___T_102) {
                if (vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_156) {
                    vlTOPp->TLSPI__DOT__mac__DOT__cs_dflt_3 =
                        (1U & ((IData)(vlTOPp->TLSPI__DOT__mac__DOT___T_107) >> 3U));
                }
            }
        }
    }
    if (vlTOPp->TLSPI__DOT__mac__DOT___T_97) {
        if ((1U & (~(IData)(vlTOPp->TLSPI__DOT__mac__DOT__cs_assert)))) {
            if ((1U & (~(IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_42)))) {
                if (vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_156) {
                    vlTOPp->TLSPI__DOT__mac__DOT__cs_set = (3U != (IData)(vlTOPp->TLSPI__DOT__fifo__DOT__cs_mode));
                }
            }
        }
    }
    if (vlTOPp->__Vcellinp__TLSPI__reset) {
        __Vdly__TLSPI__DOT__mac__DOT__cs_assert = 0U;
    } else {
        if (vlTOPp->TLSPI__DOT__mac__DOT___T_97) {
            if ((1U & (~(IData)(vlTOPp->TLSPI__DOT__mac__DOT__cs_assert)))) {
                if ((1U & (~(IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_42)))) {
                    if (vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_156) {
                        __Vdly__TLSPI__DOT__mac__DOT__cs_assert = 1U;
                    }
                }
            }
        } else {
            if ((1U & (~(IData)(vlTOPp->TLSPI__DOT__mac__DOT___T_99)))) {
                if (vlTOPp->TLSPI__DOT__mac__DOT___T_102) {
                    __Vdly__TLSPI__DOT__mac__DOT__cs_assert = 0U;
                }
            }
        }
    }
    if (vlTOPp->__Vcellinp__TLSPI__reset) {
        vlTOPp->TLSPI__DOT__mac__DOT__state = 0U;
    } else {
        if (vlTOPp->TLSPI__DOT__mac__DOT___T_97) {
            if (vlTOPp->TLSPI__DOT__mac__DOT__cs_assert) {
                if (vlTOPp->TLSPI__DOT__mac__DOT__cs_deassert) {
                    if (vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_156) {
                        vlTOPp->TLSPI__DOT__mac__DOT__state = 2U;
                    }
                } else {
                    if (((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_156) &
                         (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy_io_op_valid))) {
                        vlTOPp->TLSPI__DOT__mac__DOT__state = 1U;
                    }
                }
            }
        } else {
            if (vlTOPp->TLSPI__DOT__mac__DOT___T_99) {
                if (((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_156) |
                     (0U == (IData)(vlTOPp->TLSPI__DOT__ctrl_dla_interxfr)))) {
                    vlTOPp->TLSPI__DOT__mac__DOT__state = 0U;
                }
            } else {
                if (vlTOPp->TLSPI__DOT__mac__DOT___T_102) {
                    if (vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_156) {
                        vlTOPp->TLSPI__DOT__mac__DOT__state = 0U;
                    }
                }
            }
        }
    }
    VL_ASSIGN_SII(1, vlTOPp->auto_io_out_dq_1_oe, ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_111) |
                                                   (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__txen_2)));
    VL_ASSIGN_SII(1, vlTOPp->auto_io_out_dq_0_oe,
                  ((0U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__ctrl_fmt_proto)) |
                   ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_111) |
                    (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__txen_2))));
    vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_35___05FT_58_data =
        vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_35[vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT__value_1];
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_554 =
        (1U & ((IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_551) - (IData)(1U)));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_555 =
        (1U & (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_551)));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_639 =
        (1U & ((IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_636) - (IData)(1U)));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_640 =
        (1U & (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_636)));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_499 =
        (1U & ((IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_496) - (IData)(1U)));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_500 =
        (1U & (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_496)));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_618 =
        (1U & ((IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_615) - (IData)(1U)));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_619 =
        (1U & (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_615)));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_554 =
        (1U & ((IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_551) - (IData)(1U)));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_555 = (1U & (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_551)));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_639 =
        (1U & ((IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_636) - (IData)(1U)));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_640 = (1U & (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_636)));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_499 =
        (1U & ((IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_496) - (IData)(1U)));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_500 = (1U & (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_496)));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_618 =
        (1U & ((IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_615) - (IData)(1U)));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_619 = (1U & (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_615)));
    vlTOPp->TLSPI__DOT__mac__DOT__cs_assert = __Vdly__TLSPI__DOT__mac__DOT__cs_assert;
    vlTOPp->TLSPI__DOT__fifo__DOT___T_57 =
        (0xfU &
         (((((0U == (IData)(vlTOPp->TLSPI__DOT__ctrl_fmt_proto)) ? (IData)(vlTOPp->TLSPI__DOT__ctrl_fmt_len) : 0U) |
            (7U &
             ((1U == (IData)(vlTOPp->TLSPI__DOT__ctrl_fmt_proto)) ? ((IData)(vlTOPp->TLSPI__DOT__ctrl_fmt_len) >> 1U)
                                                                  : 0U))) |
           (3U &
            ((2U == (IData)(vlTOPp->TLSPI__DOT__ctrl_fmt_proto)) ? ((IData)(vlTOPp->TLSPI__DOT__ctrl_fmt_len) >> 2U)
                                                                 : 0U))) +
          (((1U == (IData)(vlTOPp->TLSPI__DOT__ctrl_fmt_proto)) & (IData)(vlTOPp->TLSPI__DOT__ctrl_fmt_len)) |
           ((2U == (IData)(vlTOPp->TLSPI__DOT__ctrl_fmt_proto)) &
            (0U != (3U & (IData)(vlTOPp->TLSPI__DOT__ctrl_fmt_len)))))));
    vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_128 = ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__done) |
                                                      (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__last_d));
    vlTOPp->TLSPI__DOT__fifo__DOT__rxq_io_enq_valid =
        ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__done) & (IData)(vlTOPp->TLSPI__DOT__fifo__DOT__rxen));
    vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_52 =
        (7U & ((IData)(1U) + (IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT__value)));
    vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_40 = ((IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT__value) ==
                                                      (IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT__value_1));
    vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_71 =
        ((((0x80U & ((IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_35___05FT_58_data) << 7U)) |
           (0x40U & ((IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_35___05FT_58_data) << 5U))) |
          ((0x20U & ((IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_35___05FT_58_data) << 3U)) |
           (0x10U & ((IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_35___05FT_58_data) << 1U)))) |
         (((8U & ((IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_35___05FT_58_data) >> 1U)) |
           (4U & ((IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_35___05FT_58_data) >> 3U))) |
          ((2U & ((IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_35___05FT_58_data) >> 5U)) |
           (1U & ((IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_35___05FT_58_data) >> 7U)))));
    // ALWAYS at verilog/TLSPI.v:962
    if (vlTOPp->__Vcellinp__TLSPI__reset) {
        vlTOPp->TLSPI__DOT__ctrl_fmt_endian = 0U;
    } else {
        if (((IData)(vlTOPp->TLSPI__DOT___T_1832) & (vlTOPp->TLSPI__DOT___T_626 >> 2U))) {
            vlTOPp->TLSPI__DOT__ctrl_fmt_endian =
                (1U & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_data >> 2U));
        }
    }
    vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT___T_52 =
        (7U & ((IData)(1U) + (IData)(vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT__value)));
    vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT___T_40 = ((IData)(vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT__value) ==
                                                      (IData)(vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT__value_1));
    vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__cinv = ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__ctrl_sck_pha) ^
                                                    (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__ctrl_sck_pol));
    // ALWAYS at verilog/TLSPI.v:962
    if (vlTOPp->__Vcellinp__TLSPI__reset) {
        vlTOPp->TLSPI__DOT__ctrl_sck_pol = 0U;
    } else {
        if (((IData)(vlTOPp->TLSPI__DOT___T_1742) & (vlTOPp->TLSPI__DOT___T_626 >> 1U))) {
            vlTOPp->TLSPI__DOT__ctrl_sck_pol =
                (1U & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_data >> 1U));
        }
    }
    // ALWAYS at verilog/SPIPhysical_1.v:429
    vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_44 = ((~(IData)(vlTOPp->__Vcellinp__TLSPI__reset)) &
                                                     ((1U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__scnt)) &
                                                      (((0U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__tcnt)) &
                                                        (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__cref)) &
                                                       (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__xfr))));
    // ALWAYS at verilog/SPIPhysical_1.v:486
    vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_42 = ((~(IData)(vlTOPp->__Vcellinp__TLSPI__reset)) &
                                                     ((0U != (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__scnt)) &
                                                      ((0U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__tcnt)) &
                                                       ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__xfr) &
                                                        (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__cref)))));
    vlTOPp->TLSPI__DOT__mac__DOT___T_97 = (0U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__state));
    vlTOPp->TLSPI__DOT__mac__DOT___T_99 = (1U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__state));
    vlTOPp->TLSPI__DOT__mac__DOT___T_102 = (2U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__state));
    // ALWAYS at verilog/TLSPI.v:962
    if (vlTOPp->__Vcellinp__TLSPI__reset) {
        vlTOPp->TLSPI__DOT__ctrl_dla_interxfr = 0U;
    } else {
        if (((IData)(vlTOPp->TLSPI__DOT___T_1802) & (0U == (0xffU & (~(vlTOPp->TLSPI__DOT___T_626 >> 0x10U)))))) {
            vlTOPp->TLSPI__DOT__ctrl_dla_interxfr =
                (0xffU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_data >> 0x10U));
        }
    }
    VL_ASSIGN_SII(1, vlTOPp->auto_io_out_cs_0, vlTOPp->TLSPI__DOT__mac__DOT__cs_dflt_0);
    VL_ASSIGN_SII(1, vlTOPp->auto_io_out_cs_2, vlTOPp->TLSPI__DOT__mac__DOT__cs_dflt_2);
    VL_ASSIGN_SII(1, vlTOPp->auto_io_out_cs_3, vlTOPp->TLSPI__DOT__mac__DOT__cs_dflt_3);
    vlTOPp->TLSPI__DOT__mac__DOT___T_88 =
        ((((IData)(vlTOPp->TLSPI__DOT__mac__DOT__cs_dflt_3) << 3U) |
          ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__cs_dflt_2) << 2U)) |
         (((IData)(vlTOPp->TLSPI__DOT__mac__DOT__cs_dflt_1) << 1U) | (IData)(vlTOPp->TLSPI__DOT__mac__DOT__cs_dflt_0)));
    // ALWAYS at verilog/TLSPI.v:962
    if (vlTOPp->__Vcellinp__TLSPI__reset) {
        vlTOPp->TLSPI__DOT__ctrl_cs_dflt_0 = 1U;
    } else {
        if (((IData)(vlTOPp->TLSPI__DOT___T_1766) & vlTOPp->TLSPI__DOT___T_626)) {
            vlTOPp->TLSPI__DOT__ctrl_cs_dflt_0 = (1U & vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_data);
        }
    }
    // ALWAYS at verilog/TLSPI.v:962
    if (vlTOPp->__Vcellinp__TLSPI__reset) {
        vlTOPp->TLSPI__DOT__ctrl_cs_dflt_1 = 1U;
    } else {
        if (((IData)(vlTOPp->TLSPI__DOT___T_1766) & (vlTOPp->TLSPI__DOT___T_626 >> 1U))) {
            vlTOPp->TLSPI__DOT__ctrl_cs_dflt_1 =
                (1U & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_data >> 1U));
        }
    }
    // ALWAYS at verilog/TLSPI.v:962
    if (vlTOPp->__Vcellinp__TLSPI__reset) {
        vlTOPp->TLSPI__DOT__ctrl_cs_dflt_2 = 1U;
    } else {
        if (((IData)(vlTOPp->TLSPI__DOT___T_1766) & (vlTOPp->TLSPI__DOT___T_626 >> 2U))) {
            vlTOPp->TLSPI__DOT__ctrl_cs_dflt_2 =
                (1U & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_data >> 2U));
        }
    }
    // ALWAYS at verilog/TLSPI.v:962
    if (vlTOPp->__Vcellinp__TLSPI__reset) {
        vlTOPp->TLSPI__DOT__ctrl_cs_dflt_3 = 1U;
    } else {
        if (((IData)(vlTOPp->TLSPI__DOT___T_1766) & (vlTOPp->TLSPI__DOT___T_626 >> 3U))) {
            vlTOPp->TLSPI__DOT__ctrl_cs_dflt_3 =
                (1U & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_data >> 3U));
        }
    }
    // ALWAYS at verilog/TLSPI.v:962
    if (vlTOPp->__Vcellinp__TLSPI__reset) {
        vlTOPp->TLSPI__DOT__ctrl_cs_id = 0U;
    } else {
        if (((((IData)(vlTOPp->TLSPI__DOT___T_1732) &
               (((IData)(1U) << (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U))) >>
                4U)) &
              (0U == (0x3e0U & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))) &
             (0U == (3U & (~vlTOPp->TLSPI__DOT___T_626))))) {
            vlTOPp->TLSPI__DOT__ctrl_cs_id = (3U & vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_data);
        }
    }
    // ALWAYS at verilog/SPIFIFO.v:195
    vlTOPp->TLSPI__DOT__fifo__DOT__cs_mode =
        ((IData)(vlTOPp->__Vcellinp__TLSPI__reset) ? 0U : (IData)(vlTOPp->TLSPI__DOT__ctrl_cs_mode));
    vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_42 = ((IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_40) &
                                                      (~(IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_39)));
    vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_43 = ((IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_40) &
                                                      (IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_39));
    vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT___T_43 = ((IData)(vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT___T_40) &
                                                      (IData)(vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT___T_39));
    vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT___T_42 = ((IData)(vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT___T_40) &
                                                      (~(IData)(vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT___T_39)));
    vlTOPp->TLSPI__DOT__mac__DOT___T_107 =
        (0xfU & ((IData)(vlTOPp->TLSPI__DOT__mac__DOT___T_88) ^
                 ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__cs_set) << (IData)(vlTOPp->TLSPI__DOT__mac__DOT__cs_id))));
    vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT___T_44 = ((~(IData)(vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT___T_43)) &
                                                      (IData)(vlTOPp->TLSPI__DOT__fifo__DOT__rxq_io_enq_valid));
    // ALWAYS at verilog/SPIPhysical_1.v:429
    if (vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_156) {
        if (vlTOPp->TLSPI__DOT__mac__DOT__phy_io_op_valid) {
            vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__xfr =
                (1U & (~(IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy_io_op_bits_fn)));
        }
    }
    // ALWAYS at verilog/SPIPhysical_1.v:429
    if (vlTOPp->__Vcellinp__TLSPI__reset) {
        vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__cref = 1U;
    } else {
        if ((0U != (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__scnt))) {
            if ((0U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__tcnt))) {
                vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__cref = vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_154;
            }
        }
    }
    vlTOPp->TLSPI__DOT__mac__DOT___T_69 =
        (0xfU &
         (((((IData)(vlTOPp->TLSPI__DOT__ctrl_cs_dflt_3) << 3U) | ((IData)(vlTOPp->TLSPI__DOT__ctrl_cs_dflt_2) << 2U)) |
           (((IData)(vlTOPp->TLSPI__DOT__ctrl_cs_dflt_1) << 1U) | (IData)(vlTOPp->TLSPI__DOT__ctrl_cs_dflt_0))) ^
          ((3U != (IData)(vlTOPp->TLSPI__DOT__fifo__DOT__cs_mode)) << (IData)(vlTOPp->TLSPI__DOT__ctrl_cs_id))));
    // ALWAYS at verilog/TLSPI.v:962
    if (vlTOPp->__Vcellinp__TLSPI__reset) {
        vlTOPp->TLSPI__DOT__ctrl_cs_mode = 0U;
    } else {
        if (((((IData)(vlTOPp->TLSPI__DOT___T_1732) &
               (((IData)(1U) << (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U))) >>
                6U)) &
              (0U == (0x3e0U & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))) &
             (0U == (3U & (~vlTOPp->TLSPI__DOT___T_626))))) {
            vlTOPp->TLSPI__DOT__ctrl_cs_mode = (3U & vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_data);
        }
    }
    vlTOPp->TLSPI__DOT__mac__DOT__cs_deassert =
        ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__clear) |
         ((IData)(vlTOPp->TLSPI__DOT__mac__DOT___T_69) != (IData)(vlTOPp->TLSPI__DOT__mac__DOT___T_88)));
    vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_154 = (1U & (~(IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__cref)));
    vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_148 =
        ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__cref) ^ (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__cinv));
    // ALWAYS at verilog/SPIPhysical_1.v:429
    vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__scnt =
        (0xffU & ((IData)(vlTOPp->__Vcellinp__TLSPI__reset)
                      ? 0U
                      : ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_156)
                             ? ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy_io_op_valid)
                                    ? (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy_io_op_bits_cnt)
                                    : (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___GEN_16))
                             : (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___GEN_16))));
    // ALWAYS at verilog/SPIPhysical_1.v:429
    vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__tcnt =
        (0xfffU & ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__sched)
                       ? (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__ctrl_sck_div)
                       : ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_47) - (IData)(1U))));
    vlTOPp->TLSPI__DOT__mac__DOT__phy_io_op_bits_cnt =
        ((0U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__state))
             ? ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__cs_assert)
                    ? ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__cs_deassert)
                           ? (IData)(vlTOPp->TLSPI__DOT__ctrl_dla_sckcs)
                           : (IData)(vlTOPp->TLSPI__DOT__fifo__DOT___T_57))
                    : ((IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_42)
                           ? 0U
                           : (IData)(vlTOPp->TLSPI__DOT__ctrl_dla_cssck)))
             : ((1U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__state))
                    ? (IData)(vlTOPp->TLSPI__DOT__ctrl_dla_interxfr)
                    : ((2U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__state))
                           ? (IData)(vlTOPp->TLSPI__DOT__ctrl_dla_intercs)
                           : (IData)(vlTOPp->TLSPI__DOT__fifo__DOT___T_57))));
    vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__shift = ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__setup_d) |
                                                     ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__sample_d) &
                                                      (0U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__scnt))));
    vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__sched = ((0U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__scnt)) |
                                                     (0U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__tcnt)));
    vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___GEN_13 =
        ((0U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__scnt))
             ? (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__sck)
             : ((0U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__tcnt))
                    ? ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__xfr)
                           ? (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_148)
                           : (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__sck))
                    : (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__sck)));
    vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_47 = ((0U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__tcnt))
                                                         ? (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__scnt)
                                                         : (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__tcnt));
    vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___GEN_15 = ((0U != (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__scnt)) &
                                                       ((0U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__tcnt)) &
                                                        ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__xfr) &
                                                         (~(IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__cref)))));
    vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_155 = ((0U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__tcnt)) &
                                                      (~(IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__cref)));
    // ALWAYS at verilog/SPIPhysical_1.v:429
    if (vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_156) {
        if (vlTOPp->TLSPI__DOT__mac__DOT__phy_io_op_valid) {
            if (vlTOPp->TLSPI__DOT__mac__DOT__phy_io_op_bits_fn) {
                if (vlTOPp->TLSPI__DOT__mac__DOT__phy_io_op_bits_fn) {
                    if (vlTOPp->TLSPI__DOT__mac__DOT__phy_io_op_bits_stb) {
                        vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__ctrl_sck_div = vlTOPp->TLSPI__DOT__ctrl_sck_div;
                    }
                }
            }
        }
    }
    vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___GEN_16 =
        (0xfffU & ((0U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__scnt))
                       ? (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__scnt)
                       : ((0U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__tcnt))
                              ? ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__cref)
                                     ? (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__scnt)
                                     : ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_47) - (IData)(1U)))
                              : (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__scnt))));
    vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___GEN_22 =
        ((1U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__scnt))
             ? ((~(IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_155)) &
                (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___GEN_15))
             : (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___GEN_15));
    vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__accept =
        ((1U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__scnt))
             ? ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_155) |
                (0U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__scnt)))
             : (0U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__scnt)));
    vlTOPp->TLSPI__DOT__mac__DOT__phy_io_op_bits_fn =
        (1U &
         ((0U != (IData)(vlTOPp->TLSPI__DOT__mac__DOT__state)) |
          ((~(IData)(vlTOPp->TLSPI__DOT__mac__DOT__cs_assert)) | (IData)(vlTOPp->TLSPI__DOT__mac__DOT__cs_deassert))));
    vlTOPp->TLSPI__DOT__mac__DOT__phy_io_op_bits_stb =
        (1U & ((0U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__state))
                   ? ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__cs_assert)
                          ? (~(IData)(vlTOPp->TLSPI__DOT__mac__DOT__cs_deassert))
                          : (IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_42))
                   : ((1U != (IData)(vlTOPp->TLSPI__DOT__mac__DOT__state)) &
                      (2U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__state)))));
    vlTOPp->TLSPI__DOT__mac__DOT__phy_io_op_valid =
        (1U & ((0U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__state))
                   ? ((~(IData)(vlTOPp->TLSPI__DOT__mac__DOT__cs_assert)) |
                      ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__cs_deassert) |
                       (~(IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_42))))
                   : ((1U != (IData)(vlTOPp->TLSPI__DOT__mac__DOT__state)) |
                      (0U != (IData)(vlTOPp->TLSPI__DOT__ctrl_dla_interxfr)))));
    vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_102 =
        ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__accept)
             ? (IData)(vlTOPp->TLSPI__DOT__ctrl_fmt_proto)
             : (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__ctrl_fmt_proto));
    vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__txd_in =
        (0xfU & ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__accept)
                     ? (((IData)(vlTOPp->TLSPI__DOT__ctrl_fmt_endian)
                             ? (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_71)
                             : (IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_35___05FT_58_data)) >>
                        4U)
                     : ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__buffer) >> 4U)));
    vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_156 = ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__accept) &
                                                      (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__done));
    // ALWAYS at verilog/TLSPI.v:962
    if (vlTOPp->__Vcellinp__TLSPI__reset) {
        vlTOPp->TLSPI__DOT__ctrl_sck_div = 3U;
    } else {
        if (((((IData)(vlTOPp->TLSPI__DOT___T_1732) &
               ((IData)(1U) << (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))) &
              (0U == (0x3e0U & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))) &
             (0U == (0xfffU & (~vlTOPp->TLSPI__DOT___T_626))))) {
            vlTOPp->TLSPI__DOT__ctrl_sck_div = (0xfffU & vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_data);
        }
    }
    vlTOPp->TLSPI__DOT__mac_io_link_tx_ready = ((0U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__state)) &
                                                ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__cs_assert) &
                                                 ((~(IData)(vlTOPp->TLSPI__DOT__mac__DOT__cs_deassert)) &
                                                  (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_156))));
    vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_47 = ((IData)(vlTOPp->TLSPI__DOT__mac_io_link_tx_ready) &
                                                      (~(IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_42)));
    vlTOPp->TLSPI__DOT__mac__DOT___T_94 =
        ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__clear) |
         ((((IData)(vlTOPp->TLSPI__DOT__fifo__DOT__cs_mode) != (IData)(vlTOPp->TLSPI__DOT__ctrl_cs_mode)) |
           ((IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_47) &
            (~((2U == (IData)(vlTOPp->TLSPI__DOT__fifo__DOT__cs_mode)) |
               (3U == (IData)(vlTOPp->TLSPI__DOT__fifo__DOT__cs_mode)))))) &
          (IData)(vlTOPp->TLSPI__DOT__mac__DOT__cs_assert)));
}

VL_INLINE_OPT void VTLSPI::_sequent__TOP__5(VTLSPI__Syms *__restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTLSPI::_sequent__TOP__5\n"););
    VTLSPI *__restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at ../git/freedom/rocket-chip/src/main/resources/vsrc/AsyncResetReg.v:70
    vlTOPp->TLSPI__DOT__intsource__DOT__AsyncResetRegVec_w1_i0__DOT__reg_0_q =
        ((~(IData)(vlTOPp->__Vcellinp__TLSPI__reset)) &
         (((IData)(vlTOPp->TLSPI__DOT__fifo_io_ip_txwm) & (IData)(vlTOPp->TLSPI__DOT__ie_txwm)) |
          ((IData)(vlTOPp->TLSPI__DOT__fifo_io_ip_rxwm) & (IData)(vlTOPp->TLSPI__DOT__ie_rxwm))));
    VL_ASSIGN_SII(1, vlTOPp->auto_int_xing_out_sync_0,
                  vlTOPp->TLSPI__DOT__intsource__DOT__AsyncResetRegVec_w1_i0__DOT__reg_0_q);
}

VL_INLINE_OPT void VTLSPI::_combo__TOP__6(VTLSPI__Syms *__restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTLSPI::_combo__TOP__6\n"););
    VTLSPI *__restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    VL_ASSIGN_ISI(1, vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_corrupt,
                  vlTOPp->auto_control_xing_in_a_bits_corrupt);
    VL_ASSIGN_ISI(4, vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_mask,
                  vlTOPp->auto_control_xing_in_a_bits_mask);
    VL_ASSIGN_ISI(1, vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid, vlTOPp->auto_control_xing_in_a_valid);
    VL_ASSIGN_ISI(3, vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_param,
                  vlTOPp->auto_control_xing_in_a_bits_param);
    VL_ASSIGN_ISI(3, vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode,
                  vlTOPp->auto_control_xing_in_a_bits_opcode);
    VL_ASSIGN_ISI(6, vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_source,
                  vlTOPp->auto_control_xing_in_a_bits_source);
    VL_ASSIGN_ISI(2, vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_size,
                  vlTOPp->auto_control_xing_in_a_bits_size);
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_687 =
        ((((VL_ULL(0) == vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_604) |
           (0U == vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT__plusarg_reader__DOT__myplus)) |
          (vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_679 <
           vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT__plusarg_reader__DOT__myplus)) |
         (IData)(vlTOPp->__Vcellinp__TLSPI__reset));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_687 =
        ((((VL_ULL(0) == vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_604) |
           (0U == vlTOPp->TLSPI__DOT__TLMonitor__DOT__plusarg_reader__DOT__myplus)) |
          (vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_679 <
           vlTOPp->TLSPI__DOT__TLMonitor__DOT__plusarg_reader__DOT__myplus)) |
         (IData)(vlTOPp->__Vcellinp__TLSPI__reset));
    vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT___T_96 =
        ((((0U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__ctrl_fmt_proto))
               ? ((0xfeU & (((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__shift)
                                 ? (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__buffer)
                                 : ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__buffer) >> 1U))
                            << 1U)) |
                  (1U & ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__sample_d)
                             ? ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__rxd) >> 1U)
                             : (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__buffer))))
               : 0U) |
          ((1U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__ctrl_fmt_proto))
               ? ((0xfcU & (((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__shift)
                                 ? (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__buffer)
                                 : ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__buffer) >> 2U))
                            << 2U)) |
                  (3U & ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__sample_d)
                             ? (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__rxd)
                             : (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__buffer))))
               : 0U)) |
         ((2U == (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__ctrl_fmt_proto))
              ? ((0xf0U & (((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__shift)
                                ? (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__buffer)
                                : ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__buffer) >> 4U))
                           << 4U)) |
                 (0xfU & ((IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__sample_d)
                              ? (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__rxd)
                              : (IData)(vlTOPp->TLSPI__DOT__mac__DOT__phy__DOT__buffer))))
              : 0U));
    VL_ASSIGN_ISI(29, vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address,
                  vlTOPp->auto_control_xing_in_a_bits_address);
    VL_ASSIGN_SII(1, vlTOPp->auto_control_xing_in_d_valid, vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid);
    vlTOPp->TLSPI__DOT___T_1495 = ((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid) &
                                   (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_d_ready));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_542 =
        ((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_d_ready) &
         (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_542 = ((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_d_ready) &
                                                  (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_486 =
        ((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_d_ready) &
         (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_486 = ((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_d_ready) &
                                                  (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_valid));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_526 =
        (((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_param) ==
          (IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_511)) |
         (IData)(vlTOPp->__Vcellinp__TLSPI__reset));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_526 =
        (((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_param) ==
          (IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_511)) |
         (IData)(vlTOPp->__Vcellinp__TLSPI__reset));
    VL_ASSIGN_SII(3, vlTOPp->auto_control_xing_in_d_bits_opcode,
                  (4U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode)));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_522 =
        (((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode) ==
          (IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_509)) |
         (IData)(vlTOPp->__Vcellinp__TLSPI__reset));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_579 =
        (((4U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode)) ==
          (IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_564)) |
         (IData)(vlTOPp->__Vcellinp__TLSPI__reset));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_522 =
        (((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode) ==
          (IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_509)) |
         (IData)(vlTOPp->__Vcellinp__TLSPI__reset));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_579 =
        (((4U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode)) ==
          (IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_564)) |
         (IData)(vlTOPp->__Vcellinp__TLSPI__reset));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_534 =
        (((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_source) ==
          (IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_515)) |
         (IData)(vlTOPp->__Vcellinp__TLSPI__reset));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_658 =
        (1U & ((~(IData)((vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_604 >>
                          (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_source)))) |
               (IData)(vlTOPp->__Vcellinp__TLSPI__reset)));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_534 =
        (((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_source) ==
          (IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_515)) |
         (IData)(vlTOPp->__Vcellinp__TLSPI__reset));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_658 =
        (1U & ((~(IData)((vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_604 >>
                          (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_source)))) |
               (IData)(vlTOPp->__Vcellinp__TLSPI__reset)));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_530 =
        (((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_size) ==
          (IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_513)) |
         (IData)(vlTOPp->__Vcellinp__TLSPI__reset));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_530 =
        (((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_size) ==
          (IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_513)) |
         (IData)(vlTOPp->__Vcellinp__TLSPI__reset));
    vlTOPp->TLSPI__DOT___T_426 = (((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_source) << 2U) |
                                  (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_size));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_97 =
        ((0U ==
          (3U & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address &
                 (~(0x1fU & ((IData)(3U) << (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_size))))))) |
         (IData)(vlTOPp->__Vcellinp__TLSPI__reset));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_167 =
        (((2U >= (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_size)) &
          (0U == (0x3ffff000U & (0x10024000U ^ vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address)))) |
         (IData)(vlTOPp->__Vcellinp__TLSPI__reset));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_538 =
        ((vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address ==
          vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_517) |
         (IData)(vlTOPp->__Vcellinp__TLSPI__reset));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_97 =
        ((0U ==
          (3U & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address &
                 (~(0x1fU & ((IData)(3U) << (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_size))))))) |
         (IData)(vlTOPp->__Vcellinp__TLSPI__reset));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_167 =
        (((2U >= (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_size)) &
          (0U == (0x3ffff000U & (0x10024000U ^ vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address)))) |
         (IData)(vlTOPp->__Vcellinp__TLSPI__reset));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_538 = ((vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address ==
                                                   vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_517) |
                                                  (IData)(vlTOPp->__Vcellinp__TLSPI__reset));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_52 =
        (1U &
         ((2U <= (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_size)) |
          (1U & ((((IData)(1U) << (1U & (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_size))) >> 1U) &
                 (~(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 1U))))));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_55 =
        (1U &
         ((2U <= (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_size)) |
          (1U & ((((IData)(1U) << (1U & (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_size))) >> 1U) &
                 (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 1U)))));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_52 =
        (1U &
         ((2U <= (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_size)) |
          (1U & ((((IData)(1U) << (1U & (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_size))) >> 1U) &
                 (~(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 1U))))));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_55 =
        (1U &
         ((2U <= (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_size)) |
          (1U & ((((IData)(1U) << (1U & (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_size))) >> 1U) &
                 (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 1U)))));
    vlTOPp->TLSPI__DOT___GEN_155 =
        ((0x10U == (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
             ? (0U == (0x3e0U & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
             : ((0x12U == (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
                    ? (0U == (0x3e0U & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
                    : ((0x13U == (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
                           ? (0U == (0x3e0U & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
                           : ((0x14U ==
                               (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
                                  ? (0U ==
                                     (0x3e0U & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
                                  : ((0x15U ==
                                      (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
                                         ? (0U ==
                                            (0x3e0U &
                                             (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
                                         : ((0x1cU ==
                                             (0x1fU &
                                              (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
                                                ? (0U ==
                                                   (0x3e0U &
                                                    (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >>
                                                     2U)))
                                                : ((0x1dU !=
                                                    (0x1fU &
                                                     (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >>
                                                      2U))) |
                                                   (0U ==
                                                    (0x3e0U &
                                                     (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >>
                                                      2U))))))))));
    vlTOPp->TLSPI__DOT___T_1732 = ((IData)(vlTOPp->TLSPI__DOT___T_1495) &
                                   (4U != (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode)));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_602 =
        ((IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_542) &
         (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_551)));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_602 =
        ((IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_542) & (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_551)));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_541 =
        ((IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_486) &
         (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_496)));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___GEN_15 =
        (((IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_486) &
          (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_615)))
             ? (VL_ULL(1) << (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_source))
             : VL_ULL(0));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_541 =
        ((IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_486) & (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_496)));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___GEN_15 =
        (((IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_486) & (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_615)))
             ? (VL_ULL(1) << (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_source))
             : VL_ULL(0));
    VL_ASSIGN_SII(6, vlTOPp->auto_control_xing_in_d_bits_source, (0x3fU & ((IData)(vlTOPp->TLSPI__DOT___T_426) >> 2U)));
    VL_ASSIGN_SII(2, vlTOPp->auto_control_xing_in_d_bits_size, (3U & (IData)(vlTOPp->TLSPI__DOT___T_426)));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_587 =
        (((3U & (IData)(vlTOPp->TLSPI__DOT___T_426)) ==
          (IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_568)) |
         (IData)(vlTOPp->__Vcellinp__TLSPI__reset));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_591 =
        (((0x3fU & ((IData)(vlTOPp->TLSPI__DOT___T_426) >> 2U)) ==
          (IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_570)) |
         (IData)(vlTOPp->__Vcellinp__TLSPI__reset));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_587 =
        (((3U & (IData)(vlTOPp->TLSPI__DOT___T_426)) == (IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_568)) |
         (IData)(vlTOPp->__Vcellinp__TLSPI__reset));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_591 = (((0x3fU & ((IData)(vlTOPp->TLSPI__DOT___T_426) >> 2U)) ==
                                                   (IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_570)) |
                                                  (IData)(vlTOPp->__Vcellinp__TLSPI__reset));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_73 =
        (((8U & (((IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_55) << 3U) |
                 (0xfffffff8U & ((vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address << 2U) &
                                 (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address << 3U))))) |
          (4U & (((IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_55) << 2U) |
                 (0xfffffffcU & ((vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address << 1U) &
                                 ((~vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address) << 2U)))))) |
         ((2U & (((IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_52) |
                  ((~(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 1U)) &
                   vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address))
                 << 1U)) |
          (1U & ((IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_52) |
                 ((~(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 1U)) &
                  (~vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address))))));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_73 =
        (((8U & (((IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_55) << 3U) |
                 (0xfffffff8U & ((vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address << 2U) &
                                 (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address << 3U))))) |
          (4U & (((IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_55) << 2U) |
                 (0xfffffffcU & ((vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address << 1U) &
                                 ((~vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address) << 2U)))))) |
         ((2U & (((IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_52) |
                  ((~(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 1U)) &
                   vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address))
                 << 1U)) |
          (1U & ((IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_52) |
                 ((~(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 1U)) &
                  (~vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address))))));
    vlTOPp->TLSPI__DOT___GEN_162 =
        ((0U == (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
             ? (0U == (0x3e0U & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
             : ((1U == (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
                    ? (0U == (0x3e0U & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
                    : ((4U == (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
                           ? (0U == (0x3e0U & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
                           : ((5U == (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
                                  ? (0U ==
                                     (0x3e0U & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
                                  : ((6U ==
                                      (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
                                         ? (0U ==
                                            (0x3e0U &
                                             (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
                                         : ((0xaU ==
                                             (0x1fU &
                                              (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
                                                ? (0U ==
                                                   (0x3e0U &
                                                    (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >>
                                                     2U)))
                                                : ((0xbU ==
                                                    (0x1fU &
                                                     (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >>
                                                      2U)))
                                                       ? (0U ==
                                                          (0x3e0U &
                                                           (vlTOPp
                                                                ->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >>
                                                            2U)))
                                                       : (IData)(vlTOPp->TLSPI__DOT___GEN_155))))))));
    vlTOPp->TLSPI__DOT___T_1766 =
        (((IData)(vlTOPp->TLSPI__DOT___T_1732) &
          (((IData)(1U) << (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U))) >> 5U)) &
         (0U == (0x3e0U & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U))));
    vlTOPp->TLSPI__DOT___T_1796 =
        (((IData)(vlTOPp->TLSPI__DOT___T_1732) &
          (((IData)(1U) << (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U))) >> 0xaU)) &
         (0U == (0x3e0U & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U))));
    vlTOPp->TLSPI__DOT___T_1742 =
        (((IData)(vlTOPp->TLSPI__DOT___T_1732) &
          (((IData)(1U) << (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U))) >> 1U)) &
         (0U == (0x3e0U & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U))));
    vlTOPp->TLSPI__DOT___T_1832 =
        (((IData)(vlTOPp->TLSPI__DOT___T_1732) &
          (((IData)(1U) << (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U))) >>
           0x10U)) &
         (0U == (0x3e0U & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U))));
    vlTOPp->TLSPI__DOT___T_1802 =
        (((IData)(vlTOPp->TLSPI__DOT___T_1732) &
          (((IData)(1U) << (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U))) >> 0xbU)) &
         (0U == (0x3e0U & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U))));
    vlTOPp->TLSPI__DOT___T_1844 =
        (((IData)(vlTOPp->TLSPI__DOT___T_1732) &
          (((IData)(1U) << (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U))) >>
           0x12U)) &
         (0U == (0x3e0U & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U))));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_673 =
        (1U & ((IData)(((vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___GEN_15 |
                         vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_604) >>
                        (0x3fU & ((IData)(vlTOPp->TLSPI__DOT___T_426) >> 2U)))) |
               (IData)(vlTOPp->__Vcellinp__TLSPI__reset)));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_677 =
        ((vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_604 |
          vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___GEN_15) &
         (~(((IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_542) &
             (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_636)))
                ? (VL_ULL(1) << (0x3fU & ((IData)(vlTOPp->TLSPI__DOT___T_426) >> 2U)))
                : VL_ULL(0))));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_673 =
        (1U & ((IData)(((vlTOPp->TLSPI__DOT__TLMonitor__DOT___GEN_15 | vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_604) >>
                        (0x3fU & ((IData)(vlTOPp->TLSPI__DOT___T_426) >> 2U)))) |
               (IData)(vlTOPp->__Vcellinp__TLSPI__reset)));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_677 =
        ((vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_604 | vlTOPp->TLSPI__DOT__TLMonitor__DOT___GEN_15) &
         (~(((IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_542) &
             (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_636)))
                ? (VL_ULL(1) << (0x3fU & ((IData)(vlTOPp->TLSPI__DOT___T_426) >> 2U)))
                : VL_ULL(0))));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_181 =
        (((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_mask) ==
          (IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_73)) |
         (IData)(vlTOPp->__Vcellinp__TLSPI__reset));
    vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_245 =
        ((0U == ((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_mask) &
                 (~(IData)(vlTOPp->TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_73)))) |
         (IData)(vlTOPp->__Vcellinp__TLSPI__reset));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_181 =
        (((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_mask) ==
          (IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_73)) |
         (IData)(vlTOPp->__Vcellinp__TLSPI__reset));
    vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_245 =
        ((0U == ((IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_mask) &
                 (~(IData)(vlTOPp->TLSPI__DOT__TLMonitor__DOT___T_73)))) |
         (IData)(vlTOPp->__Vcellinp__TLSPI__reset));
}

VL_INLINE_OPT void VTLSPI::_sequent__TOP__7(VTLSPI__Syms *__restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTLSPI::_sequent__TOP__7\n"););
    VTLSPI *__restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->TLSPI__DOT__fifo_io_ip_txwm = (((((IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_39) &
                                              (IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_40))
                                             << 3U) |
                                            (7U & ((IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT__value) -
                                                   (IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT__value_1)))) <
                                           (IData)(vlTOPp->TLSPI__DOT__ctrl_wm_tx));
    vlTOPp->TLSPI__DOT__fifo_io_ip_rxwm = (((((IData)(vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT___T_39) &
                                              (IData)(vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT___T_40))
                                             << 3U) |
                                            (7U & ((IData)(vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT__value) -
                                                   (IData)(vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT__value_1)))) >
                                           (IData)(vlTOPp->TLSPI__DOT__ctrl_wm_rx));
    // ALWAYS at verilog/TLSPI.v:962
    if (vlTOPp->__Vcellinp__TLSPI__reset) {
        vlTOPp->TLSPI__DOT__ie_txwm = 0U;
    } else {
        if (((IData)(vlTOPp->TLSPI__DOT___T_1904) & vlTOPp->TLSPI__DOT___T_626)) {
            vlTOPp->TLSPI__DOT__ie_txwm = (1U & vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_data);
        }
    }
    // ALWAYS at verilog/TLSPI.v:962
    if (vlTOPp->__Vcellinp__TLSPI__reset) {
        vlTOPp->TLSPI__DOT__ie_rxwm = 0U;
    } else {
        if (((IData)(vlTOPp->TLSPI__DOT___T_1904) & (vlTOPp->TLSPI__DOT___T_626 >> 1U))) {
            vlTOPp->TLSPI__DOT__ie_rxwm = (1U & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_data >> 1U));
        }
    }
}

VL_INLINE_OPT void VTLSPI::_combo__TOP__8(VTLSPI__Syms *__restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTLSPI::_combo__TOP__8\n"););
    VTLSPI *__restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->TLSPI__DOT___T_1904 =
        (((IData)(vlTOPp->TLSPI__DOT___T_1732) &
          (((IData)(1U) << (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U))) >>
           0x1cU)) &
         (0U == (0x3e0U & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U))));
    VL_ASSIGN_ISI(1, vlTOPp->__Vcellinp__TLSPI__reset, vlTOPp->reset);
    VL_ASSIGN_ISI(32, vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_data,
                  vlTOPp->auto_control_xing_in_a_bits_data);
    vlTOPp->TLSPI__DOT___T_626 =
        (((((8U & (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_mask)) ? 0xffU : 0U) << 0x18U) |
          (((4U & (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_mask)) ? 0xffU : 0U) << 0x10U)) |
         ((((2U & (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_mask)) ? 0xffU : 0U) << 8U) |
          ((1U & (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_mask)) ? 0xffU : 0U)));
    vlTOPp->TLSPI__DOT___GEN_172 =
        ((6U == (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
             ? (IData)(vlTOPp->TLSPI__DOT__ctrl_cs_mode)
             : ((0xaU == (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
                    ? (((IData)(vlTOPp->TLSPI__DOT__ctrl_dla_sckcs) << 0x10U) |
                       (IData)(vlTOPp->TLSPI__DOT__ctrl_dla_cssck))
                    : ((0xbU == (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
                           ? (((IData)(vlTOPp->TLSPI__DOT__ctrl_dla_interxfr) << 0x10U) |
                              (IData)(vlTOPp->TLSPI__DOT__ctrl_dla_intercs))
                           : ((0x10U ==
                               (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
                                  ? (((IData)(vlTOPp->TLSPI__DOT__ctrl_fmt_len) << 0x10U) |
                                     (((IData)(vlTOPp->TLSPI__DOT__ctrl_fmt_iodir) << 3U) |
                                      (((IData)(vlTOPp->TLSPI__DOT__ctrl_fmt_endian) << 2U) |
                                       (IData)(vlTOPp->TLSPI__DOT__ctrl_fmt_proto))))
                                  : ((0x12U ==
                                      (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
                                         ? ((IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_43) << 0x1fU)
                                         : ((0x13U ==
                                             (0x1fU &
                                              (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
                                                ? (((IData)(vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT___T_42) << 0x1fU) |
                                                   vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT___T_35
                                                       [vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT__value_1])
                                                : ((0x14U ==
                                                    (0x1fU &
                                                     (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >>
                                                      2U)))
                                                       ? (IData)(vlTOPp->TLSPI__DOT__ctrl_wm_tx)
                                                       : ((0x15U ==
                                                           (0x1fU &
                                                            (vlTOPp
                                                                 ->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >>
                                                             2U)))
                                                              ? (IData)(vlTOPp->TLSPI__DOT__ctrl_wm_rx)
                                                              : ((0x1cU ==
                                                                  (0x1fU &
                                                                   (vlTOPp
                                                                        ->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >>
                                                                    2U)))
                                                                     ? (((IData)(vlTOPp->TLSPI__DOT__ie_rxwm) << 1U) |
                                                                        (IData)(vlTOPp->TLSPI__DOT__ie_txwm))
                                                                     : ((0x1dU ==
                                                                         (0x1fU &
                                                                          (vlTOPp
                                                                               ->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >>
                                                                           2U)))
                                                                            ? (((IData)(
                                                                                    vlTOPp->TLSPI__DOT__fifo_io_ip_rxwm)
                                                                                << 1U) |
                                                                               (IData)(
                                                                                   vlTOPp->TLSPI__DOT__fifo_io_ip_txwm))
                                                                            : 0U))))))))));
    vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT___T_47 =
        ((((((IData)(vlTOPp->TLSPI__DOT___T_1495) &
             (4U == (IData)(vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode))) &
            (((IData)(1U) << (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U))) >>
             0x13U)) &
           (0U == (0x3e0U & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))) &
          (0U != (0xffU & vlTOPp->TLSPI__DOT___T_626))) &
         (~(IData)(vlTOPp->TLSPI__DOT__fifo__DOT__rxq__DOT___T_42)));
    vlTOPp->TLSPI__DOT__fifo_io_tx_valid =
        (((IData)(vlTOPp->TLSPI__DOT___T_1844) & (0U == (0xffU & (~vlTOPp->TLSPI__DOT___T_626)))) &
         (~(((IData)(vlTOPp->TLSPI__DOT___T_1844) & (vlTOPp->TLSPI__DOT___T_626 >> 0x1fU)) &
            (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_data >> 0x1fU))));
    VL_ASSIGN_SII(
        32, vlTOPp->auto_control_xing_in_d_bits_data,
        ((IData)(vlTOPp->TLSPI__DOT___GEN_162)
             ? ((0U == (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
                    ? (IData)(vlTOPp->TLSPI__DOT__ctrl_sck_div)
                    : ((1U == (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
                           ? (((IData)(vlTOPp->TLSPI__DOT__ctrl_sck_pol) << 1U) |
                              (IData)(vlTOPp->TLSPI__DOT__ctrl_sck_pha))
                           : ((4U == (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
                                  ? (IData)(vlTOPp->TLSPI__DOT__ctrl_cs_id)
                                  : ((5U ==
                                      (0x1fU & (vlTOPp->__Vcellinp__TLSPI__auto_control_xing_in_a_bits_address >> 2U)))
                                         ? (((IData)(vlTOPp->TLSPI__DOT__ctrl_cs_dflt_3) << 3U) |
                                            (((IData)(vlTOPp->TLSPI__DOT__ctrl_cs_dflt_2) << 2U) |
                                             (((IData)(vlTOPp->TLSPI__DOT__ctrl_cs_dflt_1) << 1U) |
                                              (IData)(vlTOPp->TLSPI__DOT__ctrl_cs_dflt_0))))
                                         : vlTOPp->TLSPI__DOT___GEN_172))))
             : 0U));
    vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_44 =
        ((~(IData)(vlTOPp->TLSPI__DOT__fifo__DOT__txq__DOT___T_43)) & (IData)(vlTOPp->TLSPI__DOT__fifo_io_tx_valid));
}

void VTLSPI::_eval(VTLSPI__Syms *__restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTLSPI::_eval\n"););
    VTLSPI *__restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__2(vlSymsp);
    if (((IData)(vlTOPp->__Vcellinp__TLSPI__clock) & (~(IData)(vlTOPp->__Vclklast__TOP____Vcellinp__TLSPI__clock)))) {
        vlTOPp->_sequent__TOP__4(vlSymsp);
    }
    if ((((IData)(vlTOPp->__Vcellinp__TLSPI__clock) & (~(IData)(vlTOPp->__Vclklast__TOP____Vcellinp__TLSPI__clock))) |
         ((IData)(vlTOPp->__VinpClk__TOP____Vcellinp__TLSPI__reset) &
          (~(IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP____Vcellinp__TLSPI__reset))))) {
        vlTOPp->_sequent__TOP__5(vlSymsp);
    }
    vlTOPp->_combo__TOP__6(vlSymsp);
    if (((IData)(vlTOPp->__Vcellinp__TLSPI__clock) & (~(IData)(vlTOPp->__Vclklast__TOP____Vcellinp__TLSPI__clock)))) {
        vlTOPp->_sequent__TOP__7(vlSymsp);
    }
    vlTOPp->_combo__TOP__8(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP____Vcellinp__TLSPI__clock = vlTOPp->__Vcellinp__TLSPI__clock;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP____Vcellinp__TLSPI__reset =
        vlTOPp->__VinpClk__TOP____Vcellinp__TLSPI__reset;
    vlTOPp->__VinpClk__TOP____Vcellinp__TLSPI__reset = vlTOPp->__Vcellinp__TLSPI__reset;
}

void VTLSPI::_eval_initial(VTLSPI__Syms *__restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTLSPI::_eval_initial\n"););
    VTLSPI *__restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
}

void VTLSPI::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTLSPI::final\n"););
    // Variables
    VTLSPI__Syms *__restrict vlSymsp = this->__VlSymsp;
    VTLSPI *__restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VTLSPI::_eval_settle(VTLSPI__Syms *__restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTLSPI::_eval_settle\n"););
    VTLSPI *__restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
}

VL_INLINE_OPT QData VTLSPI::_change_request(VTLSPI__Syms *__restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTLSPI::_change_request\n"););
    VTLSPI *__restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false; // Logically a bool
    __req |= ((vlTOPp->__Vcellinp__TLSPI__reset ^ vlTOPp->__Vchglast__TOP____Vcellinp__TLSPI__reset));
    VL_DEBUG_IF(if (__req && ((vlTOPp->__Vcellinp__TLSPI__reset ^ vlTOPp->__Vchglast__TOP____Vcellinp__TLSPI__reset)))
                    VL_DBG_MSGF("        CHANGE: verilog/TLSPI.v:3: __Vcellinp__TLSPI__reset\n"););
    // Final
    vlTOPp->__Vchglast__TOP____Vcellinp__TLSPI__reset = vlTOPp->__Vcellinp__TLSPI__reset;
    return __req;
}

#ifdef VL_DEBUG
void VTLSPI::_eval_debug_assertions() { VL_DEBUG_IF(VL_DBG_MSGF("+    VTLSPI::_eval_debug_assertions\n");); }
#endif // VL_DEBUG

void VTLSPI::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTLSPI::_ctor_var_reset\n"););
    // Body
    __Vcellinp__TLSPI__auto_io_out_dq_3_i = VL_RAND_RESET_I(1);
    __Vcellinp__TLSPI__auto_io_out_dq_2_i = VL_RAND_RESET_I(1);
    __Vcellinp__TLSPI__auto_io_out_dq_1_i = VL_RAND_RESET_I(1);
    __Vcellinp__TLSPI__auto_io_out_dq_0_i = VL_RAND_RESET_I(1);
    __Vcellinp__TLSPI__auto_control_xing_in_d_ready = VL_RAND_RESET_I(1);
    __Vcellinp__TLSPI__auto_control_xing_in_a_bits_corrupt = VL_RAND_RESET_I(1);
    __Vcellinp__TLSPI__auto_control_xing_in_a_bits_data = VL_RAND_RESET_I(32);
    __Vcellinp__TLSPI__auto_control_xing_in_a_bits_mask = VL_RAND_RESET_I(4);
    __Vcellinp__TLSPI__auto_control_xing_in_a_bits_address = VL_RAND_RESET_I(29);
    __Vcellinp__TLSPI__auto_control_xing_in_a_bits_source = VL_RAND_RESET_I(6);
    __Vcellinp__TLSPI__auto_control_xing_in_a_bits_size = VL_RAND_RESET_I(2);
    __Vcellinp__TLSPI__auto_control_xing_in_a_bits_param = VL_RAND_RESET_I(3);
    __Vcellinp__TLSPI__auto_control_xing_in_a_bits_opcode = VL_RAND_RESET_I(3);
    __Vcellinp__TLSPI__auto_control_xing_in_a_valid = VL_RAND_RESET_I(1);
    __Vcellinp__TLSPI__reset = VL_RAND_RESET_I(1);
    __Vcellinp__TLSPI__clock = VL_RAND_RESET_I(1);
    TLSPI__DOT__fifo_io_tx_valid = VL_RAND_RESET_I(1);
    TLSPI__DOT__fifo_io_ip_txwm = VL_RAND_RESET_I(1);
    TLSPI__DOT__fifo_io_ip_rxwm = VL_RAND_RESET_I(1);
    TLSPI__DOT__mac_io_link_tx_ready = VL_RAND_RESET_I(1);
    TLSPI__DOT__ctrl_fmt_proto = VL_RAND_RESET_I(2);
    TLSPI__DOT__ctrl_fmt_endian = VL_RAND_RESET_I(1);
    TLSPI__DOT__ctrl_fmt_iodir = VL_RAND_RESET_I(1);
    TLSPI__DOT__ctrl_fmt_len = VL_RAND_RESET_I(4);
    TLSPI__DOT__ctrl_sck_div = VL_RAND_RESET_I(12);
    TLSPI__DOT__ctrl_sck_pol = VL_RAND_RESET_I(1);
    TLSPI__DOT__ctrl_sck_pha = VL_RAND_RESET_I(1);
    TLSPI__DOT__ctrl_cs_id = VL_RAND_RESET_I(2);
    TLSPI__DOT__ctrl_cs_dflt_0 = VL_RAND_RESET_I(1);
    TLSPI__DOT__ctrl_cs_dflt_1 = VL_RAND_RESET_I(1);
    TLSPI__DOT__ctrl_cs_dflt_2 = VL_RAND_RESET_I(1);
    TLSPI__DOT__ctrl_cs_dflt_3 = VL_RAND_RESET_I(1);
    TLSPI__DOT__ctrl_cs_mode = VL_RAND_RESET_I(2);
    TLSPI__DOT__ctrl_dla_cssck = VL_RAND_RESET_I(8);
    TLSPI__DOT__ctrl_dla_sckcs = VL_RAND_RESET_I(8);
    TLSPI__DOT__ctrl_dla_intercs = VL_RAND_RESET_I(8);
    TLSPI__DOT__ctrl_dla_interxfr = VL_RAND_RESET_I(8);
    TLSPI__DOT__ctrl_wm_tx = VL_RAND_RESET_I(4);
    TLSPI__DOT__ctrl_wm_rx = VL_RAND_RESET_I(4);
    TLSPI__DOT__ie_txwm = VL_RAND_RESET_I(1);
    TLSPI__DOT__ie_rxwm = VL_RAND_RESET_I(1);
    TLSPI__DOT___T_426 = VL_RAND_RESET_I(8);
    TLSPI__DOT___T_626 = VL_RAND_RESET_I(32);
    TLSPI__DOT___T_1495 = VL_RAND_RESET_I(1);
    TLSPI__DOT___T_1732 = VL_RAND_RESET_I(1);
    TLSPI__DOT___T_1766 = VL_RAND_RESET_I(1);
    TLSPI__DOT___T_1796 = VL_RAND_RESET_I(1);
    TLSPI__DOT___T_1742 = VL_RAND_RESET_I(1);
    TLSPI__DOT___T_1904 = VL_RAND_RESET_I(1);
    TLSPI__DOT___T_1844 = VL_RAND_RESET_I(1);
    TLSPI__DOT___T_1832 = VL_RAND_RESET_I(1);
    TLSPI__DOT___T_1802 = VL_RAND_RESET_I(1);
    TLSPI__DOT___GEN_155 = VL_RAND_RESET_I(1);
    TLSPI__DOT___GEN_162 = VL_RAND_RESET_I(1);
    TLSPI__DOT___GEN_172 = VL_RAND_RESET_I(32);
    TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_52 = VL_RAND_RESET_I(1);
    TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_55 = VL_RAND_RESET_I(1);
    TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_73 = VL_RAND_RESET_I(4);
    TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_97 = VL_RAND_RESET_I(1);
    TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_167 = VL_RAND_RESET_I(1);
    TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_181 = VL_RAND_RESET_I(1);
    TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_245 = VL_RAND_RESET_I(1);
    TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_486 = VL_RAND_RESET_I(1);
    TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_496 = VL_RAND_RESET_I(1);
    TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_499 = VL_RAND_RESET_I(1);
    TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_500 = VL_RAND_RESET_I(1);
    TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_509 = VL_RAND_RESET_I(3);
    TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_511 = VL_RAND_RESET_I(3);
    TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_513 = VL_RAND_RESET_I(2);
    TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_515 = VL_RAND_RESET_I(6);
    TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_517 = VL_RAND_RESET_I(29);
    TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_522 = VL_RAND_RESET_I(1);
    TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_526 = VL_RAND_RESET_I(1);
    TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_530 = VL_RAND_RESET_I(1);
    TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_534 = VL_RAND_RESET_I(1);
    TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_538 = VL_RAND_RESET_I(1);
    TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_541 = VL_RAND_RESET_I(1);
    TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_542 = VL_RAND_RESET_I(1);
    TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_551 = VL_RAND_RESET_I(1);
    TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_554 = VL_RAND_RESET_I(1);
    TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_555 = VL_RAND_RESET_I(1);
    TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_564 = VL_RAND_RESET_I(3);
    TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_568 = VL_RAND_RESET_I(2);
    TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_570 = VL_RAND_RESET_I(6);
    TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_579 = VL_RAND_RESET_I(1);
    TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_587 = VL_RAND_RESET_I(1);
    TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_591 = VL_RAND_RESET_I(1);
    TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_602 = VL_RAND_RESET_I(1);
    TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_604 = VL_RAND_RESET_Q(64);
    TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_615 = VL_RAND_RESET_I(1);
    TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_618 = VL_RAND_RESET_I(1);
    TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_619 = VL_RAND_RESET_I(1);
    TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_636 = VL_RAND_RESET_I(1);
    TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_639 = VL_RAND_RESET_I(1);
    TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_640 = VL_RAND_RESET_I(1);
    TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_658 = VL_RAND_RESET_I(1);
    TLSPI__DOT__buffer__DOT__TLMonitor__DOT___GEN_15 = VL_RAND_RESET_Q(64);
    TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_673 = VL_RAND_RESET_I(1);
    TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_677 = VL_RAND_RESET_Q(64);
    TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_679 = VL_RAND_RESET_I(32);
    TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_687 = VL_RAND_RESET_I(1);
    TLSPI__DOT__buffer__DOT__TLMonitor__DOT___T_690 = VL_RAND_RESET_I(32);
    TLSPI__DOT__buffer__DOT__TLMonitor__DOT__plusarg_reader__DOT__myplus = VL_RAND_RESET_I(32);
    TLSPI__DOT__intsource__DOT__AsyncResetRegVec_w1_i0__DOT__reg_0_q = VL_RAND_RESET_I(1);
    TLSPI__DOT__TLMonitor__DOT___T_52 = VL_RAND_RESET_I(1);
    TLSPI__DOT__TLMonitor__DOT___T_55 = VL_RAND_RESET_I(1);
    TLSPI__DOT__TLMonitor__DOT___T_73 = VL_RAND_RESET_I(4);
    TLSPI__DOT__TLMonitor__DOT___T_97 = VL_RAND_RESET_I(1);
    TLSPI__DOT__TLMonitor__DOT___T_167 = VL_RAND_RESET_I(1);
    TLSPI__DOT__TLMonitor__DOT___T_181 = VL_RAND_RESET_I(1);
    TLSPI__DOT__TLMonitor__DOT___T_245 = VL_RAND_RESET_I(1);
    TLSPI__DOT__TLMonitor__DOT___T_486 = VL_RAND_RESET_I(1);
    TLSPI__DOT__TLMonitor__DOT___T_496 = VL_RAND_RESET_I(1);
    TLSPI__DOT__TLMonitor__DOT___T_499 = VL_RAND_RESET_I(1);
    TLSPI__DOT__TLMonitor__DOT___T_500 = VL_RAND_RESET_I(1);
    TLSPI__DOT__TLMonitor__DOT___T_509 = VL_RAND_RESET_I(3);
    TLSPI__DOT__TLMonitor__DOT___T_511 = VL_RAND_RESET_I(3);
    TLSPI__DOT__TLMonitor__DOT___T_513 = VL_RAND_RESET_I(2);
    TLSPI__DOT__TLMonitor__DOT___T_515 = VL_RAND_RESET_I(6);
    TLSPI__DOT__TLMonitor__DOT___T_517 = VL_RAND_RESET_I(29);
    TLSPI__DOT__TLMonitor__DOT___T_522 = VL_RAND_RESET_I(1);
    TLSPI__DOT__TLMonitor__DOT___T_526 = VL_RAND_RESET_I(1);
    TLSPI__DOT__TLMonitor__DOT___T_530 = VL_RAND_RESET_I(1);
    TLSPI__DOT__TLMonitor__DOT___T_534 = VL_RAND_RESET_I(1);
    TLSPI__DOT__TLMonitor__DOT___T_538 = VL_RAND_RESET_I(1);
    TLSPI__DOT__TLMonitor__DOT___T_541 = VL_RAND_RESET_I(1);
    TLSPI__DOT__TLMonitor__DOT___T_542 = VL_RAND_RESET_I(1);
    TLSPI__DOT__TLMonitor__DOT___T_551 = VL_RAND_RESET_I(1);
    TLSPI__DOT__TLMonitor__DOT___T_554 = VL_RAND_RESET_I(1);
    TLSPI__DOT__TLMonitor__DOT___T_555 = VL_RAND_RESET_I(1);
    TLSPI__DOT__TLMonitor__DOT___T_564 = VL_RAND_RESET_I(3);
    TLSPI__DOT__TLMonitor__DOT___T_568 = VL_RAND_RESET_I(2);
    TLSPI__DOT__TLMonitor__DOT___T_570 = VL_RAND_RESET_I(6);
    TLSPI__DOT__TLMonitor__DOT___T_579 = VL_RAND_RESET_I(1);
    TLSPI__DOT__TLMonitor__DOT___T_587 = VL_RAND_RESET_I(1);
    TLSPI__DOT__TLMonitor__DOT___T_591 = VL_RAND_RESET_I(1);
    TLSPI__DOT__TLMonitor__DOT___T_602 = VL_RAND_RESET_I(1);
    TLSPI__DOT__TLMonitor__DOT___T_604 = VL_RAND_RESET_Q(64);
    TLSPI__DOT__TLMonitor__DOT___T_615 = VL_RAND_RESET_I(1);
    TLSPI__DOT__TLMonitor__DOT___T_618 = VL_RAND_RESET_I(1);
    TLSPI__DOT__TLMonitor__DOT___T_619 = VL_RAND_RESET_I(1);
    TLSPI__DOT__TLMonitor__DOT___T_636 = VL_RAND_RESET_I(1);
    TLSPI__DOT__TLMonitor__DOT___T_639 = VL_RAND_RESET_I(1);
    TLSPI__DOT__TLMonitor__DOT___T_640 = VL_RAND_RESET_I(1);
    TLSPI__DOT__TLMonitor__DOT___T_658 = VL_RAND_RESET_I(1);
    TLSPI__DOT__TLMonitor__DOT___GEN_15 = VL_RAND_RESET_Q(64);
    TLSPI__DOT__TLMonitor__DOT___T_673 = VL_RAND_RESET_I(1);
    TLSPI__DOT__TLMonitor__DOT___T_677 = VL_RAND_RESET_Q(64);
    TLSPI__DOT__TLMonitor__DOT___T_679 = VL_RAND_RESET_I(32);
    TLSPI__DOT__TLMonitor__DOT___T_687 = VL_RAND_RESET_I(1);
    TLSPI__DOT__TLMonitor__DOT___T_690 = VL_RAND_RESET_I(32);
    TLSPI__DOT__TLMonitor__DOT__plusarg_reader__DOT__myplus = VL_RAND_RESET_I(32);
    TLSPI__DOT__fifo__DOT__rxq_io_enq_valid = VL_RAND_RESET_I(1);
    TLSPI__DOT__fifo__DOT__rxen = VL_RAND_RESET_I(1);
    TLSPI__DOT__fifo__DOT___T_57 = VL_RAND_RESET_I(4);
    TLSPI__DOT__fifo__DOT__cs_mode = VL_RAND_RESET_I(2);
    {
        int __Vi0 = 0;
        for (; __Vi0 < 8; ++__Vi0) {
            TLSPI__DOT__fifo__DOT__txq__DOT___T_35[__Vi0] = VL_RAND_RESET_I(8);
        }
    }
    TLSPI__DOT__fifo__DOT__txq__DOT___T_35___05FT_58_data = VL_RAND_RESET_I(8);
    TLSPI__DOT__fifo__DOT__txq__DOT__value = VL_RAND_RESET_I(3);
    TLSPI__DOT__fifo__DOT__txq__DOT__value_1 = VL_RAND_RESET_I(3);
    TLSPI__DOT__fifo__DOT__txq__DOT___T_39 = VL_RAND_RESET_I(1);
    TLSPI__DOT__fifo__DOT__txq__DOT___T_40 = VL_RAND_RESET_I(1);
    TLSPI__DOT__fifo__DOT__txq__DOT___T_42 = VL_RAND_RESET_I(1);
    TLSPI__DOT__fifo__DOT__txq__DOT___T_43 = VL_RAND_RESET_I(1);
    TLSPI__DOT__fifo__DOT__txq__DOT___T_44 = VL_RAND_RESET_I(1);
    TLSPI__DOT__fifo__DOT__txq__DOT___T_47 = VL_RAND_RESET_I(1);
    TLSPI__DOT__fifo__DOT__txq__DOT___T_52 = VL_RAND_RESET_I(3);
    TLSPI__DOT__fifo__DOT__txq__DOT___T_54 = VL_RAND_RESET_I(3);
    {
        int __Vi0 = 0;
        for (; __Vi0 < 8; ++__Vi0) {
            TLSPI__DOT__fifo__DOT__rxq__DOT___T_35[__Vi0] = VL_RAND_RESET_I(8);
        }
    }
    TLSPI__DOT__fifo__DOT__rxq__DOT__value = VL_RAND_RESET_I(3);
    TLSPI__DOT__fifo__DOT__rxq__DOT__value_1 = VL_RAND_RESET_I(3);
    TLSPI__DOT__fifo__DOT__rxq__DOT___T_39 = VL_RAND_RESET_I(1);
    TLSPI__DOT__fifo__DOT__rxq__DOT___T_40 = VL_RAND_RESET_I(1);
    TLSPI__DOT__fifo__DOT__rxq__DOT___T_42 = VL_RAND_RESET_I(1);
    TLSPI__DOT__fifo__DOT__rxq__DOT___T_43 = VL_RAND_RESET_I(1);
    TLSPI__DOT__fifo__DOT__rxq__DOT___T_44 = VL_RAND_RESET_I(1);
    TLSPI__DOT__fifo__DOT__rxq__DOT___T_47 = VL_RAND_RESET_I(1);
    TLSPI__DOT__fifo__DOT__rxq__DOT___T_52 = VL_RAND_RESET_I(3);
    TLSPI__DOT__fifo__DOT__rxq__DOT___T_54 = VL_RAND_RESET_I(3);
    TLSPI__DOT__mac__DOT__phy_io_op_valid = VL_RAND_RESET_I(1);
    TLSPI__DOT__mac__DOT__phy_io_op_bits_fn = VL_RAND_RESET_I(1);
    TLSPI__DOT__mac__DOT__phy_io_op_bits_stb = VL_RAND_RESET_I(1);
    TLSPI__DOT__mac__DOT__phy_io_op_bits_cnt = VL_RAND_RESET_I(8);
    TLSPI__DOT__mac__DOT__cs_id = VL_RAND_RESET_I(2);
    TLSPI__DOT__mac__DOT__cs_dflt_0 = VL_RAND_RESET_I(1);
    TLSPI__DOT__mac__DOT__cs_dflt_1 = VL_RAND_RESET_I(1);
    TLSPI__DOT__mac__DOT__cs_dflt_2 = VL_RAND_RESET_I(1);
    TLSPI__DOT__mac__DOT__cs_dflt_3 = VL_RAND_RESET_I(1);
    TLSPI__DOT__mac__DOT__cs_set = VL_RAND_RESET_I(1);
    TLSPI__DOT__mac__DOT___T_69 = VL_RAND_RESET_I(4);
    TLSPI__DOT__mac__DOT___T_88 = VL_RAND_RESET_I(4);
    TLSPI__DOT__mac__DOT__clear = VL_RAND_RESET_I(1);
    TLSPI__DOT__mac__DOT__cs_assert = VL_RAND_RESET_I(1);
    TLSPI__DOT__mac__DOT__cs_deassert = VL_RAND_RESET_I(1);
    TLSPI__DOT__mac__DOT___T_94 = VL_RAND_RESET_I(1);
    TLSPI__DOT__mac__DOT__state = VL_RAND_RESET_I(2);
    TLSPI__DOT__mac__DOT___T_97 = VL_RAND_RESET_I(1);
    TLSPI__DOT__mac__DOT___T_99 = VL_RAND_RESET_I(1);
    TLSPI__DOT__mac__DOT___T_102 = VL_RAND_RESET_I(1);
    TLSPI__DOT__mac__DOT___T_107 = VL_RAND_RESET_I(4);
    TLSPI__DOT__mac__DOT__phy__DOT__ctrl_sck_div = VL_RAND_RESET_I(12);
    TLSPI__DOT__mac__DOT__phy__DOT__ctrl_sck_pol = VL_RAND_RESET_I(1);
    TLSPI__DOT__mac__DOT__phy__DOT__ctrl_sck_pha = VL_RAND_RESET_I(1);
    TLSPI__DOT__mac__DOT__phy__DOT__ctrl_fmt_proto = VL_RAND_RESET_I(2);
    TLSPI__DOT__mac__DOT__phy__DOT__ctrl_fmt_endian = VL_RAND_RESET_I(1);
    TLSPI__DOT__mac__DOT__phy__DOT__ctrl_fmt_iodir = VL_RAND_RESET_I(1);
    TLSPI__DOT__mac__DOT__phy__DOT__setup_d = VL_RAND_RESET_I(1);
    TLSPI__DOT__mac__DOT__phy__DOT___T_42 = VL_RAND_RESET_I(1);
    TLSPI__DOT__mac__DOT__phy__DOT___T_43 = VL_RAND_RESET_I(1);
    TLSPI__DOT__mac__DOT__phy__DOT__sample_d = VL_RAND_RESET_I(1);
    TLSPI__DOT__mac__DOT__phy__DOT___T_44 = VL_RAND_RESET_I(1);
    TLSPI__DOT__mac__DOT__phy__DOT___T_45 = VL_RAND_RESET_I(1);
    TLSPI__DOT__mac__DOT__phy__DOT__last_d = VL_RAND_RESET_I(1);
    TLSPI__DOT__mac__DOT__phy__DOT__scnt = VL_RAND_RESET_I(8);
    TLSPI__DOT__mac__DOT__phy__DOT__tcnt = VL_RAND_RESET_I(12);
    TLSPI__DOT__mac__DOT__phy__DOT___T_47 = VL_RAND_RESET_I(12);
    TLSPI__DOT__mac__DOT__phy__DOT__sched = VL_RAND_RESET_I(1);
    TLSPI__DOT__mac__DOT__phy__DOT__sck = VL_RAND_RESET_I(1);
    TLSPI__DOT__mac__DOT__phy__DOT__cref = VL_RAND_RESET_I(1);
    TLSPI__DOT__mac__DOT__phy__DOT__cinv = VL_RAND_RESET_I(1);
    TLSPI__DOT__mac__DOT__phy__DOT__rxd = VL_RAND_RESET_I(4);
    TLSPI__DOT__mac__DOT__phy__DOT__buffer = VL_RAND_RESET_I(8);
    TLSPI__DOT__mac__DOT__phy__DOT___T_71 = VL_RAND_RESET_I(8);
    TLSPI__DOT__mac__DOT__phy__DOT__shift = VL_RAND_RESET_I(1);
    TLSPI__DOT__mac__DOT__phy__DOT___T_96 = VL_RAND_RESET_I(8);
    TLSPI__DOT__mac__DOT__phy__DOT__txd = VL_RAND_RESET_I(4);
    TLSPI__DOT__mac__DOT__phy__DOT___T_154 = VL_RAND_RESET_I(1);
    TLSPI__DOT__mac__DOT__phy__DOT___T_155 = VL_RAND_RESET_I(1);
    TLSPI__DOT__mac__DOT__phy__DOT__accept = VL_RAND_RESET_I(1);
    TLSPI__DOT__mac__DOT__phy__DOT__txd_in = VL_RAND_RESET_I(4);
    TLSPI__DOT__mac__DOT__phy__DOT___T_102 = VL_RAND_RESET_I(2);
    TLSPI__DOT__mac__DOT__phy__DOT__done = VL_RAND_RESET_I(1);
    TLSPI__DOT__mac__DOT__phy__DOT___T_156 = VL_RAND_RESET_I(1);
    TLSPI__DOT__mac__DOT__phy__DOT__xfr = VL_RAND_RESET_I(1);
    TLSPI__DOT__mac__DOT__phy__DOT___GEN_15 = VL_RAND_RESET_I(1);
    TLSPI__DOT__mac__DOT__phy__DOT___GEN_22 = VL_RAND_RESET_I(1);
    TLSPI__DOT__mac__DOT__phy__DOT___T_111 = VL_RAND_RESET_I(1);
    TLSPI__DOT__mac__DOT__phy__DOT__txen_2 = VL_RAND_RESET_I(1);
    TLSPI__DOT__mac__DOT__phy__DOT___T_128 = VL_RAND_RESET_I(1);
    TLSPI__DOT__mac__DOT__phy__DOT___T_148 = VL_RAND_RESET_I(1);
    TLSPI__DOT__mac__DOT__phy__DOT___GEN_13 = VL_RAND_RESET_I(1);
    TLSPI__DOT__mac__DOT__phy__DOT___GEN_16 = VL_RAND_RESET_I(12);
    __VinpClk__TOP____Vcellinp__TLSPI__reset = VL_RAND_RESET_I(1);
    __Vclklast__TOP____Vcellinp__TLSPI__clock = VL_RAND_RESET_I(1);
    __Vclklast__TOP____VinpClk__TOP____Vcellinp__TLSPI__reset = VL_RAND_RESET_I(1);
    __Vchglast__TOP____Vcellinp__TLSPI__reset = VL_RAND_RESET_I(1);
}
