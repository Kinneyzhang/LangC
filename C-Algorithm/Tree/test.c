#include <stdio.h>

int* test_var () {
  int a = 3;
  int* b = &a;
  return b;
}

int main () {
  int* data = test_var();
  printf("data: %p\n", data);
}

// C语言函数是否不能返回局部变量的值
