#include "Led.h"

void Led_On(void)
{
	out_w(GPIO_OUT_SET, (1 << 17));
}

void Led_Off(void)
{
	out_w(GPIO_OUT_CLR, (1 << 17));
}