/*
    Copyright © 2002, The AROS Development Team.
    All rights reserved.

    $Id: aircos_prefs.c 43254 2011-12-27 19:04:57Z jmcmullan $
*/

#include    <exec/types.h>
#include    <stdlib.h>
#include    <stdio.h>
#include    <string.h>
#include    <ctype.h>

#include    <proto/alib.h>
#include    <proto/exec.h>
#include    <proto/dos.h>
#include    <proto/intuition.h>
#include    <proto/muimaster.h>
#include    <proto/graphics.h>

#include    <dos/dos.h>
#include    <intuition/gadgetclass.h>
#include    <intuition/icclass.h>
#include    <clib/alib_protos.h>

#include <libraries/mui.h>
#include <mui/NListtree_mcc.h>
#include <mui/NListview_mcc.h>
#include <mui/NList_mcc.h>
//#include <MUI/BetterString_mcc.h>

#include <utility/hooks.h>

/* Start Network Includes */
#include <proto/socket.h>
#include <bsdsocket/socketbasetags.h>
//#include <sys/param.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <sys/errno.h>

#include <net/if.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#include "aircos_global.h"
#include "locale.h"


const char *aircos_Prefs_DefUser;
const char *aircos_Prefs_DefNick;

BOOL aircosApp_loadPrefs()
{

  /* Setup app defaults for missing prefs options .. */
  if (!(aircos_Prefs_DefUser)) aircos_Prefs_DefUser = _(MSG_DEFAULT_USERNAME);
  if (!(aircos_Prefs_DefNick)) aircos_Prefs_DefNick = _(MSG_DEFAULT_NICKNAME); 
  return TRUE; 
}
