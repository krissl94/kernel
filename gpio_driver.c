/*
 *  gpiodrivercustom.c - The simplest kernel module.
 */
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/gpio.h>                 // Required for the GPIO functions
#include <linux/interrupt.h>            // Required for the IRQ code

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Kris & Jeroen");
MODULE_DESCRIPTION("GPIO LED driver");
MODULE_VERSION("0.1");

static unsigned int gpioLED1 = 18;       ///< hard coding the LED gpio for this example to P9_23 (GPIO49)
static unsigned int gpioLED2 = 12;
static unsigned int gpioLED3 = 16;

void led_toggle(bool led1, bool led2, bool led3)
{
	gpio_set_value(gpioLED1, led1);
	gpio_set_value(gpioLED2, led2);
	gpio_set_value(gpioLED3, led3);
}

int gpio_init(void)
{
	printk(KERN_INFO "GPIO Driver started.\n");
	if(gpio_is_valid(gpioLED1) && gpio_is_valid(gpioLED2) && gpio_is_valid(gpioLED3)){
		gpio_request(gpioLED1, "sysfs");
		gpio_request(gpioLED2, "sysfs");
		gpio_request(gpioLED3, "sysfs");
		gpio_direction_output(gpioLED1, 0);        // Set the button GPIO to be an input
		gpio_direction_output(gpioLED2, 0);        // Set the button GPIO to be an input
		gpio_direction_output(gpioLED3, 0);        // Set the button GPIO to be an input
		return 0;
	}
	/*
	 * A non 0 return means init_module failed; module can't be loaded.
	 */
	return 2;
}

void gpio_cleanup(void)
{
	if(gpio_is_valid(18)){
		gpio_free(gpioLED1);
		gpio_free(gpioLED2);
		gpio_free(gpioLED3);
	}
	printk(KERN_INFO "GPIO Driver stopped.\n");
}
