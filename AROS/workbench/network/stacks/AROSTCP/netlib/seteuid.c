/* $Id: seteuid.c 36648 2011-01-17 14:31:59Z neil $
 *
 *      seteuid() - set effective user
 *
 *      Copyright © 1994 AmiTCP/IP Group, 
 *                       Network Solutions Development Inc.
 *                       All rights reserved.
 */

#include <sys/types.h>
#include <unistd.h>

#include <proto/usergroup.h>

#ifdef seteuid
#undef seteuid
#endif

int
seteuid(uid_t u)
{
  return setreuid(-1, u);
}

