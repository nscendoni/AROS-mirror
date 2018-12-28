/*
    Copyright © 1995-2014, The AROS Development Team. All rights reserved.
    $Id: test9.c 49667 2014-09-30 17:35:27Z neil $
*/

#include <stdio.h>

char * config;

int main (int argc, char ** argv)
{
    config = &argv[0][1];

    return 0;
}
