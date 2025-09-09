#ifndef LED_H
#define LED_H
#include "kedknl.h"
typedef struct
{
    void (*On)(void);
    void (*Off)(void);
} LedDriver;

void vdg_ledmodl_ledledon(void);
void vdg_ledmodl_blueledon(void);
void vdg_ledmodl_greenledon(void);
void vdg_ledmodl_yellowledon(void);

#endif
