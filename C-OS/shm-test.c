#include "thread.h"

int x = 0;

void Thello(int id) {
  usleep(id * 100000);
  printf("ID: %d, Hello from thread #%c\n", id, "123456789ABCDEF"[x++]);
}

int main() {
  for(int i=0; i<12; i++) {
    create(Thello);
  }
}
