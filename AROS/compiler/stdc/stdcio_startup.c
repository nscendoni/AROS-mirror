/*
    Copyright © 2010-2013, The AROS Development Team. All rights reserved.
    $Id: stdcio_startup.c 53132 2016-12-29 10:32:06Z deadwood $

    Additional startup code for stdcio.library that is executed during
    init of a program that uses the library.
    This file is thus not part of stdcio.library but is used by the
    startup section in stdcio.conf
*/

#include <aros/symbolsets.h>
#include <proto/stdc.h>
#include <libraries/stdcio.h>

#define DEBUG 0
#include <aros/debug.h>

static int __stdcio_startup(void)
{
    struct StdCIOBase *StdCIOBase = __aros_getbase_StdCIOBase();

    StdCIOBase->StdCBase = __aros_getbase_StdCBase();

    D(bug("[__stdcio_startup]StdCIOBase->StdCBase = %p\n",
          StdCIOBase->StdCBase
    ));

    return StdCIOBase->StdCBase != NULL;
}

ADD2INIT(__stdcio_startup, -50);
