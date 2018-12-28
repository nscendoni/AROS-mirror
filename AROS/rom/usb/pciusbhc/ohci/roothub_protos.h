/*
   Copyright © 2002-2009, Chris Hodges. All rights reserved.
   Copyright © 2009-2012, The AROS Development Team. All rights reserved.
   $Id: roothub_protos.h 45600 2012-08-19 10:26:41Z neil $
*/

#ifndef ROOTHUB_H
#define ROOTHUB_H

#include "dev.h"

void CheckRootHubChanges(struct PCIUnit *unit);
WORD cmdControlXFerRootHub(struct IOUsbHWReq *ioreq,
    struct PCIUnit *unit, struct PCIDevice *base);
WORD cmdIntXFerRootHub(struct IOUsbHWReq *ioreq,
    struct PCIUnit *unit, struct PCIDevice *base);

#endif /* ROOTHUB_H */
