riscv:
	scons build/RISCV/gem5.opt



riscv-hello:
	./build/RISCV/gem5.opt ./configs/example/se.py -x ./tests/test-progs/hello/bin/riscv/linux/hello
