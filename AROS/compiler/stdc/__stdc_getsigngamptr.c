/*
    Copyright © 2013, The AROS Development Team. All rights reserved.
    $Id: __stdc_getsigngamptr.c 48035 2013-09-08 21:17:21Z verhaegs $

    Get pointer to errno variable in stdc.library libbase.
    This function is both in static linklib as in stdc.library.
*/
#include <libraries/stdc.h>

int *__stdc_getsigngamptr(void)
{
    return &(__aros_getbase_StdCBase()->_signgam);
}
