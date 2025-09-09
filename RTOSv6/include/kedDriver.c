/*
 * kedDriver.c
 *
 *  Created on: 2025/07/24
 *      Author: shion
 */

#include "KedDriver.h"

KedDriver Ked =
{
    .IgSw = 
    {
        .Push = u2g_btnmodl_igswonoff 
    },
    .UpSw =
    {
        .Push = u2g_btnmodl_drvmdmsswup
    },
    .DwSw =
    {
        .Push = u2g_btnmodl_drvmdmsswdw
    }
    .ConfSw =
    {
        .Push = u2g_btnmodl_confacsw
    }
    .FiftLed = 
    {
        .On  = vdg_ledmodl_fiftledon,
        .Off = vdg_ledmodl_fiftledoff
    },
    .ThirtLed = 
    {
        .On  = vdg_ledmodl_thirtledon,
        .Off = vdg_ledmodl_thirtledoff
    },
    .ElevLed =
    {
        .On  = vdg_ledmodl_elevledon,
        .Off = vdg_ledmodl_elevledoff
    },
    .NineLed =
    {
        .On  = vdg_ledmodl_nineledon,
        .Off = vdg_ledmodl_nineledoff
    }
};