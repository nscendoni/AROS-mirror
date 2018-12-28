/*
   Copyright © 2002-2009, Chris Hodges. All rights reserved.
   Copyright © 2009-2012, The AROS Development Team. All rights reserved.
   $Id: pci_protos.h 45600 2012-08-19 10:26:41Z neil $
*/

#ifndef PCI_PROTOS_H
#define PCI_PROTOS_H

#include "dev.h"

BOOL pciInit(struct PCIDevice *hd);
void pciExpunge(struct PCIDevice *hd);
BOOL pciAllocUnit(struct PCIUnit *hu);
void pciFreeUnit(struct PCIUnit *hu);
APTR pciGetPhysical(struct PCIController *hc, APTR virtaddr);

#endif /* PCI_PROTOS_H */
