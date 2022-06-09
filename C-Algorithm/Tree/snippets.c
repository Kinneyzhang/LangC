int* twoMinWeight (int weightArray[], int size, int minArray[4]) {
  
  /**
   * Return the two minimum weight and their order in weightArray.
   */
  
  int minWeight1 = weightArray[0];
  int minWeight2 = weightArray[0];
  int k1 = 0;
  int k2 = 0;
  for (int i=1; i<size; i++) {
    int currWeight = weightArray[i];
    if (currWeight < minWeight1) {
      minWeight2 = minWeight1;
      k2 = k1;
      minWeight1 = currWeight;
      k1 = i;
    }
    if (currWeight < minWeight2 && currWeight != minWeight1) {
      minWeight2 = currWeight;
      k2 = i;
    }
    /* printf("w1:%d, w2:%d\n", minWeight1, minWeight2); */
  }
  *minArray = minWeight1;
  *(minArray+1) = minWeight2;
  *(minArray+2) = k1;
  *(minArray+3) = k2;
  return minArray;
}
