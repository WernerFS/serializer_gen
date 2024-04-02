// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop_st_pkt_intf.h"

std::string VL_TO_STRING(const Vtop_st_pkt_intf* obj) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_st_pkt_intf::VL_TO_STRING\n"); );
    // Body
    return (obj ? obj->name() : "null");
}
