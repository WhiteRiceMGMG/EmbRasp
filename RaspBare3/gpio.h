#ifndef GPIO_H
#define GPIO_H
#include <stdint.h>
#define GPIO_BASE 0x3f200000

typedef struct {
	volatile uint32_t GPFSEL[6];
	volatile uint32_t RESERVED0;
	volatile uint32_t GPSET[2];
	volatile uint32_t RESERVED1;
	volatile uint32_t GPCLR[2];

} GPIORegisters;

extern volatile GPIORegisters *gpio;

void gpio_init();
void gpio_set_output(int pin);
void gpio_write(int pin, int value);

#endif
