// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    // Body
    Vtop___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial__TOP\n"); );
    // Body
    vlSelf->top_module__DOT__st_encoder_inst__DOT__msg_type_supported = 4U;
    vlSelf->top_module__DOT__st_encoder_inst__DOT__fields_bytes[0U] = 0U;
    vlSelf->top_module__DOT__st_encoder_inst__DOT__fields_bytes[1U] = 0U;
    vlSelf->top_module__DOT__st_encoder_inst__DOT__fields_bytes[2U] = 0U;
    vlSelf->top_module__DOT__st_encoder_inst__DOT__fields_bytes[3U] = 0U;
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("/home/xikhari/Downloads/exercise_1.2/exercise/top.sv", 3, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtop___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtop___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vtop___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->rst_n = VL_RAND_RESET_I(1);
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->i_fields_field6_avail = VL_RAND_RESET_I(1);
    vlSelf->i_fields_field6 = VL_RAND_RESET_I(32);
    vlSelf->i_fields_field7_avail = VL_RAND_RESET_I(1);
    vlSelf->i_fields_field7 = VL_RAND_RESET_I(32);
    vlSelf->i_fields_field8_avail = VL_RAND_RESET_I(1);
    vlSelf->i_fields_field8 = VL_RAND_RESET_I(32);
    vlSelf->i_fields_field9_avail = VL_RAND_RESET_I(1);
    vlSelf->i_fields_field9 = VL_RAND_RESET_I(24);
    vlSelf->top_module__DOT__rst_n = VL_RAND_RESET_I(1);
    vlSelf->top_module__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->top_module__DOT__i_fields_field6_avail = VL_RAND_RESET_I(1);
    vlSelf->top_module__DOT__i_fields_field6 = VL_RAND_RESET_I(32);
    vlSelf->top_module__DOT__i_fields_field7_avail = VL_RAND_RESET_I(1);
    vlSelf->top_module__DOT__i_fields_field7 = VL_RAND_RESET_I(32);
    vlSelf->top_module__DOT__i_fields_field8_avail = VL_RAND_RESET_I(1);
    vlSelf->top_module__DOT__i_fields_field8 = VL_RAND_RESET_I(32);
    vlSelf->top_module__DOT__i_fields_field9_avail = VL_RAND_RESET_I(1);
    vlSelf->top_module__DOT__i_fields_field9 = VL_RAND_RESET_I(24);
    VL_RAND_RESET_W(124, vlSelf->top_module__DOT__i_fields);
    vlSelf->top_module__DOT__st_encoder_inst__DOT__rst_n = VL_RAND_RESET_I(1);
    vlSelf->top_module__DOT__st_encoder_inst__DOT__clk = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(124, vlSelf->top_module__DOT__st_encoder_inst__DOT__i_fields);
    vlSelf->top_module__DOT__st_encoder_inst__DOT__msg_type_supported = VL_RAND_RESET_I(8);
    vlSelf->top_module__DOT__st_encoder_inst__DOT__sop = VL_RAND_RESET_I(1);
    vlSelf->top_module__DOT__st_encoder_inst__DOT__eop = VL_RAND_RESET_I(1);
    vlSelf->top_module__DOT__st_encoder_inst__DOT__valid = VL_RAND_RESET_I(1);
    vlSelf->top_module__DOT__st_encoder_inst__DOT__data = VL_RAND_RESET_I(32);
    vlSelf->top_module__DOT__st_encoder_inst__DOT__len = VL_RAND_RESET_I(2);
    VL_RAND_RESET_W(128, vlSelf->top_module__DOT__st_encoder_inst__DOT__fields_bytes);
    vlSelf->top_module__DOT__st_encoder_inst__DOT__counter = VL_RAND_RESET_I(32);
    vlSelf->top_module__DOT__st_encoder_inst__DOT__pkt_valid = VL_RAND_RESET_I(1);
    vlSelf->top_module__DOT__st_encoder_inst__DOT__field6_avail = VL_RAND_RESET_I(1);
    vlSelf->top_module__DOT__st_encoder_inst__DOT__field7_avail = VL_RAND_RESET_I(1);
    vlSelf->top_module__DOT__st_encoder_inst__DOT__field8_avail = VL_RAND_RESET_I(1);
    vlSelf->top_module__DOT__st_encoder_inst__DOT__field9_avail = VL_RAND_RESET_I(1);
    vlSelf->top_module__DOT__st_encoder_inst__DOT__state = 0;
    vlSelf->top_module__DOT__st_encoder_inst__DOT__nextstate = 0;
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
}
