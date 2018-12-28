#ifndef _LISTTREE_PRIVATE_H_
#define _LISTTREE_PRIVATE_H_

/*
    Copyright © 2012, The AROS Development Team. All rights reserved.
    $Id: listtree_private.h 51308 2016-01-17 15:41:47Z deadwood $
*/

#include <libraries/mui.h>

/*** Instance data **********************************************************/
struct Listtree_DATA
{
    /*- Private ------------------------------------------------------------*/
    APTR pool;
    struct Hook *constrhook;
    struct Hook *destrhook;
    struct Hook *displayhook;
    struct Hook *sorthook;

    Object *nlisttree;
    struct Hook notifysimulatehook;
    struct Hook displayhookproxy;
    struct Hook sorthookproxy;
    struct Hook destructhookproxy;
    struct Hook constructhookproxy;

    /*- Protected ----------------------------------------------------------*/

    /*- Public -------------------------------------------------------------*/
};

#endif /* _LISTTREE_PRIVATE_H_ */
