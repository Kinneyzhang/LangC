/*
 * 选择排序
 */

#include <stdlib.h>
#include <stdio.h>

void selectSort (char a[], int size) {
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
  /* int size = 8; */
  /* int a[8] = {4, 2, 5, 7, 1, 3, 9, 0}; */

  int size = 12;
  char a[12] = {'E', 'A', 'S', 'Y', 'Q', 'U', 'E', 'S', 'T', 'I', 'O', 'N'};
  
  printf("Before sort: ");
  for (int i=0; i<size; i++) {
    printf("%c ", a[i]);
  }
  
  printf("\n");
  
  selectSort(a, size);
  printf("After sort:  ");
  for (int i=0; i<size; i++) {
    printf("%c ", a[i]);
  }
}
