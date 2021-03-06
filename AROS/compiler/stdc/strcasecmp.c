/*
    Copyright � 1995-2012, The AROS Development Team. All rights reserved.
    $Id: strcasecmp.c 48031 2013-09-08 21:16:04Z verhaegs $

    POSIX.1-2008 function strcasecmp().
*/

#include <ctype.h>

/*****************************************************************************

    NAME */
#include <string.h>

	int strcasecmp (

/*  SYNOPSIS */
	const char * str1,
	const char * str2)

/*  FUNCTION
	Calculate str1 - str2 ignoring case.

    INPUTS
	str1, str2 - Strings to compare

    RESULT
	The difference of the strings. The difference is 0, if both are
	equal, < 0 if str1 < str2 and > 0 if str1 > str2. Note that
	it may be greater then 1 or less than -1.

    NOTES
	This function is not part of a library and may thus be called
	any time.

    EXAMPLE

    BUGS

    SEE ALSO

    INTERNALS

******************************************************************************/
{
    int diff;

    /* No need to check *str2 since: a) str1 is equal str2 (both are 0),
	then *str1 will terminate the loop b) str1 and str2 are not equal
	(eg. *str2 is 0), then the diff part will be FALSE. I calculate
	the diff first since a) it's more probable that the first chars
	will be different and b) I don't need to initialize diff then. */
    while (!(diff = tolower (*str1) - tolower (*str2)) && *str1)
    {
	/* advance both strings. I do that here, since doing it in the
	    check above would mean to advance the strings once too often */
	str1 ++;
	str2 ++;
    }

    /* Now return the difference. */
    return diff;
} /* strcasecmp */
