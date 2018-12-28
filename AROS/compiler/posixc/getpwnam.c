/*
    Copyright © 2004-2013, The AROS Development Team. All rights reserved.
    $Id: getpwnam.c 48053 2013-09-08 21:20:12Z verhaegs $
*/

#include <aros/debug.h>
#include <errno.h>

/*****************************************************************************

    NAME */

#include <pwd.h>

	struct passwd *getpwnam(

/*  SYNOPSIS */
	const char *name)

/*  FUNCTION

    INPUTS

    RESULT

    NOTES
	Not implemented.

    EXAMPLE

    BUGS

    SEE ALSO

    INTERNALS

******************************************************************************/
{
    /* TODO:  Implement getpwnam() */
    AROS_FUNCTION_NOT_IMPLEMENTED("posixc");
    errno = ENOSYS;

    return NULL;
}

