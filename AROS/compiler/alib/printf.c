/*
    Copyright © 1995-2001, The AROS Development Team. All rights reserved.
    $Id: printf.c 30792 2009-03-07 22:40:04Z neil $

    Desc: Varargs stub for Printf()
    Lang: english
*/

#include <dos/dos.h>
#include <proto/dos.h>

LONG Printf(STRPTR fmt, ...) __stackparm;

LONG Printf(STRPTR fmt, ...)
{
    LONG retval;

    retval = VFPrintf(Output(), fmt, &fmt+1);

    return retval;
}
