/*
    Copyright © 2012-2013, The AROS Development Team. All rights reserved.
    $Id: __stdc_mb_cur_max.c 48037 2013-09-08 21:17:44Z verhaegs $

    Get the MB_CUR_MAX value
    This function is both in static linklib as in stdc.library.
*/
#include <libraries/stdc.h>

int __stdc_mb_cur_max(void)
{
    return __aros_getbase_StdCBase()->mb_cur_max;
}
