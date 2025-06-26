#include <stdint.h>

#define GPIO_BASE     0x40014000
#define GPIO_OE       (*(volatile uint32_t *)(GPIO_BASE + 0x20)) // Output enable
#define GPIO_OUT      (*(volatile uint32_t *)(GPIO_BASE + 0x10)) // GPIO out
#define LED_PIN       15

void delay(volatile uint32_t t) {
    while (t--) __asm__("nop");
}

int main(void) {
    // set pin 15 as output
    GPIO_OE |= (1 << LED_PIN);

    while (1) {
        // turn on
        GPIO_OUT |= (1 << LED_PIN);
        delay(10000);

        // turn off
        GPIO_OUT &= ~(1 << LED_PIN);
        delay(300000);
    }
}
