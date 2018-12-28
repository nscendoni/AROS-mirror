/*
    Copyright © 1995-2007, The AROS Development Team. All rights reserved.
    $Id: beginio.c 30792 2009-03-07 22:40:04Z neil $

    Desc: amiga.lib function BeginIO()
    Lang: english
*/
#include <proto/exec.h>

/*****************************************************************************

    NAME */
#include <exec/ports.h>
#include <proto/alib.h>

	void BeginIO (

/*  SYNOPSIS */
	struct IORequest * ioReq)

/*  FUNCTION
	Call the BeginIO() function of the given device.

    INPUTS
        ioReq - a filled out IORequest structure.

    RESULT
	None.

    NOTES

    EXAMPLE

    BUGS

    SEE ALSO
        exec.library/AbortIO()

    INTERNALS

    HISTORY

******************************************************************************/
{
    /* Call BeginIO() vector */
    AROS_LVO_CALL1NR(void,
	AROS_LCA(struct IORequest *,ioReq,A1),
	struct Device *,ioReq->io_Device,5,
    );
} /* BeginIO */
