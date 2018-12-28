/*
    Copyright © 1995-2014, The AROS Development Team. All rights reserved.
    $Id: cfgetispeed.c 49667 2014-09-30 17:35:27Z neil $
*/

#include "__termios.h"

/* FIXME: Add autodocs */
speed_t cfgetispeed(const struct termios *__termios_p)
{
    if (__termios_p)
    {
        struct termios_intern *t = (struct termios_intern *)__termios_p;
        return t->c_ispeed;
    }

    /* According to man pages and online standard documents providing an
     * invalid pointer does not result in an error. Tests on Linux resulted
     * in segmentation faults, we can not do this so we retun a speed of 0.
     */
    return B0;
}
