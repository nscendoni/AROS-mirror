/*
    Copyright © 1995-2006, The AROS Development Team. All rights reserved.
    $Id: misc_init.c 30792 2009-03-07 22:40:04Z neil $

    Desc: 
    Lang: English
*/

/*  HISTORY:  23.7.98  SDuvan  Implemented based on BattClock code. */

#include <exec/types.h>
#include <exec/memory.h>
#include <exec/resident.h>
#include <proto/exec.h>
#include <proto/misc.h>
#include <resources/misc.h>

#include <aros/symbolsets.h>
#include "misc_intern.h"

#include LC_LIBDEFS_FILE

static int GM_UNIQUENAME(Init)(LIBBASETYPEPTR MiscBase)
{
    InitSemaphore(&MiscBase->mb_Lock);

    return TRUE;
}

ADD2INITLIB(GM_UNIQUENAME(Init), 0)
