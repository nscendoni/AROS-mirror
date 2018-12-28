/*
    Copyright © 1995-2006, The AROS Development Team. All rights reserved.
    $Id: mathtrans_init.c 30792 2009-03-07 22:40:04Z neil $

    Desc: Init of mathtrans.library
    Lang: english
*/

#include <aros/symbolsets.h>

#include "mathtrans_intern.h"
#include LC_LIBDEFS_FILE

#define DEBUG 0
#include <aros/debug.h>
#undef kprintf

struct Library * MathBase;

static int Init(LIBBASETYPEPTR LIBBASE)
{
    MathBase = OpenLibrary ("mathffp.library", 0);
    if (!MathBase)
	return FALSE;

    return TRUE;
}

static int Expunge(LIBBASETYPEPTR LIBBASE)
{
    if (MathBase)
	CloseLibrary ((struct Library *)MathBase);

    return TRUE;
}

ADD2INITLIB(Init, 0);
ADD2EXPUNGELIB(Expunge, 0);

