/*
    Copyright © 1995-2007, The AROS Development Team. All rights reserved.
    $Id: freelocalitem.c 30792 2009-03-07 22:40:04Z neil $
*/

#include "iffparse_intern.h"

/*****************************************************************************

    NAME */
#include <proto/iffparse.h>

	AROS_LH1(void, FreeLocalItem,

/*  SYNOPSIS */
	AROS_LHA(struct LocalContextItem *, localItem, A0),

/*  LOCATION */
	struct Library *, IFFParseBase, 34, IFFParse)

/*  FUNCTION
	Frees a local context item previously allocated by AllocLocalItem.
	This functioned should always be calles by custom LCI purge hooks.

    INPUTS
	localItem    -	pointer to LocalContextItem struct.

    RESULT

    NOTES

    EXAMPLE

    BUGS

    SEE ALSO
	AllocLocalItem()

    INTERNALS

*****************************************************************************/
{
    AROS_LIBFUNC_INIT

    if (localItem != NULL)
    {
	/* If the LCI has supplied userdata, then free it */
	if ( GetIntLCI(localItem)->lci_UserData )
	{
	    FreeMem
	    (
		GetIntLCI(localItem)->lci_UserData,
		GetIntLCI(localItem)->lci_UserDataSize
	    );
	}


	/* Free the LCI itself */
	FreeMem(localItem, sizeof (struct IntLocalContextItem));
    }
    
    AROS_LIBFUNC_EXIT
} /* FreeLocalItem */
