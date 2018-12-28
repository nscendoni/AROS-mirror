/*
    Copyright © 1995-2012, The AROS Development Team. All rights reserved.
    $Id: fullscreen.h 45143 2012-07-01 11:23:47Z mazze $

    Desc: Enable fullscreen mode.
    Lang: English.
*/

int x11_fullscreen_supported(Display *display);
void x11_fullscreen_switchmode(Display *display, int *w, int *h);
