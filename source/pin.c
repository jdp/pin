#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "pin.h"

/* Opens a file and interprets it */
int PinDoFile(char *filename)
{
	FILE *fp;
	struct stat fstats;
	
	if(stat(filename, &fstats) == -1)
	{
		fprintf(stderr, "Couldn't stat `%s'\n", filename);
		return 0;
	}
	if ((fp = fopen(filename, "rb")) == NULL)
	{
		fprintf(stderr, "Couldn't open `%s'\n", filename);
		return 0;
	}
	char *source = (char *)malloc(sizeof(char)*fstats.st_size+1);
	memset(source, '\0', sizeof(char)*fstats.st_size+1);
	if (fread(source, 1, fstats.st_size, fp) != fstats.st_size)
	{
		fprintf(stderr, "Error reading `%s'\n", filename);
		return 0;
	}
	//source[fstats.st_size-1] = '\0'; /* peg fucks up on 0d 0a eof's */
	PinDo(source);
	free(source);
	return 1;
}
	
int main(int argc, char *argv[])
{
	char *filename = argv[argc-1];
	
	if (argc > 0)
	{
		if (PinDoFile(filename))
		{
			return 0;
		}
		else
		{
			fprintf(stderr, "Error executing `%s'\n", filename);
			return 1;
		}
	}
	else
	{
		fputs("Usage: pin <filename>\n", stderr);
		return 1;
	}
}
	
	
