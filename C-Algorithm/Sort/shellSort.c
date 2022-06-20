/*
 * 希尔排序
 * 希尔排序是插入排序的拓展，允许非相邻的元素进行交换提高效率：使数组中任意间隔是h的元素都是有序的。
 * 
 */

#include <stdlib.h>
#include <stdio.h>

#define less(A, B) A < B
#define exch(arr, A, B) int t = arr[A]; arr[A] = arr[B]; arr[B] = t;

void shellSort (int a[], int size) {
  int h = 1;
  while (h < size/3) h = 3*h + 1;
  while (h >= 1) {
    // 将数组变成h有序
    for (int i=h; i<size; i++) {
      for (int j=i; j>=h && less(a[j], a[j-h]); j-=h ) {
        printf("exchange: a[%d]:%d, a:[%d]:%d -- ", j, a[j], j-h, a[j-h]);
        exch(a,j,j-h);
        for (int i=0; i<size; i++) {
          printf("%d ", a[i]);
        }
        printf("\n");
      }
    }
    for (int i=0; i<size; i++) {
      printf("%d ", a[i]);
    }
    printf("\n");
    h = h/3;
  }
}

int main () {
  int a[8] = {9, 8, 7, 6, 5, 4, 3, 2};
  int size = 8;

  printf("Before sort: ");
  for (int i=0; i<size; i++) {
    printf("%d ", a[i]);
  }
  
  printf("\n\n");
  shellSort(a, size);
  
  printf("\nAfter sort:  ");
  for (int i=0; i<size; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}
