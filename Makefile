obj-m := goof.o
ccflags-y := -Wframe-larger-than=4608 -std=gnu99 -Wno-declaration-after-statement -g -O0 -fno-stack-protector -z execstack

KERNEL_DIR = /lib/modules/$(shell uname -r)/build

PWD=$(shell pwd)

INC_DIR = ./include/beaengine
INC_DIR += ./beaengineSources
all:
	$(MAKE) -C $(KERNEL_DIR) SUBDIRS=$(PWD)

ins:
	rmmod goof
	insmod goof.ko
	dmesg | grep goof --color=always

clean:
	rm -rf *.o *.ko *.symvers *.mod *.mod.c *.order .*.cmd

