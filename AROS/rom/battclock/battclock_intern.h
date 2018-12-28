/*
    Copyright © 1995-2010, The AROS Development Team. All rights reserved.
    $Id: battclock_intern.h 33126 2010-04-30 09:44:08Z sonic $

    Desc: Internal data structures for battclock.resource and HIDD
    Lang: english
*/

#ifndef BATTCLOCK_INTERN_H
#define BATTCLOCK_INTERN_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef EXEC_NODES_H
#include <exec/nodes.h>
#endif
#ifndef UTILITY_UTILITY_H
#include <utility/utility.h>
#endif
#ifndef HIDD_HIDD_H
#include <hidd/hidd.h>
#endif

struct BattClockBase
{
    struct Library bb_LibNode;
};

#endif //BATTCLOCK_INTERN_H
