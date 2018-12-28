/*
    Copyright © 2015, The AROS Development Team. All rights reserved.
    $Id: preboot.c 51948 2016-03-14 19:21:58Z neil $
*/

#include <unistd.h>
#include <syscall.h>

pid_t arostid;

void Host_PreBoot()
{
    arostid = syscall(SYS_gettid);
}
