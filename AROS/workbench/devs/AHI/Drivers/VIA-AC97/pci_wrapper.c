/*
    Copyright © 2004-2013, The AROS Development Team. All rights reserved.
    $Id: pci_wrapper.c 46698 2013-02-25 01:57:03Z neil $
*/

#include <exec/types.h>

#if defined(__AROS__)
#include "pci_aros.c"
#elif defined(__AMIGAOS4__)
#include "pci_aos4.c"
#else
#include "pci_openpci.c"
#endif

