#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* int main() { */
/* //一维数组 */
/* int vector[5]; */
/* printf("size: %d\n", sizeof(vector)/sizeof(int)); */

/* //二维数组 */
/* int matrix[2][3] = {{1,2,3},{4,5,6}}; */
/* for(int i=0; i<2; i++) { */
/*   printf("&matrix[%d]: %p; sizeof(matrix[%d]):%d\n", i, &matrix[i], i, sizeof(matrix[i])); */
/* } */

/* //三维数组 */
/* int arr3d[3][2][4] = { */
/*   {{1,2,3,4}, {5,6,7,8}}, */
/*   {{9,10,11,12}, {13,14,15,16}}, */
/*   {{17,18,19,20}, {21,22,23,24}} */
/* }; */
/* for(int i=0; i<3; i++) { */
/*   for(int j=0; j<2; j++) { */
/*     for(int k=0; k<4; k++) { */
/*       printf("&arr3d[%d][%d][%d]: %p\n", i, j, k, &arr3d[i][j][k]); */
/*     } */
/*   } */
/* } */

/* //数组的指针表示法 */
/* int vector[5] = {1,2,3,4,5}; */
/* int *pv = vector; */
/* printf("%p\n", vector); */
/* printf("%p\n", &vector[0]); */
/* printf("%p\n", &vector); //返回整个数组的指针，有何区别?? */
  
/* printf("%d\n", *(vector+1)); */
/* printf("%d\n", vector[1]); */
  
/* printf("%d\n", *(pv+1)); */
/* printf("%d\n", pv[1]); */

/* //数组和指针的差别 */
/* int vector[5] = {1,2,3,4,5}; */
/* int *pv = vector; */
/* printf("%d\n", vector[2]); */
/* printf("%d\n", *(vector+2)); // 尽管结果相同，但是生成的机器码不同 */

/* //使用malloc创建一维数组 */
/* int *pv = (int*)malloc(5 * sizeof(int)); */
/* for(int i=0; i<5; i++) { */
/*   pv[i] = i+1; */
/*   printf("pv[%d]:%d\n", i, pv[i]); */
/* } */
/* /\* for(int i=0; i<5; i++) { *\/ */
/* /\*   *(pv+i) = i+1; *\/ */
/* /\*   printf("pv[%d]:%d\n", i, *(pv+i)); *\/ */
/* } */
/* } */

/* //使用realloc调大指针长度 */
/* char* getline2(void) { */
/*   const size_t sizeIncrement = 10; */
/*   char* buffer = malloc(sizeIncrement); */
/*   char* currentPosition = buffer; */
/*   size_t maximumLength = sizeIncrement; */
/*   size_t length = 0; */
/*   int character; */
/*   if(currentPosition == NULL){return NULL;} */
/*   while(1) { */
/*     character = fgetc(stdin); */
/*     if(character == '\n') {break;} */
/*     if(++length >= maximumLength) { */
/*       char *newBuffer = realloc(buffer, maximumLength += sizeIncrement); */
/*       if(newBuffer == NULL) { */
/*         free(buffer); */
/*         return NULL; */
/*       } */
/*       currentPosition = newBuffer + (currentPosition - buffer); */
/*     } */
/*     *currentPosition++ = character; */
/*   } */
/*   *currentPosition = '\0'; */
/*   return buffer; */
/* } */

/* int main() { */
/*   char *buffer = getline2(); */
/*   while(1) { */
/*     if(*buffer == '\0') {break;} */
/*     printf("%c", *(buffer++)); */
/*   } */
/* } */

/* //使用realloc调小指针长度：实现trim函数 */
/* char* trim(char* phrase) { */
/*   char* old = phrase; */
/*   char* new = phrase; */
/*   while(*old == ' ') { */
/*     old++; */
/*   } */
/*   while(*old) { */
/*     *(new++) = *(old++); */
/*   } */
/*   *new = 0; */
/*   return (char*)realloc(phrase, strlen(phrase)+1); */
/* } */

/* int main() { */
/*   char* buffer = (char*)malloc(strlen("  cat")+1); */
/*   strcpy(buffer, "  cat"); */
/*   printf("%s\n", trim(buffer)); */
/* } */

/* //传递数组：数组表示法 */
/* void displayArray(int arr[], int size) { */
/*   for(int i=0; i<size; i++) { */
/*     printf("%d\n", arr[i]); */
/*     printf("%d\n", *(arr+i)); */
/*   } */
/* } */
/* int main() { */
/*   int vector[5] = {1,2,3,4,5}; */
/*   displayArray(vector, 5); */
/*   displayArray(vector, sizeof(vector)/sizeof(int)); */
/* } */

