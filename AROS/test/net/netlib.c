/*
    Copyright © 1995-2014, The AROS Development Team. All rights reserved.
    $Id: netlib.c 49667 2014-09-30 17:35:27Z neil $
*/

/*
 * Small netlib autoopen test.
 * In future may grow into something bigger.
 */

#include <proto/socket.h>

#include <stdio.h>

int __nocommandline = 1;

int main(void)
{
    printf("Library opened, SocketBase is 0x%p\n", SocketBase);

    return 0;
}
