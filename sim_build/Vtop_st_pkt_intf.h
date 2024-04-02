// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_ST_PKT_INTF_H_
#define VERILATED_VTOP_ST_PKT_INTF_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_st_pkt_intf final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ ready;
    CData/*0:0*/ valid;
    CData/*0:0*/ sop;
    CData/*0:0*/ eop;
    CData/*1:0*/ len;
    IData/*31:0*/ data;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // PARAMETERS
    static constexpr IData/*31:0*/ WIDTH = 0x00000020U;

    // CONSTRUCTORS
    Vtop_st_pkt_intf(Vtop__Syms* symsp, const char* v__name);
    ~Vtop_st_pkt_intf();
    VL_UNCOPYABLE(Vtop_st_pkt_intf);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const Vtop_st_pkt_intf* obj);

#endif  // guard
