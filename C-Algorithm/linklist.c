// 链表
// 链表涉及的操作：
// 创建链表、遍历链表、插入一个节点、删除一个节点

#include<stdlib.h>
#include<stdio.h>

typedef struct _node {
  void* data;
  struct _node* next;
} Node;

typedef struct _linklist {
  Node* head;
  Node* tail;
} LinkedList;

// 定义函数指针
typedef void(*PRINT)(void*);

void initList(LinkedList* list) {
  list->head = NULL;
  list->tail = NULL;
}

// 通过 data 以 void指针形式传递，可以传递任何数据类型
void addHead(LinkedList* list, void* data) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->data = data;
  // 空链表的特殊处理，需要初始化头尾指针
  if (list->head == NULL) {
    list->tail = node;
    node->next = NULL;
  } else {
    node->next = list->head;
  }
  list->head = node;
}

void addTail(LinkedList* list, void* data) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;
  if (list->tail == NULL) {
    list->head = node;
  } else {
    list->tail->next = node;
  }
  list->tail = node;
}

void delete(LinkedList* list, Node* node) {
  Node* curr = list->head;
  if(curr == NULL) {
    return NULL;
  }
  while(curr != NULL) {
    if (curr->data == node->data) {
      
    }
    curr = curr->next;
  }
}

Node* getNode(LinkedList* list, void* data) {
  
}

void printLinkedList (LinkedList* list, PRINT print) {
  Node *node = list->head;
  while (node != NULL) {
    print(node->data);
    node = node->next;
  }
}

/* ------------------------------- */

void printIntArray (void* data) {
  printf("%d\n", *(int*)data);
}

int main() {
  LinkedList linkedlist;
  initList(&linkedlist);
  int arr[5] = {1,2,3,4,5};
  /* printf("size of int: %lu\n", sizeof(int)); */
  /* printf("%p\n", arr); */
  /* printf("%d\n", *arr); */
  /* printf("%p\n", arr+4); */
  /* printf("%d\n", *(arr+4)); */
  addHead(&linkedlist, arr);
  addHead(&linkedlist, arr+1);
  addTail(&linkedlist, arr+2);
  addHead(&linkedlist, arr+3);
  addTail(&linkedlist, arr+4);
  printLinkedList(&linkedlist, (PRINT)printIntArray);
}
