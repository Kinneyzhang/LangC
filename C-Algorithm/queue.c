/**
 * Queue: 队列
 * 2022/04/04
 */

#include<stdlib.h>
#include<stdio.h>
#include "linkedlist.h"

typedef struct _queue {
  Node* front;
  Node* rear;
} Queue;

boolean isEmpty (Queue* queue);
int length (Queue* queue);
void enqueue (Queue* queue, void* data);
Node* dequeue (Queue* queue);

void enqueue (Queue* queue, void* data) {
  
}
