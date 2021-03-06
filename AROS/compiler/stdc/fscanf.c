/*
    Copyright © 1995-2012, The AROS Development Team. All rights reserved.
    $Id: fscanf.c 48044 2013-09-08 21:18:52Z verhaegs $

    C99 function fscanf().
*/

#include <stdarg.h>

/*****************************************************************************

    NAME */
#include <stdio.h>

	int fscanf (

/*  SYNOPSIS */
	FILE	   * restrict fh,
	const char * restrict format,
	...)

/*  FUNCTION
	Scan a string with the specified arguments and write the results
	in the specified parameters.

    INPUTS
	fh - Read from this stream
	format - How to convert the input into the arguments
	... - Write the result in these arguments

    RESULT
	The number of converted arguments.

    NOTES

    EXAMPLE

    BUGS

    SEE ALSO
	scanf()

    INTERNALS

******************************************************************************/
{
    int     retval;
    va_list args;

    va_start (args, format);

    retval = vfscanf (fh, format, args);

    va_end (args);

    return retval;
} /* fscanf */
