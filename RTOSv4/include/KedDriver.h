/*
 * kedDriver.h
 *
 *  Created on: 2025/07/24
 *      Author: shion
 */
#ifndef KEDDRIVER_H_
#define KEDDRIVER_H_
#include "kedknl.h"
#include "Led.h"
#include "Button.h"

typedef struct
{
	LedDriver Led;
	ButtonDriver Button;
} KedDriver;

extern KedDriver Ked;

#endif
