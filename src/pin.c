#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>
#include "pin.h"
#include "grammar.h"
#include "token.h"

int main(int argc, char **argv) {
	FILE *fp;
	long fsize;
	char *buffer;
	size_t result;
	
	if (argc < 2) {
		fputs("Usage: pin <filename.pin>\n", stderr);
		exit(1);
	}
	
	if ((fp = fopen(argv[1], "rb")) == NULL) {
		fputs("File open error\n", stderr);
		exit(1);
	}
	
	fseek(fp, 0, SEEK_END);
	fsize = ftell(fp);
	rewind(fp);
	
	buffer = (char *)malloc(sizeof(char)*fsize);
	if (buffer == NULL) {
		fputs("Memory error\n", stderr);
		exit(2);
	}
	
	result = fread(buffer, 1, fsize, fp);
	if (result != fsize) {
		fputs("File read error\n", stderr);
		exit(3);
	}
	
	PinBlock(buffer, result);
	
	fclose(fp);
	free(buffer);
	return 0;
}
