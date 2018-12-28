#if !defined(_STORAGE_VOLUME_H)
#define _STORAGE_VOLUME_H

/*
    Copyright © 1995-2016, The AROS Development Team. All rights reserved.
    $Id: volume.h 52973 2016-10-06 03:28:07Z neil $
*/

struct StorageVolume
{
    struct Node                 sv_Node;        // ln_Name points to the IDNode;
    struct StorageUnit          *sv_Unit;
};

#endif
