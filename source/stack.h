#ifndef STACK_H
#define STACK_H

PIN_STACK*    PinStack_new(int);
int           PinStack_push(PIN_STACK*, PIN_AST_NODE*);
PIN_AST_NODE* PinStack_pop(PIN_STACK*);
PIN_AST_NODE* PinStack_peek(PIN_STACK*);

#endif