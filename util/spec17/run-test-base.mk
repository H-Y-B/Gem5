spec17-500-1:
	./build/ARM/gem5.opt ./configs/example/se.py -c $(spec_run)/500.perlbench_r/perlbench_r_base.arm64-64 -o "-I. -I$(spec_run)/500.perlbench_r/lib $(spec_run)/500.perlbench_r/makerand.pl"

spec17-500-2:
	./build/ARM/gem5.opt ./configs/example/se.py -c $(spec_run)/500.perlbench_r/perlbench_r_base.arm64-64 -o "-I. -I$(spec_run)/500.perlbench_r/lib $(spec_run)/500.perlbench_r/test.pl"

spec17-502:
	./build/ARM/gem5.opt ./configs/example/se.py -c $(spec_run)/502.gcc_r/cpugcc_r_base.arm64-64 -o "$(spec_run)/502.gcc_r/t1.c -O3 -finline-limit=50000"

spec17-505:
	./build/ARM/gem5.opt ./configs/example/se.py --mem-size=2048MB -c $(spec_run)/505.mcf_r/mcf_r_base.arm64-64 -o "$(spec_run)/505.mcf_r/inp.in"

spec17-520:
	./build/ARM/gem5.opt ./configs/example/se.py -c $(spec_run)/520.omnetpp_r/omnetpp_r_base.arm64-64 -o "-c General -r 0"

spec17-523:
	./build/ARM/gem5.opt ./configs/example/se.py -c $(spec_run)/523.xalancbmk_r/cpuxalan_r_base.arm64-64 -o "-v $(spec_run)/523.xalancbmk_r/test.xml $(spec_run)/523.xalancbmk_r/xalanc.xsl"

spec17-531:
	./build/ARM/fem5.opt ./configs/example/se.py -c $(spec_run)/531.deepsjeng_r/deepsjeng_r_base.arm64-64 -o "$(spec_run)/531.deepsjeng_r/test.txt"
