/*
    Copyright © 1995-2014, The AROS Development Team. All rights reserved.
    $Id: t_illread2.c 49667 2014-09-30 17:35:27Z neil $
*/

#include <stdio.h>

int main (int argc, char ** argv)
{
    int * x;
    int a, b;

    x = &b;

    b = 0;

    a = *x++;	/* ok */
    a = *x++;	/* illegal: Uninitialized memory */

    x = (int *)&main;

    a = *x; /* illegal: Code read */

    x = (int *)0xDEADBEEF;

    a = *x; /* illegal: Illegal pointer */
}
