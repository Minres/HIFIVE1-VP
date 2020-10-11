// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header

#ifndef _VTLSPI__Syms_H_
#define _VTLSPI__Syms_H_

#include "verilated_heavy.h"

// INCLUDE MODULE CLASSES
#include "VTLSPI.h"

// SYMS CLASS
class VTLSPI__Syms : public VerilatedSyms {
public:
    // LOCAL STATE
    const char *__Vm_namep;
    bool __Vm_didInit;

    // SUBCELL STATE
    VTLSPI *TOPp;

    // SCOPE NAMES
    VerilatedScope __Vscope_TLSPI__TLMonitor;
    VerilatedScope __Vscope_TLSPI__buffer__TLMonitor;

    // CREATORS
    VTLSPI__Syms(VTLSPI *topp, const char *namep);
    ~VTLSPI__Syms() {}

    // METHODS
    inline const char *name() { return __Vm_namep; }

} VL_ATTR_ALIGNED(64);

#endif // guard
