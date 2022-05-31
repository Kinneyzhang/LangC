<<<<<<< HEAD
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
=======
// 中国象棋将帅问题
// 将帅分别用A,B表示，它们被限制在己方的3x3方格里面。A被{d10, f10, d8, f8}包围，B被{d3, f3, d1, f1}包围，A和B不能处于同一纵线上。请写程序，输出A，B所有合法的位置，要求在代码中只使用一个变量。

/**
 * 1 2 3
 * 4 5 6
 * 7 8 9
 **/

#include<stdlib.h>
#include<stdio.h>

void printDiffChess () {
  char* chessPos[2][9] =
    {{"d1","e1","f1","d2","e2","f2","d3","e3","f3"}, // 帅
     {"d8","e8","f8","d9","e9","f9","d10","e10","f10"}}; // 将
  for (int i=0; i<9; i++) {
    for (int j=0; j<9; j++) {
      if ((i+1)%3 != (j+1)%3) {
        printf("(%s, %s)\n", chessPos[0][i], chessPos[1][j]);
      }
    }
  }
}

int main () {
  unsigned char a = 10100000;
  unsigned char b = 00001101;
  printf("%c\n", a|b);
  printf("%c\n", a^b);
  // printDiffChess();
}
>>>>>>> 9436f879d7dc2bbe577ff47b197392fb1ab31a17
