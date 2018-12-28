/*
    Copyright � 1995-2013, The AROS Development Team. All rights reserved.
    $Id: strcoll.c 48038 2013-09-08 21:17:58Z verhaegs $

    C99 function strcoll().
*/

/*****************************************************************************

    NAME */
#include <string.h>

	int strcoll (

/*  SYNOPSIS */
	const char * str1,
	const char * str2)

/*  FUNCTION
	Calculate str1 - str2. The operation is based on strings interpreted
	as appropriate for the program's current locale for category LC_COLLATE.

    INPUTS
	str1, str2 - Strings to compare

    RESULT
	The difference of the strings. The difference is 0, if both are
	equal, < 0 if str1 < str2 and > 0 if str1 > str2. Note that
	it may be greater then 1 or less than -1.

    NOTES
        stdc.library only implements "C" locale so strcoll() is equivalent
        to strcmp()

    EXAMPLE

    BUGS

    SEE ALSO

    INTERNALS

******************************************************************************/
{
    return strcmp(str1, str2);
} /* strcoll */

