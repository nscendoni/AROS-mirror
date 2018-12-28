/*
    Copyright © 2009, The AROS Development Team. All rights reserved.
    $Id: misc.c 48909 2014-04-05 19:40:16Z neil $
*/

#include <exec/types.h>
#include <proto/dos.h>

void ShowError(CONST_STRPTR message)
{
    Printf("ERROR: %s\n", message);
}
