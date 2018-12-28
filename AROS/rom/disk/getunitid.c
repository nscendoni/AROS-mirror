/*
    Copyright � 2010, The AROS Development Team. All rights reserved.
    $Id: getunitid.c 36645 2011-01-17 13:41:08Z neil $

    Desc: GetUnitID() function.
    Lang: english
*/

#include <proto/disk.h>
#include <resources/disk.h>

AROS_LH1(ULONG, GetUnitID,
	 AROS_LHA(LONG, unitNum, D0),
	 struct DiscResource *, DiskBase, 5, Disk)
{
    AROS_LIBFUNC_INIT

	return DiskBase->dr_UnitID[unitNum];

    AROS_LIBFUNC_EXIT
}
