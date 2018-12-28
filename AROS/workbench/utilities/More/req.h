/*
    Copyright © 1995-2001, The AROS Development Team. All rights reserved.
    $Id: req.h 30792 2009-03-07 22:40:04Z neil $

    Desc:
    Lang: English
*/

/****************************************************************************************/

#define SEARCH_NEW 1
#define SEARCH_NEXT 2
#define SEARCH_PREV 3

/****************************************************************************************/

void CleanupRequesters(void);

void Make_Goto_Requester(void);
BOOL Handle_Goto_Requester(LONG *line);
void Kill_Goto_Requester(void);

void Make_Find_Requester(void);
WORD Handle_Find_Requester(char **text);
void Kill_Find_Requester(void);

/****************************************************************************************/
