spec_run=/home/huangyubiao-DomainA/arm-spec17-intrate-test-base-gnueabihf
tag=base.arm64-64
TARGET=$(target)

500_path=$(spec_run)/500.perlbench_r/
502_path=$(spec_run)/502.gcc_r/
503_path=$(spec_run)/503.bwaves_r/
505_path=$(spec_run)/505.mcf_r/
507_path=$(spec_run)/507.cactuBSSN_r/
508_path=$(spec_run)/508.namd_r/
510_path=$(spec_run)/510.parest_r/
511_path=$(spec_run)/511.povray_r/
519_path=$(spec_run)/519.lbm_r/
520_path=$(spec_run)/520.omnetpp_r/
521_path=$(spec_run)/521.wrf_r/
523_path=$(spec_run)/523.xalancbmk_r/
525_path=$(spec_run)/525.x264_r/            #error!
526_path=$(spec_run)/526.blender_r/
527_path=$(spec_run)/527.cam4_r/
531_path=$(spec_run)/531.deepsjeng_r/
538_path=$(spec_run)/538.imagick_r/
541_path=$(spec_run)/541.leela_r/
544_path=$(spec_run)/544.nab_r/
548_path=$(spec_run)/548.exchange2_r/
549_path=$(spec_run)/549.fotonik3d_r/
554_path=$(spec_run)/554.roms_r/
557_path=$(spec_run)/557.xz_r/


500_exe=$(500_path)/perlbench_r_$(tag)
502_exe=$(502_path)/gcc_r_$(tag)
503_exe=$(503_path)/bwaves_r_$(tag)
505_exe=$(505_path)/mcf_r_$(tag)
507_exe=$(507_path)/cactuBSSN_r_$(tag)
508_exe=$(508_path)/namd_r_$(tag)
510_exe=$(510_path)/parest_r_$(tag)
511_exe=$(511_path)/povray_r_$(tag)
519_exe=$(519_path)/lbm_r_$(tag)
520_exe=$(520_path)/omnetpp_r_$(tag)
521_exe=$(521_path)/wrf_r_$(tag)
523_exe=$(523_path)/xalancbmk_r_$(tag)
525_exe=$(525_path)/x264_r/      _$(tag)
526_exe=$(526_path)/blender_r_$(tag)
527_exe=$(527_path)/cam4_r_$(tag)
531_exe=$(531_path)/deepsjeng_r_$(tag)
538_exe=$(538_path)/imagick_r_$(tag)
541_exe=$(541_path)/leela_r_$(tag)
544_exe=$(544_path)/nab_r_$(tag)
548_exe=$(548_path)/exchange2_r_$(tag)
549_exe=$(549_path)/fotonik3d_r_$(tag)
554_exe=$(554_path)/roms_r_$(tag)
557_exe=$(557_path)/xz_r_$(tag)


