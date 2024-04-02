// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop_st_pkt_intf.h"

// Parameter definitions for Vtop_st_pkt_intf
constexpr IData/*31:0*/ Vtop_st_pkt_intf::WIDTH;


void Vtop_st_pkt_intf___ctor_var_reset(Vtop_st_pkt_intf* vlSelf);

Vtop_st_pkt_intf::Vtop_st_pkt_intf(Vtop__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtop_st_pkt_intf___ctor_var_reset(this);
}

void Vtop_st_pkt_intf::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vtop_st_pkt_intf::~Vtop_st_pkt_intf() {
}
