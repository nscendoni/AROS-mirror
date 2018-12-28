/*
    Copyright © 1995-2005, The AROS Development Team. All rights reserved.
    $Id: ascii_intern.h 30792 2009-03-07 22:40:04Z neil $
*/
#include <exec/types.h>

#define G(o) ((struct Gadget *)(o))

struct AsciiData
{
    APTR	Pool;
    ULONG	Flags;
};
