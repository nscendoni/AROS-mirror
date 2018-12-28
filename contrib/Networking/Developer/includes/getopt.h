#ifndef GETOPT_H
#define GETOPT_H
/*
    Copyright © 1995-2001, The AROS Development Team. All rights reserved.
    $Id: getopt.h 30794 2009-03-08 02:19:07Z neil $

 */

extern int opterr;
extern int optind;
extern int optopt;
extern char *optarg;
int getopt(int argc, char * const argv[], char const *opts);

#endif /* GETOPT_H */
