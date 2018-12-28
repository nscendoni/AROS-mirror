/*
    Copyright © 2009, The AROS Development Team. All rights reserved.
    $Id: execl.c 31057 2009-03-29 21:39:39Z verhaegs $

    Desc: Test program for the libc's execl() function.
    Lang: English
*/

#include <stdio.h>
#include <unistd.h>

int main(void)
{
    char *cmd;
    
    cmd = "ls";
    printf("Trying %s\n", cmd);
    execl(cmd, cmd, (char *)NULL);
    perror(cmd);
    
    cmd = "bin:ls";
    printf("Trying %s\n", cmd);
    execl(cmd, cmd, (char *)NULL);
    perror(cmd);
    
    cmd = "/bin/ls";
    printf("Trying %s\n", cmd);
    execl(cmd, cmd, (char *)NULL);
    perror(cmd);
    
    cmd = "C:Dir";
    printf("Trying %s\n", cmd);
    execl(cmd, cmd, (char *)NULL);
    perror(cmd);
    
    return 0;
}
