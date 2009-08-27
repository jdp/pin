#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pin.h"
#include "ast.h"
#include "stack.h"

int PinEvaluate(PIN_CONTEXT* context, PIN_STACK* stack) {
	PIN_AST_NODE* node;
	node = context->node_head; // get first node
	printf("EVAL: START: From node repr:%s\n", node->repr);
	while (node != NULL) {
		switch (node->type) {
			case PINT_IDENT:
				if (!strcmp("add", node->repr)) {
					printf("EVAL: add instruction\n");
				}
				else if (!strcmp("call", node->repr)) {
					PIN_AST_NODE* qnode = PinStack_pop(stack);
					PinEvaluate((PIN_CONTEXT*)qnode->quotation, stack);
				}
				break;
			case PINT_NUMBER:
				printf("EVAL: Pushed a number %s\n", node->repr);
				PinStack_push(stack, node);
				break;
			case PINT_QUOTATION:
				printf("EVAL: Pushed a quotation\n");
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
