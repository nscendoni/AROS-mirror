/*
    Copyright � 1995-2014, The AROS Development Team. All rights reserved.
    $Id: geometry.c 49667 2014-09-30 17:35:27Z neil $
*/

/* This routine differs in different UNIX variants (using different IOCTLs) */

#include <devices/trackdisk.h>

#include <errno.h>

#include "hostdisk_host.h"

ULONG Host_DeviceGeometry(int file, struct DriveGeometry *dg, struct HostDiskBase *hdskBase)
{
    /* Not implemented for generic UNIX */
    return ENOSYS;
}
