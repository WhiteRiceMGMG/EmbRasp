#ifndef LED_H
#define LED_H
#include "kedknl.h"
typedef struct
{
    void (*On)(void);
    void (*Off)(void);
} LedDriver;

void vdg_ledmodl_fiftledon(void);
void vdg_ledmodl_thirtledon(void);
void vdg_ledmodl_elevledon(void);
void vdg_ledmodl_nineledon(void);

#endif
