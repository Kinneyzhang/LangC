#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "linkedlist.h"

typedef LinkedList Queue;

void initQueue (Queue* queue);
bool isQueueEmpty (Queue* queue);
int queueLength (Queue* queue);
void enqueue (Queue* queue, void* data);
void* dequeue (Queue* queue);
void printQueue (Queue* queue, PRINT print);

#endif