/* //传递数组：指针表示法 */
/* void displayArray(int* arr, int size) { */
/*   for(int i=0; i<size; i++) { */
/*     printf("%d\n", arr[i]); */
/*     printf("%d\n", *(arr+i)); */
/*   } */
/* } */
/* int main() { */
/*   int vector[5] = {1,2,3,4,5}; */
/*   displayArray(vector, 5); */
/*   displayArray(vector, sizeof(vector)/sizeof(int)); */
/* } */

//使用指针的一维数组
/* int main() { */
/*   int* arr[5]; */
/*   for(int i=0; i<5; i++) { */
/*     arr[i] = (int*)malloc(sizeof(int)); */
/*     *arr[i]=i; */
/*   } */
/*   for(int i=0; i<5; i++) { */
/*     printf("arr[%d]: %p; value: %d\n", i, arr[i], *arr[i]); */
/*   } */
/* } */
/* //等价指针表示法 */
/* int main() { */
/*   int* arr[5]; */
/*   for(int i=0; i<5; i++) { */
/*     *(arr+i) = (int*)malloc(sizeof(int)); */
/*     **(arr+i)=i; */
/*   } */
/*   for(int i=0; i<5; i++) { */
/*     printf("arr[%d]: %p; value: %d\n", i, *(arr+i), **(arr+i)); */
/*   } */
/* } */

//指针和多维数组
/* int main() { */
/*   int matrix[2][5] = {{1,2,3,4,5},{6,7,8,9,10}}; */
/*   for(int i=0; i<2; i++) { */
/*     for(int j=0; j<5; j++) { */
/*       printf("matrix[%d][%d] Address: %p; Value: %d\n", i, j, &matrix[i][j], matrix[i][j]); */
/*     } */
/*   } */
/* } */

/* int main() { */
/*   int matrix[2][5] = {{1,2,3,4,5},{6,7,8,9,10}}; */
/*   int (*pmatrix)[5] = matrix; // 指向整个数组的指针，数组中存放整数 */
/*   printf("%p\n", matrix); */
/*   printf("%p\n", pmatrix); */
/*   printf("%p\n", &matrix[1][4]); */
/*   printf("%p\n", pmatrix+1); */
/*   printf("%d\n", **pmatrix); //1 */
/*   printf("%d\n", **(pmatrix+1)); //6 */
/*   printf("%d\n", *pmatrix[0]); //1 */
/*   printf("%d\n", *(pmatrix[0]+2)); //3 */
/*   printf("%d\n", *pmatrix[1]); //6 */
/*   printf("%d\n", *(pmatrix[1]-1)); //5 */
/*   printf("%ld\n", sizeof(matrix[0])); */
/* } */

/* //动态分配二维数组：不连续内存 */
/* int main() { */
/*   int rows = 2; */
/*   int columns = 5; */
/*   int **matrix = (int**)malloc(rows * sizeof(int*)); */
/*   for(int i=0; i<rows; i++) { */
/*     matrix[i] = (int*)malloc(columns * sizeof(int)); */
/*   } */
/*   printf("%p\n", matrix[0]); */
/*   printf("%p\n", matrix[0]+1); */
/*   printf("%p\n", matrix[0]+2); */
/*   printf("%p\n", matrix[0]+3); */
/*   printf("%p\n", matrix[0]+4); */
/*   // 不连续 */
/*   printf("%p\n", matrix[1]); */
/*   printf("%p\n", matrix[1]+1); */
/* } */

/* //动态分配二维数组：两次malloc分配连续内存 */
/* int main() { */
/*   int rows = 2; */
/*   int columns = 5; */
/*   // 分配了一个整数指针的数组，一个元素用来存储一行的指针 */
/*   int **matrix = (int**)malloc(rows * sizeof(int*)); */
/*   // 为所有的元素分配内存 */
/*   matrix[0] = (int*)malloc(rows * columns * sizeof(int)); */
/*   // 第二个malloc 所分配的内存的一部分赋值给第一个数组的每个元素 */
/*   for(int i=1; i<rows; i++) */
/*     matrix[i] = matrix[0] + i * columns; */
/* } */

/* //动态分配二维数组：一次性分配连续内存 */
/* //这种方法不能使用二维数组的下标索引，但表明了二维数组的一维内存的本质。 */
/* int main() { */
/*   int rows = 2; */
/*   int columns = 5; */
/*   int *matrix = (int*)malloc(rows * columns * sizeof(int)); */
/*   for(int i=0; i<rows; i++) { */
/*     for(int j=0; j<columns; j++) { */
/*       *(matrix + (i*columns) + j) = i*j; */
/*     } */
/*   } */
/* } */
