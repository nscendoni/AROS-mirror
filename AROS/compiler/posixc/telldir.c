/*
    Copyright © 1995-2012, The AROS Development Team. All rights reserved.
    $Id: telldir.c 48031 2013-09-08 21:16:04Z verhaegs $
*/

#include "__dirdesc.h"

/*****************************************************************************

    NAME */

#include <dirent.h>

	long telldir(

/*  SYNOPSIS */
	DIR *dir)

/*  FUNCTION

    INPUTS

    RESULT

    NOTES

    EXAMPLE

    BUGS

    SEE ALSO

    INTERNALS

******************************************************************************/
{
    return dir->pos;
}

