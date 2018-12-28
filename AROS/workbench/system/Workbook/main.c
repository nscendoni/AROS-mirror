/*
    Copyright © 2011, The AROS Development Team. All rights reserved.
    $Id: main.c 48674 2014-01-02 17:51:04Z neil $

    Desc: Workbook wrapper for CLI
    Lang: english
*/

#include <proto/exec.h>

extern ULONG WorkbookMain(void);

int main(int argc, char **argv)
{
    return WorkbookMain();
}
