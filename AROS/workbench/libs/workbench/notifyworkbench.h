#ifndef _NOTIFYWORKBENCH_H_
#define _NOTIFYWORKBENCH_H_

/*
    Copyright � 2011, The AROS Development Team. All rights reserved.
    $Id: notifyworkbench.h 48674 2014-01-02 17:51:04Z neil $
*/

#include "workbench_intern.h"

enum WBNOTIFY_Action
{
    WBNOTIFY_Create,
    WBNOTIFY_Delete
};

enum WBNOTIFY_Target
{
    WBNOTIFY_AppIcon
};

BOOL NotifyWorkbench(enum WBNOTIFY_Action action, enum WBNOTIFY_Target target, struct WorkbenchBase * WorkbenchBase);

#endif /* _NOTIFYWORKBENCH_H_ */
