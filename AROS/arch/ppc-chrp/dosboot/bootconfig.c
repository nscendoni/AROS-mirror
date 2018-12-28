/*
    Copyright © 1995-2014, The AROS Development Team. All rights reserved.
    $Id: bootconfig.c 49667 2014-09-30 17:35:27Z neil $
*/

#include "dosboot_intern.h"

/* This file contains architecture-dependent defaults */

void InitBootConfig(struct BootConfig *bootcfg)
{
    bootcfg->gfxlib  = "radeon.hidd";
    bootcfg->gfxhidd = "RadeonDriver";
}
