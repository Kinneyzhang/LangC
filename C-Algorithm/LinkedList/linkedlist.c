// 链表
// 链表涉及的操作：
// 创建链表、遍历链表、插入一个节点、删除一个节点

#include "linkedlist.h"

void initList(LinkedList* list) {
  list->head = NULL;
  list->tail = NULL;
}

int length(LinkedList* list) {
  int len = 0;
  Node* curr = list->head;
  while(curr != NULL) {
    len += 1;
    curr = curr->next;
  }
  return len;
}

bool isEmpty(LinkedList* list) {
  return !list->head;
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

void buildLinkedList(LinkedList* list, void* arr[], int n) {
  initList(list);
  for (int i=0; i<n; i++) {
    addTail(list, arr[i]);
  }
}

/* void buildCircularLinkedList(LinkedList* list, void* arr[], int n) { */
/*   initList(list); */
/*   for (int i=0; i<n; i++) { */
/*     addTail(list, arr[i]); */
/*   } */
/*   list->tail->next = list->head; */
/* } */

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

// 再理理逻辑！
void* deleteNode(LinkedList* list, Node* node) {
  /** 删除节点 */
  /**
   * 几种特殊情况:
   * 1. 只有1个节点, 且要删除的正好是这个节点 => 头尾指针要变
   * 2. 多个节点, 删除头节点 => 头指针要变
   ******** 1,2 可以合并 因为 删除头节点的特殊性:不需要知道前驱节点. ********
   * 3. 多个节点, 删除尾节点 => 尾指针要变, 尾节点的前驱的next指针赋空.
   * 4. 多个节点, 删除中间节点 => 头尾指针不变, 删除的节点的前驱的next指针变化.
   **/
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
        if (node == list->tail) {
          list->tail = curr;
        }
        curr->next = node->next;
      }
    }
    void* data = node->data;
    free(node);
    return data;
  }
  return NULL;
}

void deleteByData(LinkedList* list, COMPARE compare, void* data) {
  /** 根据值删除节点 */
  Node* node = getNode(list, compare, data);
  deleteNode(list, node);
}

void* deleteByNth(LinkedList* list, int nth) {
  /** 根据位置删除节点 */
  Node* node = getNthNode(list, nth);
  return deleteNode(list, node);
}

void updateNode(Node* node, void* data) {
  /** 修改节点的值 */
  node->data = data;
}

void updateByData(LinkedList* list, COMPARE compare, void* data, void* newData) {
  /** 修改特定data节点的值 */
  Node* node = getNode(list, compare, data);
  updateNode(node, newData);
}

void updateByNth(LinkedList* list, int nth, void* newData) {
  /** 修改特定位置节点的值 */
  Node* node = getNthNode(list, nth);
  updateNode(node, newData);
}

void printLinkedList(LinkedList* list, PRINT print) {
  /** 打印链表 */
  Node *node = list->head;
  while (node != NULL) {
    print(node->data);
    node = node->next;
  }
}
