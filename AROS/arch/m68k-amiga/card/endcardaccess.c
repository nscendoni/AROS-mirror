/*
    Copyright � 1995-2014, The AROS Development Team. All rights reserved.
    $Id: endcardaccess.c 49553 2014-08-28 15:36:11Z neil $

    Desc: EndCardAccess() function.
    Lang: english
*/

#include "card_intern.h"

AROS_LH1(ULONG, EndCardAccess,
	AROS_LHA(struct CardHandle*, handle, A1),
	struct CardResource*, CardResource, 5, Card)
{
    AROS_LIBFUNC_INIT

    CARDDEBUG(bug("EndCardAccess(%p)\n", handle));

    if (!ISMINE)
    	return FALSE;

    return TRUE;

    AROS_LIBFUNC_EXIT
}
