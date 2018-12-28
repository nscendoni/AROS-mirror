/*
    Copyright © 1995-2014, The AROS Development Team. All rights reserved.
    $Id: test5.c 49667 2014-09-30 17:35:27Z neil $
*/

#include <stdio.h>

int c;

int main (int argc, char ** argv)
{
    int a;

    a = c;
    c = a;
}
