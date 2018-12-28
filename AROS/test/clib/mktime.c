/*
    Copyright � 1995-2014, The AROS Development Team. All rights reserved.
    $Id: mktime.c 50962 2015-07-16 18:46:56Z neil $
*/

#include <stdio.h>
#include <time.h>

int main(void)
{
    time_t t;
    struct tm *tm;
  
    t=time(NULL);
    printf("Time before: %d\n", (int)t);
    tm=gmtime(&t);
    puts(asctime(tm));
    t=mktime(tm);
    printf("Time after: %d\n", (int)t);
  
    return 0;
}
    
