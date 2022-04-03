// 链表
// 链表涉及的操作：
// 创建链表、遍历链表、插入一个节点、删除一个节点

#include<stdlib.h>
#include<stdio.h>

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

/*********************************************************************************/

void initList(LinkedList* list);

void addHead(LinkedList* list, void* data);
void addTail(LinkedList* list, void* data);

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

void updateNode(LinkedList* list, Node* node, void* data); // main
void updateByData(LinkedList* list, COMPARE compare, void* data, void* newData);
void updateByNth(LinkedList* list, int nth, void* data);

void printLinkedList(LinkedList* list, PRINT print); // main

/*********************************************************************************/

void initList(LinkedList* list) {
  list->head = NULL;
  list->tail = NULL;
}

int length(LinkedList* list) {
  int count = 0;
  Node* curr = list->head;
  while(curr != NULL) {
    count += 1;
    curr = curr->next;
  }
  return count;
}

void addHead(LinkedList* list, void* data) {
  /** 增加头节点 */
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
  /** 增加尾节点 */
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

Node* getNode(LinkedList* list, COMPARE compare, void* data) {
  /** 根据值获取节点 */
  Node* curr = list->head;
  while(curr != NULL) {
    if(compare(curr->data, data) == 0) {
      return curr;
    }
    curr = curr->next;
  }
  return NULL;
}

Node* getNthNode(LinkedList* list, int nth) {
  /** 根据位置获取节点 */
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

void insertNode(LinkedList* list, Node* node, void* newData, int flag) {
  /** 在指定节点 前面/后面 插入节点，flag=0表示在前面插入，flag=1表示在后面插入 */
  if (node != NULL && list->head != NULL) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = newData;
    if (flag == 0) {
      // 在节点前面插入
      Node* curr = list->head;
      newNode->next = node;
      if (node == curr) {
        list->head = newNode;
      } else {
        while (curr != NULL && curr->next != node) {
          curr = curr->next;
        }
        if (curr != NULL) {
          curr->next = newNode; 
        }
      }
    }
    if (flag == 1) {
      // 在节点后面插入
      if (node == list->tail) {
        list->tail = newNode;
      } else {
        newNode->next = node->next;
      }
      node->next = newNode;
    }
  }
}

void insertNodeBefore(LinkedList* list, Node* node, void* data) {
  /** 在指定节点 前面 插入节点 */
  insertNode(list, node, data, 0);
}

void insertNodeAfter(LinkedList* list, Node* node, void* data) {
  /** 在指定节点 后面 插入节点 */
  insertNode(list, node, data, 1);
}

void insertByData(LinkedList* list, COMPARE compare, void* data, void* newData, int flag) {
  /** 在指定数据的节点 前面/后面 插入节点，flag=0表示在前面插入，flag=1表示在后面插入 */
  Node* node = getNode(list, compare, data);
  insertNode(list, node, newData, flag);
}

void insertByDataBefore(LinkedList* list, COMPARE compare, void* data, void* newData) {
  insertByData(list, compare, data, newData, 0);
}

void insertByDataAfter(LinkedList* list, COMPARE compare, void* data, void* newData) {
  insertByData(list, compare, data, newData, 1);
}

void insertByNth(LinkedList* list, int nth, void* data) {
  /** 在指定位置插入节点 */
  int pos = 0;
  Node* curr = list->head;
  while (curr != NULL) {
    pos += 1;
    if(pos == nth) {
      insertNode(list, curr, data, 0);
      break;
    }
    curr = curr->next;
  }
}

void deleteNode(LinkedList* list, Node* node) {
  /** 删除节点 */
  if (node != NULL) {
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
}

void deleteByData(LinkedList* list, COMPARE compare, void* data) {
  /** 根据值删除节点 */
  Node* node = getNode(list, compare, data);
  deleteNode(list, node);
}

void deleteByNth(LinkedList* list, int nth) {
  /** 根据位置删除节点 */
  Node* node = getNthNode(list, nth);
  deleteNode(list, node);
}

void updateNode(LinkedList* list, Node* node, void* data) {
  /** 修改节点的值 */
  node->data = data;
}

void updateByData(LinkedList* list, COMPARE compare, void* data, void* newData) {
  /** 修改特定data节点的值 */
  Node* node = getNode(list, compare, data);
  node->data = newData;
}

void updateByNth(LinkedList* list, int nth, void* data) {
  /** 修改特定位置节点的值 */
  Node* node = getNthNode(list, nth);
  node->data = data;
}

void printLinkedList(LinkedList* list, PRINT print) {
  /** 打印链表 */
  Node *node = list->head;
  // printf("\ncompare func address: %p\n", compareFunc);
  while (node != NULL) {
    print(node->data);
    node = node->next;
  }
}

/* ------------------------------- */

// Specific Functions
void println(int n) {
  for(int i=0; i<n; ++i) {
    printf("\n");
  } 
}

void printInt(int* data) {
  printf("%d ", *data);
}

int compareInt(int* data1, int* data2) {
  return *data1 - *data2;
}

void prettyPrint(char str[], LinkedList* list, int n) {
  printf("%s", str);
  printLinkedList(list, (PRINT)printInt);
  println(n);
}

int main() {
  LinkedList linkedlist;
  initList(&linkedlist);
  int arr[5] = {1,2,3,4,5};
  addHead(&linkedlist, arr);
  addHead(&linkedlist, arr+1);
  addTail(&linkedlist, arr+2);
  addHead(&linkedlist, arr+3);
  addTail(&linkedlist, arr+4);
  prettyPrint("Original list: ", &linkedlist, 1);
  
  // 获取特定位置的节点
  for (int i=0; i<length(&linkedlist); ++i) {
    Node* nthNode = getNthNode(&linkedlist, i+1);
    printf("\nThe nth %d data: %d", i+1, *(int*)(nthNode->data));
  }
  
  println(2);
  
  // 删除指定位置的节点
  deleteByNth(&linkedlist, 4);
  prettyPrint("Delete the 4th node: ", &linkedlist, 2);
  
  int a = 2; int b = 8; // 在2后面插入8
  insertByData(&linkedlist, (COMPARE)compareInt, &a, &b, 1);
  prettyPrint("Insert 8 after 2: ", &linkedlist, 1);
  
  int c = 5; int d = 6; // 在5前面插入6
  insertByData(&linkedlist, (COMPARE)compareInt, &c, &d, 0);
  prettyPrint("Insert 6 before 5: ", &linkedlist, 1);

  // 在指定位置插入节点
  int e = 3;
  insertByNth(&linkedlist, 4, &e);
  prettyPrint("Insert 3 at pos 4: ", &linkedlist, 2);

  // 更新节点
  int f = 6; int g = 9; int h = 7;
  updateByData(&linkedlist, (COMPARE)compareInt, &f, &g);
  prettyPrint("Update 6 to 9: ", &linkedlist, 1);
  
  updateByNth(&linkedlist, 1, &h);
  prettyPrint("Update the 1st to 7: ", &linkedlist, 2);
  
  // 删除指定值的节点
  int deleteArr[6] = {3,1,8,5,4,2};
  for (int i=0; i<3; ++i) {
    deleteByData(&linkedlist, (COMPARE)compareInt, deleteArr+i);
    printf("Delete data '%d': ", deleteArr[i]);
    printLinkedList(&linkedlist, (PRINT)printInt);
    println(1);
  }

  println(1);
  
  // 删除指定位置的节点
  deleteByNth(&linkedlist, 2);
  prettyPrint("Delete the 2nd node: ", &linkedlist, 1);
  
  deleteByNth(&linkedlist, 3);
  prettyPrint("Delete the 3rd node: ", &linkedlist, 1);
  
  deleteByNth(&linkedlist, 1);
  prettyPrint("Delete the 1st node: ", &linkedlist, 1);
}

// FIXME: 是否可以将函数指针保存在全局变量里面，这样函数指针可以不用在参数中传递而直接使用。
