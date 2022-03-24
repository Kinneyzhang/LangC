/*
** 这个程序从标准输入中读取输入行并在标准输出中打印这些输入行，
** 每个输入行的后面一行是该行内容的一部分。
**
** 输入的第1行是一串列标号，串的最后以一个负数结尾。
** 这些列标号成对出现，说明需要打印的输入行的列的范围。
** 例如，0 3 10 12 –1表示第0列到第3列，第10列到第12列的内容将被打印。
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_COLS 20
#define MAX_INPUT 1000

int read_column_numbers(int columns[], int max);
void rearrange(char *output, char const *input,
               int n_columns, int const columns[]);

int read_column_numbers(int columns[], int max) {
  int num = 0;
  int ch;
  
  while(num < max && scanf("%d", &columns[num]) == 1 // 输入为数字返回1
         && columns[num] >= 0)
    num += 1;
  
  if(num % 2 != 0) {
    puts("Last column number is not paired!");
    exit(EXIT_FAILURE);
  }
  
  while((ch = getchar()) != EOF && ch != '\n');
  
  return num;
}

void rearrange(char *output, char const *input,
               int n_columns, int const columns) {

  output_col = 0;
  
  for(int col=0; col<n_columns; col+=2) {
    int nchars = columns[col+1] - columns[col] + 1;
    if(columns[col] >= len || output_col == MAX_INPUT -1)
      break;
    
  }
}

int main(void) {
  int n_columns;
  int columns[MAX_COLS];
  n_columns = read_column_numbers(columns, MAX_COLS);
  for(int i=0; i<4; i++) {
    printf("%d\n", columns[i]);
  }
  
}
