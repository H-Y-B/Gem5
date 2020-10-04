from m5.params import *
from m5.SimObject import SimObject

class HybObject(SimObject):
    type = 'HybObject'
    cxx_header = "hyb-simple/hyb_object.hh"
    time_to_wait = Param.Latency("Time before firing the event")
    number_of_fires = Param.Int(10, "Number of times to fire the event before "
                                   "goodbye")