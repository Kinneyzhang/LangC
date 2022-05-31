void gkReadFile (char* file, char* strBuf) {
  FILE *fp = fopen(file, "r");
  if (fp == NULL) {
    perror("Open file failed!");
    return;
  }
  int n = 0;
  do {
    strBuf[n++] = fgetc(fp);
  } while (!feof(fp));
  fclose(fp);
}
