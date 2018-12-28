/*
    Copyright © 1995-2011, The AROS Development Team. All rights reserved.
    $Id: _kprintf.c 38352 2011-04-25 11:39:13Z sonic $

    Desc: Low-level debugging support.
*/

#include <exec/rawfmt.h>
#include <proto/exec.h>
#include <aros/asmcall.h>
#include <stdarg.h>

void KPrintF(STRPTR format, ...)
{
    va_list ap;

    va_start(ap, format);

    VNewRawDoFmt(format, (APTR)RAWFMTFUNC_SERIAL, NULL, ap);

    va_end(ap);
}
