/*
    Copyright 2011-2015, The AROS Development Team. All rights reserved.
    $Id: hostgl_glagetopenglstatetrackerapi.c 51001 2015-08-10 17:43:38Z neil $
*/

#include <proto/exec.h>

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
    /* This function cannot be implemented in HostGL as it is Gallium specific */
    return NULL;
}
