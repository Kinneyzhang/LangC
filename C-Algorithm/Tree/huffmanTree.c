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

typedef struct _minWeightData {
  char data;
  int weight;
  char* rest_data_array;
  int* rest_weight_array;
} MinWData;

MinWData* findMinAndDelete (char dataArray[], int weightArray[], int size) { // MinWData* minWDataS
  /**
   * Find the minimum weight and it's order in array, Then exchange the weight element and the last element in arrays(weight and data). Return the new arrays.
   */
  int minW = weightArray[0];
  char minWData = dataArray[0];
  int minWPos = 0;
  for (int i=1; i<size; i++) {
    int currW = weightArray[i];
    if (currW < minW) {
      minWPos = i;
      minW = currW;
      minWData = dataArray[i];
    }
  }
  char lastData = dataArray[size-1];
  int lastW = weightArray[size-1];
  dataArray[size-1] = minWData;
  weightArray[size-1] = minW;
  dataArray[minWPos] = lastData;
  weightArray[minWPos] = lastW;
  
  MinWData* minWDataS = (MinWData*)malloc(sizeof(MinWData));
  minWDataS->data = minWData;
  minWDataS->weight = minW;
  minWDataS->rest_data_array = dataArray;
  minWDataS->rest_weight_array = weightArray;

  return minWDataS;
}

// Get the last element (has minimum weight) in array and delete it from array.

HftNode* createHuffmanTree (void* dataArray[], int weightArray[], int size, HftNode* root) {
  
  /**
   * 1. when root is null, find the element with minimum weight, delete it from arrays
   *    and assign it to root.
   * 2. when root is not null, find the element with minimum weight, delete it from arrays
   *    and create parent node of the element and root, then assign parent node to root.
   */

  
}


int main () {
  char a = 'A'; char b = 'B'; char c = 'C';
  char d = 'D'; char e = 'E'; char f = 'F';
  char g = 'G'; char h = 'H'; char i = 'I';
  char dataArray[9] = {a,b,c,d,e,f,g,h,i};
  int weightArray[9] = {5,8,4,2,9,6,3,7,10};
  MinWData* S = findMinAndDelete(dataArray, weightArray, 9);
  printf("weight: %d, data: %c\n", S->weight, S->data);
  
  int* wArray = S->rest_weight_array;
  char* dArray = S->rest_data_array;

  printf("rest weight array: ");
  for (int i=0; i<8; i++) {
    printf("%d ", wArray[i]);
  }
  printf("\n");
  
  printf("rest data array: ");
  for (int i=0; i<8; i++) {
    printf("%c ", dArray[i]);
  }
  printf("\n");
}
