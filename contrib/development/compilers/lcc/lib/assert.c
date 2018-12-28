#include <stdio.h>
#include <stdlib.h>

static char rcsid[] = "$Id: assert.c 30794 2009-03-08 02:19:07Z neil $";

int _assert(char *e, char *file, int line) {
	fprintf(stderr, "assertion failed:");
	if (e)
		fprintf(stderr, " %s", e);
	if (file)
		fprintf(stderr, " file %s", file);
	fprintf(stderr, " line %d\n", line);
	fflush(stderr);
	abort();
	return 0;
}
