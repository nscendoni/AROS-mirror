/*
    Copyright © 1995-2001, The AROS Development Team. All rights reserved.
    $Id: cachecontrol.s 30792 2009-03-07 22:40:04Z neil $
*/

/******************************************************************************

    NAME
	AROS_LH0(void, CacheControl,

    LOCATION
	struct ExecBase *, SysBase, 108, Exec)

    FUNCTION

    INPUTS

    RESULT

    NOTES

    EXAMPLE

    BUGS

    SEE ALSO

    INTERNALS

    HISTORY

******************************************************************************/

	#include "machine.i"

	.text
	.balign 16
	.globl	AROS_SLIB_ENTRY(CacheControl,Exec)
	.type	AROS_SLIB_ENTRY(CacheControl,Exec),@function
AROS_SLIB_ENTRY(CacheControl,Exec):
	/* Dummy */
	rts

