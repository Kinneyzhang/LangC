/*
 * 插入排序
 * 简单描述：每次只考虑一个元素，依次和左边的有序序列比较，小于则交换。
 * 描述：
 *   从第i+1个元素遍历到最后，记录当前的元素，每趟依次和前面的元素比较，小于则插入交换，直至不小于。
 *   n-1趟，每趟的比较和交换次数不定，最好情况为只比较一次，无需交换。最坏情况为比较i次。
 * 最左边得到一个依次有序的序列
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
  /* int a[8] = {4, 2, 5, 7, 1, 3, 9, 0}; */
  int a[8] = {9, 8, 7, 6, 5, 4, 3, 2};
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
