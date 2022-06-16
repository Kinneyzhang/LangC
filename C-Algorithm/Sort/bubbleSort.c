/*
 * 冒泡排序
 */

#include <stdlib.h>
#include <stdio.h>

void bubbleSort (int a[], int size) {
  for (int i=0; i<size; i++) {
    for (int j=size; j>i; j--) {
      if (a[j] < a[j-1]) {
        int t = a[j];
        a[j] = a[j-1];
        a[j-1] = t;
      }
    }
  }
}

int main () {
  int a[8] = {4, 2, 5, 7, 1, 3, 9, 0};
  int size = 8;

  printf("Before sort: ");
  for (int i=0; i<size; i++) {
    printf("%d ", a[i]);
  }
  
  printf("\n");

  bubbleSort(a, size);
  printf("After sort:  ");
  for (int i=0; i<size; i++) {
    printf("%d ", a[i]);
  }

  printf("\n");
}
