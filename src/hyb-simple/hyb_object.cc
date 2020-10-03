#include "hyb-simple/hyb_object.hh"

#include <iostream>

HybObject::HybObject(HybObjectParams *params) : SimObject(params)
{
    std::cout << "Hello World! From a HybObject!" << std::endl;
    std::cout << "Hello World! From a HybObject!" << std::endl;
    std::cout << "Hello World! From a HybObject!" << std::endl;
    std::cout << "Hello World! From a HybObject!" << std::endl;
    std::cout << "Hello World! From a HybObject!" << std::endl;
    std::cout << "Hello World! From a HybObject!" << std::endl;
    std::cout << "Hello World! From a HybObject!" << std::endl;
    std::cout << "Hello World! From a HybObject!" << std::endl;
}

HybObject*
HybObjectParams::create()
{
    return new HybObject(this);
}
