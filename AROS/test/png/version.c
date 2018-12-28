/*
    Copyright © 1995-2014, The AROS Development Team. All rights reserved.
    $Id: version.c 49667 2014-09-30 17:35:27Z neil $
*/

#include <png.h>
#include <stdio.h>

int main(void)
{
    printf("Version %d\n", png_access_version_number());
    return 0;
}
