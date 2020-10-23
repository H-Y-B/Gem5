# note

FS(Full system)

SE(Syscall emulation)



python脚本的参数配置

```python
#configs/common/Options.py
def addNoISAOptions(parser):
def addCommonOptions(parser):
def addSEOptions(parser):
def addFSOptions(parser)
```



System

```
#src/sim/System.py
```



Options: {
'redirects': [], 
'dist': None, 
'lpae': None, 
'l1i_assoc': 2, 
'dist_server_port': 2200, 
'bp_type': None, 
'prog_interval': None, 
'checkpoint_dir': None, 
'simpoint_profile': None, 
'param': [], 
'bench': None, 
'cpu_clock': '2GHz', 
'checkpoint_at_end': None, 
'work_cpus_checkpoint_count': None, 
'warmup_insts': None, 
'dist_sync_repeat': '0us', 
'l2cache': None, 
'work_begin_checkpoint_count': None, 
'maxtime': None, 
'indirect_bp_type': None, 
'init_param': 0, 
'cmd': '****/spec06-base-test-int/400.perlbench/perlbench_base.riscv', 
'mem_channels': 1, 
'output': '', 
'cacheline_size': 64, 
'work_item_id': None, 
'caches': None, 
'dist_sync_on_pseudo_op': None, 
'l1i_size': '32kB', 
'dist_server_name': '127.0.0.1', 
'dist_size': 0, 
'elastic_trace_en': None, 
'virtualisation': None, 
'smt': False, 
'num_dirs': 1, 
'maxinsts': None, 
'ethernet_linkdelay': '10us', 
'tlm_memory': None, 
'work_begin_exit_count': None,
'l3_size': '16MB', 
'num_l3caches': 1, 
'num_l2caches': 1, 
'options': '-I. -I****/spec06-base-test-int/400.perlbench/lib ****spec06-base-test-int/400.perlbench/attrs.pl', 
'simpoint_interval': 10000000, 
'inst_trace_file': '', 
'enable_dram_powerdown': None, 
'arm_iset': 'arm', 
'checkpoint_restore': None, 
'l1d_size': '64kB', 
'l2_size': '2MB', 
'take_checkpoints': None, 
'memchecker': None, 
'checker': None, 
'work_end_exit_count': None, 
'simpoint': False, 
'data_trace_file': '', 
'mem_ranks': None, 
'input': '', 
'at_instruction': False, 
'ruby': None, 
'standard_switch': None, 
'l1i_hwp_type': None, 
'external_memory_system': None, 
'l1d_assoc': 2, 
'dist_sync_start': '5200000000000t', 
'cpu_type': 'AtomicSimpleCPU', 
'work_end_checkpoint_count': None, 
'l2_assoc': 8, 
'abs_max_tick': 18446744073709551615L, 
'max_checkpoints': 5, 
'l3_assoc': 16, 
'chroot': None, 
'mem_size': '512MB', 
'spec_input': 'ref', 
'interp_dir': None, 
'is_switch': None, 
'env': '', 
'l1d_hwp_type': None, 
'restore_with_cpu': 'AtomicSimpleCPU', 
'initialize_only': False, 
'fast_forward': None, 
'take_simpoint_checkpoints': None, 
'dist_rank': 0, 
'restore_simpoint_checkpoint': None, 
'l2_hwp_type': None, 
'ethernet_linkspeed': '10Gbps', 
'sys_voltage': '1.0V', 
'errout': '', 
'sys_clock': '1GHz', 
'rel_max_tick': None, 
'mem_type': 'DDR3_1600_8x8', 
'repeat_switch': None, 
'num_work_ids': None, 
'num_cpus': 1, 
'work_begin_cpu_id_exit': None
}

