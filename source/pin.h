#ifndef PIN_H
#define PIN_H

typedef unsigned long PIN_ITEM;

typedef struct {
	char *repr;
} PIN_WORD;

typedef struct {
	char *repr;
	double value;
} PIN_NUMBER;

typedef struct {
	PIN_ITEM* items;
} PIN_QUOTATION;

typedef enum {
	PINT_IDENT,
	PINT_NUMBER,
	PINT_QUOTATION
} PIN_TYPE;

typedef struct ast_node_t {
	PIN_TYPE type;
	void* quotation; // Actually a PIN_CONTEXT
	struct ast_node_t* previous;
	struct ast_node_t* next;
	char* repr;
} PIN_AST_NODE;

typedef struct context_t {
	struct context_t* parent;
	PIN_AST_NODE* node_head;
	PIN_AST_NODE* node_tail;
} PIN_CONTEXT;

typedef struct {
	PIN_AST_NODE** elements;
	int size;
	int top;
} PIN_STACK;

/* Function prototypes */

void PinError(int, int, char*, ...);

#endif
