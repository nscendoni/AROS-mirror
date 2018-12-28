/*
    Copyright © 1995-2014, The AROS Development Team. All rights reserved.
    $Id: argv0_slave.c 49667 2014-09-30 17:35:27Z neil $
*/

#include <stdio.h>
#include <string.h>

#include "test.h"

int main(int argc, char *argv[])
{
    TEST(argc == 2);
    TEST(strcmp(argv[0], argv[1]) == 0);

    return OK;
}

void cleanup(void)
{
    /* NOP */
    return;
}
