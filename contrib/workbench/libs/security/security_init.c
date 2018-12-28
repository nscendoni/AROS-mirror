/*
    Copyright © 1995-2006, The AROS Development Team. All rights reserved.
    $Id: security_init.c 30792 2009-03-07 22:40:04Z neil $

    Desc: Camd initialization code.
    Lang: English
*/

#include <exec/types.h>
#include <exec/libraries.h>

#include <aros/symbolsets.h>

#include <proto/exec.h>
#include <proto/utility.h>
#include <proto/dos.h>

#include "security_intern.h"
#include LC_LIBDEFS_FILE

#define DEBUG 1
#include <aros/debug.h>

/****************************************************************************************/
