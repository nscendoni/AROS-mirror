/*
    Copyright © 1995-2013, The AROS Development Team. All rights reserved.
    $Id: kputstr.c 48583 2013-12-16 21:03:22Z deadwood $

    Desc:
*/

#include <proto/debug.h>
#include <proto/exec.h>

VOID KPutStr(CONST_STRPTR string)
{
    while (*string)
        RawPutChar(*string++);
}
