/*
    Copyright © 1995-2014, The AROS Development Team. All rights reserved.
    $Id: s_lrintf.c 49667 2014-09-30 17:35:27Z neil $
*/

__FBSDID("$FreeBSD: src/lib/msun/src/s_lrintf.c,v 1.1 2005/01/11 23:12:55 das Exp $");

#define type		float
#define	roundit		rintf
#define dtype		long
#define	fn		lrintf

#include "s_lrint.c"
