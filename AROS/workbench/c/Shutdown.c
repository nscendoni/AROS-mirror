/*
    Copyright © 2008-2014, The AROS Development Team. All rights reserved.
    $Id: Shutdown.c 48905 2014-04-03 17:15:39Z neil $
*/

#include <exec/tasks.h>
#include <proto/dos.h>
#include <proto/exec.h>

/**************************************************************************

    NAME
	Shutdown

    SYNOPSIS
	(N/A)

    LOCATION
	C:

    FUNCTION
           Shut down AROS and power off the machine.

**************************************************************************/


int main(void)
{
    ShutdownA(SD_ACTION_POWEROFF);
    PutStr("Shutdown failed\n");
    return RETURN_FAIL;
}
