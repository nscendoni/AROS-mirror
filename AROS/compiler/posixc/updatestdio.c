/*
    Copyright � 2002, The AROS Development Team. All rights reserved.
    $Id: updatestdio.c 48048 2013-09-08 21:19:29Z verhaegs $

    C function to update stdfiles when changed by dos functions.
*/

#include "__fdesc.h"

/*****************************************************************************

    NAME */
	void updatestdio (

/*  SYNOPSIS */
	void)

/*  FUNCTION
        Update stdin, stdout, stderr to reflect changes done by calling
        dos.library functions like SelectInput(), ...

    INPUTS
        -

    RESULT
        -

    NOTES
        stdin, stdout and stderr will be flushed before they are updated.

    EXAMPLE

    BUGS

    SEE ALSO

    INTERNALS

******************************************************************************/
{
    __updatestdio();
} /* open */
