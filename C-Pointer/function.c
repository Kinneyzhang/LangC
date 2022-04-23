#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* void func2() { */
/*   Object *var1 = ...; */
/*   int var2; */
/*   printf("Program Stack Example\n"); */
/* } */

/* void func1() { */
/*   Object *var3 = ...; */
/*   func2(); */
/* } */

/* int main() { */
/*   int var4; */
/*   func1(); */
/* } */

/* float average(int *arr, int size) { */
/*   int sum; */
/*   printf("arr:  %p\n", &arr); */
/*   printf("size: %p\n", &size); */
/*   printf("sum:  %p\n", &sum); */
/*   for(int i=0; i<size; i++) { */
/*     sum += arr[i]; */
/*     printf("i:    %p\n", &i); */
/*   } */
/*   return (sum * 1.0f) / size; */
/* } */

/* int main() { */
/*   int arr[] = {1,2,3,4}; */
/*   int size = 4; */
/*   int res = average(&arr, size); */
/*   printf("res:  %p\n", &res); */
/* } */

/* //指针传递数据：交换两个数字 */
/* void swapWithPointers(int* pnum1, int* pnum2) { */
/*   int tmp; */
/*   tmp = *pnum1; */
/*   *pnum1 = *pnum2; */
/*   *pnum2 = tmp; */
/* } */

/* int main() { */
/*   int n1 = 5; */
/*   int n2 = 10; */
/*   swapWithPointers(&n1, &n2); */
/*   printf("n1: %d\n", n1); */
/*   printf("n2: %d\n", n2); */
/*   return 0; */
/* } */

/* //传递指向常量的指针 */
/* void passAddressofConstants(const int* num1, int* num2) { */
/*   *num2 = *num1; */
/*   //\*num1 = 300; */
/*   //\*num2 = 300; */
/* } */

/* int main() { */
/*   const int limit = 100; */
/*   int res = 5; */
/*   passAddressofConstants(&limit, &res); */
/*   printf("limit: %d\n", limit); */
/*   printf("res: %d\n", res); */
/*   //passAddressofConstants(&limit, &limit); //error */
/*   assingAddressOfConstants(&23, &23); */
/*   return 0; */
/* } */

/* //返回指针 */
/* int* allocateArray(int size, int value) { */
/*   int* arr = (int*)malloc(size * sizeof(int)); */
/*   for(int i=0; i<size; i++) { */
/*     arr[i] = value; */
/*   } */
/*   return arr; */
/* } */

/* int main() { */
/*   int* vector = allocateArray(5, 45); */
/*   for(int i=0; i<5; i++) { */
/*     printf("%d\n", vector[i]);; */
/*   } */
/*   free(vector); */
/* } */

/* //传递空指针 */
/* int* allocateArray(int *arr, int size, int value) { */
/*   if(arr != NULL) { */
/*     for(int i=0; i<size; i++) { */
/*       arr[i] = value; */
/*     } */
/*   } */
/*   return arr; */
/* } */

/* int main() { */
/*   int* vector = (int*)malloc(5 * sizeof(int)); */
/*   allocateArray(vector, 5, 45); */
/*   for(int i=0; i<5; i++) { */
/*     printf("%d\n", vector[i]);; */
/*   } */
/*   free(vector); */
/* } */

/* //传递指针的指针 */
/* void allocateArray(int **arr, int size, int value) { */
/*   *arr = (int*)malloc(size * sizeof(int)); */
/*   if(*arr != NULL) { */
/*     for(int i=0; i<size; i++) { */
/*       *(*arr+i) = value; */
/*     } */
/*   } */
/* } */

/* int main() { */
/*   int *vector = NULL; */
/*   allocateArray(&vector, 5, 45); */
/*   printf("%p\n", &vector); */
/*   printf("%p\n", vector); */
/*   printf("%p\n", &*vector); */
/*   printf("%p\n", *vector); */
/*   for(int i=0; i<5; i++) { */
/*     printf("vector: %d\n", vector[i]); */
/*   } */
/* } */

/* void saferFree(void **pp) { */
/*   if(pp != NULL && *pp !=NULL) { */
/*     free(*pp); */
/*     *pp = NULL; */
/*   } */
/* } */

