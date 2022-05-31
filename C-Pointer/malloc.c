#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* static int *pi2; */

int main() {
  /* // 经典内存分配 */
  /* int *pi = (int*) malloc (sizeof(int)); */
  /* *pi = 5; */
  /* printf("*pi: %d\n", *pi); */
  /* free(pi); */

  /* // “堆管理器用到的额外内存” */
  /* char *pc = (char*)malloc(6); */
  /* for(int i=0; i<8; i++) { */
  /*   pc[i] = 0; */
  /* } */

  /* // 内存泄漏 */
  /* char *chunk; */
  /* while(1) { */
  /*   chunk = (char*)malloc(1000000); */
  /*   printf("Allocating\n"); */
  /*   //free(chunk); */
  /* } */

  // 丢失地址
  /* int *pi = (int*)malloc(sizeof(int)); */
  /* *pi = 5; */
  /* printf("address of *pi: %p\n", &pi); */
  /* printf("address in *pi: %p\n", pi); */
  /* printf("value of *pi: %d\n", *pi); */
  /* pi = (int*)malloc(sizeof(int)); */
  /* printf("address of *pi: %p\n", &pi); */
  /* printf("address in *pi: %p\n", pi); */
  /* printf("value of *pi: %d\n", *pi); */

  /* char *name = (char*)malloc(strlen("Kinney")+1); */
  /* printf("address of name: %p\n", name); */
  /* strcpy(name, "Kinney"); */
  /* while(*name != 0) { */
  /*   printf("current char is: %c; ", *name); */
  /*   printf("address of name: %p\n", name); */
  /*   name++; */
  /* } */
  /* printf("current char is: %c; ", *name); */
  /* printf("address of name: %p\n", name); */

  /* int *pi = (int*)malloc(sizeof(int)); */
  /* if(pi != NULL) */
  /*   printf("指针不为空\n"); */
  /* else */
  /*   printf("指针无效\n"); */

  /* // 静态全局指针和malloc */
  /* // static int *pi = malloc(sizeof(int)); // error */
  /* static int *pi; */
  /* pi = malloc(sizeof(int)); */
  /* printf("pi:%p\n", pi); */
  /* pi2 = malloc(sizeof(int)); */
  /* printf("pi2:%p\n", pi2); */

  /* int* cpi = (int*) malloc(sizeof(int)); */
  /* printf("content of *cpi:%d\n", *(cpi+2)); */
  /* int* pi2 = (int*) calloc(5, sizeof(int)); // 分配20个字节 */
  /* printf("content of *pi2:%d\n", *pi2); */

  /* //realloc less */
  /* char *str1; */
  /* char *str2; */
  /* char *str3; */
  /* str1 = (char*)malloc(16); */
  /* strcpy(str1, "0123456789AB"); */
  /* str2 = realloc(str1, 8); // 这里实际使用的内存超出了分配的内存，可以将NUL赋给最后一个字节。 */
  /* str3 = str1; */
  /* printf("str1 value: %p [%s]; %p\n", str1, str1, &str1); */
  /* printf("str2 value: %p [%s]; %p\n", str2, str2, &str2); */
  /* printf("str3 value: %p [%s]; %p\n", str3, str3, &str3); */

  /* //realloc more */
  /* char *str1; */
  /* char *str2; */
  /* str1 = (char*)malloc(16); */
  /* strcpy(str1, "0123456789AB"); */
  /* str2 = realloc(str1, 1200); */
  /* printf("str1 value: %p [%s]\n", str1, str1); */
  /* printf("str2 value: %p [%s]\n", str2, str2); */
  /* free(str2); */

  /* //free */
  /* int *pi = (int*)malloc(sizeof(int)); */
  /* *pi = 10; */
  /* printf("address of *pi: %p\n", pi); */
  /* printf("address of *pi: %p\n", &*pi); */
  /* free(pi); */
  /* printf("address of *pi: %d\n", *pi); */
  /* pi = NULL; */

  /* int num = 3; */
  /* int *pi = &num; */
  /* free(pi); //未定义 */

  /* //迷途指针 */
  /* int *pi = (int*) malloc(sizeof(int)); */
  /* *pi = 5; */
  /* printf("*pi: %d\n", *pi); */
  /* free(pi); */
  /* *pi = 10; //迷途指针 */
  /* printf("*pi: %d\n", *pi); */
}
