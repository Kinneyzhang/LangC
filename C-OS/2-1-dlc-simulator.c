#include<stdio.h>
#include<unistd.h>

#define REGS_FOREACH(_) _(X) _(Y)
#define RUN_LOGIC X1 = !X && Y; Y1 = !X && !Y;
#define DEFINE(X) static int X, X##1;
#define UPDATE(X) X = X##1;
#define PRINT(X) printf(#X " = %d ", X);

// #: 将宏定义中的 传入参数名 转换成用一对双引号括起来参数名字符串.
// ##: 连接符（concatenator），用来将两个Token连接为一个Token.
// 合法的语法: printf("hello " "world %s", "kinney\n");;;;
// 宏展开: gcc -E a.c
/* 0 0 
 * 0 1
 * 1 0
 * 0 0
 * 0 1
 * .. */

int main () {
  REGS_FOREACH(DEFINE);
  while(1) { //clock
    RUN_LOGIC;
    REGS_FOREACH(PRINT);
    REGS_FOREACH(UPDATE);
    putchar('\n');
    sleep(1);
  }
}

/* int main () { */
/*   static int X, X1; static int Y, Y1;; */
/*   while(1) { */
/*     X1 = !X && Y; Y1 = !X && !Y;; */
/*     printf("X" " = %d ", X); printf("Y" " = %d ", Y);; */
/*     X = X1; Y = Y1;; */
/*     putchar('\n'); */
/*     sleep(1); */
/*   } */
/* } */
