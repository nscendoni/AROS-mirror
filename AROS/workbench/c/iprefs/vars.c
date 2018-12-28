/*
    Copyright © 1995-2001, The AROS Development Team. All rights reserved.
    $Id: vars.c 30792 2009-03-07 22:40:04Z neil $

    Desc:
    Lang: English
*/

#include "global.h"
#include "version.h"

const char *versionstring = VERSIONSTR;

#undef VAR
#define VAR

#include "vars.h"
