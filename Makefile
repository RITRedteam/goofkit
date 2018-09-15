obj-m := goof.o
ccflags-y := -std=gnu99 -Wno-declaration-after-statement -g -O0 -fno-stack-protector -z execstack
KERNEL_DIR = /lib/modules/$(shell uname -r)/build

PWD=$(shell pwd)

all:
	$(MAKE) -C $(KERNEL_DIR) SUBDIRS=$(PWD)

ins:
	rmmod goof
	insmod goof.ko
	dmesg | grep goof --color=always

clean:
	rm -rf *.o *.ko *.symvers *.mod *.order

