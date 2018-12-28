/*
    Copyright © 1995-2013, The AROS Development Team. All rights reserved.
    $Id: ferror.c 48044 2013-09-08 21:18:52Z verhaegs $

    C99 function ferror().
*/
#include "__stdio.h"

/*****************************************************************************

    NAME */
#include <stdio.h>

	int ferror (

/*  SYNOPSIS */
	FILE * stream)

/*  FUNCTION
	Test the error flag of a stream. This flag is set automatically by
	any function that detects an error. To clear it, call clearerr().

    INPUTS
	stream - The stream to be tested.

    RESULT
	!= 0, if the stream had an error, 0 otherwise.

    NOTES

    EXAMPLE

    BUGS

    SEE ALSO
	ferror(), clearerr()

    INTERNALS

******************************************************************************/
{
    return (stream->flags & __STDCIO_STDIO_ERROR) != 0;
} /* ferror */
