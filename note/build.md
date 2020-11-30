# gem5 build

	python /usr/bin/scons build/RISCV/gem5.opt

	./build/RISCV/gem5.opt ./configs/myconfig/se.py -c ./tests/test-progs/hello/bin/riscv/linux/hello


options:
    * debug:
		has optimizations turned off. This ensures that variables won't be optimized out, functions won't be unexpectedly inlined, and control flow will not behave in surprising ways. That makes this version easier to work with in tools like gdb, but without optimizations this version is significantly slower than the others. You should choose it when using tools like gdb and valgrind and don't want any details obscured, but other wise more optimized versions are recommended.
    * opt:
		has optimizations turned on and debugging functionality like asserts and DPRINTFs left in. This gives a good balance between the speed of the simulation and insight into what's happening in case something goes wrong. This version is best in most circumstances.
	* fast:
		has optimizations turned on and debugging functionality compiled out. This pulls out all the stops performance wise, but does so at the expense of run time error checking and the ability to turn on debug output. This version is recommended if you're very confident everything is working correctly and want to get peak performance from the simulator.
	* prof:
		is similar to gem5.fast but also includes instrumentation that allows it to be used with the gprof profiling tool. This version is not needed very often, but can be used to identify the areas of gem5 that should be focused on to improve performance.
	* perf:
		also includes instrumentation, but does so using google perftools, allowing it to be profiled with google-pprof. This profiling version is complementary to gem5.prof, and can probably replace it for all Linux-based systems.

	ref link:

	https://stackoverflow.com/questions/59860091/how-to-increase-the-simulation-speed-of-a-gem5-run

	https://www.cnblogs.com/ztguang/p/12646462.html
