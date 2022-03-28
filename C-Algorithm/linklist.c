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

/** 定义函数指针 */
typedef void(*PRINT)(void*);
typedef int(*COMPARE)(void*, void*);

void* compareFunc;

/*********************************************************************************/
void initList(LinkedList* list);

LinkedList* buildLinkedList(LinkedList* list, void* arr[]);

Node* getNode(LinkedList* list, COMPARE compare, void* data); // main
Node* getNthNode(LinkedList* list, int nth); // main

void insertNode(LinkedList* list, Node* node, void* newData, int flag); // main
void addHead(LinkedList* list, void* data);
void addTail(LinkedList* list, void* data);
/* void insertNodeBefore(LinkedList* list, Node* node, void* data); */
/* void insertNodeAfter(LinkedList* list, Node* node, void* data); */

void insertByData(LinkedList* list, COMPARE compare, void* data, void* newData, int flag);
/* void insertByDataBefore(LinkedList* list, COMPARE compare, void* data, void* newData); */
/* void insertByDataAfter(LinkedList* list, COMPARE compare, void* data, void* newData); */
void insertByNth(LinkedList* list, int nth, void* data);

void deleteNode(LinkedList* list, Node* node); // main
void deleteByData(LinkedList* list, COMPARE compare, void* data);
void deleteByNth(LinkedList* list, int nth);

void updateNode(LinkedList* list, Node* node, void* data); // main
void updateByData(LinkedList* list, COMPARE compare, void* data, void* newData);
void updateByNth(LinkedList* list, int nth, void* data);

void printLinkedList(LinkedList* list, PRINT print); // main
/*********************************************************************************/

void initList(LinkedList* list) {
  list->head = NULL;
  list->tail = NULL;
}

LinkedList* buildLinkedList(LinkedList* list, void* arr[]) {
  
}

/** 根据值获取节点 */
Node* getNode(LinkedList* list, COMPARE compare, void* data) {
  Node* curr = list->head;
  while(curr != NULL) {
    if(compare(curr->data, data) == 0) {
      return curr;
    }
    curr = curr->next;
  }
  return NULL;
}

/** 根据位置获取节点 */
Node* getNthNode(LinkedList* list, int nth) {
  /** Return node at the NTH position of linkedlist LIST. */
  int pos = 0;
  Node* curr = list->head;
  while (curr != NULL) {
    pos += 1;
    if (nth == pos) {
      return curr;
    }
    curr = curr->next;
  }
  return NULL;
}

// 在指定节点 前面/后面 插入节点
void insertNode(LinkedList* list, Node* node, void* newData, int flag) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = newData;
  if (flag == 0) {
    // 在节点前面插入
    Node* curr = list->head;
    while (curr != NULL && curr->next != node) {
      curr = curr->next;
    }
    if (curr != NULL) {
      newNode->next = node;
      curr->next = newNode;
    }
  }
  if (flag == 1) {
    // 在节点后面插入
    newNode->next = node->next;
    node->next = newNode;
  }
}

void insertByData(LinkedList* list, COMPARE compare, void* data, void* newData, int flag) {
  Node* node = getNode(list, compare, data);
  insertNode(list, node, newData, flag);
}

// 在指定位置插入节点
void insertByNth(LinkedList* list, int nth, void* data) {
}


/** 增加节点 */
void addHead(LinkedList* list, void* data) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->data = data;
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

/** 删除节点 */
void deleteNode(LinkedList* list, Node* node) {
  Node* curr = list->head;
  if (curr == node) {
    if (curr->next == NULL) {
      list->head = list->tail = NULL;
    } else {
      list->head = curr->next;
    }
  } else {
    while (curr != NULL && curr->next != node) {
      curr = curr->next;
    }
    if (curr != NULL) {
      curr->next = node->next;
    }
  }
  free(node);
}

/** 打印链表 */
void printLinkedList(LinkedList* list, PRINT print) {
  Node *node = list->head;
  printf("\ncompare func address: %p\n", compareFunc);
  while (node != NULL) {
    print(node->data);
    node = node->next;
  }
}

/** 复用其他函数 */

/** 增 */

/** 删 */
// 根据值删除节点
void deleteByData(LinkedList* list, COMPARE compare, void* data) {
  /** Delete the specific node with data DATA from linkedlist LIST,
      using the COMPARE function. */
  Node* node = getNode(list, compare, data);
  if (node != NULL) {
    deleteNode(list, node);
  }
}

// 根据位置删除节点
void deleteByNth(LinkedList* list, int nth) {
  Node* node = getNthNode(list, nth);
  if (node != NULL) {
    deleteNode(list, node);
  }
}

/** 改 */
// 修改节点的值
void updateNode(LinkedList* list, Node* node, void* data) {}

void updateByNth(LinkedList* list, int nth, void* data) {}

/* ------------------------------- */

// Specific Functions
void printInt (int* data) {
  printf("%d ", *data);
}

int compareInt (int* data1, int* data2) {
  return *data1 - *data2;
}

int main() {
  compareFunc = compareInt;
    
  LinkedList linkedlist;
  initList(&linkedlist);
  int arr[5] = {1,2,3,4,5};
  addHead(&linkedlist, arr);
  addHead(&linkedlist, arr+1);
  addTail(&linkedlist, arr+2);
  addHead(&linkedlist, arr+3);
  addTail(&linkedlist, arr+4);
  printf("Original list: ");
  printLinkedList(&linkedlist, (PRINT)printInt);

  // 获取特定位置的节点
  for (int i=0; i<5; ++i) {
    Node* nthNode = getNthNode(&linkedlist, i+1);
    printf("\nThe nth %d data: %d", i+1, *(int*)(nthNode->data));
  }

  // 删除指定位置的节点
  deleteByNth(&linkedlist, 4);
  printf("\nDelete 4th node: ");
  printLinkedList(&linkedlist, (PRINT)printInt);
  
  int a = 2;
  int b = 8;
  insertByData(&linkedlist, (COMPARE)compareInt, &a, &b, 1);
  printf("\nAfter insert: ");
  printLinkedList(&linkedlist, (PRINT)printInt);
  
  // 删除指定值的节点
  int deleteArr[6] = {3,1,8,5,4,2};
  for (int i=0; i<6; ++i) {
    deleteByData(&linkedlist, (COMPARE)compareInt, deleteArr+i);
    printf("\nDelete data '%d': ", deleteArr[i]);
    printLinkedList(&linkedlist, (PRINT)printInt);
  }
}

// FIXME: 是否可以将函数指针保存在全局变量里面，这样函数指针可以不用在参数中传递而直接使用。
