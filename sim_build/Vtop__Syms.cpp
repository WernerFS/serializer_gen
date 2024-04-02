// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__pch.h"
#include "Vtop.h"
#include "Vtop___024root.h"
#include "Vtop___024unit.h"
#include "Vtop_st_pkt_intf.h"
#include "Vtop_st_intf__Tz1.h"

// FUNCTIONS
Vtop__Syms::~Vtop__Syms()
{

    // Tear down scope hierarchy
    __Vhier.remove(0, &__Vscope_top_module);
    __Vhier.remove(&__Vscope_top_module, &__Vscope_top_module__i_msg_intf);
    __Vhier.remove(&__Vscope_top_module, &__Vscope_top_module__o_pkt_intf);
    __Vhier.remove(&__Vscope_top_module, &__Vscope_top_module__st_encoder_inst);

}

Vtop__Syms::Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
    , TOP__top_module__DOT__i_msg_intf{this, Verilated::catName(namep, "top_module.i_msg_intf")}
    , TOP__top_module__DOT__o_pkt_intf{this, Verilated::catName(namep, "top_module.o_pkt_intf")}
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.__PVT__top_module__DOT__i_msg_intf = &TOP__top_module__DOT__i_msg_intf;
    TOP.__PVT__top_module__DOT__o_pkt_intf = &TOP__top_module__DOT__o_pkt_intf;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP__top_module__DOT__i_msg_intf.__Vconfigure(true);
    TOP__top_module__DOT__o_pkt_intf.__Vconfigure(true);
    // Setup scopes
    __Vscope_TOP.configure(this, name(), "TOP", "TOP", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_top_module.configure(this, name(), "top_module", "top_module", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_top_module__i_msg_intf.configure(this, name(), "top_module.i_msg_intf", "i_msg_intf", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_top_module__o_pkt_intf.configure(this, name(), "top_module.o_pkt_intf", "o_pkt_intf", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_top_module__st_encoder_inst.configure(this, name(), "top_module.st_encoder_inst", "st_encoder_inst", -9, VerilatedScope::SCOPE_MODULE);

    // Set up scope hierarchy
    __Vhier.add(0, &__Vscope_top_module);
    __Vhier.add(&__Vscope_top_module, &__Vscope_top_module__i_msg_intf);
    __Vhier.add(&__Vscope_top_module, &__Vscope_top_module__o_pkt_intf);
    __Vhier.add(&__Vscope_top_module, &__Vscope_top_module__st_encoder_inst);

    // Setup export functions
    for (int __Vfinal = 0; __Vfinal < 2; ++__Vfinal) {
        __Vscope_TOP.varInsert(__Vfinal,"clk", &(TOP.clk), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"i_fields_field6", &(TOP.i_fields_field6), false, VLVT_UINT32,VLVD_IN|VLVF_PUB_RW,1, 31,0);
        __Vscope_TOP.varInsert(__Vfinal,"i_fields_field6_avail", &(TOP.i_fields_field6_avail), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"i_fields_field7", &(TOP.i_fields_field7), false, VLVT_UINT32,VLVD_IN|VLVF_PUB_RW,1, 31,0);
        __Vscope_TOP.varInsert(__Vfinal,"i_fields_field7_avail", &(TOP.i_fields_field7_avail), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"i_fields_field8", &(TOP.i_fields_field8), false, VLVT_UINT32,VLVD_IN|VLVF_PUB_RW,1, 31,0);
        __Vscope_TOP.varInsert(__Vfinal,"i_fields_field8_avail", &(TOP.i_fields_field8_avail), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"i_fields_field9", &(TOP.i_fields_field9), false, VLVT_UINT32,VLVD_IN|VLVF_PUB_RW,1, 23,0);
        __Vscope_TOP.varInsert(__Vfinal,"i_fields_field9_avail", &(TOP.i_fields_field9_avail), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"rst_n", &(TOP.rst_n), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_top_module.varInsert(__Vfinal,"WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.top_module__DOT__WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_top_module.varInsert(__Vfinal,"clk", &(TOP.top_module__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_top_module.varInsert(__Vfinal,"i_fields", &(TOP.top_module__DOT__i_fields), false, VLVT_WDATA,VLVD_NODIR|VLVF_PUB_RW,1 ,123,0);
        __Vscope_top_module.varInsert(__Vfinal,"i_fields_field6", &(TOP.top_module__DOT__i_fields_field6), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1, 31,0);
        __Vscope_top_module.varInsert(__Vfinal,"i_fields_field6_avail", &(TOP.top_module__DOT__i_fields_field6_avail), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_top_module.varInsert(__Vfinal,"i_fields_field7", &(TOP.top_module__DOT__i_fields_field7), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1, 31,0);
        __Vscope_top_module.varInsert(__Vfinal,"i_fields_field7_avail", &(TOP.top_module__DOT__i_fields_field7_avail), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_top_module.varInsert(__Vfinal,"i_fields_field8", &(TOP.top_module__DOT__i_fields_field8), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1, 31,0);
        __Vscope_top_module.varInsert(__Vfinal,"i_fields_field8_avail", &(TOP.top_module__DOT__i_fields_field8_avail), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_top_module.varInsert(__Vfinal,"i_fields_field9", &(TOP.top_module__DOT__i_fields_field9), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1, 23,0);
        __Vscope_top_module.varInsert(__Vfinal,"i_fields_field9_avail", &(TOP.top_module__DOT__i_fields_field9_avail), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_top_module.varInsert(__Vfinal,"rst_n", &(TOP.top_module__DOT__rst_n), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_top_module__i_msg_intf.varInsert(__Vfinal,"data", &(TOP__top_module__DOT__i_msg_intf.data), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,7,0);
        __Vscope_top_module__i_msg_intf.varInsert(__Vfinal,"ready", &(TOP__top_module__DOT__i_msg_intf.ready), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_top_module__i_msg_intf.varInsert(__Vfinal,"valid", &(TOP__top_module__DOT__i_msg_intf.valid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_top_module__o_pkt_intf.varInsert(__Vfinal,"WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP__top_module__DOT__o_pkt_intf.WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_top_module__o_pkt_intf.varInsert(__Vfinal,"data", &(TOP__top_module__DOT__o_pkt_intf.data), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_top_module__o_pkt_intf.varInsert(__Vfinal,"eop", &(TOP__top_module__DOT__o_pkt_intf.eop), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_top_module__o_pkt_intf.varInsert(__Vfinal,"len", &(TOP__top_module__DOT__o_pkt_intf.len), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,1,0);
        __Vscope_top_module__o_pkt_intf.varInsert(__Vfinal,"ready", &(TOP__top_module__DOT__o_pkt_intf.ready), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_top_module__o_pkt_intf.varInsert(__Vfinal,"sop", &(TOP__top_module__DOT__o_pkt_intf.sop), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_top_module__o_pkt_intf.varInsert(__Vfinal,"valid", &(TOP__top_module__DOT__o_pkt_intf.valid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_top_module__st_encoder_inst.varInsert(__Vfinal,"WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.top_module__DOT__st_encoder_inst__DOT__WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_top_module__st_encoder_inst.varInsert(__Vfinal,"clk", &(TOP.top_module__DOT__st_encoder_inst__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_top_module__st_encoder_inst.varInsert(__Vfinal,"counter", &(TOP.top_module__DOT__st_encoder_inst__DOT__counter), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_top_module__st_encoder_inst.varInsert(__Vfinal,"data", &(TOP.top_module__DOT__st_encoder_inst__DOT__data), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_top_module__st_encoder_inst.varInsert(__Vfinal,"eop", &(TOP.top_module__DOT__st_encoder_inst__DOT__eop), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_top_module__st_encoder_inst.varInsert(__Vfinal,"field6_avail", &(TOP.top_module__DOT__st_encoder_inst__DOT__field6_avail), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_top_module__st_encoder_inst.varInsert(__Vfinal,"field7_avail", &(TOP.top_module__DOT__st_encoder_inst__DOT__field7_avail), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_top_module__st_encoder_inst.varInsert(__Vfinal,"field8_avail", &(TOP.top_module__DOT__st_encoder_inst__DOT__field8_avail), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_top_module__st_encoder_inst.varInsert(__Vfinal,"field9_avail", &(TOP.top_module__DOT__st_encoder_inst__DOT__field9_avail), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_top_module__st_encoder_inst.varInsert(__Vfinal,"fields_bytes", &(TOP.top_module__DOT__st_encoder_inst__DOT__fields_bytes), false, VLVT_WDATA,VLVD_NODIR|VLVF_PUB_RW,1 ,127,0);
        __Vscope_top_module__st_encoder_inst.varInsert(__Vfinal,"i_fields", &(TOP.top_module__DOT__st_encoder_inst__DOT__i_fields), false, VLVT_WDATA,VLVD_NODIR|VLVF_PUB_RW,1 ,123,0);
        __Vscope_top_module__st_encoder_inst.varInsert(__Vfinal,"len", &(TOP.top_module__DOT__st_encoder_inst__DOT__len), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,1,0);
        __Vscope_top_module__st_encoder_inst.varInsert(__Vfinal,"msg_type_supported", &(TOP.top_module__DOT__st_encoder_inst__DOT__msg_type_supported), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,7,0);
        __Vscope_top_module__st_encoder_inst.varInsert(__Vfinal,"nextstate", &(TOP.top_module__DOT__st_encoder_inst__DOT__nextstate), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,1 ,31,0);
        __Vscope_top_module__st_encoder_inst.varInsert(__Vfinal,"pkt_valid", &(TOP.top_module__DOT__st_encoder_inst__DOT__pkt_valid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_top_module__st_encoder_inst.varInsert(__Vfinal,"rst_n", &(TOP.top_module__DOT__st_encoder_inst__DOT__rst_n), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_top_module__st_encoder_inst.varInsert(__Vfinal,"sop", &(TOP.top_module__DOT__st_encoder_inst__DOT__sop), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_top_module__st_encoder_inst.varInsert(__Vfinal,"state", &(TOP.top_module__DOT__st_encoder_inst__DOT__state), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,1 ,31,0);
        __Vscope_top_module__st_encoder_inst.varInsert(__Vfinal,"valid", &(TOP.top_module__DOT__st_encoder_inst__DOT__valid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
    }
}
