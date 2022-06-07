/**
 * 哈夫曼树（最有二叉树）:带权路径长度的值最小
 * 根据数组构建一个哈夫曼树
 * 
 */

#include "huffmanTree.h"

HftNode* initHuffmanNode (void* data, int weight) {
  HftNode* node = (HftNode*)malloc(sizeof(HftNode));
  node->data = data;
  node->weight = weight;
  node->left = NULL;
  node->right = NULL;
  return node;
}

int* twoMinWeight (int weightArray[], int length, int minArray[4]) {
  
  /**
   * Return the two minimum weight and their order in weightArray.
   */
  
  int minWeight1 = weightArray[0];
  int minWeight2 = weightArray[0];
  int k1 = 0;
  int k2 = 0;
  for (int i=1; i<length; i++) {
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

/* HftNode* createHuffmanTree (void* dataArray[], int weightArray[], int length, HftNode* root) { */
/*   int minWeightArray[4]; */
/*   twoMinWeight(weightArray, length, minWeightArray); */
/*   int minW1 = minWeightArray[0]; */
/*   int minW2 = minWeightArray[1]; */
/*   int k1 = minWeightArray[2]; */
/*   int k2 = minWeightArray[3]; */
  
/*   // create a new node which is the parent of the two nodes with minimum weight. */
/*   int minWeightSum = 0; */
/*   for (int i=0; i<2; i++) */
/*     minWeightSum += minWeightArray[i]; */
  
/*   HftNode* node = initHuffmanNode(minW1, minWeightSum); */
  
/*   HftNode* node = initHuffmanNode(NULL, minWeightSum); */
/*   node->left = minWeightArray[0]; */
/*   node->right = minWeightArray[1]; */

/*   // Delete the two weight data in  */
/* } */

int main () {
  int weightArray[9] = {5,8,4,2,9,6,3,7,1};
  int minArray[2];
  twoMinWeight(weightArray, 9, minArray);
  for (int i=0; i<4; i++) {
    printf("%d ", minArray[i]);
  }
  printf("\n");
}
