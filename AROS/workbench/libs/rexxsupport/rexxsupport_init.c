/*
    Copyright © 1995-2006, The AROS Development Team. All rights reserved.
    $Id: rexxsupport_init.c 30792 2009-03-07 22:40:04Z neil $

    Desc: RexxSupport initialization code.
    Lang: English
*/

#include <exec/types.h>
#include <exec/libraries.h>
#include <dos/dosextens.h>
#include <aros/symbolsets.h>
#include <aros/debug.h>

#include <proto/exec.h>
#include <proto/alib.h>

#include "rexxsupport_intern.h"
#include LC_LIBDEFS_FILE

int errno;

static int Init(LIBBASETYPEPTR LIBBASE)
{
    NewList(&RSBI(LIBBASE)->openports);

    return TRUE;
}

ADD2INITLIB(Init, 0);
