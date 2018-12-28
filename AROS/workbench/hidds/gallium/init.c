/*
    Copyright 2010, The AROS Development Team. All rights reserved.
    $Id: init.c 41761 2011-10-05 20:14:24Z deadwood $
*/

#include <aros/symbolsets.h>
#include <hidd/gallium.h>
#include <proto/oop.h>
#include <proto/exec.h>

#include "gallium_intern.h"

static int GalliumHidd_ExpungeLib(LIBBASETYPEPTR LIBBASE)
{
    if (LIBBASE->sd.galliumAttrBase)
        OOP_ReleaseAttrBase((STRPTR)IID_Hidd_Gallium);

    return TRUE;
}

static int GalliumHidd_InitLib(LIBBASETYPEPTR LIBBASE)
{
    LIBBASE->sd.galliumAttrBase = OOP_ObtainAttrBase((STRPTR)IID_Hidd_Gallium);

    if (LIBBASE->sd.galliumAttrBase)
        return TRUE;

    return FALSE;
}

ADD2INITLIB(GalliumHidd_InitLib, 0)
ADD2EXPUNGELIB(GalliumHidd_ExpungeLib, 0)

