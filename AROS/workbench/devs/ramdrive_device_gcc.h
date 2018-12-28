/*
    Copyright © 1995-2007, The AROS Development Team. All rights reserved.
    $Id: ramdrive_device_gcc.h 30792 2009-03-07 22:40:04Z neil $
*/

#ifndef RAMDRIVE_DEVICE_GCC_H
#define RAMDRIVE_DEVICE_GCC_H

#include <aros/libcall.h>
#include <exec/devices.h>
#include <exec/semaphores.h>
#include <exec/ports.h>
#include <exec/lists.h>

struct ramdrivebase
{
    struct Device 		device;
    struct SignalSemaphore 	sigsem;
    struct MsgPort 		port;
    struct MinList 		units;
};

struct unit
{
    struct Message 		msg;
    struct ramdrivebase 	*ramdrivebase;
    ULONG 			unitnum;
    ULONG			usecount;
    ULONG   	    	    	headpos;
    struct MsgPort 		port;
    UBYTE 			*mem;
};

#endif