/* #define safeFree(p) saferFree((void**)&(p)) */

/* int main() { */
/*   int *pi; */
/*   pi = (int*)malloc(sizeof(int)); */
/*   *pi = 5; */
/*   printf("Before: %p\n", pi); */
/*   safeFree(pi); */
/*   printf("After: %p\n", pi); */
/*   safeFree(pi); */
/*   return (EXIT_SUCCESS); */
/* } */

/* //使用函数指针 */
/* int (*fptr1)(int); */
/* int square(int num) { */
/*   return num*num; */
/* } */
/* int main () { */
/*   int n = 5; */
/*   fptr1 = square; */
/*   printf("%d squared is %d\n", n, fptr1(n)); */
/*   printf("Address of square is %p\n", square); */
/* } */

/* //使用函数指针2 */
/* typedef int (*funcptr)(int); */

/* int square(int num) { */
/*   return num*num; */
/* } */

/* int main() { */
/*   funcptr fptr1 = square; */
/*   printf("%d squared is %d\n", 6, fptr1(6)); */
/* } */

/* //传递函数指针 */
/* int add(int num1, int num2) { */
/*   return num1 + num2; */
/* } */
/* int subtract(int num1, int num2) { */
/*   return num1 - num2; */
/* } */
/* typedef int (*fptrOperation)(int,int); */
/* int compute(fptrOperation operation, int num1, int num2) { */
/*   return operation(num1, num2); */
/* } */

/* int main() { */
/*   printf("%d\n", compute(add, 5, 6)); */
/*   printf("%d\n", compute(subtract, 5, 6)); */
/* } */

/* //返回函数指针 */
/* typedef int (*fptrOperation)(int,int); */

/* int add(int num1, int num2) { */
/*   return num1 + num2; */
/* } */
/* int subtract(int num1, int num2) { */
/*   return num1 - num2; */
/* } */

/* fptrOperation select(char opcode) { */
/*   switch(opcode) { */
/*     case '+': return add; */
/*     case '-': return subtract; */
/*   } */
/* } */

/* int evaluate(char opcode, int num1, int num2) { */
/*   fptrOperation operation = select(opcode); */
/*   return operation(num1, num2); */
/* } */

/* int main() { */
/*   printf("%d\n", evaluate('+', 5, 6)); */
/*   printf("%d\n", evaluate('-', 5, 6)); */
/* } */

/* //函数指针数组 */
/* typedef int (*operation)(int, int); */
/* operation operations[128] = {NULL}; */

/* int add(int num1, int num2) { */
/*   return num1 + num2; */
/* } */
/* int subtract(int num1, int num2) { */
/*   return num1 - num2; */
/* } */

/* void initializeOperationsArray() { */
/*   operations['+'] = add; */
/*   operations['-'] = subtract; */
/* } */
/* int evaluateArray(char opcode, int num1, int num2) { */
/*   operation operation = operations[opcode]; */
/*   return operation(num1, num2); */
/* } */

/* int main() { */
/*   initializeOperationsArray(); */
/*   printf("%d\n", evaluateArray('+', 5, 6)); */
/*   printf("%d\n", evaluateArray('-', 5, 6)); */
/* } */

/* //比较函数指针 */
/* typedef int (*fptrOperation)(int,int); */

/* int add(int num1, int num2) { */
/*   return num1 + num2; */
/* } */

/* int main() { */
/*   fptrOperation fptr1 = add; */
/*   if(fptr1 == add) { */
/*     printf("fptr1 points to add function\n"); */
/*   }else { */
/*     printf("fptr1 does not point to add function\n"); */
/*   } */
/* } */

/* //转换函数指针 */
/* typedef int (*fptrToSingleInt)(int); */
/* typedef int (*fptrToTwoInts)(int,int); */
/* int add(int,int); */
/* int add(int num1, int num2) { */
/*   return num1 + num2; */
/* } */
/* int main() { */
/*   fptrToTwoInts fptrFirst = add; */
/*   fptrToSingleInt fptrSecond = (fptrToSingleInt)fptrFirst; */
/*   fptrFirst = (fptrToTwoInts)fptrSecond; */
/*   printf("%d\n", fptrFirst(5,6)); */
/* } */
