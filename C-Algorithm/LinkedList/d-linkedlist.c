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
int length (LinkedList* list);
void printLinkedList (LinkedList* list, PRINT print);
void buildLinkedList (LinkedList* list, void* arr[], int n);
void addHead (LinkedList* list, void* data);
void addTail (LinkedList* list, void* data);
Node* getNode (LinkedList* list, COMPARE compare, void* data);
Node* getNthNode (LinkedList* list, int nth);
void insertNode (LinkedList* list, Node* node, void* newData, int flag);
void deleteNode (LinkedList* list, Node* node);
void updateNode (Node* node, void* data);
/**************************************************/

void initList (LinkedList* list) {
  list->head = NULL;
  list->tail = NULL;
}

int length (LinkedList* list) {
  int count = 0;
  Node* curr = list->head;
  while (curr != NULL) {
    count += 1;
    curr = curr->next;
  }
  return count;
}

void printLinkedList (LinkedList* list, PRINT print) {
  Node* curr = list->head;
  while (curr != NULL) {
    print(curr->data);
    curr = curr->next;
  }
}

void buildLinkedList (LinkedList* list, void* arr[], int n) {
  initList(list);
  for (int i=0; i<n; i++) {
    addTail(list, arr[i]);
  }
}

void addHead (LinkedList* list, void* data) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->data = data;
  Node* head = list->head;
  if (head == NULL) {
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
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = newData;
  if (flag == 0) {
    if (node == list->head) {
      newNode->prev = NULL;
      newNode->next = node;
      node->prev = newNode;
      list->head = newNode;
    } else {
      newNode->prev = node->prev;
      newNode->next = node;
      node->prev->next = newNode;
      node->prev = newNode;
    }
  }
  if (flag == 1) {
    if (node == list->tail) {
      newNode->prev = node;
      newNode->next = NULL;
      node->next = newNode;
      list->tail = newNode;
    } else {
      newNode->prev = node;
      newNode->next = node->next;
      node->next->prev = newNode;
      node->next = newNode;
    }
  }
}

void deleteNode (LinkedList* list, Node* node) {
  if (list->head == node) {
    list->head = node->next;
    free(node);
  }
  if (list->tail == node) {
    list->tail = node->prev;
    free(node);
  }
  node->prev->next = node->next;
  node->next->prev = node->prev;
  free(node);
}

void updateNode (Node* node, void* data) {
  node->data = data;
}

/**************************************************/

void printInt (void* data) {
  printf("%d ", *(int*)data);
}

int compareInt (void* data1, void* data2) {
  if (*(int*)data1 == *(int*)data2) {
    return 0;
  }
  return -1;
}

int main () {
  LinkedList list;
  
  int a = 3; int b = 1;
  int c = 4; int d = 7;
  int e = 5; int f = 2;
  int g = 8; int h = 9;

  int* arr[8] = {&h, &g, &f, &e, &a, &b, &c, &d};
  buildLinkedList(&list, (void**)arr, 8);
  printf("Print Linkedlist: ");
  printLinkedList(&list, (PRINT)printInt);
  printf("\n\n");
    
  for (int i=0; i<8; i++) {
    printf("The nth %d data: %d\n", i+1, *(int*)getNthNode(&list, i+1)->data);
  }
  printf("\n");
    
  int i = 6;
  Node * node1 = getNode(&list, (COMPARE)compareInt, &b);
  insertNode(&list, node1, &i, 1);
  printf("Insert 6 after 1: ");
  printLinkedList(&list, (PRINT)printInt);
  printf("\n\n");
    
  Node * node2 = getNode(&list, (COMPARE)compareInt, &i);
  deleteNode(&list, node2); // delete 6
  printf("Delete 6: ");
  printLinkedList(&list, (PRINT)printInt);
  printf("\n\n");
    
  insertNode(&list, list.head, &i, 0);
  printf("Insert 6 before head: ");
  printLinkedList(&list, (PRINT)printInt);
  printf("\n\n");

  insertNode(&list, list.tail, &i, 1);
  printf("Insert 6 after tail: ");
  printLinkedList(&list, (PRINT)printInt);
  printf("\n\n");

  Node* node3 = getNode(&list, (COMPARE)compareInt, &g);
  printf("Update 8 to 10: ");
  int j = 10;
  updateNode(node3, &j);
  printLinkedList(&list, (PRINT)printInt);
  printf("\n\n");

  printf("Length of linkedlist: %d\n", length(&list));
}

// 写C代码一定要注意类型
