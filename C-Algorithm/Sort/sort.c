#include <stdio.h>
#include <stdlib.h>

typedef int Item;

#define less(A, B) A < B
#define exch(A, B) { Item t = A; A = B; B = t; }
#define compexch(A, B) if (less(B, A)) exch(A, B)

/* RAND_MAX = 2^15 (0x7fff)
 * atoi: 字符串转为int
 */

void sort (Item a[], int l, int r) {
  int i, j;
  for (i=l+1; i<=r; i++)
    for (j=i; j>1; j--)
      compexch(a[j-1], a[j])
}

void main (int argc, char* argv[]) {

  /* printf("argc: %d\n", argc); */
  /* printf("argv[0]: %s\n", argv[0]); */
  /* printf("argv[1]: %s\n", argv[1]); */
  /* printf("argv[2]: %s\n", argv[2]); */
  /* printf("argv[3]: %s\n", argv[3]); */
  /* printf("argv[4]: %s\n", argv[4]); */

  printf("rand: %f", 1000 * (1.0 * rand() / RAND_MAX));
  
  /* int i, N = atoi(argv[1]), sw = atoi(argv[2]); */
  /* int* a = malloc(N * sizeof(int)); */
  /* if (sw) { */
  /*   for (i=0; i<N; i++) { */
  /*     a[i] = 1000 * (1.0 * rand() / RAND_MAX); */
  /*   } */
  /* } else { */
  /*   while (scanf("%d", &a[N]) == 1) N++; */
  /* } */
  /* sort(a, 0, N-1); */
  /* for (i=0; i<N; i++) {printf("%3d ", a[i]);} */
  /* printf("\n"); */
}
