/*
    Copyright � 1995-2014, The AROS Development Team. All rights reserved.
    $Id: version.c 49667 2014-09-30 17:35:27Z neil $
*/

#include <bzlib.h>
#include <stdio.h>

int main(void)
{
    printf("Version %s\n", BZ2_bzlibVersion());
    return 0;
}
