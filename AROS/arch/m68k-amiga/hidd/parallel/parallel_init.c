/*
    Copyright © 1995-2006, The AROS Development Team. All rights reserved.
    $Id: parallel_init.c 50912 2015-07-03 19:34:27Z jmcmullan $

    Desc: Parallel hidd initialization code.
    Lang: English.
*/
#include <stddef.h>
#include <exec/types.h>
#include <exec/alerts.h>

#include <aros/system.h>
#include <aros/symbolsets.h>

#include <proto/oop.h>
#include <proto/exec.h>

#include "parallel_intern.h"

#include LC_LIBDEFS_FILE

#include <aros/debug.h>
