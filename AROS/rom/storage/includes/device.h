#if !defined(_STORAGE_DEVICE_H)
#define _STORAGE_DEVICE_H

/*
    Copyright � 1995-2016, The AROS Development Team. All rights reserved.
    $Id: device.h 52973 2016-10-06 03:28:07Z neil $
*/

/*
    Definitions relating to storage devices (i.e. controllers)
*/

struct StorageDevice
{
    struct Node                 sd_Node;
    struct List                 sd_Units;
};

#endif
