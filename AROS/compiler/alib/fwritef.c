/*
    Copyright © 1995-2001, The AROS Development Team. All rights reserved.
    $Id: fwritef.c 30792 2009-03-07 22:40:04Z neil $

    Desc: Varargs stub for VFWritef()
    Lang: english
*/

#include <dos/dos.h>
#include <proto/dos.h>
#include <stdarg.h>

LONG FWritef(BPTR fh, STRPTR fmt, ...)
{
    LONG retval;

    retval = VFWritef(fh, fmt, (LONG *)(&fmt+1));

    return retval;
}
