/*
    Copyright © 1995-2001, The AROS Development Team. All rights reserved.
    $Id: runprocess.c 30792 2009-03-07 22:40:04Z neil $
*/

#include <exec/tasks.h>
#include <clib/exec_protos.h>
#include <dos/dosextens.h>
#include "dos_intern.h"

LONG RunProcess(struct Process *proc, struct StackSwapStruct *sss,
STRPTR argptr, ULONG argsize, LONG_FUNC entry)
{
    LONG ret;
    APTR *sp;
    extern struct DosLibrary *DOSBase;
    sp=(APTR *)sss->stk_Upper;
    *--sp=SysBase;
    *--sp=(APTR)argsize;
    *--sp=argptr;
    sss->stk_Pointer=sp;
    StackSwap(sss);
    ret=entry();
    StackSwap(sss);
    return ret;
}
