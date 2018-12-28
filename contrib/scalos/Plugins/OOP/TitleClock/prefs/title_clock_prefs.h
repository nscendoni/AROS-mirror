// title_clock_prefs.h
// $Date: 2013-12-01 23:08:26 +0100 (Sun, 01 Dec 2013) $
// $Revision: 48481 $

#ifndef TITLE_CLOCK_PREFS_H
#define TITLE_CLOCK_PREFS_H

/* Maximum lengths of strings for date/time formats and the examples */
#define FORMAT_SIZE     32
#define EXAMPLE_SIZE    64

extern char    datestr[FORMAT_SIZE];
extern char    timestr[FORMAT_SIZE];

extern char    date_ex[EXAMPLE_SIZE];
extern char    time_ex[EXAMPLE_SIZE];

extern char    date_re[FORMAT_SIZE];
extern char    time_re[FORMAT_SIZE];
// from debug.lib
extern int kprintf(const char *fmt, ...);

// Debugging Macros
#define d1(x)   ;
#define d2(x)   x;

void    ForcePluginRead(void);

#endif

