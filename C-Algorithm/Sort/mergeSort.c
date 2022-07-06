/*
 * 两路归并排序：合并两个有有序数组
 */

#include <stdio.h>
#include <stdlib.h>

int *aux;

void merge (int a[], int lo, int mid, int hi) {
  // two sorted array: a[lo]~a[mid], a[mid+1]~a[hi]
  if (lo >= hi) return;
  int i = lo; int j = mid+1; int size = hi-lo+1;
  // int aux[11];
  for (int k=lo; k<=hi; k++)
    aux[k] = a[k];
  for (int k=lo; k<=hi; k++) {
    if (i > mid) a[k] = aux[j++];
    else if (j > hi) a[k] = aux[i++];
    else if (aux[i] < aux[j]) a[k] = aux[i++];
    else a[k] = aux[j++];
  }
}

void mergeSort1 (int a[], int lo, int hi) {
  if (lo >= hi) return;
  printf("lo:%d, mid:%d, hl:%d\n", lo, (lo + hi) / 2, hi);
  int mid = (lo + hi) / 2;
  mergeSort1(a, lo, mid);
  mergeSort1(a, mid+1, hi);
  
  printf("merge: %d %d %d\n", lo, mid, hi);
  
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
  
  printf("\na: ");
  for (int i=0; i<=10; i++) {
    printf("%d ", a[i]);
  }
  printf("\n-----------------\n");
}

void mergeSort (int a[], int size) { 
  aux = malloc(sizeof(int) * size);
  mergeSort1(a, 0, size-1);
}
  
int main () {
  int size = 13;
  int a[13] = {7,1,4,8,9,0,10,3,2,6,5,12,11};

  printf("\na: ");
  for (int i=0; i<=size-1; i++) {
    printf("%d ", a[i]);
  }
  printf("\n-----------------\n");

  mergeSort(a, size);
  free(aux);
  
  for (int i=0; i<=size-1; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}
