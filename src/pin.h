#ifndef PIN_H
#define PIN_H

typedef struct {
	mpf_t value;
} PinNumber;

typedef struct {
	size_t len;
	char *value;
} PinString;

typedef enum {
	PINTYPE_NUMBER,
	PINTYPE_STRING
} PinTypeId;

typedef struct {
	PinTypeId type;
	void *value;
} PinValue;

typedef struct {
	PinType *stack;
	unsigned int line;
	int errors;
} PinState;

void PinBlock(char*, size_t);

#endif
