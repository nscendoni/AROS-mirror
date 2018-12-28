/*
    Copyright (C) 1995-2010, The AROS Development Team. All rights reserved.
    $Id: cliNan.c 38776 2011-05-20 21:27:20Z mazze $
 */

#include "Shell.h"

BOOL cliNan(CONST_STRPTR s)
{
    for (; *s != '\0'; ++s)
	if (*s < '0' || *s > '9')
	    return TRUE;
    return FALSE;
}

