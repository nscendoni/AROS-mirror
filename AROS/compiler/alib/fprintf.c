/*
    Copyright © 1995-2001, The AROS Development Team. All rights reserved.
    $Id: fprintf.c 30792 2009-03-07 22:40:04Z neil $

    Desc: Varargs stub for VFPrintf()
    Lang: english
*/

#include <dos/dos.h>
#include <proto/dos.h>
#include <stdarg.h>

LONG FPrintf(BPTR fh, STRPTR fmt, ...)
{
    LONG retval;

    retval = VFPrintf(fh, fmt, (LONG *)(&fmt+1));

    return retval;
}
