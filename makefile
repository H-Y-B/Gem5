riscv:
	python	/usr/bin/scons build/RISCV/gem5.opt
	#scons build/RISCV/gem5.opt



riscv-hello:
	./build/RISCV/gem5.opt ./configs/example/se.py -c ./tests/test-progs/hello/bin/riscv/linux/hello
