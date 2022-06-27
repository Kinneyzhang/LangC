/*
 * 两路归并排序：合并两个有有序数组
 */

#include <stdio.h>
#include <stdlib.h>

void merge1 (int a[], int sa, int b[], int sb, int c[]) {
  int sc = sa + sb;
  int i=0; int j=0; // 0 ~ sa-1; 0 ~ sb-1
  for (int k=0; k<sc; k++) {
    if (i > sa-1)
      c[k] = b[j++];
    else if (j > sb-1)
      c[k] = a[i++];
    else if (a[i] < b[j])
      c[k] = a[i++];
    else
      c[k] = b[j++];
  }
}

void merge ()

void mergeSort ()

int main () {
  int sa = 5;
  int sb = 6;
  int a[5] = {1,2,4,5,7};
  int b[6] = {3,5,8,9,10,12};

  int c[sa+sb];
  mergeSort(a, 5, b, 6, c);
  
  for (int i =0; i<sa+sb; i++) {
    printf("%d ", c[i]);
  }
  printf("\n");
}
