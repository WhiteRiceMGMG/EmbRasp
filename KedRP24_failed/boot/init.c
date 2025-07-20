/*
 * syslib.c
 *
 *  Created on: 2025/07/20
 *      Author: shion
 */

#include "init.h"

void initial_ked(void)
{
	RESETS_RESET &= ~RESETS_RESET_IO_BANK0;
	RESETS_RESET &= ~RESETS_RESET_PADS_BANK0;

	while ((RESETS_RESET_DONE & (RESETS_RESET_IO_BANK0 | RESETS_RESET_PADS_BANK0)) !=
	       (RESETS_RESET_IO_BANK0 | RESETS_RESET_PADS_BANK0))
	{
	    ; // nothing to do
	}

	IO_BANK_GPIO_CTRL(17) = FUNCSEL_SIO;
	SIO_GPIO_OE_SET = (1u << 17);
}
