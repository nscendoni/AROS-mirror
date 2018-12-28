/*
    Copyright © 1995-2014, The AROS Development Team. All rights reserved.
    $Id: usleep.c 49667 2014-09-30 17:35:27Z neil $
*/

#include "test.h"
#include <stdio.h>
#include <unistd.h>

int main() 
{
    TEST((usleep(1000000) != -1));
    return OK;
}

void cleanup()
{
}
