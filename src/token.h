#ifndef TOKEN_H
#define TOKEN_H

typedef struct {
	int    id;     /* Numeric id of the token */
	char*  value;  /* String representation of the token */
	size_t length; /* Length of the token */
} PinToken;

PinToken* PinTokenCreate(int, char*, size_t);

#endif
