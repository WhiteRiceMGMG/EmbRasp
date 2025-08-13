/*
 * kedDriver.c
 *
 *  Created on: 2025/07/24
 *      Author: shion
 */

#include "KedDriver.h"

KedDriver Ked =
    {
        .Led =
        {
            .On  = Led_On,
			.Off = Led_Off
        },

        .Button =
        {
        	.On  = Button_On
        }
    };
