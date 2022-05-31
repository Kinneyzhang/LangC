#include "thread.h"

void Ta() {
  while(1) {
    /* printf("a") */;
  }
}

void Tb() {
  while(1) {
    /* printf("b") */;
  }
}

int main() {
  // while(1) printf("a"); // 死循环，打印的所有都是a。
  create(Ta);
  create(Tb);
}
