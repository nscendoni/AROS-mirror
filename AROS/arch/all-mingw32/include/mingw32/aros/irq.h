#ifndef _AROS_IRQ_H
#define _AROS_IRQ_H

/*
    Copyright © 1995-2010, The AROS Development Team. All rights reserved.
    $Id: irq.h 34602 2010-10-06 06:12:47Z sonic $

    Desc: host-side IRQ API for Windows-hosted AROS
    Lang: english
    
    Warning: this API is experimental and subject to change.
*/

int          __declspec(dllimport) KrnAllocIRQ(void);
void         __declspec(dllimport) KrnFreeIRQ(unsigned char irq);
void *       __declspec(dllimport) KrnGetIRQObject(unsigned char irq);
unsigned int __declspec(dllimport) KrnCauseIRQ(unsigned char irq);

#endif
