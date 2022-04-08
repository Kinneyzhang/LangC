#include "linkedlist.h"

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

int main () {
  LinkedList linkedlist;
  int x1 = 4; int x2 = 2; int x3 = 1; int x4 = 3; int x5 = 5;
  int* arr[5] = {&x1, &x2, &x3, &x4, &x5};
  buildLinkedList(&linkedlist, (void**)arr, 5);
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
