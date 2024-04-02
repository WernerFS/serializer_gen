// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"
class Vtop_st_intf__Tz1;
class Vtop_st_pkt_intf;


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final : public VerilatedModule {
  public:
    // CELLS
    Vtop_st_intf__Tz1* __PVT__top_module__DOT__i_msg_intf;
    Vtop_st_pkt_intf* __PVT__top_module__DOT__o_pkt_intf;

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst_n,0,0);
    VL_IN8(i_fields_field6_avail,0,0);
    VL_IN(i_fields_field6,31,0);
    VL_IN8(i_fields_field7_avail,0,0);
    VL_IN(i_fields_field7,31,0);
    VL_IN8(i_fields_field8_avail,0,0);
    VL_IN(i_fields_field8,31,0);
    VL_IN8(i_fields_field9_avail,0,0);
    VL_IN(i_fields_field9,23,0);
    CData/*0:0*/ top_module__DOT__rst_n;
    CData/*0:0*/ top_module__DOT__clk;
    CData/*0:0*/ top_module__DOT__i_fields_field6_avail;
    IData/*31:0*/ top_module__DOT__i_fields_field6;
    CData/*0:0*/ top_module__DOT__i_fields_field7_avail;
    IData/*31:0*/ top_module__DOT__i_fields_field7;
    CData/*0:0*/ top_module__DOT__i_fields_field8_avail;
    IData/*31:0*/ top_module__DOT__i_fields_field8;
    CData/*0:0*/ top_module__DOT__i_fields_field9_avail;
    IData/*23:0*/ top_module__DOT__i_fields_field9;
    CData/*0:0*/ top_module__DOT__st_encoder_inst__DOT__rst_n;
    CData/*0:0*/ top_module__DOT__st_encoder_inst__DOT__clk;
    CData/*7:0*/ top_module__DOT__st_encoder_inst__DOT__msg_type_supported;
    CData/*0:0*/ top_module__DOT__st_encoder_inst__DOT__sop;
    CData/*0:0*/ top_module__DOT__st_encoder_inst__DOT__eop;
    CData/*0:0*/ top_module__DOT__st_encoder_inst__DOT__valid;
    CData/*1:0*/ top_module__DOT__st_encoder_inst__DOT__len;
    CData/*0:0*/ top_module__DOT__st_encoder_inst__DOT__pkt_valid;
    CData/*0:0*/ top_module__DOT__st_encoder_inst__DOT__field6_avail;
    CData/*0:0*/ top_module__DOT__st_encoder_inst__DOT__field7_avail;
    CData/*0:0*/ top_module__DOT__st_encoder_inst__DOT__field8_avail;
    CData/*0:0*/ top_module__DOT__st_encoder_inst__DOT__field9_avail;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ top_module__DOT__st_encoder_inst__DOT__data;
    IData/*31:0*/ top_module__DOT__st_encoder_inst__DOT__counter;
    IData/*31:0*/ top_module__DOT__st_encoder_inst__DOT__state;
    IData/*31:0*/ top_module__DOT__st_encoder_inst__DOT__nextstate;
    IData/*31:0*/ __VactIterCount;
    VlWide<4>/*123:0*/ top_module__DOT__i_fields;
    VlWide<4>/*123:0*/ top_module__DOT__st_encoder_inst__DOT__i_fields;
    VlWide<4>/*127:0*/ top_module__DOT__st_encoder_inst__DOT__fields_bytes;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // PARAMETERS
    static constexpr IData/*31:0*/ top_module__DOT__WIDTH = 0x00000020U;
    static constexpr IData/*31:0*/ top_module__DOT__st_encoder_inst__DOT__WIDTH = 0x00000020U;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
