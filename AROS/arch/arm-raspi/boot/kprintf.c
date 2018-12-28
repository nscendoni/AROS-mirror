/*
    Copyright © 2013, The AROS Development Team. All rights reserved.
    $Id: kprintf.c 47619 2013-07-02 18:27:20Z neil $
*/

#include <stdio.h>

#include "serialdebug.h"
#include "bootconsole.h"

void putBytes(const char *str)
{
    while(*str)
    {
        fb_Putc(*str);
        putByte(*str++);
    }
}

static char tmpbuf[512];

void kprintf(const char *format, ...)
{
	char *out = tmpbuf;
	va_list vp;

	va_start(vp, format);
	vsnprintf(tmpbuf, 511, format, vp);
	va_end(vp);

	putBytes(out);
}
