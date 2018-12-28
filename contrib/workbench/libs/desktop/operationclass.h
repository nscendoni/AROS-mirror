/*
   Copyright © 1995-2002, The AROS Development Team. All rights reserved.
   $Id: operationclass.h 30792 2009-03-07 22:40:04Z neil $ 
 */

#ifndef OPERATIONCLASS_H
#    define OPERATIONCLASS_H

#    define OPM_Execute TAG_USER+5001

struct OperationClassData
{
    ULONG           dummy;
};

struct opExecute
{
    STACKED ULONG           MethodID;
    STACKED Object         *target;
    STACKED ULONG           operationCode;
};

#endif
