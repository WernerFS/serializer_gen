// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop_st_intf__Tz1.h"

VL_ATTR_COLD void Vtop_st_intf__Tz1___ctor_var_reset(Vtop_st_intf__Tz1* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_st_intf__Tz1___ctor_var_reset\n"); );
    // Body
    vlSelf->ready = VL_RAND_RESET_I(1);
    vlSelf->valid = VL_RAND_RESET_I(1);
    vlSelf->data = VL_RAND_RESET_I(8);
}
