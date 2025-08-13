/*
 * Led.h
 *
 *  Created on: 2025/07/24
 *      Author: shion
 */
#ifndef LED_H
#define LED_H
#include "kedknl.h"
typedef struct
{
    void (*On)(void);
    void (*Off)(void);
} LedDriver;

void Led_On(void);
void Led_Off(void);
#endif
