/*
    Copyright © 1995-2014, The AROS Development Team. All rights reserved.
    $Id: s_lroundf.c 49667 2014-09-30 17:35:27Z neil $
*/

__FBSDID("$FreeBSD: src/lib/msun/src/s_lroundf.c,v 1.2 2005/04/08 00:52:27 das Exp $");

#define type		float
#define	roundit		roundf
#define dtype		long
#define	DTYPE_MIN	LONG_MIN
#define	DTYPE_MAX	LONG_MAX
#define	fn		lroundf

#include "s_lround.c"
