/*
    Copyright © 1995-2012, The AROS Development Team. All rights reserved.
    $Id: unsetenv.c 48031 2013-09-08 21:16:04Z verhaegs $

    POSIX.1-2008 function unsetenv().
*/

#include <proto/dos.h>

/*****************************************************************************

    NAME */
#include <stdlib.h>

	void unsetenv (

/*  SYNOPSIS */
	const char *name)

/*  FUNCTION
	 deletes a variable from the environment.

    INPUTS
	name  --  Name of the environment variable to delete.

    RESULT
       Returns zero on success, or -1 if the variable was not found.

    NOTES
    
    EXAMPLE

    BUGS

    SEE ALSO

    INTERNALS

******************************************************************************/
{
    DeleteVar(name, GVF_LOCAL_ONLY);
} /* unsetenv */

