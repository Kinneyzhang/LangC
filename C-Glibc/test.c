/* #include<stdlib.h> */
#include<stdio.h>
#include "c:/Users/26289/GitRepo/glibc-2.35/stdlib/stdlib.h"

#define TABLE_BASE 0x2e // 46

int main () {
  char* string = "%";
  printf("string address: %p\n", string);
  printf("string value: %p\n", *string);
  const char *ptr = string;
  printf("ptr address: %p\n", ptr);
  printf("ptr value: %p\n", *ptr);
  unsigned index = *ptr - TABLE_BASE;
  printf("index: %d\n", index);
  const char* str = "%";
  printf("%d", (long int)a64l(str));
}
