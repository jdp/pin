#include <stdio.h>
#include <stdlib.h>
#include "pin.h"

int PinEvaluate(PIN_CONTEXT* context, PIN_STACK* stack) {
	PIN_AST_NODE* node;
	node = context->node_head; // get first node
	while (node != NULL) {
		switch (node->type) {
			case PINT_IDENT:
				/*
				 * Is the identifier a primitive?
				 * Is it a defined word?
				 */
				break;
			case PINT_NUMBER:
				/* Push a number to the stack */
				break;
			case PINT_QUOTATION:
				/* Push a quotation to the stack */
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
