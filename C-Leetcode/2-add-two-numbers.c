/**
 * 两数相加：链表实现
 */

#include <stdlib.h>
#include <stdio.h>

typedef struct _list_node {
  int data;
  struct _list_node *next;
} ListNode;

ListNode* buildList (int *array, int size) {
  ListNode* root = malloc(sizeof(ListNode));
  root->data = array[0];
  ListNode* curr = root;
  for (int i=1; i<size; i++) {
    ListNode* node = malloc(sizeof(ListNode));
    node->data = array[i];
    curr->next = node;
    curr = node;
  }
  curr->next = NULL;
  return root;
}

void printList (ListNode* node) {
  while (node) {
    printf("%d ", node->data);
    node = node->next;
  }
  printf("\n");
}

ListNode* addTwoNumbers (ListNode* l1, ListNode* l2) {  
  int carry = 0; // 进位
  int value = 0;

  // root is: pre->next
  ListNode* pre = malloc(sizeof(ListNode));
  ListNode* curr = pre;

  int v1 = 0;
  int v2 = 0;
  while (l1 != NULL || l2 != NULL) {   // while代替for更合适，避免了多余的大小计算
    if (l1 == NULL) v1 = 0;
    else v1 = l1->data;
    if (l2 == NULL) v2 = 0;
    else v2 = l2->data;
    
    ListNode* node = malloc(sizeof(ListNode));
    value = (v1 + v2 + carry) % 10;
    node->data = value;
    carry = (v1 + v2 + carry) / 10; // 下一位的进位
    curr->next = node;
    curr = node;

    if (l1 != NULL) l1 = l1->next;
    if (l2 != NULL) l2 = l2->next;
  }
  
  // 当最后一位有进位时
  if (carry != 0) {
    ListNode* node = malloc(sizeof(ListNode));
    node->data = carry;
    node->next = NULL;
    curr->next = node;
  }
  
  return pre->next;
}

int main () {
  /* 842 + 999465 = 1000307 */
  int a1[3] = {2,4,8};
  int a2[6] = {5,6,4,9,9,9};
  ListNode* l1  = buildList (a1, 3);
  ListNode* l2  = buildList (a2, 6);
  
  printf("l1: ");
  printList(l1);
  
  printf("l2: ");
  printList(l2);
  
  ListNode* ls = addTwoNumbers(l1, l2);
  printf("ls: ");
  printList(ls);
}
