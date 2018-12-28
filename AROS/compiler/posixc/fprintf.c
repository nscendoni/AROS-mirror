/*
    Copyright © 1995-2012, The AROS Development Team. All rights reserved.
    $Id: fprintf.c 48031 2013-09-08 21:16:04Z verhaegs $

    C99 function fprintf().
*/

#include <stdarg.h>

/*****************************************************************************

    NAME */
#include <stdio.h>

	int fprintf (

/*  SYNOPSIS */
	FILE	   * fh,
	const char * format,
	...)

/*  FUNCTION
	Format a string with the specified arguments and write it to
	the stream.

    INPUTS
	fh - Write to this stream
	format - How to format the arguments
	... - The additional arguments

    RESULT
	The number of characters written to the stream or EOF on error.

    NOTES

    EXAMPLE

    BUGS

    SEE ALSO

    INTERNALS

******************************************************************************/
{
    int     retval;
    va_list args;

    va_start (args, format);

    retval = vfprintf (fh, format, args);

    va_end (args);

    return retval;
} /* fprintf */

