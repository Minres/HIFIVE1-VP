// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "VTLSPI__Syms.h"
#include "VTLSPI.h"

// FUNCTIONS
VTLSPI__Syms::VTLSPI__Syms(VTLSPI *topp, const char *namep)
// Setup locals
: __Vm_namep(namep)
, __Vm_didInit(false)
// Setup submodule names
{
    // Pointer to top level
    TOPp = topp;
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOPp->__Vconfigure(this, true);
    // Setup scope names
    __Vscope_TLSPI__TLMonitor.configure(this, name(), "TLSPI.TLMonitor");
    __Vscope_TLSPI__buffer__TLMonitor.configure(this, name(), "TLSPI.buffer.TLMonitor");
}
