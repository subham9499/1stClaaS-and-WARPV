// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtoy_kernel__Syms.h"


//======================

void Vtoy_kernel::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&Vtoy_kernel::traceInit, &Vtoy_kernel::traceFull, &Vtoy_kernel::traceChg, this);
}
void Vtoy_kernel::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    Vtoy_kernel* t = (Vtoy_kernel*)userthis;
    Vtoy_kernel__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void Vtoy_kernel::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vtoy_kernel* t = (Vtoy_kernel*)userthis;
    Vtoy_kernel__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void Vtoy_kernel::traceInitThis(Vtoy_kernel__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtoy_kernel* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
        vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void Vtoy_kernel::traceFullThis(Vtoy_kernel__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtoy_kernel* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vtoy_kernel::traceInitThis__1(Vtoy_kernel__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtoy_kernel* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->declBit(c+1,"clk", false,-1);
        vcdp->declBit(c+9,"reset", false,-1);
        vcdp->declBit(c+17,"in_ready", false,-1);
        vcdp->declBit(c+25,"in_avail", false,-1);
        vcdp->declArray(c+33,"in_data", false,-1, 511,0);
        vcdp->declBit(c+161,"out_ready", false,-1);
        vcdp->declBit(c+169,"out_avail", false,-1);
        vcdp->declArray(c+177,"out_data", false,-1, 511,0);
        vcdp->declBus(c+305,"toy_kernel C_DATA_WIDTH", false,-1, 31,0);
        vcdp->declBit(c+1,"toy_kernel clk", false,-1);
        vcdp->declBit(c+9,"toy_kernel reset", false,-1);
        vcdp->declBit(c+17,"toy_kernel in_ready", false,-1);
        vcdp->declBit(c+25,"toy_kernel in_avail", false,-1);
        vcdp->declArray(c+33,"toy_kernel in_data", false,-1, 511,0);
        vcdp->declBit(c+161,"toy_kernel out_ready", false,-1);
        vcdp->declBit(c+169,"toy_kernel out_avail", false,-1);
        vcdp->declArray(c+177,"toy_kernel out_data", false,-1, 511,0);
    }
}

void Vtoy_kernel::traceFullThis__1(Vtoy_kernel__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtoy_kernel* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->fullBit(c+1,(vlTOPp->clk));
        vcdp->fullBit(c+9,(vlTOPp->reset));
        vcdp->fullBit(c+17,(vlTOPp->in_ready));
        vcdp->fullBit(c+25,(vlTOPp->in_avail));
        vcdp->fullArray(c+33,(vlTOPp->in_data),512);
        vcdp->fullBit(c+161,(vlTOPp->out_ready));
        vcdp->fullBit(c+169,(vlTOPp->out_avail));
        vcdp->fullArray(c+177,(vlTOPp->out_data),512);
        vcdp->fullBus(c+305,(0x200U),32);
    }
}
