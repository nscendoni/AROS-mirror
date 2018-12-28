/*  $Id: MakeTestDisk.c 51565 2016-02-29 15:26:35Z NicJA $
    test program to make disk for archiver tests

    XAD library system for archive handling
    Copyright (C) 1998 and later by Dirk St�cker <soft@dstoecker.de>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include <stdio.h>
#include <proto/exec.h>
#include <devices/trackdisk.h>

int main(void)
{
  struct MsgPort *port;
      
  if((port = CreateMsgPort()))
  {
    struct IOExtTD *ioreq;

    if((ioreq = (struct IOExtTD *) CreateIORequest(port, sizeof(struct IOExtTD))))
    {
      if(!OpenDevice("trackdisk.device", 0, (struct IORequest *) ioreq, 0))
      {
        int i, j;
        char buf[512], Label[16];

	for(i = 0; i < 1760; ++i)
	{
	  sprintf(Label, "SecLabel * %4ld", (long int)i);
	  sprintf(buf, "***** Block Number %4ld *****", (long int)i);
	  for(j = 30; j < 512; ++j)
	    buf[j] = i ^ j;
	
          ioreq->iotd_Req.io_Flags   = 0;
	  ioreq->iotd_Req.io_Command = ETD_WRITE;
	  ioreq->iotd_Req.io_Data    = buf;
	  ioreq->iotd_Req.io_Length  = 512;
	  ioreq->iotd_Req.io_Offset  = i * 512;
	  ioreq->iotd_SecLabel = (IPTR) Label;
	  ioreq->iotd_Count = 0xFFFFFFFF;
	  if((j = DoIO(((struct IORequest *) ioreq))))
	  {
	    printf("Error %ld with block %ld\n", (long int)j, (long int)i);
	    break;
	  }
	}

	CloseDevice((struct IORequest *) (ioreq));
      } /* OpenDevice */
      DeleteIORequest((struct IOStdReq *) ioreq);
    } /* CreatIORequest */
    DeleteMsgPort(port);
  } /* CreateMsgPort */
  return 0;
}
