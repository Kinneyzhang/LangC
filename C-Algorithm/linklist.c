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
typedef int(*COMPARE)(void*, void*);

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

void delete(LinkedList* list, Node* node) {
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

void printLinkedList (LinkedList* list, PRINT print) {
  Node *node = list->head;
  while (node != NULL) {
    print(node->data);
    node = node->next;
  }
}

// Extra Functions
void deleteData(LinkedList* list, COMPARE compare, void* data) {
  /** Delete the specific node with data DATA from linkedlist LIST,
      using the COMPARE function. */
  Node* node = getNode(list, compare, data);
  if (node != NULL) {
    delete(list, node);
  } 
}

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

void deleteNthNode(LinkedList* list, int nth) {
  Node* node = getNthNode(list, nth);
  if (node != NULL) {
    delete(list, node);
  }
}

/* ------------------------------- */

// Specific Functions
void printIntArray (void* data) {
  printf("%d ", *(int*)data);
}

int compareIntVal (void* data1, void* data2) {
  if (*((int*)data1) == *((int*)data2)) {
    return 0;
  }
  return -1;
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
  printf("Original list: ");
  printLinkedList(&linkedlist, (PRINT)printIntArray);

  // 获取特定位置的节点
  for (int i=0; i<5; ++i) {
    Node* nthNode = getNthNode(&linkedlist, i+1);
    printf("\nThe nth %d data: %d", i+1, *(int*)(nthNode->data));
    //free(nthNode);
  }

  // 删除指定位置的节点
  deleteNthNode(&linkedlist, 4);
  printf("\nDelete 4th node: ");
  printLinkedList(&linkedlist, (PRINT)printIntArray);
  
  // 删除指定值的节点
  int deleteArr[6] = {3,1,8,5,4,2};
  for (int i=0; i<6; ++i) {
    deleteData(&linkedlist, (COMPARE)compareIntVal, deleteArr+i);
    printf("\nDelete data '%d': ", deleteArr[i]);
    printLinkedList(&linkedlist, (PRINT)printIntArray);
  }
}
