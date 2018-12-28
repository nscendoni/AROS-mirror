/*
    Copyright © 1995-2001, The AROS Development Team. All rights reserved.
    $Id: exec.c 30792 2009-03-07 22:40:04Z neil $
*/

#include <exec/types.h>

extern void main_init(void * memory, ULONG memSize);

int main(void)
{
	main_init((void *)0x20000,0x4000);
	return 0;
}
