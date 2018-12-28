/*
    Copyright © 1995-2001, The AROS Development Team. All rights reserved.
    $Id: rewinddir.c 48031 2013-09-08 21:16:04Z verhaegs $
*/

/*****************************************************************************

    NAME */

#include <dirent.h>

	void rewinddir(

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
    seekdir(dir, 0);
}

