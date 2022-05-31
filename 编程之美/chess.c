// 中国象棋将帅问题
// 将帅分别用A,B表示，它们被限制在己方的3x3方格里面。A被{d10, f10, d8, f8}包围，B被{d3, f3, d1, f1}包围，A和B不能处于同一纵线上。请写程序，输出A，B所有合法的位置，要求在代码中只使用一个变量。

/**
 * 1 2 3
 * 4 5 6
 * 7 8 9
 **/

#include<stdlib.h>
#include<stdio.h>

#define HALF_BITS_LENGTH 4
#define FULLMASK 255
#define LMASK (FULLMASK << HALF_BITS_LENGTH)

int main () {
  
  return 0;
}
