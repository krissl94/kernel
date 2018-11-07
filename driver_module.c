#include </home/pi/kerneldriver/final/sysfs.c>

static int gpiodriver_init(void){
  printk(KERN_INFO "GPIODRIVER: staring...");
  gpio_init();
  gpiodriver_sysfs_init();
  printk(KERN_INFO "GPIODRIVER: staring done.");
  return 0;
}

static void gpiodriver_exit(void){
  printk(KERN_INFO "GPIODRIVER: stopping...");
  gpio_cleanup();
  gpiodriver_sysfs_exit();
  printk(KERN_INFO "GPIODRIVER: stopping done.");
}


module_init(gpiodriver_init);
module_exit(gpiodriver_exit);
