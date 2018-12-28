/*
    Copyright © 2004-2016, The AROS Development Team. All rights reserved.
    $Id: getpwuid.c 52857 2016-08-14 18:56:26Z deadwood $
*/

#include <aros/debug.h>
#include <errno.h>

#include "__usergrp.h"

/*****************************************************************************

    NAME */

#include <pwd.h>

        struct passwd *getpwuid(

/*  SYNOPSIS */
        uid_t uid)

/*  FUNCTION

    INPUTS

    RESULT

    NOTES
        Function is not re-entrant. Results will be overwritten by
        subsequent calls.

    EXAMPLE

    BUGS

    SEE ALSO

    INTERNALS

******************************************************************************/
{
    static struct passwd _return = {0};

    if (_return.pw_name == NULL)
        __fill_passwd(&_return);

    if (_return.pw_uid == uid)
        return &_return;

    return NULL;
}

