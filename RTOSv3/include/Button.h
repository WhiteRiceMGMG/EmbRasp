/*
 * Button.h
 *
 *  Created on: 2025/07/24
 *      Author: shion
 */
#ifndef BUTTON_H
#define BUTTON_H
#include "kedknl.h"
typedef struct
{
    int (*On)(void);
} ButtonDriver;

int Button_On(void);
#endif
