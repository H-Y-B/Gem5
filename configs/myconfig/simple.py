# -*- coding: utf-8 -*-

#导入m5库以及我们编译的所有SimObjects
import m5
from m5.objects import *

system = System()

system.clk_domain = SrcClockDomain()
system.clk_domain.clock = '1GHz'
system.clk_domain.voltage_domain = VoltageDomain() #电压域的默认选项

system.mem_mode = 'timing'    #使用 timing 模式进行内存模拟
system.mem_ranges = [AddrRange('512MB')] #建立一个512MB大小的单一内存范围

system.cpu = TimingSimpleCPU()

#创建系统范围内存总线
system.membus = SystemXBar()


#将I-cache和D-cache端口直接连接到membus
system.cpu.icache_port = system.membus.slave
system.cpu.dcache_port = system.membus.slave

system.cpu.createInterruptController()
#system.cpu.interrupts[0].pio = system.membus.master
#system.cpu.interrupts[0].int_master = system.membus.slave
#system.cpu.interrupts[0].int_slave = system.membus.master

system.system_port = system.membus.slave

system.mem_ctrl = DDR3_1600_8x8()
system.mem_ctrl.range = system.mem_ranges[0]
system.mem_ctrl.port = system.membus.master

process = Process()
process.cmd = ['tests/test-progs/hello/bin/riscv/linux/hello']
system.cpu.workload = process
system.cpu.createThreads()

root = Root(full_system = False, system = system)
m5.instantiate()
print("--------------------------------------------------------------------------")
print("--------------------------------------------------------------------------")
print("Beginning simulation!")
exit_event = m5.simulate()
print("--------------------------------------------------------------------------")
print("--------------------------------------------------------------------------")
print('Exiting @ tick {} because {}'.format(m5.curTick(), exit_event.getCause()))
