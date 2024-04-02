// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtop___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgBit(oldp+0,(vlSelf->rst_n));
    bufp->chgBit(oldp+1,(vlSelf->clk));
    bufp->chgBit(oldp+2,(vlSelf->i_fields_field6_avail));
    bufp->chgIData(oldp+3,(vlSelf->i_fields_field6),32);
    bufp->chgBit(oldp+4,(vlSelf->i_fields_field7_avail));
    bufp->chgIData(oldp+5,(vlSelf->i_fields_field7),32);
    bufp->chgBit(oldp+6,(vlSelf->i_fields_field8_avail));
    bufp->chgIData(oldp+7,(vlSelf->i_fields_field8),32);
    bufp->chgBit(oldp+8,(vlSelf->i_fields_field9_avail));
    bufp->chgIData(oldp+9,(vlSelf->i_fields_field9),24);
    bufp->chgBit(oldp+10,(vlSelf->top_module__DOT__rst_n));
    bufp->chgBit(oldp+11,(vlSelf->top_module__DOT__clk));
    bufp->chgBit(oldp+12,(vlSelf->top_module__DOT__i_fields_field6_avail));
    bufp->chgIData(oldp+13,(vlSelf->top_module__DOT__i_fields_field6),32);
    bufp->chgBit(oldp+14,(vlSelf->top_module__DOT__i_fields_field7_avail));
    bufp->chgIData(oldp+15,(vlSelf->top_module__DOT__i_fields_field7),32);
    bufp->chgBit(oldp+16,(vlSelf->top_module__DOT__i_fields_field8_avail));
    bufp->chgIData(oldp+17,(vlSelf->top_module__DOT__i_fields_field8),32);
    bufp->chgBit(oldp+18,(vlSelf->top_module__DOT__i_fields_field9_avail));
    bufp->chgIData(oldp+19,(vlSelf->top_module__DOT__i_fields_field9),24);
    bufp->chgWData(oldp+20,(vlSelf->top_module__DOT__i_fields),124);
    bufp->chgBit(oldp+24,(vlSelf->top_module__DOT__st_encoder_inst__DOT__rst_n));
    bufp->chgBit(oldp+25,(vlSelf->top_module__DOT__st_encoder_inst__DOT__clk));
    bufp->chgWData(oldp+26,(vlSelf->top_module__DOT__st_encoder_inst__DOT__i_fields),124);
    bufp->chgCData(oldp+30,(vlSelf->top_module__DOT__st_encoder_inst__DOT__msg_type_supported),8);
    bufp->chgBit(oldp+31,(vlSelf->top_module__DOT__st_encoder_inst__DOT__sop));
    bufp->chgBit(oldp+32,(vlSelf->top_module__DOT__st_encoder_inst__DOT__eop));
    bufp->chgBit(oldp+33,(vlSelf->top_module__DOT__st_encoder_inst__DOT__valid));
    bufp->chgIData(oldp+34,(vlSelf->top_module__DOT__st_encoder_inst__DOT__data),32);
    bufp->chgCData(oldp+35,(vlSelf->top_module__DOT__st_encoder_inst__DOT__len),2);
    bufp->chgWData(oldp+36,(vlSelf->top_module__DOT__st_encoder_inst__DOT__fields_bytes),128);
    bufp->chgIData(oldp+40,(vlSelf->top_module__DOT__st_encoder_inst__DOT__counter),32);
    bufp->chgBit(oldp+41,(vlSelf->top_module__DOT__st_encoder_inst__DOT__pkt_valid));
    bufp->chgBit(oldp+42,(vlSelf->top_module__DOT__st_encoder_inst__DOT__field6_avail));
    bufp->chgBit(oldp+43,(vlSelf->top_module__DOT__st_encoder_inst__DOT__field7_avail));
    bufp->chgBit(oldp+44,(vlSelf->top_module__DOT__st_encoder_inst__DOT__field8_avail));
    bufp->chgBit(oldp+45,(vlSelf->top_module__DOT__st_encoder_inst__DOT__field9_avail));
    bufp->chgIData(oldp+46,(vlSelf->top_module__DOT__st_encoder_inst__DOT__state),32);
    bufp->chgIData(oldp+47,(vlSelf->top_module__DOT__st_encoder_inst__DOT__nextstate),32);
    bufp->chgBit(oldp+48,(vlSymsp->TOP__top_module__DOT__o_pkt_intf.ready));
    bufp->chgBit(oldp+49,(vlSymsp->TOP__top_module__DOT__o_pkt_intf.valid));
    bufp->chgBit(oldp+50,(vlSymsp->TOP__top_module__DOT__o_pkt_intf.sop));
    bufp->chgBit(oldp+51,(vlSymsp->TOP__top_module__DOT__o_pkt_intf.eop));
    bufp->chgIData(oldp+52,(vlSymsp->TOP__top_module__DOT__o_pkt_intf.data),32);
    bufp->chgCData(oldp+53,(vlSymsp->TOP__top_module__DOT__o_pkt_intf.len),2);
    bufp->chgBit(oldp+54,(vlSymsp->TOP__top_module__DOT__i_msg_intf.ready));
    bufp->chgBit(oldp+55,(vlSymsp->TOP__top_module__DOT__i_msg_intf.valid));
    bufp->chgCData(oldp+56,(vlSymsp->TOP__top_module__DOT__i_msg_intf.data),8);
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
