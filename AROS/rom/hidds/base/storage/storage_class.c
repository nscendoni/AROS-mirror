/*
    Copyright (C) 2015-2016, The AROS Development Team. All rights reserved.
    $Id: storage_class.c 51948 2016-03-14 19:21:58Z neil $
*/

#define DEBUG 1
#include <aros/debug.h>
#include <oop/oop.h>
#include <utility/tagitem.h>

#include "storage_intern.h"

OOP_Object *StorageHW__Root__New(OOP_Class *cl, OOP_Object *o, struct pRoot_New *msg)
{
    if (!CSD(cl)->instance)
    {
        struct TagItem new_tags[] =
        {
            {aHW_ClassName, (IPTR)"Storage Controllers"},
            {TAG_DONE     , 0          }
        };
        struct pRoot_New new_msg =
        {
            .mID      = msg->mID,
            .attrList = new_tags
        };

        CSD(cl)->instance =  (OOP_Object *)OOP_DoSuperMethod(cl, o, &new_msg.mID);
    }

    return CSD(cl)->instance;
}

VOID StorageHW__Root__Dispose(OOP_Class *cl, OOP_Object *o, OOP_Msg msg)
{
    /* We are singletone. Cannot dispose. */
}
