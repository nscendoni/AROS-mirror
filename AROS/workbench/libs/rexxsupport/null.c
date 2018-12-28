/*
    Copyright © 1995-2006, The AROS Development Team. All rights reserved.
    $Id: null.c 30792 2009-03-07 22:40:04Z neil $

    Desc: Returns NULL pointer
    Lang: English
*/

#include <proto/exec.h>
#include <proto/rexxsyslib.h>
#include <exec/types.h>
#include <exec/memory.h>
#include <rexx/storage.h>
#include <rexx/errors.h>

#include <ctype.h>
#include <stdlib.h>

#include "rexxsupport_intern.h"
#include "rxfunctions.h"

LONG rxsupp_null(struct Library *RexxSupportBase, struct RexxMsg *msg, UBYTE **argstring)
{
    void *ptr = NULL;
  
    *argstring = CreateArgstring((UBYTE *)&ptr, sizeof(void *));
    return 0;
}
