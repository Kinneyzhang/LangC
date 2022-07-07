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

int countList (ListNode* node) {
  int count = 0;
  while (node) {
    count++;
    node = node->next;
  }
  return count;
}

ListNode* addTwoNumbers (ListNode* l1, ListNode* l2) {
  int s1 = countList(l1);
  int s2 = countList(l2);
  int maxs;
  int num;
  ListNode* smallList;
  
  if (s1<s2) {
    num = s2 - s1;
    maxs = s2;
    smallList = l1;
  } else {
    num = s1 - s2;
    maxs = s1;
    smallList = l2;
  }
  
  // 给位数小的数字，高位补0
  while (smallList->next) {
    smallList = smallList->next;
  }
  for (int i=0; i<num; i++) {
    ListNode* node = malloc(sizeof(ListNode));
    node->data = 0;
    smallList->next = node;
    smallList = node; 
  }
  smallList->next = NULL;
  
  int carry = 0; // 进位
  int value = 0;

  // virtual root, real root is: root->next
  ListNode* root = malloc(sizeof(ListNode));
  root->data = 0;
  ListNode* curr = root;
  
  for (int i=0; i<maxs; i++) {
    ListNode* node = malloc(sizeof(ListNode));
    int a1 = l1->data;
    int a2 = l2->data;
    
    value = (a1 + a2 + carry) % 10;
    node->data = value;
    
    carry = (a1 + a2 + carry) / 10; // 下一位的进位
    curr->next = node;
    curr = node;
    
    l1 = l1->next;
    l2 = l2->next;
  }
  
  // 当最后一位有进位时
  if (carry != 0) {
    ListNode* node = malloc(sizeof(ListNode));
    node->data = carry;
    node->next = NULL;
    curr->next = node;
  }
  
  return root->next;
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
