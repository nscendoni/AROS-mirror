#include <stdio.h>
#include <stdlib.h>

static char rcsid[] = "$Id: yynull.c 30794 2009-03-08 02:19:07Z neil $";

void _YYnull(char *file, int line) {
	fprintf(stderr, "null pointer dereferenced:");
	if (file)
		fprintf(stderr, " file %s,", file);
	fprintf(stderr, " line %d\n", line);
	fflush(stderr);
	abort();
}
