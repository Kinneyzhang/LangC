/**
 * 两数相加
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
  int sm; // the smaller one of s1 and s2;
  int num;
  ListNode* smallList;
  if (s1<s2) {
    num = s2 - s1;
    sm = s1;
    smallList = l1;
  }
  else {
    num = s1 - s2;
    sm = s2;
    smallList = l2;
  }
  // 高位补0
  while (smallList) {
    smallList = smallList->next;
  }
  for (int i=0; i<num; i++) {
    ListNode* node = malloc(sizeof(ListNode));
    node->data = 0;
    node->next = NULL;
    smallList->next = node;
    smallList = node;
  }
  smallList->next = NULL;
  
  int carry = 0; // 进位
  int value = 0;

  ListNode* root = malloc(sizeof(ListNode)); // virtual root
  root->data = 0;
  ListNode* curr = root;
  
  for (int i=0; i<sm; i++) {
    ListNode* node = malloc(sizeof(ListNode));
    int a1 = l1->data;
    int a2 = l2->data;
    
    value = (a1 + a2) % 10;
    node->data = value + carry;
    
    carry = (a1 + a2) / 10; // 下一位的进位
    curr->next = node;
    curr = node;
    
    l1 = l1->next;
    l2 = l2->next;
  }
  
  curr->next = NULL;
  return root->next;
}

int main () {
  /* ListNode* n1 = malloc(sizeof(ListNode)); */
  /* ListNode* n2 = malloc(sizeof(ListNode)); */
  int a1[3] = {2,4,3};   // 342
  int a2[4] = {5,6,4,1}; // 1465
  ListNode* l1  = buildList (a1, 3);
  ListNode* l2  = buildList (a2, 4);
  printList(l1);
  printf("count1: %d\n", countList(l1));
  printList(l2);
  printf("count2: %d\n", countList(l2));
  ListNode* ls = addTwoNumbers(l1, l2);
  printList(ls);
}
