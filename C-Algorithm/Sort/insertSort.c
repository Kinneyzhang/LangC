/**
 * 插入排序
 */

#include <stdlib.h>
#include <stdio.h>

void insertSort (int a[], int size) {
  for (int i=1; i<size; i++) {
    int t = a[i];
    for (int j=i-1; j>=0; j--) {
      if (t > a[j])
        break;
      else {
        a[j+1] = a[j];
        a[j] = t;
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

  insertSort(a, size);
  printf("After sort:  ");
  for (int i=0; i<size; i++) {
    printf("%d ", a[i]);
  }

  printf("\n");
}