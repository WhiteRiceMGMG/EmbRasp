/*
 * Button.c
 *
 *  Created on: 2025/07/24
 *      Author: shion
 */
#include "Button.h"
#include "kedknl.h"

int Button_On(void)
{
    return (in_w(GPIO_IN) & (1 << 18)) != 0;
}

