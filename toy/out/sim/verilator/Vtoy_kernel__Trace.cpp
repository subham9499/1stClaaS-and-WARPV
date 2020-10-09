// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtoy_kernel__Syms.h"


//======================

void Vtoy_kernel::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vtoy_kernel* t = (Vtoy_kernel*)userthis;
    Vtoy_kernel__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
        t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void Vtoy_kernel::traceChgThis(Vtoy_kernel__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtoy_kernel* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vtoy_kernel::traceChgThis__2(Vtoy_kernel__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtoy_kernel* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+1,(vlTOPp->clk));
        vcdp->chgBit(c+9,(vlTOPp->reset));
        vcdp->chgBit(c+17,(vlTOPp->in_ready));
        vcdp->chgBit(c+25,(vlTOPp->in_avail));
        vcdp->chgArray(c+33,(vlTOPp->in_data),512);
        vcdp->chgBit(c+161,(vlTOPp->out_ready));
        vcdp->chgBit(c+169,(vlTOPp->out_avail));
        vcdp->chgArray(c+177,(vlTOPp->out_data),512);
    }
}
