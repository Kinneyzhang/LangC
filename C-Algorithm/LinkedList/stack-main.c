#include "stack.h"

void printInt (int* data) {
  printf("%d ", *data);
}

int main () {
  Stack stack;
  initStack(&stack);
  int y1 = 3; int y2 = 5;
  int y3 = 6; int y4 = 1;
  int y5 = 4; int y6 = 2;
  int* arr[6] = {&y1, &y2, &y3, &y4, &y5, &y6};
  
  for (int i=0; i<6; i++) {
    push(&stack, arr[i]);
    printf("Push %d: ", *arr[i]);
    printStack(&stack, (PRINT)printInt);
    printf("\tPeek: %d", *(int*)peek(&stack));
    printf("\tLength: %d\n", stackLength(&stack));
  }
  
  for (int i=6; i>0; i--) {
    pop(&stack);
    printf("Pop  %d: ", *arr[i-1]);
    printStack(&stack, (PRINT)printInt);
    if (i != 1) {
      printf("\tPeek: %d", *(int*)peek(&stack));
      printf("\tLength: %d\n", stackLength(&stack));
    } else {
      printf("\tLength: %d\n", stackLength(&stack));
    }
  }
  
  if (isEmpty(&stack)) {
    printf("Empty!\n");
  } else {
    printf("Not Empty!\n");
  }
}
