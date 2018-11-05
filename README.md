# kernel

In order to make the project, just type "make" in the directory.

To add it to your kernel, run: 
sudo insmod driver_module.ko

Then, to clean the directory, run:
make clean

We still need to make a wrapper for controlling the leds, but for now this works: 
> sudo su
> echo 1 1 1 > /sys/gpiodriver/leds
