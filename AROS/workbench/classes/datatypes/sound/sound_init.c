/*
    Copyright © 1995-2006, The AROS Development Team. All rights reserved.
    $Id: sound_init.c 30792 2009-03-07 22:40:04Z neil $

    Desc: Text.datatype initialization code.
    Lang: English.
*/

#include <exec/types.h>

#include <proto/exec.h>

#include <aros/symbolsets.h>

#include "classbase.h"

/***************************************************************************************************/

static int InitSem(struct ClassBase *lh)
{
    InitSemaphore(&lh->cb_LibLock);

    return TRUE;
}

ADD2INITLIB(InitSem, 0);

/***************************************************************************************************/
