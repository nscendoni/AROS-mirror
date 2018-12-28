/*
    Copyright © 2002-2007, The AROS Development Team. All rights reserved.
    $Id: secGetPktOwner.c 30792 2009-03-07 22:40:04Z neil $
*/

#include <stdio.h>

#include "security_intern.h"

#define DEBUG 1
#include <aros/debug.h>

/*****************************************************************************

    NAME */
	AROS_LH1(struct muExtOwner *, secGetPktOwner,

/*  SYNOPSIS */
	/* void */
	AROS_LHA(struct DosPacket *, pkt, A1),

/*  LOCATION */
	struct Library *, SecurityBase, 34, Security)

/*  FUNCTION

    INPUTS


    RESULT


    NOTES


    EXAMPLE

    BUGS

    SEE ALSO


    INTERNALS

    HISTORY

*****************************************************************************/
{
    AROS_LIBFUNC_INIT

    D(bug( DEBUG_NAME_STR "secGetPktOwner()\n") );;

    return NULL;

    AROS_LIBFUNC_EXIT

} /* secGetPktOwner */

