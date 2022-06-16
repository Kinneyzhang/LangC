/*
 * 冒泡排序
 * 简单描述：每次将最小的元素冒泡(连续交换)到开头。
 * 描述：
 *   从最后一个元素(j)遍历到第i+1(i from 0 to size)个元素，比较 j 和 j-1 个元素，a[j] < a[j-1] 则交换。每次遍历将最小的元素放（冒泡）到i的位置。
 * n-1 趟，每趟有从 n-1 到 1 递减的比较（交换）操作
 * 最左边得到一个依次有序的序列
 */

#include <stdlib.h>
#include <stdio.h>

void bubbleSort (int a[], int size) {
  for (int i=0; i<size-1; i++) {
    for (int j=size; j>i; j--) {
      if (a[j] < a[j-1]) {
        int t = a[j];
        a[j] = a[j-1];
        a[j-1] = t;
      }
    }
    /* for (int i=0; i<size; i++) { */
    /*   printf("%d ", a[i]); */
    /* } */
    /* printf("\n"); */
  }
}

int main () {
  /* int a[8] = {4, 2, 5, 7, 1, 3, 9, 0}; */
  int a[8] = {9, 8, 7, 6, 5, 4, 3, 2};
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
