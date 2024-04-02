// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval_triggers__ico(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__ico\n"); );
    // Body
    vlSelf->__VicoTriggered.set(0U, (IData)(vlSelf->__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

VL_INLINE_OPT void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->top_module__DOT__i_fields_field6_avail 
        = vlSelf->i_fields_field6_avail;
    vlSelf->top_module__DOT__i_fields_field6 = vlSelf->i_fields_field6;
    vlSelf->top_module__DOT__i_fields_field7_avail 
        = vlSelf->i_fields_field7_avail;
    vlSelf->top_module__DOT__i_fields_field7 = vlSelf->i_fields_field7;
    vlSelf->top_module__DOT__i_fields_field8_avail 
        = vlSelf->i_fields_field8_avail;
    vlSelf->top_module__DOT__i_fields_field8 = vlSelf->i_fields_field8;
    vlSelf->top_module__DOT__i_fields_field9_avail 
        = vlSelf->i_fields_field9_avail;
    vlSelf->top_module__DOT__i_fields_field9 = vlSelf->i_fields_field9;
    vlSelf->top_module__DOT__rst_n = vlSelf->rst_n;
    vlSelf->top_module__DOT__clk = vlSelf->clk;
    if ((0U == vlSelf->top_module__DOT__st_encoder_inst__DOT__state)) {
        vlSelf->top_module__DOT__st_encoder_inst__DOT__sop = 0U;
        vlSelf->top_module__DOT__st_encoder_inst__DOT__len = 0U;
        vlSelf->top_module__DOT__st_encoder_inst__DOT__eop = 0U;
        vlSelf->top_module__DOT__st_encoder_inst__DOT__nextstate = 1U;
        vlSelf->top_module__DOT__st_encoder_inst__DOT__data = 0U;
        vlSelf->top_module__DOT__st_encoder_inst__DOT__valid = 0U;
        vlSelf->top_module__DOT__st_encoder_inst__DOT__pkt_valid = 0U;
    } else if ((1U == vlSelf->top_module__DOT__st_encoder_inst__DOT__state)) {
        vlSelf->top_module__DOT__st_encoder_inst__DOT__sop = 0U;
        vlSelf->top_module__DOT__st_encoder_inst__DOT__len = 0U;
        vlSelf->top_module__DOT__st_encoder_inst__DOT__eop = 0U;
        vlSelf->top_module__DOT__st_encoder_inst__DOT__data = 0U;
        vlSelf->top_module__DOT__st_encoder_inst__DOT__valid = 0U;
        vlSelf->top_module__DOT__st_encoder_inst__DOT__pkt_valid = 0U;
        if ((((IData)(vlSymsp->TOP__top_module__DOT__i_msg_intf.data) 
              == (IData)(vlSelf->top_module__DOT__st_encoder_inst__DOT__msg_type_supported)) 
             & (IData)(vlSymsp->TOP__top_module__DOT__i_msg_intf.valid))) {
            vlSelf->top_module__DOT__st_encoder_inst__DOT__nextstate = 2U;
            vlSelf->top_module__DOT__st_encoder_inst__DOT__pkt_valid = 1U;
        }
    } else {
        if ((2U != vlSelf->top_module__DOT__st_encoder_inst__DOT__state)) {
            if ((3U == vlSelf->top_module__DOT__st_encoder_inst__DOT__state)) {
                if (((IData)(vlSymsp->TOP__top_module__DOT__o_pkt_intf.ready) 
                     & (IData)(vlSelf->top_module__DOT__st_encoder_inst__DOT__field7_avail))) {
                    vlSelf->top_module__DOT__st_encoder_inst__DOT__sop = 1U;
                    vlSelf->top_module__DOT__st_encoder_inst__DOT__len = 0U;
                    vlSelf->top_module__DOT__st_encoder_inst__DOT__data 
                        = vlSelf->top_module__DOT__st_encoder_inst__DOT__fields_bytes[0U];
                }
                if ((1U & (~ ((IData)(vlSymsp->TOP__top_module__DOT__o_pkt_intf.ready) 
                              & (IData)(vlSelf->top_module__DOT__st_encoder_inst__DOT__field7_avail))))) {
                    vlSelf->top_module__DOT__st_encoder_inst__DOT__eop = 1U;
                }
                vlSelf->top_module__DOT__st_encoder_inst__DOT__valid 
                    = ((IData)(vlSymsp->TOP__top_module__DOT__o_pkt_intf.ready) 
                       & (IData)(vlSelf->top_module__DOT__st_encoder_inst__DOT__field7_avail));
            } else {
                if ((4U == vlSelf->top_module__DOT__st_encoder_inst__DOT__state)) {
                    vlSelf->top_module__DOT__st_encoder_inst__DOT__sop = 0U;
                    if ((1U & (~ ((IData)(vlSymsp->TOP__top_module__DOT__o_pkt_intf.ready) 
                                  & (IData)(vlSelf->top_module__DOT__st_encoder_inst__DOT__field8_avail))))) {
                        vlSelf->top_module__DOT__st_encoder_inst__DOT__eop = 1U;
                        vlSelf->top_module__DOT__st_encoder_inst__DOT__valid = 0U;
                    }
                    if (((IData)(vlSymsp->TOP__top_module__DOT__o_pkt_intf.ready) 
                         & (IData)(vlSelf->top_module__DOT__st_encoder_inst__DOT__field8_avail))) {
                        vlSelf->top_module__DOT__st_encoder_inst__DOT__data 
                            = vlSelf->top_module__DOT__st_encoder_inst__DOT__fields_bytes[1U];
                    }
                } else if ((5U == vlSelf->top_module__DOT__st_encoder_inst__DOT__state)) {
                    if ((1U & (~ ((IData)(vlSymsp->TOP__top_module__DOT__o_pkt_intf.ready) 
                                  & (IData)(vlSelf->top_module__DOT__st_encoder_inst__DOT__field9_avail))))) {
                        vlSelf->top_module__DOT__st_encoder_inst__DOT__eop = 1U;
                        vlSelf->top_module__DOT__st_encoder_inst__DOT__valid = 0U;
                    }
                    if (((IData)(vlSymsp->TOP__top_module__DOT__o_pkt_intf.ready) 
                         & (IData)(vlSelf->top_module__DOT__st_encoder_inst__DOT__field9_avail))) {
                        vlSelf->top_module__DOT__st_encoder_inst__DOT__data 
                            = vlSelf->top_module__DOT__st_encoder_inst__DOT__fields_bytes[2U];
                    }
                } else if ((6U == vlSelf->top_module__DOT__st_encoder_inst__DOT__state)) {
                    vlSelf->top_module__DOT__st_encoder_inst__DOT__eop = 1U;
                    if (vlSymsp->TOP__top_module__DOT__o_pkt_intf.ready) {
                        vlSelf->top_module__DOT__st_encoder_inst__DOT__data 
                            = ((0xff0000U & vlSelf->top_module__DOT__st_encoder_inst__DOT__fields_bytes[3U]) 
                               | (0xffffU & vlSelf->top_module__DOT__st_encoder_inst__DOT__fields_bytes[3U]));
                    }
                    if ((1U & (~ (IData)(vlSymsp->TOP__top_module__DOT__o_pkt_intf.ready)))) {
                        vlSelf->top_module__DOT__st_encoder_inst__DOT__valid = 0U;
                    }
                }
                if ((4U != vlSelf->top_module__DOT__st_encoder_inst__DOT__state)) {
                    if ((5U != vlSelf->top_module__DOT__st_encoder_inst__DOT__state)) {
                        if ((6U == vlSelf->top_module__DOT__st_encoder_inst__DOT__state)) {
                            if (vlSymsp->TOP__top_module__DOT__o_pkt_intf.ready) {
                                vlSelf->top_module__DOT__st_encoder_inst__DOT__len = 3U;
                            }
                        }
                    }
                }
            }
        }
        if ((2U == vlSelf->top_module__DOT__st_encoder_inst__DOT__state)) {
            vlSelf->top_module__DOT__st_encoder_inst__DOT__nextstate 
                = ((3U > vlSelf->top_module__DOT__st_encoder_inst__DOT__counter)
                    ? 2U : (((IData)(vlSymsp->TOP__top_module__DOT__o_pkt_intf.ready) 
                             & (IData)(vlSelf->top_module__DOT__st_encoder_inst__DOT__field6_avail))
                             ? 3U : 1U));
            if ((3U <= vlSelf->top_module__DOT__st_encoder_inst__DOT__counter)) {
                if ((1U & (~ ((IData)(vlSymsp->TOP__top_module__DOT__o_pkt_intf.ready) 
                              & (IData)(vlSelf->top_module__DOT__st_encoder_inst__DOT__field6_avail))))) {
                    vlSelf->top_module__DOT__st_encoder_inst__DOT__pkt_valid = 0U;
                }
            }
        } else if ((3U == vlSelf->top_module__DOT__st_encoder_inst__DOT__state)) {
            vlSelf->top_module__DOT__st_encoder_inst__DOT__nextstate 
                = (((IData)(vlSymsp->TOP__top_module__DOT__o_pkt_intf.ready) 
                    & (IData)(vlSelf->top_module__DOT__st_encoder_inst__DOT__field7_avail))
                    ? 4U : 1U);
            if ((1U & (~ ((IData)(vlSymsp->TOP__top_module__DOT__o_pkt_intf.ready) 
                          & (IData)(vlSelf->top_module__DOT__st_encoder_inst__DOT__field7_avail))))) {
                vlSelf->top_module__DOT__st_encoder_inst__DOT__pkt_valid = 0U;
            }
        } else if ((4U == vlSelf->top_module__DOT__st_encoder_inst__DOT__state)) {
            vlSelf->top_module__DOT__st_encoder_inst__DOT__nextstate 
                = (((IData)(vlSymsp->TOP__top_module__DOT__o_pkt_intf.ready) 
                    & (IData)(vlSelf->top_module__DOT__st_encoder_inst__DOT__field8_avail))
                    ? 5U : 1U);
            if ((1U & (~ ((IData)(vlSymsp->TOP__top_module__DOT__o_pkt_intf.ready) 
                          & (IData)(vlSelf->top_module__DOT__st_encoder_inst__DOT__field8_avail))))) {
                vlSelf->top_module__DOT__st_encoder_inst__DOT__pkt_valid = 0U;
            }
        } else if ((5U == vlSelf->top_module__DOT__st_encoder_inst__DOT__state)) {
            vlSelf->top_module__DOT__st_encoder_inst__DOT__nextstate 
                = (((IData)(vlSymsp->TOP__top_module__DOT__o_pkt_intf.ready) 
                    & (IData)(vlSelf->top_module__DOT__st_encoder_inst__DOT__field9_avail))
                    ? 6U : 1U);
            if ((1U & (~ ((IData)(vlSymsp->TOP__top_module__DOT__o_pkt_intf.ready) 
                          & (IData)(vlSelf->top_module__DOT__st_encoder_inst__DOT__field9_avail))))) {
                vlSelf->top_module__DOT__st_encoder_inst__DOT__pkt_valid = 0U;
            }
        } else if ((6U == vlSelf->top_module__DOT__st_encoder_inst__DOT__state)) {
            vlSelf->top_module__DOT__st_encoder_inst__DOT__nextstate = 1U;
            if ((1U & (~ (IData)(vlSymsp->TOP__top_module__DOT__o_pkt_intf.ready)))) {
                vlSelf->top_module__DOT__st_encoder_inst__DOT__pkt_valid = 0U;
            }
        }
    }
    vlSelf->top_module__DOT__i_fields[0U] = (IData)(
                                                    (((QData)((IData)(vlSelf->i_fields_field8_avail)) 
                                                      << 0x39U) 
                                                     | (((QData)((IData)(vlSelf->i_fields_field8)) 
                                                         << 0x19U) 
                                                        | (QData)((IData)(
                                                                          (((IData)(vlSelf->i_fields_field9_avail) 
                                                                            << 0x18U) 
                                                                           | vlSelf->i_fields_field9))))));
    vlSelf->top_module__DOT__i_fields[1U] = ((vlSelf->i_fields_field7 
                                              << 0x1aU) 
                                             | (IData)(
                                                       ((((QData)((IData)(vlSelf->i_fields_field8_avail)) 
                                                          << 0x39U) 
                                                         | (((QData)((IData)(vlSelf->i_fields_field8)) 
                                                             << 0x19U) 
                                                            | (QData)((IData)(
                                                                              (((IData)(vlSelf->i_fields_field9_avail) 
                                                                                << 0x18U) 
                                                                               | vlSelf->i_fields_field9))))) 
                                                        >> 0x20U)));
    vlSelf->top_module__DOT__i_fields[2U] = ((vlSelf->i_fields_field6 
                                              << 0x1bU) 
                                             | (((IData)(vlSelf->i_fields_field7_avail) 
                                                 << 0x1aU) 
                                                | (vlSelf->i_fields_field7 
                                                   >> 6U)));
    vlSelf->top_module__DOT__i_fields[3U] = (((IData)(vlSelf->i_fields_field6_avail) 
                                              << 0x1bU) 
                                             | (vlSelf->i_fields_field6 
                                                >> 5U));
    vlSelf->top_module__DOT__st_encoder_inst__DOT__rst_n 
        = vlSelf->top_module__DOT__rst_n;
    vlSelf->top_module__DOT__st_encoder_inst__DOT__clk 
        = vlSelf->top_module__DOT__clk;
    vlSymsp->TOP__top_module__DOT__o_pkt_intf.sop = vlSelf->top_module__DOT__st_encoder_inst__DOT__sop;
    vlSymsp->TOP__top_module__DOT__o_pkt_intf.len = vlSelf->top_module__DOT__st_encoder_inst__DOT__len;
    vlSymsp->TOP__top_module__DOT__o_pkt_intf.eop = vlSelf->top_module__DOT__st_encoder_inst__DOT__eop;
    vlSelf->top_module__DOT__st_encoder_inst__DOT__i_fields[0U] 
        = vlSelf->top_module__DOT__i_fields[0U];
    vlSelf->top_module__DOT__st_encoder_inst__DOT__i_fields[1U] 
        = vlSelf->top_module__DOT__i_fields[1U];
    vlSelf->top_module__DOT__st_encoder_inst__DOT__i_fields[2U] 
        = vlSelf->top_module__DOT__i_fields[2U];
    vlSelf->top_module__DOT__st_encoder_inst__DOT__i_fields[3U] 
        = vlSelf->top_module__DOT__i_fields[3U];
    if (vlSelf->top_module__DOT__st_encoder_inst__DOT__valid) {
        vlSymsp->TOP__top_module__DOT__o_pkt_intf.valid = 1U;
        vlSymsp->TOP__top_module__DOT__o_pkt_intf.data 
            = vlSelf->top_module__DOT__st_encoder_inst__DOT__data;
    } else {
        vlSymsp->TOP__top_module__DOT__o_pkt_intf.valid = 0U;
        vlSymsp->TOP__top_module__DOT__o_pkt_intf.data = 0U;
    }
    vlSymsp->TOP__top_module__DOT__i_msg_intf.ready 
        = (1U & (~ (IData)(vlSelf->top_module__DOT__st_encoder_inst__DOT__pkt_valid)));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, ((IData)(vlSelf->clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__clk__0))));
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__act(vlSelf);
    }
