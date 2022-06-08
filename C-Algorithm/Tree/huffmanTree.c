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

typedef struct _minWeightData {
  void* data;
  int weight;
  void* rest_data_array[20];
  int rest_weight_array[20];
} MinWData;

MinWData* findMinAndDelete (void* dataArray[], int weightArray[], int size) { // MinWData* minWDataS
  /**
   * Find the minimum weight and it's order in array, Then exchange the weight element and the last element in arrays(weight and data). Return the new arrays.
   */
  int minW = weightArray[0];
  void* minWData = dataArray[0];
  int minWPos = 0;
  for (int i=1; i<size; i++) {
    int currW = weightArray[i];
    if (currW < minW) {
      minWPos = i;
      minW = currW;
      minWData = dataArray[i];
    }
  }
  void* lastData = dataArray[size-1];
  int lastW = weightArray[size-1];
  dataArray[size-1] = minWData;
  weightArray[size-1] = minW;
  dataArray[minWPos] = lastData;
  weightArray[minWPos] = lastW;
  
  MinWData* minWDataS = (MinWData*)malloc(sizeof(MinWData));
  minWDataS->data = minWData;
  minWDataS->weight = minW;
  minWDataS->rest_data_array[0] = dataArray;
  minWDataS->rest_weight_array[0] = weightArray;

  return minWDataS;
}

// Get the last element (has minimum weight) in array and delete it from array.

/* HftNode* createHuffmanTree (void* dataArray[], int weightArray[], int size, HftNode* root) { */
/*   /\** */
/*    * 1. when root is null, find the element with minimum weight, delete it from arrays */
/*    *    and assign it to root. */
/*    * 2. when root is not null, find the element with minimum weight, delete it from arrays */
/*    *    and create parent node of the element and root, then assign parent node to root. */
/*    *\/ */
/*   int minWeightArray[4]; */
/*   twoMinWeight(weightArray, size, minWeightArray); */
/*   int minW1 = minWeightArray[0]; */
/*   int minW2 = minWeightArray[1]; */
/*   int k1 = minWeightArray[2]; */
/*   int k2 = minWeightArray[3]; */
/*   void* data1 = dataArray[k1]; */
/*   void* data2 = dataArray[k2]; */
  
/*   // create a new node which is the parent of the two nodes with minimum weight. */
  
/*   HftNode* node = initHuffmanNode(minW1, minWeightSum); */

/*   int minWeightSum = 0; */
/*   for (int i=0; i<2; i++) */
/*     minWeightSum += minWeightArray[i]; */
/*   HftNode* node = initHuffmanNode(NULL, minWeightSum); */
/*   node->left = minWeightArray[0]; */
/*   node->right = minWeightArray[1]; */

/*   // The current parent node is the root. */
/*   root = node; */
  
/*   // Delete the two weight data in */
/* } */

int main () {
  char a = 'A'; char b = 'B'; char c = 'C';
  char d = 'D'; char e = 'E'; char f = 'F';
  char g = 'G'; char h = 'H'; char i = 'I';
  void* dataArray[9] = {&a,&b,&c,&d,&e,&f,&g,&h,&i};
  int weightArray[9] = {5,8,4,2,9,6,3,7,10};
  /* MinWData* minWDataS; */
  findMinAndDelete(dataArray, weightArray, 9);
}
