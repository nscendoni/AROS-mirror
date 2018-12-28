/*
    Copyright © 1995-2011, The AROS Development Team. All rights reserved.
    $Id: kvprintf.c 45599 2012-08-19 07:29:58Z neil $

    Desc: Low-level debugging support.
*/

#include <exec/rawfmt.h>
#include <proto/exec.h>
#include <aros/asmcall.h>
#include <stdarg.h>

void KVPrintF(STRPTR format, CONST APTR values)
{
    RawDoFmt(format, values, (APTR)RAWFMTFUNC_SERIAL, NULL);
}
