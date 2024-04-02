// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop_st_intf__Tz1.h"

void Vtop_st_intf__Tz1___ctor_var_reset(Vtop_st_intf__Tz1* vlSelf);

Vtop_st_intf__Tz1::Vtop_st_intf__Tz1(Vtop__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtop_st_intf__Tz1___ctor_var_reset(this);
}

void Vtop_st_intf__Tz1::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vtop_st_intf__Tz1::~Vtop_st_intf__Tz1() {
}
