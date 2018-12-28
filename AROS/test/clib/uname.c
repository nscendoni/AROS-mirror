/*
    Copyright � 1995-2014, The AROS Development Team. All rights reserved.
    $Id: uname.c 49667 2014-09-30 17:35:27Z neil $
*/

#include <stdio.h>
#include <sys/utsname.h>
#include "test.h"

int main()
{
    struct utsname buf;
    TEST((uname(&buf) != -1));

    printf("Operating system name: %s\n", buf.sysname);
    printf("Operating system release: %s\n", buf.release);
    printf("Operating system version: %s\n", buf.version);
    printf("Machine: %s\n", buf.machine);
    
    cleanup();
    return OK;
}

void cleanup()
{
}
