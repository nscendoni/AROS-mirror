/*
    Copyright � 2013, The AROS Development Team. All rights reserved.
    $Id: processpixelarray_opnegative.c 48674 2014-01-02 17:51:04Z neil $
*/

#include <aros/debug.h>

#include <aros/debug.h>

#include <proto/cybergraphics.h>

#include <hidd/graphics.h>
#include <cybergraphx/cybergraphics.h>
#include <exec/types.h>

#include "cybergraphics_intern.h"

void ProcessPixelArrayNegativeFunc(struct RastPort *opRast, struct Rectangle *opRect, ULONG tintval, struct Library *CyberGfxBase)
{
    D(bug("[Cgfx] %s(0x%08x)\n", __PRETTY_FUNCTION__, tintval));
    D(bug("[Cgfx] %s: Negative operator not implemented\n", __PRETTY_FUNCTION__));
}
