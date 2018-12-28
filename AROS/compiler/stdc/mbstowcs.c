/*
    Copyright © 2007-2013, The AROS Development Team. All rights reserved.
    $Id: mbstowcs.c 48037 2013-09-08 21:17:44Z verhaegs $

    C99 function mbstowcs().
*/

/*****************************************************************************

    NAME
#include <stdlib.h>

	size_t mbstowcs(

    SYNOPSIS
	wchar_t * restrict pwcs,
	const char * restrict s,
	size_t n)

    FUNCTION
        C99 function mbstowcs.

    INPUTS

    RESULT

    NOTES
        stdc.library currenlty only implements "C" locale.

    EXAMPLE

    BUGS

    SEE ALSO

    INTERNALS
        Implemented as static inline function to adapt to changing wchar_t
        definitions

******************************************************************************/
