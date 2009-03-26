#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"

PinToken *PinTokenCreate(int type, char *source, size_t length) {
	PinToken *token;
	
	if ((token = (PinToken *)malloc(sizeof(PinToken))) == NULL) {
		fputs("Couldn't allocate memory for PinToken\n", stderr);
		return NULL;
	}
	
	token->id = type;
	if ((token->value = (char *)malloc(sizeof(char) * length + 1)) == NULL) {
		fputs("Couldn't allocate memory for PinToken value\n", stderr);
		return NULL;
	}
	memset(token->value, '\0', length + 1);
	strncpy(token->value, source, length);
	token->length = length;
	
	if (token == NULL) {
		fputs("My token is null!\n", stderr);
	}
	
	return token;
}
