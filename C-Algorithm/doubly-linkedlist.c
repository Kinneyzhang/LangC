/**
 * Doubly-Linkedlist: 双向链表
 * 2022/04/02
 */

#include<stdlib.h>
#include<stdio.h>

typedef struct _node {
  void* data;
  struct _node* prev;
  struct _node* next;
} Node;

typedef struct _linkedlist {
  Node *head;
  Node *tail;
} LinkedList;

typedef int(*COMPARE)(void*, void*);
typedef void(*PRINT)(void*);

/**************************************************/
void initList (LinkedList* list);
void addHead (LinkedList* list, void* data);
void addTail (LinkedList* list, void* data);
int length (LinkedList* list);
Node* getNode (LinkedList* list, COMPARE compare, void* data);
Node* getNthNode (LinkedList* list, int nth);
void insertNode (LinkedList* list, Node* node, void* newData, int flag);
void deleteNode (LinkedList* list, Node* node);
void updateNode (LinkedList* list, Node* node, void* data);
void printLinkedList (LinkedList* list, PRINT print);
/**************************************************/

void initList (LinkedList* list) {
  list->head = NULL;
  list->tail = NULL;
}

void addHead (LinkedList* list, void* data) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->data = data;
  Node* head = list->head;
  if (head = NULL) {
      list->tail = node;
      node->next = NULL;
  } else {
      node->next = head;
      head->prev = node;
  }
  node->prev = NULL;
  list->head = node;
}

void addTail (LinkedList* list, void* data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    Node* tail = list->tail;
    if (tail == NULL) {
        list->head = node;
        node->prev = NULL;
    } else {
        tail->next = node;
        node->prev = tail;
    }
    node->next = NULL;
    list->tail = node;   
}

Node* getNode (LinkedList* list, COMPARE compare, void* data) {
    Node* curr = list->head;
    while (curr != NULL) {
        if (compare(curr->data, data) == 0) {
            return curr;
            break;
        }
        curr = curr->next;
    }
    return NULL;
}

Node* getNthNode (LinkedList* list, int nth) {
    Node* curr = list->head;
    int pos = 0;
    while (curr != NULL) {
        pos += 1;
        if (pos == nth) {
            return curr;
            break;
        }
        curr = curr->next;
    }
    return NULL;
}

void insertNode (LinkedList* list, Node* node, void* newData, int flag) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = newData;
    
}
