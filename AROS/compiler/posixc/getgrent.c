/*
    Copyright © 2004, The AROS Development Team. All rights reserved.
    $Id: getgrent.c 48053 2013-09-08 21:20:12Z verhaegs $
*/

#include <aros/debug.h>
#include <errno.h>

/*****************************************************************************

    NAME */

#include <grp.h>

	struct group *getgrent(

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
    /* TODO: Implement getgrent() */
    AROS_FUNCTION_NOT_IMPLEMENTED("posixc");
    errno = ENOSYS;

    return NULL;
}

