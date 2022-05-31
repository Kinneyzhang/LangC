#ifndef __STACK_H__
#define __STACK_H__

#include "linkedlist.h"

typedef LinkedList Stack;

void initStack (Stack* stack);
bool isStackEmpty(Stack* stack);
int stackLength (Stack* stack);
void push (Stack* stack, void* data);
void* pop (Stack* stack);
void* peek(Stack* stack);
void printStack (Stack* stack, PRINT print);

#endif
