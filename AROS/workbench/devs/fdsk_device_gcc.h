#ifndef FDSK_DEVICE_GCC_H
#define FDSK_DEVICE_GCC_H

/*
    Copyright © 1995-2010, The AROS Development Team. All rights reserved.
    $Id: fdsk_device_gcc.h 43306 2011-12-29 15:04:41Z olivieradam $
*/

#include <aros/libcall.h>
#include <exec/devices.h>
#include <exec/semaphores.h>
#include <exec/lists.h>
#include <exec/ports.h>
#include <dos/dos.h>

struct fdskbase
{
    struct Device           device;
    struct SignalSemaphore  sigsem;
    struct MsgPort      port;
    struct MinList      units;
};

struct unit
{
    struct Message      msg;
    struct fdskbase     *fdskbase;
    STRPTR              filename;
    ULONG           unitnum;
    ULONG           usecount;
    struct MsgPort  port;
    BPTR            file;
    BOOL            writable;
    ULONG           changecount;
    struct MinList  changeints;
};

#endif
