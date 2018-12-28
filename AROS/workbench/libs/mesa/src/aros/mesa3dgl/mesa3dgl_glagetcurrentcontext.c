/*
    Copyright 2009-2015, The AROS Development Team. All rights reserved.
    $Id: mesa3dgl_glagetcurrentcontext.c 50856 2015-06-23 22:01:54Z NicJA $
*/

#include <proto/exec.h>

#include "mesa3dgl_types.h"

/*****************************************************************************

    NAME */

      GLAContext glAGetCurrentContext(

/*  SYNOPSIS */
      )

/*  FUNCTION
        Returns the currently selected GL rendering context.

    INPUTS

    RESULT
        The GL rendering context which is currently active.

    BUGS

    INTERNALS

    HISTORY

*****************************************************************************/
{
    GET_CURRENT_CONTEXT(ctx);

    return (GLAContext)ctx;
}

