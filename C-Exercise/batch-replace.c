// 批量替换特定文件夹下的所有文件的文本内容
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

// 每行最大长度
#define LINE_MAX 1024

/**
 *@param  path 输入文件路径
 *@return 文件行数
 */
int read_line(char *path, char** str)
{
  FILE *fp;
  int line_num = 0; // 文件行数
  int line_len = 0; // 文件每行的长度
  // r buf[LINE_MAX] = {0}; // 行数据缓存
  char* buf;

  fp = fopen(path, "rt");
  if (NULL == fp) {
    printf("open %s failed.\n", path);
    return -1;
  }
  
  buf = (char*)malloc(LINE_MAX * sizeof(char));
  while(fgets(buf, LINE_MAX, fp)) {  
    line_num++;
    line_len = strlen(buf);
    // 排除换行符
    if ('\n' == buf[line_len - 1]) {
      buf[line_len - 1] = '\0';
      line_len--;
      if (0 == line_len) {
        //空行
        continue;
      }
    }
    // windos文本排除回车符
    if ('\r' == buf[line_len - 1]) {
      buf[line_len - 1] = '\0';
      line_len--;
      if (0 == line_len) {
        //空行
        continue;
      }
    }
    // printf("%p, %s\n", buf, &buf);
    /* printf("%p, %s\n", buf+1, buf+1); */
    str[line_num-1] = buf;
    /* printf("%s\n", buf); */
    /** 对每行数据(buf)进行处理 **/

    buf = (char*)malloc(LINE_MAX * sizeof(char));
  }
  
  if (0 == feof) {
    // 未读到文件末尾
    printf("fgets error\n");
    return -1;
  }
  fclose(fp);

  return line_num;
}

// 把得到的每行字符串 按照逗号 分割为

// 根据当前的待处理的源文件路径,生成相同目录下的一个新文件.
/* char* copy_directory (path) { */
  
/* } */

int main (int argc, char *argv[]) {
  char* str[1024];
  char* path = "./repl-pairs.txt";
  int line_num = read_line(path, str);
  printf("line_num = %d\n", line_num);
  for (int i=0; i<line_num; i++) {
    printf("%s\n", str[i]);
  }
  return 0;
}
