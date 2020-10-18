spec_run=$(SPEC06_TEST_RUN)
config=se.py
riscv:
	python	/usr/bin/scons build/RISCV/gem5.opt -j8
	#scons build/RISCV/gem5.opt

riscv-hello:
	./build/RISCV/gem5.opt ./configs/myconfig/se.py -c ./tests/test-progs/hello/bin/riscv/linux/hello
riscv-hello-o3-pipeline:
	./build/RISCV/gem5.opt --debug-flags=O3PipeView --debug-start=10000 --debug-file=trace.out ./configs/myconfig/se.py --cpu-type=DerivO3CPU --caches -c ./tests/test-progs/hello/bin/riscv/linux/hello
o3-pipeview:
	util/o3-pipeview.py -c 500 -o pipeview.out --color m5out/trace.out
	#less -r pipeview.out


clean-build:
	rm -rf build/
clean-m5out:
	rm -rf m5out/

spec-400:
	./build/RISCV/gem5.opt ./configs/myconfig/se.py -c $(spec_run)/400.perlbench/perlbench_base.riscv -o "-I. -I$(spec_run)/lib $(spec_run)/attrs.pl"
spec-401:
	./build/RISCV/gem5.opt ./configs/myconfig/se.py --mem-size=1024MB -c $(spec_run)/401.bzip2/bzip2_base.riscv -o "$(spec_run)/401.bzip2/input.program 5"


#######################################################
#demo
#./build/RISCV/gem5.opt --debug-flags=MinorTiming --debug-file=trace.txt ./configs/myconfig/se.py --cpu-type=MinorCPU --caches  -c ./tests/test-progs/hello/bin/riscv/linux/hello
#python  /usr/bin/scons build/ALPHA/gem5.opt -j8