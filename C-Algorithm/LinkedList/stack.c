/**
 * Stack: 栈
 * 2022/04/07
 */

#include "stack.h"

void initStack (Stack* stack) {
  initList(stack);
}

bool isStackEmpty (Stack* stack) {
  return isEmpty(stack);
}

int stackLength (Stack* stack) {
  return length(stack);
}

void push (Stack* stack, void* data) {
  addTail(stack, data);
}

void* pop (Stack* stack) {
  return deleteNode(stack, stack->tail);
}

void* peek (Stack* stack) {
  return stack->tail->data;
}

void printStack (Stack* stack, PRINT print) {
  printLinkedList(stack, print);
}
