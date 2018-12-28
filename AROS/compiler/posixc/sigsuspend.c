/*
    Copyright © 1995-2013, The AROS Development Team. All rights reserved.
    $Id: sigsuspend.c 48053 2013-09-08 21:20:12Z verhaegs $

    POSIX.1-2008 function sigsuspend().
*/

#include <aros/debug.h>
#include <errno.h>

/*****************************************************************************

    NAME */

#include <signal.h>

	int sigsuspend (

/*  SYNOPSIS */
	const sigset_t *mask)

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
    /* TODO: Implement sigsuspend() */
    AROS_FUNCTION_NOT_IMPLEMENTED("posixc");
    errno = ENOSYS;

    return -1;
} /* sigsuspend */
