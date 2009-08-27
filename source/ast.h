#ifndef AST_H
#define AST_H

PIN_CONTEXT* PinNew();
PIN_AST_NODE* PinAddNode(PIN_CONTEXT*, PIN_TYPE, char*);
PIN_CONTEXT* PinDoFile(char*);
PIN_CONTEXT* PinDo(char*);
int PinEvaluate(PIN_CONTEXT*, PIN_STACK*);

#endif