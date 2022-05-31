#include<stdlib.h>
#include<stdio.h>
#include<assert.h>

int main () {
  int a = 1;
  long b = 2;
  assert(sizeof(a) == 4);
  assert(sizeof(b) == 8);
}
