# GPIO Kernel module

In order to make the project, just run:
> make


To add it to your kernel, run: 
sudo insmod driver_module.ko

Then, to clean the directory, run:
> make clean

We still need to make a wrapper for controlling the leds, but for now this works: 
> sudo su

> echo 1 1 1 > /sys/gpiodriver/leds

# gpio_driver.c
This file handles the actual kernel driver. It initializes the GPIO and frees it after the driver is released.

# sysfs.c
This file handles the creation and updating of the sysfs files. 

# driver_module.c
This file is a wrapper that starts everything in the right order. It does nothing special otherwise
