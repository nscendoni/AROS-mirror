/*
    Copyright © 1995-2012, The AROS Development Team. All rights reserved.
    $Id: sigemptyset.c 48031 2013-09-08 21:16:04Z verhaegs $

    POSIX.1-2008 function sigemptyset().
*/

#include <string.h>

/*****************************************************************************

    NAME */
#include <signal.h>

	int sigemptyset (

/*  SYNOPSIS */
	sigset_t *set)

/*  FUNCTION

    INPUTS

    RESULT

    NOTES

    EXAMPLE

    BUGS

    SEE ALSO

    INTERNALS

******************************************************************************/
{
    if (NULL != set) {
        memset(&set->__val, 0x00, sizeof(set->__val));
        return 0;
    }

    return -1; /* return failure */
} /* sigemptyset */
