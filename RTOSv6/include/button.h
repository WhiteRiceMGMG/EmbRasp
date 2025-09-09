#ifndef BUTTON_H
#define BUTTON_H
#include "kedknl.h"

typedef struct
{
    u2 (*Push)(void);
} ButtonDriver;

u2 u2g_btnmodl_igswonoff(void)
u2 u2g_btnmodl_drvmdmsswup(void);
u2 u2g_btnmodl_drvmdmsswdw(void);
u2 u2g_btnmodl_confacsw(void);

#endif