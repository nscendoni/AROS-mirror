/*
    Copyright © 2013, The AROS Development Team. All rights reserved.
    $Id: vc_mb.h 50385 2015-04-14 17:13:22Z NicJA $
*/

#ifndef VC_MB_H
#define VC_MB_H

#define VCMB_PROPCHAN           8

extern volatile unsigned int *vcmb_read(void *mb, unsigned int chan);
extern void vcmb_write(void *mb, unsigned int chan, void *msg);

#endif	/* VC_MB_H */
