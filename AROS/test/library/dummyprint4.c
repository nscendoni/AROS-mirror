/*
    Copyright © 1995-2014, The AROS Development Team. All rights reserved.
    $Id: dummyprint4.c 49667 2014-09-30 17:35:27Z neil $
*/

#include <exec/types.h>
#include <proto/dummy.h>

#include LC_LIBDEFS_FILE

/* Member of userel.library */

LONG DummyPrint4(LONG a, LONG b, LONG c, LONG d)
{
    return printx(4, a, b, c, d);
}
