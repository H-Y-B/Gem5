#include "hyb-debug/hyb_debug.hh"

#include <iostream>
#include "debug/hybdebug.hh"

HybDebug::HybDebug(HybDebugParams *params) :
    SimObject(params)
{
    std::cout << "Hello World! From a HybDebug!" << std::endl;
    std::cout << "Hello World! From a HybDebug!" << std::endl;
    std::cout << "Hello World! From a HybDebug!" << std::endl;
    std::cout << "Hello World! From a HybDebug!" << std::endl;
    DPRINTF(hybdebug, " --debug-flags=hybdebug\n");
    DPRINTF(hybdebug, " --debug-flags=hybdebug\n");
    DPRINTF(hybdebug, " --debug-flags=hybdebug\n");
    DPRINTF(hybdebug, " --debug-flags=hybdebug\n");
    DPRINTF(hybdebug, " --debug-flags=hybdebug\n");

    if(DTRACE(hybdebug))
        std::cout << "DTRACE(hyb)=true" << std::endl;
    else
        std::cout << "DTRACE(hyb)=false" << std::endl;
    
}
HybDebug*
HybDebugParams::create()
{
    return new HybDebug(this);
}