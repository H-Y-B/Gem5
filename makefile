x86:
	python /usr/bin/scons USE_HDF5=0 build/X86/gem5.opt -j12
x86-hello:
	./build/X86/gem5.opt ./configs/example/se.py -c ./test/test-progs/hello/bin/x86/linux/hello
