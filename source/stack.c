#include <stdio.h>
#include <stdlib.h>
#include "pin.h"
#include "ast.h"
#include "stack.h"

PIN_STACK* PinStack_new(int size) {
	PIN_STACK* stack;
	if ((stack = (PIN_STACK*)malloc(sizeof(PIN_STACK))) == NULL) {
		fprintf(stderr, "Not enough memory for a new stack\n");
		exit(1);
		return NULL;
	}
	stack->size = size;
	if ((stack->elements = (PIN_AST_NODE**)malloc(sizeof(PIN_AST_NODE*)*size)) == NULL) {
		fprintf(stderr, "Not enough memory to set stack size to %d\n", size);
		exit(1);
		return NULL;
	}
	stack->top = -1;
	return stack;
}

int PinStack_push(PIN_STACK* stack, PIN_AST_NODE* node) {
	/* TODO: grow stack */
	if (stack->top < stack->size) {
		stack->elements[++stack->top] = node;
		return 1;
	}
	else {
		return 0;
	}
}

PIN_AST_NODE* PinStack_pop(PIN_STACK* stack) {
	if (stack->top >= 0) {
		return stack->elements[stack->top--];
	}
	else {
		return NULL;
	}
}

PIN_AST_NODE* PinStack_peek(PIN_STACK* stack) {
	if (stack->top >= 0) {
		return stack->elements[stack->top];
	}
	else {
		return NULL;
	}
}