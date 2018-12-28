/*
    Copyright © 1995-2014, The AROS Development Team. All rights reserved.
    $Id: getchildvalue.c 49667 2014-09-30 17:35:27Z neil $
*/

/*
 * This is part of userel.library to check if it can access global variable
 * defined in pertask.library.
 */

#include "pertaskvalue.h"

int GetChildValue(void)
{
    return pertaskvalue;
}
