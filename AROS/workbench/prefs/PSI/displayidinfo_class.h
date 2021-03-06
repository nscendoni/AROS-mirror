#ifndef DISPLAYIDINFO_CLASS
#define DISPLAYIDINFO_CLASS

/*
    Copyright � 1995-1997 Stefan Stuntz.
    Copyright � 2009-2010, The AROS Development Team.
    All rights reserved.

    $Id: displayidinfo_class.h 33557 2010-06-12 20:08:25Z mazze $
*/

#include "psi.h"

#define MUIA_DispIDinfo_ID (TAGBASE_STUNTZI | 0x1010)

struct MUI_CustomClass *CL_DispIDinfo;

VOID DispIDinfo_Init(VOID);
VOID DispIDinfo_Exit(VOID);

#endif
