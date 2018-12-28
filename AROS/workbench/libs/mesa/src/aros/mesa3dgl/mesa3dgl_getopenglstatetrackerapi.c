/*
    Copyright 2014-2015, The AROS Development Team. All rights reserved.
    $Id: mesa3dgl_getopenglstatetrackerapi.c 50856 2015-06-23 22:01:54Z NicJA $
*/

#include <proto/exec.h>

#include "state_tracker/st_gl_api.h"

/*****************************************************************************

    NAME */

      APTR GetOpenGLStateTrackerApi(

/*  SYNOPSIS */
      )

/*  FUNCTION
        This is a PRIVATE function used by egl.library to receive pointer to
        api structure of OpenGL. Do not use this function in your application.

    INPUTS

    RESULT

    BUGS

    INTERNALS

    HISTORY

*****************************************************************************/
{
    return (APTR)st_gl_api_create();
}
