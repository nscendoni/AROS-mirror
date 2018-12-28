/*
    Copyright © 2013-2014, The AROS Development Team. All rights reserved.
    $Id: assert.c 48972 2014-04-25 15:45:34Z neil $
*/

#include <assert.h>
#include <stdio.h>

int main(void)
{
    printf("Expecting a failed assertion...\n");
    assert(0);
    
    return 20;
}
