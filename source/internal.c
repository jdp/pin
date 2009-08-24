#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pin.h"

/* Returns a new Pin context */
PIN_CONTEXT* PinNew() {
	PIN_CONTEXT* context = NULL;
	context = (PIN_CONTEXT*)malloc(sizeof(PIN_CONTEXT));
	if (context == NULL) {
		fprintf(stderr, "Failed to create new Pin context\n");
		return NULL;
	}
	context->node_head = NULL;
	context->node_tail = NULL;
	context->nodes = NULL;
	return context;
}

PIN_AST_NODE* PinAddNode(PIN_CONTEXT* ctx, PIN_TYPE type, char* repr) {
	PIN_AST_NODE* node = NULL;
	node = (PIN_AST_NODE*)malloc(sizeof(PIN_AST_NODE));
	if (node == NULL) {
		fprintf(stderr, "Failed to create new AST node\n");
		return NULL;
	}
	node->type = type;
	if (type == PINT_QUOTATION) {
		node->quotation = PinNew();
	}
	else {
		node->quotation = NULL;
	}
	node->next = NULL;
	node->repr = (char*)malloc(sizeof(char)*strlen(repr));
	strcpy(node->repr, repr);
	if (ctx->node_head == NULL) {
		ctx->node_head = node;
	}
	else {
		ctx->node_tail->next = node;
	}
	ctx->node_tail = node;
	return node;
}
