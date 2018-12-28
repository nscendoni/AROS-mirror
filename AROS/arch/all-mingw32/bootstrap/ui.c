/*
    Copyright © 1995-2014, The AROS Development Team. All rights reserved.
    $Id: ui.c 49667 2014-09-30 17:35:27Z neil $
*/

#include <stdarg.h>
#include <stdio.h>
#include <windows.h>

#include "bootstrap.h"
#include "unicode.h"

void DisplayError(char *fmt, ...)
{
    va_list args;
    LPTSTR str;

    va_start(args, fmt);
    vsnprintf(buf, sizeof(buf), fmt, args);
    va_end(args);

    str = StrConvert(buf);
    MessageBox(NULL, str, TEXT("AROS bootstrap error"), MB_OK|MB_ICONSTOP);
    StrFree(str);
}