#endif
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    // Body
    if (vlSelf->rst_n) {
        vlSelf->top_module__DOT__st_encoder_inst__DOT__counter 
            = ((IData)(vlSelf->top_module__DOT__st_encoder_inst__DOT__pkt_valid)
                ? ((IData)(1U) + vlSelf->top_module__DOT__st_encoder_inst__DOT__counter)
                : 0U);
        if (((((IData)(vlSymsp->TOP__top_module__DOT__i_msg_intf.data) 
               == (IData)(vlSelf->top_module__DOT__st_encoder_inst__DOT__msg_type_supported)) 
              & (IData)(vlSymsp->TOP__top_module__DOT__i_msg_intf.valid)) 
             | (IData)(vlSelf->top_module__DOT__st_encoder_inst__DOT__pkt_valid))) {
            if ((0x8000000U & vlSelf->top_module__DOT__i_fields[3U])) {
                vlSelf->top_module__DOT__st_encoder_inst__DOT__fields_bytes[0U] 
                    = ((vlSelf->top_module__DOT__i_fields[3U] 
                        << 5U) | (vlSelf->top_module__DOT__i_fields[2U] 
                                  >> 0x1bU));
                vlSelf->top_module__DOT__st_encoder_inst__DOT__field6_avail = 1U;
            }
            if ((0x4000000U & vlSelf->top_module__DOT__i_fields[2U])) {
                vlSelf->top_module__DOT__st_encoder_inst__DOT__fields_bytes[1U] 
                    = ((vlSelf->top_module__DOT__i_fields[2U] 
                        << 6U) | (vlSelf->top_module__DOT__i_fields[1U] 
                                  >> 0x1aU));
                vlSelf->top_module__DOT__st_encoder_inst__DOT__field7_avail = 1U;
            }
            if ((0x2000000U & vlSelf->top_module__DOT__i_fields[1U])) {
                vlSelf->top_module__DOT__st_encoder_inst__DOT__fields_bytes[2U] 
                    = ((vlSelf->top_module__DOT__i_fields[1U] 
                        << 7U) | (vlSelf->top_module__DOT__i_fields[0U] 
                                  >> 0x19U));
                vlSelf->top_module__DOT__st_encoder_inst__DOT__field8_avail = 1U;
            }
            if ((0x1000000U & vlSelf->top_module__DOT__i_fields[0U])) {
                vlSelf->top_module__DOT__st_encoder_inst__DOT__fields_bytes[3U] 
                    = ((0xff000000U & vlSelf->top_module__DOT__st_encoder_inst__DOT__fields_bytes[3U]) 
                       | (0xffffffU & vlSelf->top_module__DOT__i_fields[0U]));
                vlSelf->top_module__DOT__st_encoder_inst__DOT__field9_avail = 1U;
            }
        } else {
            vlSelf->top_module__DOT__st_encoder_inst__DOT__field6_avail = 0U;
            vlSelf->top_module__DOT__st_encoder_inst__DOT__field8_avail = 0U;
            vlSelf->top_module__DOT__st_encoder_inst__DOT__field9_avail = 0U;
            vlSelf->top_module__DOT__st_encoder_inst__DOT__field7_avail = 0U;
        }
        vlSelf->top_module__DOT__st_encoder_inst__DOT__state 
            = vlSelf->top_module__DOT__st_encoder_inst__DOT__nextstate;
    } else {
        vlSelf->top_module__DOT__st_encoder_inst__DOT__counter = 0U;
        vlSelf->top_module__DOT__st_encoder_inst__DOT__field6_avail = 0U;
        vlSelf->top_module__DOT__st_encoder_inst__DOT__state = 0U;
        vlSelf->top_module__DOT__st_encoder_inst__DOT__field8_avail = 0U;
        vlSelf->top_module__DOT__st_encoder_inst__DOT__field9_avail = 0U;
        vlSelf->top_module__DOT__st_encoder_inst__DOT__field7_avail = 0U;
    }
    if ((0U == vlSelf->top_module__DOT__st_encoder_inst__DOT__state)) {
        vlSelf->top_module__DOT__st_encoder_inst__DOT__sop = 0U;
        vlSelf->top_module__DOT__st_encoder_inst__DOT__len = 0U;
        vlSelf->top_module__DOT__st_encoder_inst__DOT__eop = 0U;
        vlSelf->top_module__DOT__st_encoder_inst__DOT__nextstate = 1U;
        vlSelf->top_module__DOT__st_encoder_inst__DOT__data = 0U;
        vlSelf->top_module__DOT__st_encoder_inst__DOT__valid = 0U;
        vlSelf->top_module__DOT__st_encoder_inst__DOT__pkt_valid = 0U;
    } else if ((1U == vlSelf->top_module__DOT__st_encoder_inst__DOT__state)) {
        vlSelf->top_module__DOT__st_encoder_inst__DOT__sop = 0U;
        vlSelf->top_module__DOT__st_encoder_inst__DOT__len = 0U;
        vlSelf->top_module__DOT__st_encoder_inst__DOT__eop = 0U;
        vlSelf->top_module__DOT__st_encoder_inst__DOT__data = 0U;
        vlSelf->top_module__DOT__st_encoder_inst__DOT__valid = 0U;
        vlSelf->top_module__DOT__st_encoder_inst__DOT__pkt_valid = 0U;
        if ((((IData)(vlSymsp->TOP__top_module__DOT__i_msg_intf.data) 
              == (IData)(vlSelf->top_module__DOT__st_encoder_inst__DOT__msg_type_supported)) 
             & (IData)(vlSymsp->TOP__top_module__DOT__i_msg_intf.valid))) {
            vlSelf->top_module__DOT__st_encoder_inst__DOT__nextstate = 2U;
            vlSelf->top_module__DOT__st_encoder_inst__DOT__pkt_valid = 1U;
        }
    } else {
        if ((2U != vlSelf->top_module__DOT__st_encoder_inst__DOT__state)) {
            if ((3U == vlSelf->top_module__DOT__st_encoder_inst__DOT__state)) {
                if (((IData)(vlSymsp->TOP__top_module__DOT__o_pkt_intf.ready) 
                     & (IData)(vlSelf->top_module__DOT__st_encoder_inst__DOT__field7_avail))) {
                    vlSelf->top_module__DOT__st_encoder_inst__DOT__sop = 1U;
                    vlSelf->top_module__DOT__st_encoder_inst__DOT__len = 0U;
                    vlSelf->top_module__DOT__st_encoder_inst__DOT__data 
                        = vlSelf->top_module__DOT__st_encoder_inst__DOT__fields_bytes[0U];
                }
                if ((1U & (~ ((IData)(vlSymsp->TOP__top_module__DOT__o_pkt_intf.ready) 
                              & (IData)(vlSelf->top_module__DOT__st_encoder_inst__DOT__field7_avail))))) {
                    vlSelf->top_module__DOT__st_encoder_inst__DOT__eop = 1U;
                }
                vlSelf->top_module__DOT__st_encoder_inst__DOT__valid 
                    = ((IData)(vlSymsp->TOP__top_module__DOT__o_pkt_intf.ready) 
                       & (IData)(vlSelf->top_module__DOT__st_encoder_inst__DOT__field7_avail));
            } else {
                if ((4U == vlSelf->top_module__DOT__st_encoder_inst__DOT__state)) {
                    vlSelf->top_module__DOT__st_encoder_inst__DOT__sop = 0U;
                    if ((1U & (~ ((IData)(vlSymsp->TOP__top_module__DOT__o_pkt_intf.ready) 
                                  & (IData)(vlSelf->top_module__DOT__st_encoder_inst__DOT__field8_avail))))) {
                        vlSelf->top_module__DOT__st_encoder_inst__DOT__eop = 1U;
                        vlSelf->top_module__DOT__st_encoder_inst__DOT__valid = 0U;
                    }
                    if (((IData)(vlSymsp->TOP__top_module__DOT__o_pkt_intf.ready) 
                         & (IData)(vlSelf->top_module__DOT__st_encoder_inst__DOT__field8_avail))) {
                        vlSelf->top_module__DOT__st_encoder_inst__DOT__data 
                            = vlSelf->top_module__DOT__st_encoder_inst__DOT__fields_bytes[1U];
                    }
                } else if ((5U == vlSelf->top_module__DOT__st_encoder_inst__DOT__state)) {
                    if ((1U & (~ ((IData)(vlSymsp->TOP__top_module__DOT__o_pkt_intf.ready) 
                                  & (IData)(vlSelf->top_module__DOT__st_encoder_inst__DOT__field9_avail))))) {
                        vlSelf->top_module__DOT__st_encoder_inst__DOT__eop = 1U;
                        vlSelf->top_module__DOT__st_encoder_inst__DOT__valid = 0U;
                    }
                    if (((IData)(vlSymsp->TOP__top_module__DOT__o_pkt_intf.ready) 
                         & (IData)(vlSelf->top_module__DOT__st_encoder_inst__DOT__field9_avail))) {
                        vlSelf->top_module__DOT__st_encoder_inst__DOT__data 
                            = vlSelf->top_module__DOT__st_encoder_inst__DOT__fields_bytes[2U];
                    }
                } else if ((6U == vlSelf->top_module__DOT__st_encoder_inst__DOT__state)) {
                    vlSelf->top_module__DOT__st_encoder_inst__DOT__eop = 1U;
                    if (vlSymsp->TOP__top_module__DOT__o_pkt_intf.ready) {
                        vlSelf->top_module__DOT__st_encoder_inst__DOT__data 
                            = ((0xff0000U & vlSelf->top_module__DOT__st_encoder_inst__DOT__fields_bytes[3U]) 
                               | (0xffffU & vlSelf->top_module__DOT__st_encoder_inst__DOT__fields_bytes[3U]));
                    }
                    if ((1U & (~ (IData)(vlSymsp->TOP__top_module__DOT__o_pkt_intf.ready)))) {
                        vlSelf->top_module__DOT__st_encoder_inst__DOT__valid = 0U;
                    }
                }
                if ((4U != vlSelf->top_module__DOT__st_encoder_inst__DOT__state)) {
                    if ((5U != vlSelf->top_module__DOT__st_encoder_inst__DOT__state)) {
                        if ((6U == vlSelf->top_module__DOT__st_encoder_inst__DOT__state)) {
                            if (vlSymsp->TOP__top_module__DOT__o_pkt_intf.ready) {
                                vlSelf->top_module__DOT__st_encoder_inst__DOT__len = 3U;
                            }
                        }
                    }
                }
            }
        }
        if ((2U == vlSelf->top_module__DOT__st_encoder_inst__DOT__state)) {
            vlSelf->top_module__DOT__st_encoder_inst__DOT__nextstate 
                = ((3U > vlSelf->top_module__DOT__st_encoder_inst__DOT__counter)
                    ? 2U : (((IData)(vlSymsp->TOP__top_module__DOT__o_pkt_intf.ready) 
                             & (IData)(vlSelf->top_module__DOT__st_encoder_inst__DOT__field6_avail))
                             ? 3U : 1U));
            if ((3U <= vlSelf->top_module__DOT__st_encoder_inst__DOT__counter)) {
                if ((1U & (~ ((IData)(vlSymsp->TOP__top_module__DOT__o_pkt_intf.ready) 
                              & (IData)(vlSelf->top_module__DOT__st_encoder_inst__DOT__field6_avail))))) {
                    vlSelf->top_module__DOT__st_encoder_inst__DOT__pkt_valid = 0U;
                }
            }
        } else if ((3U == vlSelf->top_module__DOT__st_encoder_inst__DOT__state)) {
            vlSelf->top_module__DOT__st_encoder_inst__DOT__nextstate 
                = (((IData)(vlSymsp->TOP__top_module__DOT__o_pkt_intf.ready) 
                    & (IData)(vlSelf->top_module__DOT__st_encoder_inst__DOT__field7_avail))
                    ? 4U : 1U);
            if ((1U & (~ ((IData)(vlSymsp->TOP__top_module__DOT__o_pkt_intf.ready) 
                          & (IData)(vlSelf->top_module__DOT__st_encoder_inst__DOT__field7_avail))))) {
                vlSelf->top_module__DOT__st_encoder_inst__DOT__pkt_valid = 0U;
            }
        } else if ((4U == vlSelf->top_module__DOT__st_encoder_inst__DOT__state)) {
            vlSelf->top_module__DOT__st_encoder_inst__DOT__nextstate 
                = (((IData)(vlSymsp->TOP__top_module__DOT__o_pkt_intf.ready) 
                    & (IData)(vlSelf->top_module__DOT__st_encoder_inst__DOT__field8_avail))
                    ? 5U : 1U);
            if ((1U & (~ ((IData)(vlSymsp->TOP__top_module__DOT__o_pkt_intf.ready) 
                          & (IData)(vlSelf->top_module__DOT__st_encoder_inst__DOT__field8_avail))))) {
                vlSelf->top_module__DOT__st_encoder_inst__DOT__pkt_valid = 0U;
            }
        } else if ((5U == vlSelf->top_module__DOT__st_encoder_inst__DOT__state)) {
            vlSelf->top_module__DOT__st_encoder_inst__DOT__nextstate 
                = (((IData)(vlSymsp->TOP__top_module__DOT__o_pkt_intf.ready) 
                    & (IData)(vlSelf->top_module__DOT__st_encoder_inst__DOT__field9_avail))
                    ? 6U : 1U);
            if ((1U & (~ ((IData)(vlSymsp->TOP__top_module__DOT__o_pkt_intf.ready) 
                          & (IData)(vlSelf->top_module__DOT__st_encoder_inst__DOT__field9_avail))))) {
                vlSelf->top_module__DOT__st_encoder_inst__DOT__pkt_valid = 0U;
            }
        } else if ((6U == vlSelf->top_module__DOT__st_encoder_inst__DOT__state)) {
            vlSelf->top_module__DOT__st_encoder_inst__DOT__nextstate = 1U;
            if ((1U & (~ (IData)(vlSymsp->TOP__top_module__DOT__o_pkt_intf.ready)))) {
                vlSelf->top_module__DOT__st_encoder_inst__DOT__pkt_valid = 0U;
            }
        }
    }
    vlSymsp->TOP__top_module__DOT__o_pkt_intf.sop = vlSelf->top_module__DOT__st_encoder_inst__DOT__sop;
    vlSymsp->TOP__top_module__DOT__o_pkt_intf.len = vlSelf->top_module__DOT__st_encoder_inst__DOT__len;
    vlSymsp->TOP__top_module__DOT__o_pkt_intf.eop = vlSelf->top_module__DOT__st_encoder_inst__DOT__eop;
    if (vlSelf->top_module__DOT__st_encoder_inst__DOT__valid) {
        vlSymsp->TOP__top_module__DOT__o_pkt_intf.valid = 1U;
        vlSymsp->TOP__top_module__DOT__o_pkt_intf.data 
            = vlSelf->top_module__DOT__st_encoder_inst__DOT__data;
    } else {
        vlSymsp->TOP__top_module__DOT__o_pkt_intf.valid = 0U;
        vlSymsp->TOP__top_module__DOT__o_pkt_intf.data = 0U;
    }
    vlSymsp->TOP__top_module__DOT__i_msg_intf.ready 
        = (1U & (~ (IData)(vlSelf->top_module__DOT__st_encoder_inst__DOT__pkt_valid)));
}
