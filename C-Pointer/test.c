#include<stdio.h>
#include<stdlib.h>

int main () {
  int a = 2;
  int *ptr = &a;
  
  printf("a的地址是：%p\n", &a);
  printf("a的内容是：%d\n", a);
  printf("ptr指针的地址是：%p\n", &ptr); // 指针变量自己所在的地址
  printf("ptr指针的内容是：%p\n", ptr); // a的地址
  printf("ptr指针所指向的内容是：%d\n", *ptr); // 指针指向的a的值
  printf("----------\n");
  
  *ptr = 5; // 修改指针指向的变量a的值
  printf("修改值后，a的地址是：%p\n", &a);
  printf("修改值后，a的内容是：%d\n", a);
  printf("修改值后，ptr指针的地址是：%p\n", &ptr); // 指针变量自己所在的地址
  printf("修改值后，ptr指针的内容是：%p\n", ptr); // 指针的指向未变：还是a的地址
  printf("修改值后，ptr指针所指向的内容是：%d\n", *ptr); // 指针指向的a的值，此时被修改了
  printf("----------\n");
  
  int b = 3;
  ptr = &b; // 修改指针的指向为变量b
  printf("修改指向后，a的地址是：%p\n", &a); // 指针已经不指向a了
  printf("修改指向后，a的内容是：%d\n", a); // 指针已经不指向a了
  printf("修改指向后，b的地址是：%p\n", &b);
  printf("修改指向后，b的内容是：%d\n", b);
  printf("修改指向后，ptr指针的地址是：%p\n", &ptr); // 指针变量自己所在的地址，未修改
  printf("修改指向后，ptr指针的内容是：%p\n", ptr); // b的地址
  printf("修改指向后，ptr指针所指向的内容是：%d\n", *ptr); // 指针指向的b的值
  printf("----------\n");
}
