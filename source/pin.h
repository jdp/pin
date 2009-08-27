#ifndef PIN_H
#define PIN_H

/* Dictionary */

typedef struct dict_entry_t {
	char* key;
	char* repr;
	struct dict_entry_t* next;
} PIN_DICT_ENTRY;

typedef struct {
	int size;
	PIN_DICT_ENTRY entries;
} PIN_DICT;

/* AST node types */

typedef enum {
	PINT_IDENT,
	PINT_NUMBER,
	PINT_QUOTATION
} PIN_TYPE;

typedef struct ast_node_t {
	PIN_TYPE type;
	void* quotation; // Actually a PIN_CONTEXT
	struct ast_node_t* next;
	char* repr;
} PIN_AST_NODE;

/* States hold the current execution context */

typedef struct {
	PIN_AST_NODE* elements;
} PIN_STACK;

typedef struct context_t {
	struct context_t* parent;
	PIN_DICT dictionary;
	PIN_AST_NODE* nodes;
	PIN_AST_NODE* node_head;
	PIN_AST_NODE* node_tail;
} PIN_CONTEXT;

/* Function prototypes */

int PinDoFile(char*);
PIN_CONTEXT* PinDo(char*);
void PinError(int, int, char*, ...);

PIN_CONTEXT* PinNew();
PIN_AST_NODE* PinAddNode(PIN_CONTEXT*, PIN_TYPE, char*);

#endif
