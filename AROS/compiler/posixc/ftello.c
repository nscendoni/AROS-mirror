/*
    Copyright © 1995-2014, The AROS Development Team. All rights reserved.
    $Id: ftello.c 49667 2014-09-30 17:35:27Z neil $
*/

#include <stdio.h>

/* FIXME: add autodoc */
off_t ftello(FILE *stream)
{
    /* TODO: implement ftello() */
    return ftell(stream);
}
