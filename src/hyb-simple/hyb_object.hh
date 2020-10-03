#ifndef HYB_OBJECT_HH
#define HYB_OBJECT_HH

#include "params/HybObject.hh"
#include "sim/sim_object.hh"

class HybObject : public SimObject
{
  public:
    HybObject(HybObjectParams *p);
};

#endif // HYB_OBJECT_HH
