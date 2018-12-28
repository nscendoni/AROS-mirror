/*
    Copyright © 2013, The AROS Development Team. All rights reserved.
    $Id: cgxbootpic_init.c 48424 2013-11-18 09:28:30Z neil $
*/

#define DEBUG 1
#include <aros/debug.h>

#include <aros/symbolsets.h>
#include <proto/exec.h>

#include "cgxbootpic_intern.h"

#include LC_LIBDEFS_FILE

int cgxbootpic_Init(LIBBASETYPEPTR CgxBootPicBase)
{
    D(bug("[CgxBootPic] %s()\n", __PRETTY_FUNCTION__));
    
    return TRUE;
}

ADD2INITLIB(cgxbootpic_Init, 0);
