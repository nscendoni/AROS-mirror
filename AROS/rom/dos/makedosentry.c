/*
    (C) 1995-96 AROS - The Amiga Replacement OS
    $Id$
    $Log$
    Revision 1.5  1996/10/24 15:50:32  aros
    Use the official AROS macros over the __AROS versions.

    Revision 1.4  1996/10/10 13:20:50  digulla
    Use dol_DevName(STRPTR) instead of dol_Name(BSTR) (Fleischer)

    Revision 1.3  1996/08/13 13:52:49  digulla
    Replaced <dos/dosextens.h> by "dos_intern.h" or added "dos_intern.h"
    Replaced AROS_LA by AROS_LHA

    Revision 1.2  1996/08/01 17:40:54  digulla
    Added standard header for all files

    Desc:
    Lang: english
*/
#include <exec/memory.h>
#include <clib/exec_protos.h>
#include "dos_intern.h"

/*****************************************************************************

    NAME */
	#include <clib/dos_protos.h>

	AROS_LH2(struct DosList *, MakeDosEntry,

/*  SYNOPSIS */
	AROS_LHA(STRPTR, name, D1),
	AROS_LHA(LONG,   type, D2),

/*  LOCATION */
	struct DosLibrary *, DOSBase, 116, Dos)

/*  FUNCTION
	Create an entry for the dos list. Depending on the type this may
	be a device a volume or an assign node.

    INPUTS
	name - pointer to name
	type - type of list entry to create

    RESULT

    NOTES

    EXAMPLE

    BUGS

    SEE ALSO

    INTERNALS

    HISTORY
	29-10-95    digulla automatically created from
			    dos_lib.fd and clib/dos_protos.h

*****************************************************************************/
{
    AROS_LIBFUNC_INIT
    AROS_LIBBASE_EXT_DECL(struct DosLibrary *,DOSBase)

    STRPTR s2, s3;
    struct DosList *dl;

    dl=(struct DosList *)AllocMem(sizeof(struct DosList),MEMF_PUBLIC|MEMF_CLEAR);
    if(dl!=NULL)
    {
	s2=name;
	while(*s2++)
	    ;
	s3=(STRPTR)AllocMem(s2-name+1,MEMF_PUBLIC);
	if(s3!=NULL)
	{
	    /* Compatibility */
	    dl->dol_OldName=MKBADDR(s3);
	    *s3++=s2-name>256?255:s2-name-1;

	    CopyMem(name,s3,s2-name);
	    dl->dol_DevName=s3;
	    dl->dol_Type=type;
	    return dl;
	}
	FreeMem(dl,sizeof(struct DosList));
    }
    return NULL;
    AROS_LIBFUNC_EXIT
} /* MakeDosEntry */
