#include <stdio.h>
#include <stdlib.h>

#ifndef __WINDOWS__
#define __WINDOWS__
#endif

int main() {
  printf("%s\n", __WINDOWS__ );
}
