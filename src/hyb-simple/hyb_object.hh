#ifndef HYB_OBJECT_HH
#define HYB_OBJECT_HH

#include "params/HybObject.hh"
#include "sim/sim_object.hh"

class HybObject : public SimObject
{
  private:
    void processEvent();
    EventFunctionWrapper event;
    
    Tick latency;
    int timesLeft;

  public:
    HybObject(HybObjectParams *p);
    void startup();
};

#endif // HYB_OBJECT_HH
