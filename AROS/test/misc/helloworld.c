/*
    Copyright © 1995-96, The AROS Development Team. All rights reserved.
    $Id: helloworld.c 51689 2016-03-09 18:38:27Z NicJA $

    Desc: most simple demo for AROS
    Lang: english
*/
#include <stdio.h>

static const char version[] __attribute__((used)) = "$VER: helloworld 41.1 (14.3.1997)\n";

int main (int argc, char ** argv)
{
    printf ("Hello, world\n");
    return 0;
}
