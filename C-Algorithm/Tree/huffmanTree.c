/**
 * 哈夫曼树（最有二叉树）:带权路径长度的值最小
 * 根据数组构建一个哈夫曼树
 * 
 */

#include "huffmanTree.h"

HftNode* initHuffmanNode (char data, int weight) {
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

MinWData* findMinAndDelete (char dataArray[], int weightArray[], int size) {
  
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

HftNode* createHuffmanTree (char dataArray[], int weightArray[],
                            int size, HftNode* root) {
  
  /**
   * 1. when root is null, find the element with minimum weight,
   *    delete it from arrays and assign it to root.
   * 2. when root is not null, find the element with minimum weight, 
   *    delete it from arrays and create parent node of the element 
   *    and root, then assign parent node to root.
   */
  
  while (1) {
    MinWData* minWDataS = findMinAndDelete(dataArray, weightArray, size);
    int minW = minWDataS->weight;
    char minD = minWDataS->data;
    char* restDArray = minWDataS->rest_data_array;
    int* restWArray = minWDataS->rest_weight_array;

    // printf("min weight: %d\n", minW);
    
    if (root->data == 1) {
      root->data = minD;
      root->weight = minW;
      root->left = NULL;
      root->right = NULL;
      dataArray = restDArray;
      weightArray = restWArray;
      // printf("root weight: %d\n", root->weight);
      printf("- root data: %c\n", root->data);
    } else {
      // Create the node with minimum weight in current array.
      HftNode* mNode = (HftNode*)malloc(sizeof(HftNode));
      mNode->data = minD;
      mNode->weight = minW;
      mNode->left = NULL;
      mNode->right = NULL;
      
      // Create the parent node and assign it as a root.
      HftNode* pNode = (HftNode*)malloc(sizeof(HftNode));
      pNode->data = 0;
      pNode->weight = root->weight + minW;
      pNode->left = root;
      pNode->right = mNode;
      root = pNode;
      // printf("root weight: %d\n", root->weight);
      printf("root data: %c\n", root->right->data);
    }
    
    dataArray = restDArray;
    weightArray = weightArray;
    size -= 1;
    if (size == 0) break;
  }
  /* printf("root weight: %d\n", root->weight); */
  return root;
}

void preOrderTraversal (HftNode* root) {
  if (root == NULL) {
    return;
  } else {
    printf("%d ", root->weight);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
  }
}

void inOrderTraversal (HftNode* root) {
  if (root == NULL) {
    return;
  } else {
    inOrderTraversal(root->left);
    printf("%c ", root->data);
    inOrderTraversal(root->right);
  }
}

void postOrderTraversal (HftNode* root) {
  if (root == NULL) {
    return;
  } else {
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%c ", root->data);
  }
}

int main () {
  char a = 'A'; char b = 'B'; char c = 'C';
  char d = 'D'; char e = 'E'; char f = 'F';
  char g = 'G'; char h = 'H'; char i = 'I';
  
  char dataArray[9] =  {a,b,c,d,e,f,g,h,i};
  int weightArray[9] = {5,8,4,2,9,6,3,7,10};

  // the init data is 1;
  HftNode *root = initHuffmanNode(1, 0);
  createHuffmanTree(dataArray, weightArray, 9, root);
  preOrderTraversal(root); // 有问题，为什么不能够遍历到底？？
  printf("\n");
}
