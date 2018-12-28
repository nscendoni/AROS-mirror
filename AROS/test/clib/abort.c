/*
    Copyright © 1995-2014, The AROS Development Team. All rights reserved.
    $Id: abort.c 49667 2014-09-30 17:35:27Z neil $
*/

#include <stdlib.h>

#include <aros/debug.h>

int main(void)
{
    abort();

    bug("Abort() did not work!\n");

    return 20;
}
