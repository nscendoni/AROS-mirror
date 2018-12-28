/*
    Copyright © 1995-2004, The AROS Development Team. All rights reserved.
    $Id: stophook.c 30792 2009-03-07 22:40:04Z neil $

    Handler installed by StopChunk() and StopOnExit()
*/

#include "iffparse_intern.h"

/***************************/
/* StopChunk entry-handler */
/***************************/

LONG StopFunc
(
    struct Hook *hook,
     APTR         obj, 
     APTR         p
)
{
    return (IFF_RETURN2CLIENT);
}

