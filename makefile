pwd=$(shell pwd)

spec_run=/home/huangyubiao-DomainA/arm-spec17-intrate-test-base-gnueabihf

spec17_mk=$(pwd)/util/spec17/run-test-base.mk


default: arm-hello

arm:
	python	/usr/bin/scons USE_HDF5=0 build/ARM/gem5.opt -j8
	#scons build/ARM/gem5.opt

arm-hello:
	./build/ARM/gem5.opt ./configs/example/se.py -c ./tests/test-progs/hello/bin/arm/linux/hello

include $(spec17_mk)

clean-build:
	rm -rf build/
clean-m5out:
	rm -rf m5out/
