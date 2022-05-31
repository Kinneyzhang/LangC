#include "queue.h"

void printInt (int* data) {
  printf("%d ", *data);
}

int main () {
  Queue queue;
  initQueue(&queue);
  int x1 = 3; int x2 = 5;
  int x3 = 6; int x4 = 1;
  int x5 = 4; int x6 = 2;
  int* arr[6] = {&x1, &x2, &x3, &x4, &x5, &x6};
  for (int i=0; i<6; i++) {
    enqueue(&queue, arr[i]);
  }
  printf("Queue: ");
  printQueue(&queue, (PRINT)printInt);
  printf("\n");
  for (int i=0; i<6; i++) {
    dequeue(&queue);
    printf("Dequeue: ");
    printQueue(&queue, (PRINT)printInt);
    printf("\n");
  }
  if (queue.head) {
    printf("Head: %d\n", *(int*)queue.head->data);
    printf("Tail: %d\n", *(int*)queue.tail->data);
  }
  printf("Length: %d\n", queueLength(&queue));
  if (isEmpty(&queue)) {
    printf("Empty!\n");
  } else {
    printf("Not Empty!\n");
  }
}

