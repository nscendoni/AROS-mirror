/*
    Copyright © 1995-2013, The AROS Development Team. All rights reserved.
    $Id: putchar.c 48044 2013-09-08 21:18:52Z verhaegs $

    C99 function putchar()
*/
#include <libraries/stdcio.h>

/*****************************************************************************

    NAME */

#include <stdio.h>

	int putchar(

/*  SYNOPSIS */
	int c)

/*  FUNCTION
        Equivalent to fputc(stdout)

    INPUTS

    RESULT

    NOTES

    EXAMPLE

    BUGS

    SEE ALSO
        fputc(), putc()

    INTERNALS

******************************************************************************/
{
    struct StdCIOBase *StdCIOBase = __aros_getbase_StdCIOBase();

    return fputc(c, StdCIOBase->_stdout);
}
