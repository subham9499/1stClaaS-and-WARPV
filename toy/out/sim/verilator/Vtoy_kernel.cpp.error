// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtoy_kernel.h for the primary calling header

#include "Vtoy_kernel.h"
#include "Vtoy_kernel__Syms.h"

//==========

VL_CTOR_IMP(Vtoy_kernel) {
    Vtoy_kernel__Syms* __restrict vlSymsp = __VlSymsp = new Vtoy_kernel__Syms(this, name());
    Vtoy_kernel* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vtoy_kernel::__Vconfigure(Vtoy_kernel__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vtoy_kernel::~Vtoy_kernel() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void Vtoy_kernel::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtoy_kernel::eval\n"); );
    Vtoy_kernel__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtoy_kernel* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("../fpga/src/toy_kernel.sv", 2, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vtoy_kernel::_eval_initial_loop(Vtoy_kernel__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("../fpga/src/toy_kernel.sv", 2, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vtoy_kernel::_combo__TOP__1(Vtoy_kernel__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoy_kernel::_combo__TOP__1\n"); );
    Vtoy_kernel* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->in_ready = vlTOPp->out_ready;
    vlTOPp->out_avail = vlTOPp->in_avail;
    vlTOPp->out_data[0U] = ((IData)(1U) + vlTOPp->in_data[0U]);
    vlTOPp->out_data[1U] = ((IData)(1U) + vlTOPp->in_data[1U]);
    vlTOPp->out_data[2U] = ((IData)(1U) + vlTOPp->in_data[2U]);
    vlTOPp->out_data[3U] = ((IData)(1U) + vlTOPp->in_data[3U]);
    vlTOPp->out_data[4U] = ((IData)(1U) + vlTOPp->in_data[4U]);
    vlTOPp->out_data[5U] = ((IData)(1U) + vlTOPp->in_data[5U]);
    vlTOPp->out_data[6U] = ((IData)(1U) + vlTOPp->in_data[6U]);
    vlTOPp->out_data[7U] = ((IData)(1U) + vlTOPp->in_data[7U]);
    vlTOPp->out_data[8U] = ((IData)(1U) + vlTOPp->in_data[8U]);
    vlTOPp->out_data[9U] = ((IData)(1U) + vlTOPp->in_data[9U]);
    vlTOPp->out_data[0xaU] = ((IData)(1U) + vlTOPp->in_data[0xaU]);
    vlTOPp->out_data[0xbU] = ((IData)(1U) + vlTOPp->in_data[0xbU]);
    vlTOPp->out_data[0xcU] = ((IData)(1U) + vlTOPp->in_data[0xcU]);
    vlTOPp->out_data[0xdU] = ((IData)(1U) + vlTOPp->in_data[0xdU]);
    vlTOPp->out_data[0xeU] = ((IData)(1U) + vlTOPp->in_data[0xeU]);
    vlTOPp->out_data[0xfU] = ((IData)(1U) + vlTOPp->in_data[0xfU]);
}

void Vtoy_kernel::_eval(Vtoy_kernel__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoy_kernel::_eval\n"); );
    Vtoy_kernel* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

void Vtoy_kernel::_eval_initial(Vtoy_kernel__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoy_kernel::_eval_initial\n"); );
    Vtoy_kernel* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtoy_kernel::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoy_kernel::final\n"); );
    // Variables
    Vtoy_kernel__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtoy_kernel* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtoy_kernel::_eval_settle(Vtoy_kernel__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoy_kernel::_eval_settle\n"); );
    Vtoy_kernel* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

VL_INLINE_OPT QData Vtoy_kernel::_change_request(Vtoy_kernel__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoy_kernel::_change_request\n"); );
    Vtoy_kernel* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vtoy_kernel::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoy_kernel::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((in_avail & 0xfeU))) {
        Verilated::overWidthError("in_avail");}
    if (VL_UNLIKELY((out_ready & 0xfeU))) {
        Verilated::overWidthError("out_ready");}
}
#endif  // VL_DEBUG

void Vtoy_kernel::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoy_kernel::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    in_ready = VL_RAND_RESET_I(1);
    in_avail = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(512, in_data);
    out_ready = VL_RAND_RESET_I(1);
    out_avail = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(512, out_data);
    __Vm_traceActivity = 0;
}
