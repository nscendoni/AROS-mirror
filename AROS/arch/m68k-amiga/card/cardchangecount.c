/*
    Copyright © 1995-2014, The AROS Development Team. All rights reserved.
    $Id: cardchangecount.c 49553 2014-08-28 15:36:11Z neil $

    Desc: CardChangeCount() function.
    Lang: english
*/

#include <proto/exec.h>

#include "card_intern.h"

AROS_LH0(ULONG, CardChangeCount,
	struct CardResource*, CardResource, 16, Card)
{
    AROS_LIBFUNC_INIT

    return CardResource->changecount;

    AROS_LIBFUNC_EXIT
}
