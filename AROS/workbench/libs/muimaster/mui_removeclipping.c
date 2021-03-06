/*
    Copyright � 2002-2012, The AROS Development Team. All rights reserved.
    $Id: mui_removeclipping.c 53132 2016-12-29 10:32:06Z deadwood $
*/

#include <proto/muimaster.h>

#include "mui.h"
#include "muimaster_intern.h"

/*****************************************************************************

    NAME */
        AROS_LH2(VOID, MUI_RemoveClipping,

/*  SYNOPSIS */
        AROS_LHA(struct MUI_RenderInfo *, mri, A0),
        AROS_LHA(APTR, handle, A1),

/*  LOCATION */
        struct Library *, MUIMasterBase, 25, MUIMaster)

/*  FUNCTION

    INPUTS

    RESULT

    NOTES

    EXAMPLE

    BUGS

    SEE ALSO

    INTERNALS

*****************************************************************************/
{
    AROS_LIBFUNC_INIT

    MUI_RemoveClipRegion(mri, handle);

    AROS_LIBFUNC_EXIT

} /* MUIA_RemoveClipping */
