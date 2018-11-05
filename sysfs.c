#include <linux/init.h>
#include <linux/module.h>
#include <linux/delay.h>
#include <linux/gpio.h>
#include </home/pi/kerneldriver/final/gpio_driver.c>

static struct kobject *gpiodriver_kobject;

static ssize_t set_leds(struct kobject *kobj, struct kobj_attribute *attr, const char *buff, size_t count) {
  int led1 = 0;
  int led2 = 0;
  int led3 = 0;
  sscanf(buff, "%d %d %d", &led1, &led2, &led3);

  if(
     (led1 == 1 || led1 == 0) &&
     (led2 == 1 || led2 == 0) &&
     (led3 == 1 || led3 == 0))
{
	  led_toggle(!led1,!led2,!led3); //Inverse logic because that's how the leds are wired.
}
//  printk(KERN_INFO "GPIODRIVER: updating syysfs...");

  return count;
}

static struct kobj_attribute gpiodriver_attribute =__ATTR(leds, (S_IWUSR | S_IRUGO), NULL, set_leds);

void gpiodriver_sysfs_init(void){
  printk(KERN_INFO "GPIODRIVER: starting sysfs...");
  gpiodriver_kobject = kobject_create_and_add("gpiodriver", NULL);
  if (sysfs_create_file(gpiodriver_kobject, &gpiodriver_attribute.attr)) {
    pr_debug("failed to create gpiodriver sysfs!\n");
  }
  printk(KERN_INFO "GPIODRIVER: starting sysfs done.");
}

void gpiodriver_sysfs_exit(void){
  printk(KERN_INFO "GPIODRIVER: stopping sysfs...");
  kobject_put(gpiodriver_kobject);
  printk(KERN_INFO "GPIODRIVER: stopping sysfs done.");
}
