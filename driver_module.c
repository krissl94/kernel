#include </home/pi/kerneldriver/final/sysfs.c>

static int pix_init(void){
  printk(KERN_INFO "PIX: staring...");
  gpio_init();
  gpiodriver_sysfs_init();
  printk(KERN_INFO "PIX: staring done.");
  return 0;
}

static void pix_exit(void){
  printk(KERN_INFO "PIX: stopping...");
  gpio_cleanup();
  gpiodriver_sysfs_exit();
  printk(KERN_INFO "PIX: stopping done.");
}


module_init(pix_init);
module_exit(pix_exit);
