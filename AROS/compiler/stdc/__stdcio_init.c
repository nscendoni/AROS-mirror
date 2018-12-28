/*
    Copyright © 2012-2013, The AROS Development Team. All rights reserved.
    $Id: __stdcio_init.c 48029 2013-09-08 21:13:47Z verhaegs $

    Initialisation code for stdcio.library
*/
#include <aros/symbolsets.h>

#include <proto/stdcio.h>

/* Set StdCBase offset */
const ULONG const __aros_rellib_base_StdCBase = 0;
SETRELLIBOFFSET(StdCBase, struct StdCIOBase, StdCBase)
