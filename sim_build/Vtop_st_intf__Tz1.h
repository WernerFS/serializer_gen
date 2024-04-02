// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_ST_INTF__TZ1_H_
#define VERILATED_VTOP_ST_INTF__TZ1_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_st_intf__Tz1 final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ ready;
    CData/*0:0*/ valid;
    CData/*7:0*/ data;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop_st_intf__Tz1(Vtop__Syms* symsp, const char* v__name);
    ~Vtop_st_intf__Tz1();
    VL_UNCOPYABLE(Vtop_st_intf__Tz1);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const Vtop_st_intf__Tz1* obj);

#endif  // guard
