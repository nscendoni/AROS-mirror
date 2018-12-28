/*
    Copyright © 1995-2011, The AROS Development Team. All rights reserved.
    $Id: vars.c 42365 2011-11-10 07:19:41Z yannick $

    Desc:
    Lang: English
*/

#include "global.h"
#include "version.h"

const char *versionstring = VERSIONSTR;

#undef VAR
#define VAR

#include "vars.h"
