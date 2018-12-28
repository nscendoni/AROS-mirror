/*
    Copyright © 1995-2001, The AROS Development Team. All rights reserved.
    $Id: config.h 30792 2009-03-07 22:40:04Z neil $

    Desc: Amiga bootloader -- config file routines
    Lang: C
*/

extern struct BootConfig *ReadConfig(char *);
extern void FreeConfig(struct BootConfig *);
