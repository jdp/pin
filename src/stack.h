#ifndef STACK_H
#define STACK_H

typedef struct stack_tag {
	PinValue value;
	struct stack_tag *next;
} StackNode;

typedef struct {
	StackNode *top;
} Stack;

Stack*    stack_create();
int       stack_destroy(Stack*);
int       stack_push(Stack*, StackNode);
StackNode stack_pop(Stack*);

#endif
