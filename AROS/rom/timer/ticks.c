/*
    Copyright � 1995-2011, The AROS Development Team. All rights reserved.
    $Id: ticks.c 48424 2013-11-18 09:28:30Z neil $

    Desc: Hardware management routines, template
    Lang: english
*/

#include "timer_intern.h"

void EClockUpdate(struct TimerBase *TimerBase)
{
    /* This is called whenever timer.device wants to read EClock value from the hardware */
}

void EClockSet(struct TimerBase *TimerBase)
{
    /* This is called from SetSysTime() in order to set the new EClock value in hardware */
}
