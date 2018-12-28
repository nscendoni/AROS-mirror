/*
    Copyright © 2004, The AROS Development Team. All rights reserved.
    $Id: support.c 30792 2009-03-07 22:40:04Z neil $
*/

#include <proto/dos.h>
#include <string.h>

#include "support.h"

BOOL ReadLine(BPTR fh, STRPTR buffer, ULONG size)
{
    if (FGets(fh, buffer, size) != NULL)
    {
        ULONG last = strlen(buffer) - 1;
        if (buffer[last] == '\n') buffer[last] = '\0';
        
        return TRUE;
    }
    
    return FALSE;
}
