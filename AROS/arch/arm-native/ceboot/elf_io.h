/*
    Copyright © 1995-2014, The AROS Development Team. All rights reserved.
    $Id: elf_io.h 49667 2014-09-30 17:35:27Z neil $
*/

extern struct ELFNode *FirstELF;

int AddKernelFile(char *name);
void FreeKernelList(void);
