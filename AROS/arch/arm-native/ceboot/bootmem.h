/*
    Copyright � 1995-2014, The AROS Development Team. All rights reserved.
    $Id: bootmem.h 49667 2014-09-30 17:35:27Z neil $
*/

extern ULONG_PTR bootmem_Phys;

ULONG_PTR InitBootMem(void);
void *AllocBootMem(unsigned int size);
void *AddTag(unsigned int tag, ULONG_PTR data);
