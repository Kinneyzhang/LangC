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

MinWData* findMinAndDelete (char dataArray[], int weightArray[], int size) {
  
  /**
   * Find the minimum weight and it's order in array, Then exchange the weight
   * element and the last element in arrays(weight and data). Return the new arrays.
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

void createHuffmanTree (char dataArray[], int weightArray[],
                        int size, HftNode* root) {
  
  /**
   * 1. find the element with minimum weight and create a node.
   * 2. when curr is null, assign the node to curr.
   * 3. when curr is not null, create parent node of the node 
   *    and curr, then assign parent node to curr.
   * 4. set the new dataArray, weightArray and size, then loop.
   */
  
  HftNode* curr = NULL; // curr is a pointer points to the root of huffman tree.
  
  while (1) {
    MinWData* minWDataS = findMinAndDelete(dataArray, weightArray, size);
    int minW = minWDataS->weight;
    char minD = minWDataS->data;
    char* restDArray = minWDataS->rest_data_array;
    int* restWArray = minWDataS->rest_weight_array;

    // Create the node with minimum weight in current array.
    HftNode* mNode = (HftNode*)malloc(sizeof(HftNode));
    mNode->data = minD;
    mNode->weight = minW;
    mNode->left = NULL;
    mNode->right = NULL;
    
    if (curr == NULL) {
      curr = mNode;
      /* printf("- curr w:%d d:%c\n", curr->weight, curr->data); */
    } else {
      // Create the parent node and assign it as a root.
      HftNode* pNode = (HftNode*)malloc(sizeof(HftNode));
      pNode->data = 0;
      pNode->weight = curr->weight + minW;
      pNode->left = curr;
      pNode->right = mNode;
      
      /**
       * 1. 函数参数传递指针，本质上就是值传递，只不过传的是一个指针变量
       * 2. 函数内部修改了指针的值（修改了指针的指向），如果不返回自然不会改变原来的指针指向。
       * 3. 但是解引后再赋值就不一样了，接引可以访问指针指向的节点内存，可以将节点赋值为其他的节点。此时，无需返回值。
       */
      
      curr = pNode;
      
      /* printf("curr  w: %d d: %c\n", curr->weight, curr->data); */
      /* printf("left  w: %d d: %c\n", curr->left->weight, curr->left->data); */
      /* printf("right w: %d d: %c\n", curr->right->weight, curr->right->data); */
    }
    
    dataArray = restDArray;
    weightArray = restWArray;
    size -= 1;
    if (size == 0) break;
  }
  *root = *curr;
}

void preOrderHuffmanTree (HftNode* root) {
  if (root == NULL) {
    return;
  } else {
    printf("w:%d d:%c\n", root->weight, root->data);
    preOrderHuffmanTree(root->left);
    preOrderHuffmanTree(root->right);
  }
}

/* void inOrderTraversal (HftNode* root) { */
/*   if (root == NULL) { */
/*     return; */
/*   } else { */
/*     inOrderTraversal(root->left); */
/*     printf("w:%d d:%c\n", root->weight, root->data); */
/*     inOrderTraversal(root->right); */
/*   } */
/* } */

/* void postOrderTraversal (HftNode* root) { */
/*   if (root == NULL) { */
/*     return; */
/*   } else { */
/*     postOrderTraversal(root->left); */
/*     postOrderTraversal(root->right); */
/*     printf("w:%d d:%c\n", root->weight, root->data); */
/*   } */
/* } */

int main () {
  char a = 'A'; char b = 'B'; char c = 'C';
  char d = 'D'; char e = 'E'; char f = 'F';
  char g = 'G'; char h = 'H'; char i = 'I';
  
  char dataArray[9] =  {a,b,c,d,e,f,g,h,i};
  int weightArray[9] = {5,8,4,2,9,6,3,7,10};
  
  HftNode *root = initHuffmanNode(0, 0);
  createHuffmanTree(dataArray, weightArray, 9, root);
  /* printf("w:%d d:%c\n", root->weight, root->data); */
  preOrderHuffmanTree(root);
}
