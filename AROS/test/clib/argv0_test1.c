/*
    Copyright © 1995-2014, The AROS Development Team. All rights reserved.
    $Id: argv0_test1.c 49667 2014-09-30 17:35:27Z neil $
*/

#include <unistd.h>

#include "test.h"

int main(void)
{
    const char *cmd = "/clib/argv0_slave", *arg1 = "/clib/argv0_slave"; 
    execl(cmd, cmd, arg1, NULL);

    return FAIL;
}
