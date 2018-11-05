obj-m += gpio_driver.o
obj-m += sysfs.o
obj-m += driver_module.o
all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	rm *.o
	rm *.ko
	rm Module.symvers
	rm modules.order
	rm *.mod.c