500-1_opt=-I. -I$(500_path)/lib $(500_path)/makerand.pl
500-2_opt=-I. -I$(500_path)/lib $(500_path)/test.pl
502_opt=$(502_path)/t1.c -O3 -finline-limit=50000 -o t1.opts-O3_-finline-limit_50000.s
503_opt=bwaves_1 < $(503_path)/bwaves_1.in
505_opt=$(505_path)/inp.in
507_opt=$(507_path)/spec_test.par
508_opt=--input $(508_path)/apoa1.input --iterations 1 --output apoa1.test.output
510_opt=$(510_path)/test.prm
511_opt=$(511_path)/SPEC-benchmark-test.ini
519_opt=$(519_path)/reference.dat 0 1 $(519_path)/100_100_130_cf_a.of
520_opt=-c General -r 0
521_opt=  #nothing
523_opt=-v $(523_path)/test.xml $(523_path)/xalanc.xsl
525_opt=--dumpyuv 50 --frames 156 -o BuckBunny_New.264 BuckBunny.yuv 1280x720
526_opt=cube.blend --render-output cube_ --threads 1 -b -F RAWTGA -s 1 -e 1 -a
527_opt=  #nothing
531_opt=$(531_path)/test.txt
538_opt=-limit disk 0 $(538_path)/test_input.tga -shear 25 -resize 640x480 -negate -alpha Offtest_output.tga
541_opt=$(541_path)/ttest.sgf
544_opt=hkrdenq 1930344093 1000
548_opt=0
549_opt=  #nothing
554_opt=< ocean_benchmark0.in.x
557-1_opt =$(557_path)/cpu2006docs.tar.xz 4 055ce243071129412e9dd0b3b69a21654033a9b723d874b2015c774fac1553d9713be561ca86f74e4f16f22e664fc17a79f30caa5ad2c04fbc447549c2810fae 1548636 1555348 0
557-2_opt =$(557_path)/cpu2006docs.tar.xz 4 055ce243071129412e9dd0b3b69a21654033a9b723d874b2015c774fac1553d9713be561ca86f74e4f16f22e664fc17a79f30caa5ad2c04fbc447549c2810fae 1462248 -1 1 
557-3_opt =$(557_path)/cpu2006docs.tar.xz 4 055ce243071129412e9dd0b3b69a21654033a9b723d874b2015c774fac1553d9713be561ca86f74e4f16f22e664fc17a79f30caa5ad2c04fbc447549c2810fae 1428548 -1 2
557-4_opt =$(557_path)/cpu2006docs.tar.xz 4 055ce243071129412e9dd0b3b69a21654033a9b723d874b2015c774fac1553d9713be561ca86f74e4f16f22e664fc17a79f30caa5ad2c04fbc447549c2810fae 1034828 -1 3e
557-5_opt =$(557_path)/cpu2006docs.tar.xz 4 055ce243071129412e9dd0b3b69a21654033a9b723d874b2015c774fac1553d9713be561ca86f74e4f16f22e664fc17a79f30caa5ad2c04fbc447549c2810fae 1061968 -1 4
557-6_opt =$(557_path)/cpu2006docs.tar.xz 4 055ce243071129412e9dd0b3b69a21654033a9b723d874b2015c774fac1553d9713be561ca86f74e4f16f22e664fc17a79f30caa5ad2c04fbc447549c2810fae 1034588 -1 4e
557-7_opt =$(557_path)/cpu2006docs.tar.xz 1 055ce243071129412e9dd0b3b69a21654033a9b723d874b2015c774fac1553d9713be561ca86f74e4f16f22e664fc17a79f30caa5ad2c04fbc447549c2810fae 650156 -1 0
557-8_opt =$(557_path)/cpu2006docs.tar.xz 1 055ce243071129412e9dd0b3b69a21654033a9b723d874b2015c774fac1553d9713be561ca86f74e4f16f22e664fc17a79f30caa5ad2c04fbc447549c2810fae 639996 -1 1
557-9_opt =$(557_path)/cpu2006docs.tar.xz 1 055ce243071129412e9dd0b3b69a21654033a9b723d874b2015c774fac1553d9713be561ca86f74e4f16f22e664fc17a79f30caa5ad2c04fbc447549c2810fae 637616 -1 2
557-10_opt=$(557_path)/cpu2006docs.tar.xz 1 055ce243071129412e9dd0b3b69a21654033a9b723d874b2015c774fac1553d9713be561ca86f74e4f16f22e664fc17a79f30caa5ad2c04fbc447549c2810fae 628996 -1 3e
557-11_opt=$(557_path)/cpu2006docs.tar.xz 1 055ce243071129412e9dd0b3b69a21654033a9b723d874b2015c774fac1553d9713be561ca86f74e4f16f22e664fc17a79f30caa5ad2c04fbc447549c2810fae 631912 -1 4
557-12_opt=$(557_path)/cpu2006docs.tar.xz 1 055ce243071129412e9dd0b3b69a21654033a9b723d874b2015c774fac1553d9713be561ca86f74e4f16f22e664fc17a79f30caa5ad2c04fbc447549c2810fae 629064 -1 4e

TAR=$(shell echo $(TARGET)|awk -F '-' '{ print $$1 }')
spec17-test:
	./build/ARM/gem5.opt ./configs/example/se.py -c $($(TAR)_exe) -o "$($(TARGET)_opt)"
