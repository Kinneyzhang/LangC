/**
 * Queue: 队列
 * 2022/04/04
 */

#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include "linkedlist.h"

typedef struct _queue {
  Node* front;
  Node* rear;
} Queue;

typedef void(*PRINT)(void*);

void initQueue (Queue* queue);
bool isEmpty (Queue* queue);
int length (Queue* queue);
void enqueue (Queue* queue, void* data);
void* dequeue (Queue* queue);

void initQueue (Queue* queue) {
  queue->front = NULL;
  queue->rear = NULL;
}

bool isEmpty (Queue* queue) {
  return queue->front;
}

int length (Queue* queue) {
  Node* curr = queue->front;
  int len = 0;
  while (curr != NULL) {
    len += 1;
    curr = curr->next;
  }
  return len;
}

void enqueue (Queue* queue, void* data) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;
  Node* rear = queue->rear;
  if (rear == NULL) {
    queue->front = queue->rear = node;
  } else { 
    rear->next = node;
    queue->rear = node;
  }
}

void* dequeue (Queue* queue) {
  Node* front = queue->front;
  if (front == NULL) {
    return NULL;
  } else {
    queue->front = front->next;
    void* data = front->data;
    free(front);
    return data;
  }
}

void printQueue (Queue* queue, PRINT print) {
  Node* curr = queue->front;
  while (curr != NULL) {
    print(curr->data);
    curr = curr->next;
  }
}

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
  for (int i=0; i<5; i++) {
    dequeue(&queue);
    printf("Dequeue: ");
    printQueue(&queue, (PRINT)printInt);
    printf("\n");
  }
  printf("Front: %d\n", *(int*)queue.front->data);
  printf("Rear: %d\n", *(int*)queue.rear->data);
  printf("Length: %d\n", length(&queue));
  if (isEmpty(&queue)) {
    printf("Empty!\n");
  } else {
    printf("Not Empty!\n");
  }
}
