/*
    Copyright © 1995-2011, The AROS Development Team. All rights reserved.
    $Id: partitiontables.h 38399 2011-04-27 07:44:49Z sonic $
*/

#ifndef PARTITIONTABLES_H
#define PARTITIONTABLES_H

#include <exec/nodes.h>
#include <dos/filehandler.h>
#include <intuition/intuition.h>
#include <libraries/partition.h>

struct HDTBPartition;

struct PartitionTable
{
    const struct PartitionAttribute *tattrlist; /* supported partition table attributes */
    const struct PartitionAttribute *pattrlist; /* supported partition attributes */
    ULONG reserved;
    ULONG max_partitions;
    ULONG type;
};

BOOL findPartitionTable(struct HDTBPartition *);
void freePartitionTable(struct HDTBPartition *);
BOOL makePartitionTable(struct HDTBPartition *, ULONG);

void mountPartitions(struct List *);

#endif

