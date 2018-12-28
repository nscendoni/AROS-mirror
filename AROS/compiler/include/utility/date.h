#ifndef UTILITY_DATE_H
#define UTILITY_DATE_H

/*
    Copyright © 1995-2001, The AROS Development Team. All rights reserved.
    $Id: date.h 30792 2009-03-07 22:40:04Z neil $

    Desc: ClockData
    Lang: English
*/

#ifndef EXEC_TYPES_H
#   include <exec/types.h>
#endif

struct ClockData
{
    UWORD sec;
    UWORD min;
    UWORD hour;
    UWORD mday;
    UWORD month;
    UWORD year;
    UWORD wday;
};

#endif /* UTILITY_DATE_H */
