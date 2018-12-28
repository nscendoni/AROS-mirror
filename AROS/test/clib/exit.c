/*
    Copyright � 2013-2014, The AROS Development Team. All rights reserved.
    $Id: exit.c 48976 2014-04-29 15:24:29Z neil $
*/

#include <stdio.h>
#include <stdlib.h>

#include <aros/debug.h>

static unsigned int level = 0;

int main(void)
{
    bug("Nest level: %u\n", ++level);

    if (level < 20)
    	main();

    bug("About to call exit()...\n");

    exit(0);

    bug("exit() did not work!\n");
    return 20;
}
