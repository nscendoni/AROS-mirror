/* $Id: fib.c 36648 2011-01-17 14:31:59Z neil $
 *
 *      fib.c - common fib buffer for stat() and chown()
 *
 *      Copyright © 1994 AmiTCP/IP Group, 
 *                       Network Solutions Development Inc.
 *                       All rights reserved.
 */

/* DOS 3.0 and MuFS extensions to file info block */
#include "fibex.h"

struct FileInfoBlock __dostat_fib[1];

