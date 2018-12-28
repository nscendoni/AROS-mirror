/*
    Copyright © 2013, The AROS Development Team. All rights reserved.
    $Id: processor_frequency.c 53107 2016-12-27 13:16:31Z deadwood $
*/

#define DEBUG 0

#include <aros/config.h>
#include <aros/debug.h>
#include <proto/exec.h>
#include <resources/processor.h>

#include "processor_arch_intern.h"

VOID ReadMaxFrequencyInformation(struct ARMProcessorInformation * info)
{
    D(bug("[processor.ARM] :%s()\n", __PRETTY_FUNCTION__));

    info->MaxCPUFrequency = 0;
}

UQUAD GetCurrentProcessorFrequency(struct ARMProcessorInformation * info)
{
    UQUAD retFreq = info->MaxCPUFrequency;

    D(bug("[processor.ARM] :%s()\n", __PRETTY_FUNCTION__));

    return retFreq;
}
