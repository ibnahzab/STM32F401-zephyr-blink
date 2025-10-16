#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

/* LED configuration */
#define LED0_NODE DT_ALIAS(led0)

static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios);
static struct k_work_delayable led_work;

static void led_work_handler(struct k_work *work)
{
    /* Toggle LED */
    gpio_pin_toggle_dt(&led);
    printk("LED toggled\n");
    
    /* Reschedule the work */
    k_work_schedule(&led_work, K_MSEC(1000));
}

void main(void)
{
    int ret;

    /* Check if LED device is ready */
    if (!gpio_is_ready_dt(&led)) {
        printk("Error: LED device not ready\n");
        return;
    }

    /* Configure LED pin as output */
    ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);
    if (ret < 0) {
        printk("Error: Failed to configure LED pin\n");
        return;
    }

    printk("STM32F401 Blackpill LED Blink with scheduler\n");

    /* Initialize work item */
    k_work_init_delayable(&led_work, led_work_handler);

    /* Schedule first run */
    k_work_schedule(&led_work, K_NO_WAIT);

    /* Let the scheduler run */
    while (1) {
        k_sleep(K_FOREVER);
    }
}