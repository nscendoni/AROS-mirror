/*
    Copyright � 2013, The AROS Development Team. All rights reserved.
    $Id: processpixelarray_opblur.c 48674 2014-01-02 17:51:04Z neil $
*/

#include <aros/debug.h>

#include <proto/cybergraphics.h>

#include <hidd/graphics.h>
#include <cybergraphx/cybergraphics.h>
#include <exec/types.h>

#include "cybergraphics_intern.h"

void ProcessPixelArrayBlurFunc(struct RastPort *opRast, struct Rectangle *opRect, struct Library *CyberGfxBase)
{
    bug ("[Cgfx] %s()\n", __PRETTY_FUNCTION__);
    bug ("[Cgfx] %s: Blur operator not implemented\n", __PRETTY_FUNCTION__);
}
