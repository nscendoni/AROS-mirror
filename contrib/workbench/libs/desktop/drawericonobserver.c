/*
   Copyright � 1995-2003, The AROS Development Team. All rights reserved.
   $Id: drawericonobserver.c 30792 2009-03-07 22:40:04Z neil $ 
*/

#define MUIMASTER_YES_INLINE_STDARG

#define DEBUG 1
#include <aros/debug.h>

#include <exec/types.h>
#include <exec/memory.h>
#include <intuition/classes.h>
#include <intuition/classusr.h>
#include <libraries/gadtools.h>
#include <libraries/mui.h>
#include <libraries/desktop.h>

#include "support.h"
#include "worker.h"
#include "desktop_intern.h"

#include <proto/desktop.h>
#include <proto/dos.h>
#include <proto/intuition.h>
#include <proto/utility.h>

#include "presentation.h"
#include "observer.h"
#include "iconobserver.h"
#include "drawericonobserver.h"

#include "desktop_intern_protos.h"

#include <string.h>

IPTR drawerIconObserverNew(Class * cl, Object * obj, struct opSet * msg)
{
    IPTR            retval = 0;
    struct DrawerIconObserverClassData *data;
    //struct TagItem *tag;

    retval = DoSuperMethodA(cl, obj, (Msg) msg);
    if (retval)
    {
        obj = (Object *) retval;
        data = INST_DATA(cl, obj);
    }

    return retval;
}

IPTR drawerIconObserverSet(Class * cl, Object * obj, struct opSet * msg)
{
    struct DrawerIconObserverClassData *data;
    IPTR            retval = 1;
    struct TagItem *tag,
                   *tstate = msg->ops_AttrList;

    data = (struct DrawerIconObserverClassData *) INST_DATA(cl, obj);

    while ((tag = NextTagItem(&tstate)))
    {
        switch (tag->ti_Tag)
        {
            default:
                break;
        }
    }

    retval = DoSuperMethodA(cl, obj, (Msg) msg);

    return retval;
}

IPTR drawerIconObserverGet(Class * cl, Object * obj, struct opGet * msg)
{
    IPTR            retval = 1;
    struct DrawerIconObserverClassData *data;

    data = (struct DrawerIconObserverClassData *) INST_DATA(cl, obj);

    switch (msg->opg_AttrID)
    {
        default:
            retval = DoSuperMethodA(cl, obj, (Msg) msg);
            break;
    }

    return retval;
}

IPTR drawerIconObserverDispose(Class * cl, Object * obj, Msg msg)
{
    IPTR            retval;

    retval = DoSuperMethodA(cl, obj, msg);

    return retval;
}

BOOPSI_DISPATCHER(IPTR, drawerIconObserverDispatcher, cl, obj, msg)
{
    ULONG           retval = 0;

    switch (msg->MethodID)
    {
        case OM_NEW:
            retval = drawerIconObserverNew(cl, obj, (struct opSet *) msg);
            break;
        case OM_SET:
            retval = drawerIconObserverSet(cl, obj, (struct opSet *) msg);
            break;
        case OM_GET:
            retval = drawerIconObserverGet(cl, obj, (struct opGet *) msg);
            break;
        case OM_DISPOSE:
            retval = drawerIconObserverDispose(cl, obj, msg);
            break;
        default:
            retval = DoSuperMethodA(cl, obj, msg);
            break;
    }

    return retval;
}
BOOPSI_DISPATCHER_END
