/*
 * 选择排序
 * 简单描述：每次选择一个最小的元素，交换到开头。
 * 描述：
 *   从第一个元素遍历到最后一个元素，每趟在剩余的元素中依次与当前元素比较，记录最小元素的下标，将当前元素与最小元素交换。
 * n-1趟，每趟有从 n-1 到 1 递减次的比较操作，最后(交换)一次。
 * 最左边得到一个依次有序的序列
 * 每次交换都将一个元素放到它最终的位置上，交换次数是n-1
 * 缺点：不能利用已排序好的顺序，每次都要比较所有剩余元素才能选出最小。
 * 优点：比较的次数多(固定)，但交换的次数少(n-1)，适合元素较大(突出交换的优势)，但关键字较小(减少比较的开销)的文件。
 */

#include <stdlib.h>
#include <stdio.h>

void selectSort (int a[], int size) {
  for (int i=0; i<size; i++) {
    int m = i; // position of the minimum element.
    for (int j=i+1; j<size; j++)
      if (a[j] < a[m]) m = j;
    // exchange
    int t = a[i];
    a[i] = a[m];
    a[m] = t;
  }
}

int main () {
  /* int a[8] = {4, 2, 5, 7, 1, 3, 9, 0}; */
  int a[8] = {9, 8, 7, 6, 5, 4, 3, 2};
  int size = 8;

  /* int size = 12; */
  /* char a[12] = {'E', 'A', 'S', 'Y', 'Q', 'U', 'E', 'S', 'T', 'I', 'O', 'N'}; */
  
  printf("Before sort: ");
  for (int i=0; i<size; i++) {
    printf("%d ", a[i]);
  }
  
  printf("\n");
  
  selectSort(a, size);
  printf("After sort:  ");
  for (int i=0; i<size; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}
