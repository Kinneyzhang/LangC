#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

typedef struct _node {
  void* data;
  struct _node* next;
} Node;

typedef struct _linkedlist {
  Node* head;
  Node* tail;
} LinkedList;

/** 定义函数指针 */
typedef void(*PRINT)(void*);
typedef int(*COMPARE)(void*, void*);

void initList(LinkedList* list);

void addHead(LinkedList* list, void* data);
void addTail(LinkedList* list, void* data);

void buildLinkedList(LinkedList* list, void* arr[], int n);

Node* getNode(LinkedList* list, COMPARE compare, void* data); // main
Node* getNthNode(LinkedList* list, int nth); // main

void insertNode(LinkedList* list, Node* node, void* newData, int flag); // main
void insertNodeBefore(LinkedList* list, Node* node, void* data);
void insertNodeAfter(LinkedList* list, Node* node, void* data);

void insertByData(LinkedList* list, COMPARE compare, void* data, void* newData, int flag);
void insertByDataBefore(LinkedList* list, COMPARE compare, void* data, void* newData);
void insertByDataAfter(LinkedList* list, COMPARE compare, void* data, void* newData);

void insertByNth(LinkedList* list, int nth, void* data);

void deleteNode(LinkedList* list, Node* node); // main
void deleteByData(LinkedList* list, COMPARE compare, void* data);
void deleteByNth(LinkedList* list, int nth);

void updateNode(Node* node, void* data); // main
void updateByData(LinkedList* list, COMPARE compare, void* data, void* newData);
void updateByNth(LinkedList* list, int nth, void* newData);

void printLinkedList(LinkedList* list, PRINT print); // main

#endif
