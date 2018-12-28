/*
    Copyright © 1995-2014, The AROS Development Team. All rights reserved.
    $Id: util.c 49667 2014-09-30 17:35:27Z neil $
*/

#include <stdlib.h>
#include <stdio.h>
#include "util.h"

void * xmalloc (int size)
{
    void * ptr = malloc (size);

    if (!ptr)
    {
	fprintf (stderr, "Out of memory\n");
	exit (20);
    }

    return ptr;
}

void xfree (void * ptr)
{
    if (ptr)
	free (ptr);
    else
	fprintf (stderr, "Warning: free (NULL);\n");
}
