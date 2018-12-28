/*
    Copyright © 1995-2014, The AROS Development Team. All rights reserved.
    $Id: kernel_bootmem.h 49667 2014-09-30 17:35:27Z neil $
*/

void *krnAllocBootMem(unsigned int size);
void *krnAllocBootMemAligned(unsigned int size, unsigned int align);
