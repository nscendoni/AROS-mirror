/*
    Copyright © 1995-2011, The AROS Development Team. All rights reserved.
    $Id: _displayalert.c 47619 2013-07-02 18:27:20Z neil $

    Desc: Display an alert in supervisor mode, Windows hosted version.
    Lang: english
*/

#include "kernel_base.h"

void krnDisplayAlert(const char *text, struct KernelBase *KernelBase)
{
    /* This displays an alert via MessageBox() */
    KernelIFace.core_alert(text);
}
