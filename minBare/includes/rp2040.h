#ifndef INCLUDES_RP2040_H_
#define INCLUDES_RP2040_H_
#include <stdint.h>

#define IO_BANK0_BASE  0x40014000
#define SIO_BASE       0xd0000000

#define GPIO17_CTRL  (*(volatile uint32_t *)(IO_BANK0_BASE + 0x04 + 0x70))
#define SIO_GPIO_OE  (*(volatile uint32_t *)(SIO_BASE + 0x20))
#define SIO_GPIO_OUT (*(volatile uint32_t *)(SIO_BASE + 0x10))


#endif /* INCLUDES_RP2040_H_ */
