/*
 * 两路归并排序：合并两个有有序数组
 */

#include <stdio.h>
#include <stdlib.h>

/* void merge1 (int a[], int sa, int b[], int sb, int c[]) { */
/*   int sc = sa + sb; */
/*   int i=0; int j=0; // 0 ~ sa-1; 0 ~ sb-1 */
/*   for (int k=0; k<sc; k++) { */
/*     if (i > sa-1) */
/*       c[k] = b[j++]; */
/*     else if (j > sb-1) */
/*       c[k] = a[i++]; */
/*     else if (a[i] < b[j]) */
/*       c[k] = a[i++]; */
/*     else */
/*       c[k] = b[j++]; */
/*   } */
/* } */

void merge (int a[], int lo, int mid, int hi) {
  // two sorted array: a[lo]~a[mid], a[mid+1]~a[hi]
  int i = lo; int j = mid+1; int size = hi-lo+1;
  int aux[size];
  for (int k=lo; k<=hi; k++)
    aux[k] = a[k];
  for (int k=lo; k<=hi; k++) {
    if (i > mid) a[k] = aux[j++];
    else if (j > hi) a[k] = aux[i++];
    else if (aux[i] < aux[j]) a[k] = aux[i++];
    else a[k] = aux[j++];
  }
}



void mergeSort (int a[], int lo, int hi) {
  if (lo >= hi) return;
  printf("lo:%d, hl:%d, ", lo, hi);
  int mid = (lo + hi) / 2;
  printf("mid:%d\n", mid);
  mergeSort(a, lo, mid);
  mergeSort(a, mid+1, hi);
  
  printf("merge: %d~%d, %d~%d\n", lo, mid, mid+1, hi);
  
  printf("before: ");
  for (int i=lo; i<=hi; i++) {
    printf("a[%d]:%d ", i, a[i]);
  }
  printf("\n");
  
  merge(a, lo, mid, hi);
  
  printf("after: ");
  for (int i=lo; i<=hi; i++) {
    printf("a[%d]:%d ", i, a[i]);
  }
  printf("\n");
  printf("-----------\n");
  for (int i=0; i<=10; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}
  
int main () {
  // int a[11] = {7,1,4,8,9,0,3,10,2,6,5};
  int a[11] = {7,1,4,8,9,0,10,3,2,6,5};
  mergeSort(a, 0, 10);
  printf("222");
  for (int i=0; i<=10; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}
