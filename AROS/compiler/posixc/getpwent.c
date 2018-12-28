/*
    Copyright © 2004-2013, The AROS Development Team. All rights reserved.
    $Id: getpwent.c 48053 2013-09-08 21:20:12Z verhaegs $
*/

#include <aros/debug.h>
#include <errno.h>

/*****************************************************************************

    NAME */

#include <pwd.h>

	struct passwd *getpwent(

/*  SYNOPSIS */
	void)

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
    /* TODO: Implement getpwent() */
    AROS_FUNCTION_NOT_IMPLEMENTED("posixc");
    errno = ENOSYS;

    return NULL;
}

