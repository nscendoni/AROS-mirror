/*
    Copyright © 1995-2014, The AROS Development Team. All rights reserved.
    $Id: childwait.c 49667 2014-09-30 17:35:27Z neil $
*/

#include <proto/exec.h>
#include <dos/dosextens.h>
#include <proto/dos.h>

LONG entry()
{
    Delay(50);
    return 0;
}

int main()
{
    struct Process *child;
    
    struct TagItem tags[] =
    {
	{ NP_Entry,         (IPTR) entry              },
    	{ NP_Cli,           (IPTR) TRUE               },
        { NP_Name,          (IPTR) "test"             },
        { NP_NotifyOnDeath, (IPTR) TRUE               },
        { TAG_DONE,         0                         }
    };
    
    child = CreateNewProc(tags);
    
    if(child)
    {
	ULONG childid = GetETask((struct Task*) child)->et_UniqueID;
	Printf("Waiting for child with id %d\n", childid);
	ChildWait(childid);
	Printf("Child exited, freeing child\n");
	ChildFree(childid);
    }
    else
	PrintFault(IoErr(), "Couldn't create child process");
    return 0;
}
