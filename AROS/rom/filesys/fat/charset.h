/*
    Copyright © 1995-2015, The AROS Development Team. All rights reserved.
    $Id: charset.h 50940 2015-07-09 01:16:32Z neil $
*/

void InitCharsetTables(struct Globals *glob);
BOOL ReadUnicodeTable(struct Globals *glob, STRPTR name);
