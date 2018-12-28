/*
    Copyright (C) 1995-2011, The AROS Development Team. All rights reserved.
    $Id: cliLen.c 38778 2011-05-21 05:17:33Z mazze $
 */

#include "Shell.h"

LONG cliLen(CONST_STRPTR s)
{
    LONG i;

    for (i = 0; *s != '\0'; ++i)
	++s;

    return i;
}

