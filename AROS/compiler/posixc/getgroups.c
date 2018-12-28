/*
    Copyright © 2004-2013, The AROS Development Team. All rights reserved.
    $Id: getgroups.c 48053 2013-09-08 21:20:12Z verhaegs $

    POSIX.1-2008 function getgroups().
*/

#include <aros/debug.h>
#include <errno.h>

/*****************************************************************************

    NAME */

#include <unistd.h>

	int getgroups(

/*  SYNOPSIS */
	int gidsetlen,
	gid_t *gidset)

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
    /* TODO: Implement getgroups() */
    AROS_FUNCTION_NOT_IMPLEMENTED("posixc");
    errno = ENOSYS;

    return 0;
}

