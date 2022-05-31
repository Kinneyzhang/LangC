<<<<<<< HEAD
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
=======
#include <stdio.h>

int main () {
  for(int i=0; i<10; i++) {
    printf("char: #%c\n", "123456789ABCDEFG"[i]); 
  }
}
>>>>>>> 9436f879d7dc2bbe577ff47b197392fb1ab31a17
