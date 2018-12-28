/*
    Copyright © 2013, The AROS Development Team. All rights reserved.
    $Id: mbox_private.h 50277 2015-04-01 01:16:56Z NicJA $
*/

#ifndef MBOX_PRIVATE_H_
#define MBOX_PRIVATE_H_

#include <exec/nodes.h>
#include <exec/semaphores.h>
#include <inttypes.h>

struct MBoxBase {
    struct Node		        mbox_Node;
    struct SignalSemaphore      mbox_Sem;
};

#endif /* MBOX_PRIVATE_H_ */
