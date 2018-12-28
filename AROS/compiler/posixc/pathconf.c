/*
    Copyright © 1995-2014, The AROS Development Team. All rights reserved.
    $Id: pathconf.c 49667 2014-09-30 17:35:27Z neil $
*/

#include <limits.h>	/* _POSIX_*_MAX */
#include <stdio.h>	/* FILENAME_MAX */
#include <unistd.h>	/* _PC_*	*/

/* FIXME: add autodoc */
long pathconf(const char *path, int name)
{
    /* TODO: Implement pathconf() properly */
    switch (name) {
    case _POSIX_NAME_MAX:
	return FILENAME_MAX;
    case _PC_PATH_MAX:
	return PATH_MAX;
    default:
	return -1;
    }
}
