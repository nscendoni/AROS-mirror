/*
    Copyright © 1995-2013, The AROS Development Team. All rights reserved.
    $Id: kgetchar.c 47345 2013-05-04 11:12:06Z mazze $

    Desc:
*/

#include <proto/debug.h>
#include <proto/exec.h>

LONG KGetChar(VOID)
{
    LONG c;
    
    do
        c = RawMayGetChar();
    while (c == -1);

    return c;
}
