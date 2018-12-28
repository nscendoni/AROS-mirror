/*
    Copyright © 1995-2013, The AROS Development Team. All rights reserved.
    $Id: gfxfuncsupport.h 47604 2013-06-24 21:28:04Z sonic $
*/

#include <hidd/graphics.h>
#include <cybergraphx/cybergraphics.h>

#include "cybergraphics_intern.h"

UBYTE GetRectFmtBytesPerPixel(UBYTE rectfmt, struct RastPort *rp,
    struct Library *CyberGfxBase);
HIDDT_StdPixFmt GetHIDDRectFmt(UBYTE rectfmt, struct RastPort *rp,
    struct Library *CyberGfxBase);
