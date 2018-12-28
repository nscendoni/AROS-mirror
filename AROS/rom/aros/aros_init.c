/*
    Copyright © 1995-2014, The AROS Development Team. All rights reserved.
    $Id: aros_init.c 49667 2014-09-30 17:35:27Z neil $
*/

#include <aros/symbolsets.h>
#include <proto/exec.h>

#include "aros_intern.h"

#include LC_LIBDEFS_FILE

int aros_Init(LIBBASETYPEPTR ArosBase)
{
    ArosBase->aros_KernelBase = OpenResource("kernel.resource");
    
    return TRUE;
}

ADD2INITLIB(aros_Init, 0);
