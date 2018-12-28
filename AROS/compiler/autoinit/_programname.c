/*
    Copyright © 1995-2014, The AROS Development Team. All rights reserved.
    $Id: _programname.c 53132 2016-12-29 10:32:06Z deadwood $
*/

#include <aros/symbolsets.h>
#include <aros/startup.h>
#include <proto/autoinit.h>


char *_ProgramName = NULL;

void __initprogramname(struct ExecBase *SysBase)
{
    ProgramNameInit((STRPTR *)&_ProgramName);

    __startup_entries_next();

    return;
}

ADD2SET(__initprogramname, PROGRAM_ENTRIES, -20);
