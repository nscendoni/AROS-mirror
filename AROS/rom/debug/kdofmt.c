/*
    Copyright © 1995-2013, The AROS Development Team. All rights reserved.
    $Id: kdofmt.c 47345 2013-05-04 11:12:06Z mazze $

    Desc:
*/

#include <proto/debug.h>
#include <proto/exec.h>

VOID KDoFmt(CONST_STRPTR formatString, CONST APTR dataStream, CONST APTR putChProc, APTR putChData)
{
    RawDoFmt(formatString, dataStream, putChProc, putChData);
}
