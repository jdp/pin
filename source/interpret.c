#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pin.h"
#include "ast.h"
#include "stack.h"

#define PIN_WORD(W) Pin_##W(context, stack)

void Pin_add(PIN_CONTEXT* context, PIN_STACK* stack) {
	PIN_AST_NODE* op_a, * op_b, * result_node;
	op_a = PinStack_pop(stack);
	op_b = PinStack_pop(stack);
	int result = atoi(op_a->repr) + atoi(op_b->repr);
	result_node = (PIN_AST_NODE*)malloc(sizeof(PIN_AST_NODE));
	result_node->repr = (char*)malloc(sizeof(char)*8);
	sprintf(result_node->repr, "%d", result);
	PinStack_push(stack, result_node);
}

void Pin_print(PIN_CONTEXT* context, PIN_STACK* stack) {
	PIN_AST_NODE* op_a;
	op_a = PinStack_pop(stack);
	switch (op_a->type) {
		case PINT_IDENT:
		case PINT_NUMBER:
			printf("%s", op_a->repr);
			break;
		case PINT_QUOTATION:
			printf("#Quotation");
			break;
	}
}

void Pin_println(PIN_CONTEXT* context, PIN_STACK* stack) {
	PIN_AST_NODE* op_a;
	op_a = PinStack_pop(stack);
	switch (op_a->type) {
		case PINT_IDENT:
		case PINT_NUMBER:
			printf("%s\n", op_a->repr);
			break;
		case PINT_QUOTATION:
			printf("#Quotation\n");
			break;
	}
}

void Pin_call(PIN_CONTEXT* context, PIN_STACK* stack) {
	PIN_AST_NODE* qnode = PinStack_pop(stack);
	PinEvaluate((PIN_CONTEXT*)qnode->quotation, stack);
}

int PinEvaluate(PIN_CONTEXT* context, PIN_STACK* stack) {
	PIN_AST_NODE* node;
	node = context->node_head; // get first node
	while (node != NULL) {
		switch (node->type) {
			case PINT_IDENT:
				if (!strcmp("add", node->repr)) {
					PIN_WORD(add);
				}
				else if (!strcmp("print", node->repr)) {
					PIN_WORD(print);
				}
				else if (!strcmp("println", node->repr)) {
					PIN_WORD(println);
				}
				else if (!strcmp("call", node->repr)) {
					PIN_WORD(call);
				}
				break;
			case PINT_NUMBER:
				PinStack_push(stack, node);
				break;
			case PINT_QUOTATION:
				PinStack_push(stack, node);
				break;
			default:
				/* Not sure what should happen here */
				return 0;
				break;
		}
		node = node->next;
	}
	return 1;
}
