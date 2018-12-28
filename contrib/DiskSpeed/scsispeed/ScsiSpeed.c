/*
    Copyright � 1995-2003, The AROS Development Team. All rights reserved.
    $Id: ScsiSpeed.c 30794 2009-03-08 02:19:07Z neil $

    Desc: ScsiSpeed Build definitions.
    Lang: English.

    Based on DiskSpeed v4 by Michael Sinz
*/

/*
    This file is used to just compile the ScsiSpeed version of DiskSpeed.
    We define SCSI_SPEED and then include DiskSpeed.c
*/

#define     SCSI_SPEED      1

#include    "DiskSpeed.c"
