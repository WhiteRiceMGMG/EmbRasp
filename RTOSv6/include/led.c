#include "Led.h"

void vdg_ledmodl_fiftledon(void)
{

}

void vdg_ledmodl_thirtledon(void)
{

}

void vdg_ledmodl_elevledon(void)
{

}

void vdg_ledmodl_nineledon(void)
{

}

15 13 11 9

void Led_On(void)
{
	out_w(GPIO_OUT_SET, (1 << 17));
}

void Led_Off(void)
{
	out_w(GPIO_OUT_CLR, (1 << 17));
}
