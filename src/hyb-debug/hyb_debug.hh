#ifndef _HYB_DEBUG_HH__
#define _HYB_DEBUG_HH_

#include "params/HybDebug.hh"
#include "sim/sim_object.hh"

class HybDebug : public SimObject
{
  public:
    HybDebug(HybDebugParams *p);
};

#endif // _HYB_DEBUG_HH__