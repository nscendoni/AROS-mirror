/*
    Copyright � 2008-2013, The AROS Development Team. All rights reserved.
    $Id: getlogin.c 48053 2013-09-08 21:20:12Z verhaegs $

    POSIX.1-2008 function getlogin().
*/

#include <aros/debug.h>

#include <errno.h>

/*****************************************************************************

    NAME */
#include <unistd.h>

	char * getlogin(

/*  SYNOPSIS */
	)
        
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
    /* TODO: Implement getlogin() */
    AROS_FUNCTION_NOT_IMPLEMENTED("posixc");
    
    errno = ENOSYS;
    return NULL;
}
