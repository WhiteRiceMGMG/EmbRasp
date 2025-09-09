#include "Led.h"

void vdg_ledmodl_fiftledon(void)
{
    out_w(GPIO_OUT_SET, (1 << 15));
}

void vdg_ledmodl_fiftledoff(void)
{
    out_w(GPIO_OUT_CLR, (1 << 15));
}

void vdg_ledmodl_thirtledon(void)
{
    out_w(GPIO_OUT_SET, (1 << 13));
}

void vdg_ledmodl_thirtledoff(void)
{
    out_w(GPIO_OUT_CLR, (1 << 13));
}

void vdg_ledmodl_elevledon(void)
{
    out_w(GPIO_OUT_SET, (1 << 11));
}

void vdg_ledmodl_elevledoff(void)
{
    out_w(GPIO_OUT_CLR, (1 << 11));
}

void vdg_ledmodl_nineledon(void)
{
    out_w(GPIO_OUT_SET, (1 << 9));
}

void vdg_ledmodl_nineledon(void)
{
    out_w(GPIO_OUT_CLR, (1 << 9));
}

