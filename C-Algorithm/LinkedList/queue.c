/**
 * Queue: 队列
 * 2022/04/04
 */

#include "queue.h"

void initQueue (Queue* queue) {
  initList(queue);
}

bool isQueueEmpty (Queue* queue) {
  return isEmpty(queue);
}

int queueLength (Queue* queue) {
  return length(queue);
}

void enqueue (Queue* queue, void* data) {
  addTail(queue, data);
}

void* dequeue (Queue* queue) {
  return deleteNode(queue, queue->head);
}

void printQueue (Queue* queue, PRINT print) {
  printLinkedList(queue, print);
}
