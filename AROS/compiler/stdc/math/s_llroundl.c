/*
    Copyright © 1995-2014, The AROS Development Team. All rights reserved.
    $Id: s_llroundl.c 49667 2014-09-30 17:35:27Z neil $
*/

__FBSDID("$FreeBSD: src/lib/msun/src/s_llroundl.c,v 1.1 2005/04/08 01:24:08 das Exp $");

#define type		long double
#define	roundit		roundl
#define dtype		long long
#define	DTYPE_MIN	LLONG_MIN
#define	DTYPE_MAX	LLONG_MAX
#define	fn		llroundl

#include "s_lround.c"
