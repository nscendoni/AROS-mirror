/*
    Copyright © 1995-2001, The AROS Development Team. All rights reserved.
    $Id: setsr.s 30792 2009-03-07 22:40:04Z neil $

    Desc: Exec function SetSR
    Lang: english
*/

/******************************************************************************

    NAME
	AROS_LH0(void, SetSR,

    LOCATION
	struct ExecBase *, SysBase, 24, Exec)

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
	.globl	AROS_SLIB_ENTRY(SetSR,Exec)
	.type	AROS_SLIB_ENTRY(SetSR,Exec),@function
AROS_SLIB_ENTRY(SetSR,Exec):
	/* Dummy */
	rts

