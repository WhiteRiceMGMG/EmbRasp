#include "rp2040.h"

void main(void)
{
	GPIO17_CTRL = 5;
	SIO_GPIO_OE |= (1 << 17);
	while(1)
	{
		SIO_GPIO_OUT |= (1 << 17);
	}
}
