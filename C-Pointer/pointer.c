#include<stdio.h>
#include<stdlib.h>

int main() {
  /* int num = 2; */
  /* int *pi = &num; */
  /* printf("pi指针的地址是：%p\n", &pi); */
  /* printf("pi指针的内容是：%p\n", (void*)pi); */
  /* printf("num的地址是：%p\n", &num); */
  /* printf("num的内容是：%d\n", num); */
  /* printf("pi指针所指向的内容是：%d\n", *pi); */
  /* printf("----------\n"); */
  /* *pi = 3; */
  /* printf("修改后pi指针的地址是：%p\n", &pi); */
  /* printf("修改后pi指针的内容是：%p\n", (void*)pi); */
  /* printf("修改后num的地址是：%p\n", &num); */
  /* printf("修改后pi指针所指向的内容是：%d\n", *pi); */
  /* printf("修改后num的内容是：%d\n", num); */
  /* printf("----------\n"); */
  /* // void指针 */
  /* printf("void指针的尺寸：%lu\n", sizeof(void*)); */
  
  /* printf("Size of *char: %zu\n", sizeof(char*)); */

  /* int num = 3; */
  /* intptr_t *pi = (intptr_t*)&num; */
  /* uintptr_t *pu = (uintptr_t*)&num; */
  /* printf("*pi is %ld\n", *pi); */
  /* printf("*pu is %lu\n", *pu); */

  /* int vector[] = {28, 41, 7}; */
  /* int *pi = vector; */
  /* printf("pi: %d\n", *pi); */
  /* pi += 1; */
  /* printf("pi: %d\n", *pi); */
  /* pi += 1; */
  /* printf("pi: %d\n", pi); */
  /* pi += 3; */
  /* printf("pi: %d\n", pi); */

  /* short s; */
  /* short *ps = &s; */
  /* char c; */
  /* char *pc = &c; */
  /* printf("Address of ps before: %d\n", ps); */
  /* ps += 1; */
  /* printf("Address of ps before: %d\n", ps); */
  /* printf("Address of pc before: %d\n", pc); */
  /* pc += 1; */
  /* printf("Address of pc before: %d\n", pc); */

  // 指针相减
  /* int vector[] = {28, 41, 7}; */
  /* int *p0 = vector; */
  /* int *p1 = vector+1; */
  /* int *p2 = vector+2; */
  /* printf("p0 %d\n", p0); */
  /* printf("p1 %d\n", p1); */
  /* printf("p2 %d\n", p2); */
  /* printf("p2-p0: %d\n", p2-p0); // %d 表示整数，打印时地址自动除4个字节 */
  /* printf("p2-p1: %d\n", p2-p1); */
  /* printf("p0-p1: %d\n", p0-p1); */
  /* printf("*p0-*p1: %d\n", *p0-*p1); */

  // 指针比较
  /* int vector[] = {28, 41, 7}; */
  /* int *p0 = vector; */
  /* int *p1 = vector+1; */
  /* int *p2 = vector+2; */
  /* printf("p2>p0: %d\n", p2>p0); // 1 */
  /* printf("p2<p0: %d\n", p2<p0); // 0 */

  // 多层间接引用
  /* char* titles[] = */
  /*   {"A Tale of Two Cities", "Wuthering Heights", "Don Quixotwe", */
  /*    "Odyssey", "Moby-Dick", "Hamlet", "Gulliver's Travels"}; */
  /* printf("title[1]:%s\n", titles[1]); */
  /* printf("title[1][2]:%c\n", titles[1][2]); */
  /* char** bestBooks[3]; */
  /* char** englishBooks[4]; */
  /* bestBooks[0] = &titles[0]; */
  /* bestBooks[1] = &titles[3]; */
  /* bestBooks[2] = &titles[5]; */
  /* englishBooks[0] = &titles[0]; */
  /* englishBooks[1] = &titles[1]; */
  /* englishBooks[2] = &titles[5]; */
  /* englishBooks[3] = &titles[6]; */
  /* printf("%s\n", *englishBooks[2]); */

  // 常量指针
  /* int num = 5; */
  /* const int limit = 500; */
  /* int *pi; */
  /* const int * pci; */
  /* pi = &num; */
  /* pci = &limit; */
  /* printf("num address: %d; value: %d\n", &num, num); */
  /* printf("limit address: %d; value: %d\n", &limit, limit); */
  /* printf("pi address: %d; value: %d\n", &pi, pi); */
  /* printf("pci address: %d; value: %d\n", &pci, pci); */
  /* printf("%d\n", *pi); // 5 */
  /* printf("%d\n", *pci); // 500 */
  /* pci = &num; */
  /* printf("%d\n", *pci); // 5 */
  /* // *pci = 200; // error:无法对常量指针解引赋值 */

  // 指向非常量的常量指针
  /* int num = 5; */
  /* int num2 = 6; */
  /* int const limit =50; */
  /* int *const cpi = &num; */
  /* printf("cpi: %d\n", *cpi); */
  /* // cpi = &limit; // error:不能被初始化为常量变量 */
  /* // cpi = &num2; // error:不能被修改 */
  /* *cpi = 7; */
  /* printf("cpi: %d\n", *cpi); */

  /* // 指向常量的常量指针 */
  /* int num; */
  /* const int* const cpci = &num; */
  /* int num2; */
  /* // cpci = &num2; //error */
  /* // *cpci = 20; //error */
  /* printf("cpci:%p\n", &cpci); */
  /* printf("cpci:%p\n", cpci); */
  /* printf("num:%p\n", &num); */

  /* // 指向“指向常量的常量指针”的指针 */
  /* const int limit = 500; */
  /* const int *const cpci = &limit; */
  /* printf("%d\n", *cpci); */
  /* const int *const *pcpci = &cpci; */
  /* printf("%d\n", **pcpci); */
  /* printf("%p\n", &pcpci); */
  /* printf("%p\n", &*pcpci); */
  /* printf("%p\n", &**pcpci); */
  /* printf("%p\n", &limit); */
}
