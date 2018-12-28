/*
    Copyright � 1995-2014, The AROS Development Team. All rights reserved.
    $Id: test2.c 49667 2014-09-30 17:35:27Z neil $
*/

#include <stdio.h>

int main (int argc, char ** argv)
{
    char * str;
    int t;

    str = "Hello world.\n";

    printf ("%s", str);

    printf ("argv=%p\n", argv);

    for (t=0; t<argc; t++)
	printf ("Arg %d: %s\n", t, argv[t]);

    return 0;
}
