/*
    Copyright � 1995-2001, The AROS Development Team. All rights reserved.
    $Id: stcl_d.c 48031 2013-09-08 21:16:04Z verhaegs $

    SAS/C function stcl_d().
*/

#include <stdio.h>

/*****************************************************************************

    NAME */
#include <string.h>

	int stcl_d (

/*  SYNOPSIS */
	char 		* out,
	long	    lvalue)

/*  FUNCTION
	Convert an long integer to a decimal string

    INPUTS
	out     - Result will be put into this string
	uivalue - the value to convert

    RESULT
	The number of characters written into the string

    NOTES
	SAS/C specific
	
    EXAMPLE

    BUGS

    SEE ALSO

    INTERNALS

******************************************************************************/
{
    return sprintf(out, "%ld", lvalue);
} /* stcl_d */
