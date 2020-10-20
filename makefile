x86:
	python	/usr/bin/scons build/X86/gem5.opt -j12

x86-hello-o3-pipeline:
	./build/X86/gem5.opt --debug-flags=O3PipeView --debug-start=10000 --debug-file=hello.out ./configs/myconfig/se.py --cpu-type=DerivO3CPU --caches -c ./tests/test-progs/hello/bin/x86/linux/hello
helli-o3-pipeview:
	util/o3-pipeview.py -c 500 -o pipeview.out --color m5out/trace.out
	#less -r pipeview.out


x86-spectre:
	./build/X86/gem5.opt ./configs/myconfig/se.py --cpu-type=DerivO3CPU --bp-type=LTAGE  --caches --l2cache -c ./note/spectre-attack/spectre 

x86-spectre-o3-pipeline:
	./build/X86/gem5.opt --debug-flags=O3PipeView --debug-start=10000 --debug-file=spectre.out ./configs/myconfig/se.py --cpu-type=DerivO3CPU --bp-type=LTAGE  --caches --l2cache -c ./note/spectre-attack/spectre 
spectre-o3-pipeview:
	util/o3-pipeview.py -c 500 -o pipeview.out --color m5out/trace.out
	#less -r pipeview.out
