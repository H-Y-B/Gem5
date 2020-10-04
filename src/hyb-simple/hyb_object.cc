#include "hyb-simple/hyb_object.hh"

#include <iostream>

HybObject::HybObject(HybObjectParams *params) : SimObject(params), event([this]{processEvent();}, name()),latency(100),timesLeft(10)
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
