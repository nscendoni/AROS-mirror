/*
    Copyright � 1995-2006, The AROS Development Team. All rights reserved.
    $Id: lowlevel_init.c 30792 2009-03-07 22:40:04Z neil $

    Desc: Init of workbench.library
    Lang: english
*/

#include <aros/symbolsets.h>

#include "lowlevel_intern.h"
#include LC_LIBDEFS_FILE

static int Init(LIBBASETYPEPTR lh)
{
    InitSemaphore(&lh->ll_Lock);
    lh->ll_VBlank.is_Data = NULL;
    lh->ll_VBlank.is_Code = NULL;

    return TRUE;
}

ADD2INITLIB(Init, 0);
