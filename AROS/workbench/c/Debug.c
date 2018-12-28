/*
    Copyright © 1995-2011, The AROS Development Team. All rights reserved.
    $Id: Debug.c 45720 2012-09-02 16:46:15Z jmcmullan $

    Desc: Debug
    Lang: English
*/

/*****************************************************************************

    NAME
	Debug

    FORMAT
	Debug

    SYNOPSIS

    LOCATION
	C:

    FUNCTION
	Activates built-in AROS debugger (SAD)

    EXAMPLE

    SEE ALSO

******************************************************************************/

#include <proto/exec.h>
#include <aros/shcommands.h>

AROS_SH0(Debug, 1.0)
{
    AROS_SHCOMMAND_INIT

    Debug(0);
    return 0;
    
    AROS_SHCOMMAND_EXIT
}
