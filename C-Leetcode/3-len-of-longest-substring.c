/**
 * 无重复字符的最长子串
 * 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
 * 滑动窗口问题
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* // while 循环条件中写 i++，判断的是i, 当执行到body时是i+1；可以用来计算字符串长度，但是无法打印第一个字符。 */
/* void test () { */
/*   int i = 0; */
/*   char* s  = "c"; */
/*   while (s[i++] != '\0') { */
/*     printf("i:%d, s:%c", i, s[i]); */
/*   } */
/* } */

int inString (char* s, char a) {
  int i = 0;
  while (s[i] != '\0') {
    if (a == s[i]) return 1;
    i++;
  }
  return 0;
}

void printStr (char* s) {
  int i = 0;
  while (s[i] != '\0') {
    printf("%c ", s[i]);
    i++;
  }
  printf("\n");
}

int lengthOfLongestSubstring (char* s) {
  int size = strlen(s);
  int len = 0;
  char *aux;
  
  for (int i=0; i<size-1; i++) {
    aux[0] = s[i];
    for (int j=i+1; j<size; j++) {
      if (!inString(aux, s[j])) {
        aux[j-i] = s[j];
      } else {
        int tlen = strlen(aux);
        printStr(aux);
        if (tlen > len) len = tlen;
        break;
      }
    }
    memset(aux, 0, strlen(aux));
  }
  return len;
}

int main () {
  char* s = "fababcbeccabeab";
  printf("length: %d\n", lengthOfLongestSubstring(s));
}
