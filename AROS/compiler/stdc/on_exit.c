/*
    Copyright � 1995-2002, The AROS Development Team. All rights reserved.
    $Id: on_exit.c 48031 2013-09-08 21:16:04Z verhaegs $
*/

#include <stdlib.h>
#include "__exitfunc.h"

/*****************************************************************************

    NAME */

	int on_exit(

/*  SYNOPSIS */
	void (*func)(int, void *),
	void *arg)

/*  FUNCTION

    INPUTS

    RESULT

    NOTES

    EXAMPLE

    BUGS

    SEE ALSO

    INTERNALS

******************************************************************************/
{
    struct AtExitNode *aen = malloc(sizeof(*aen));

    if (!aen) return -1;

    aen->node.ln_Type = AEN_PTR;
    aen->func.fptr = func;
    aen->ptr = arg;

    return __addexitfunc(aen);
}

