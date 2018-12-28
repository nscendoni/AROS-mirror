#ifndef AROSMESAGLUT_INTERN_H
#define AROSMESAGLUT_INTERN_H

/*
    Copyright © 1995-2006, The AROS Development Team. All rights reserved.
    $Id: arosmesaglut_intern.h 36659 2011-01-18 13:26:51Z neil $
*/

#include <exec/memory.h>
#include <exec/libraries.h>
#include <aros/asmcall.h>
#include <dos/dos.h>
#include <libraries/iffparse.h>
#include <cybergraphx/cybergraphics.h>
#include <workbench/workbench.h>
#include <workbench/icon.h>
#include <graphics/view.h>

#include <proto/alib.h>
#include <proto/exec.h>
#include <proto/intuition.h>
#include <proto/graphics.h>
#include <proto/icon.h>
#include <proto/iffparse.h>
#include <proto/utility.h>
#include <proto/cybergraphics.h>
#include <proto/dos.h>

#include <stddef.h>

#include <string.h>
#include <aros/libcall.h>
#include <aros/asmcall.h>

#include "internal.h"

/****************************************************************************************/

/* Constants */

struct AROSMesaGLUTBase
{
#if defined(AROSSHAREDGLUT)
    struct Library      _glutLib;
#endif
    struct List         _glutPertasklist;
};

#endif /* AROSMESAGLUT_INTERN_H */
