/*
    Copyright © 2009, The AROS Development Team. All rights reserved.
    $Id: nan.c 48031 2013-09-08 21:16:04Z verhaegs $

    Implementation of C99 nan/nanf/nanl functions
*/
#include <math.h>

/* FIXME: check handling of NAN for different argument types */

float nanf(const char *tagp)
{
    (void)tagp;

    return NAN;
}

double nan(const char *tagp)
{
    (void)tagp;

    return (double)NAN;
}

long double nanl(const char *tagp)
{
    (void)tagp;

    return (long double)NAN;
}
