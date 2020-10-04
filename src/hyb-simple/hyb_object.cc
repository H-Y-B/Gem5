#include "hyb-simple/hyb_object.hh"

#include <iostream>

HybObject::HybObject(HybObjectParams *params) : SimObject(params), 
                                                event(*this),
                                                myName(params->name),                       
                                                latency(params->time_to_wait),
                                                timesLeft(params->number_of_fires)
{
    std::cout << "[HybObject 构造方法]" << std::endl;
}

void
HybObject::processEvent()
{
    timesLeft--;
    DPRINTFNR("[processEvent] Processing the event! %d left\n", timesLeft);

    if (timesLeft <= 0) {
        std::cout << "[processEvent] Done firing!" << std::endl;
    } else {
        schedule(event, curTick() + latency);
    }
}

void
HybObject::startup()
{
    schedule(event, latency);
}

HybObject*
HybObjectParams::create()
{
    return new HybObject(this);
}
