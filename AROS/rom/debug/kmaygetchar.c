/*
    Copyright © 1995-2013, The AROS Development Team. All rights reserved.
    $Id: kmaygetchar.c 47345 2013-05-04 11:12:06Z mazze $

    Desc:
*/

#include <proto/debug.h>
#include <proto/exec.h>

LONG KMayGetChar(VOID)
{
    return RawMayGetChar();
}
