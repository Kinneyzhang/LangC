#include <stdio.h>
#include <unistd.h>

int main() {
  printf("here0");
  /* int arr1[10][7] = {{1,1,1,1,1,1,0}, */
  /*                    {0,1,1,0,0,0,0}, */
  /*                    {1,1,0,1,1,0,1}, */
  /*                    {1,1,1,1,0,0,1}, */
  /*                    {0,1,1,0,0,1,1}, */
  /*                    {1,0,1,1,0,1,1}, */
  /*                    {1,0,1,1,1,1,1}, */
  /*                    {1,1,1,0,0,0,0}, */
  /*                    {1,1,1,1,1,1,1}, */
  /*                    {1,1,1,1,0,1,1}}; */
  /* printf("here1"); */
  /* char arr2[7] = {'A','B','C','D','E','F','G'}; */
  /* int count = 0; */
  /* printf("here2"); */
  /* while (1) { // clock */
  /*   int n = count % 10; */
  /*   for (int i=0; i<7; i++) { */
  /*     printf("%s = %d; ", arr2[i], arr1[n][i]); */
  /*   } */
  /*   putchar('\n'); */
  /*   fflush(stdout); */
  /*   sleep(1); */
  /*   count++; */
  /* } */
  return 0;
}

/*    0 1 2 3 4 5 6 7 8 9
 * A: 1 0 1 1 0 1 1 1 1 1 
 * B: 1 1 1 1 1 0 0 1 1 1
 * C: 1 1 0 1 1 1 1 1 1 1
 * D: 1 0 1 1 0 1 1 0 1 1
 * E: 1 0 1 0 0 0 1 0 1 0
 * F: 1 0 0 0 1 1 1 0 1 1
 * G: 0 0 1 1 1 1 1 0 1 1
 */
