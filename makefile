spec_run=$(SPEC06_TEST_RUN)
config=se.py
riscv:
	python	/usr/bin/scons build/RISCV/gem5.opt
	#scons build/RISCV/gem5.opt

riscv-hello:
	./build/RISCV/gem5.opt ./configs/myconfig/se.py -c ./tests/test-progs/hello/bin/riscv/linux/hello


spec-400:
	./build/RISCV/gem5.opt ./configs/myconfig/se.py -c $(spec_run)/400.perlbench/perlbench_base.riscv -o "-I. -I$(spec_run)/lib $(spec_run)/attrs.pl"
spec-401:
	./build/RISCV/gem5.opt ./configs/myconfig/se.py --mem-size=1024MB -c $(spec_run)/401.bzip2/bzip2_base.riscv -o "$(spec_run)/401.bzip2/input.program 5"
