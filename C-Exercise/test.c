#include <stdio.h>
#include <stdlib.h>

int sum1 () {
  int sum = 0;
  for (int i=0; i<100; i++) {
    if (i % 2 == 0) {
      sum += i;
    }
  }
  return sum;
}

int sum2 () {
  int sum = 0;
  for (int i=0; i<100; i++) {
    sum += (i % 2 == 0) * i;
  }
  return sum;
}

int main() {
  printf("sum: %d\n", sum2());
  printf("%d\n", 6 % 2 == 0);
  printf("%d\n", 5 % 2 == 0);
}
