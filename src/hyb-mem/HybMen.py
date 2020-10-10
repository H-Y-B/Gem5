from m5.params import *
from m5.SimObject import SimObject


class HybMem(SimObject):
    type = 'HybMem'
    cxx_header = "hyb-mem/hyb_mem.hh"

    inst_port = SlavePort("CPU side port, receives requests")
    data_port = SlavePort("CPU side port, receives requests")
    mem_side = MasterPort("Memory side port, sends requests")