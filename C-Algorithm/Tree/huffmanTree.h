#ifndef __HUFFMAN_TREE_H__
#define __HUFFMAN_TREE_H__

#include <stdlib.h>
#include <stdio.h>
#include "binaryTree.h"

// http://data.biancheng.net/view/33.html

typedef struct _huffman_tree_node {
  void* data;
  int weight;
  struct _huffman_tree_node *left;
  struct _huffman_tree_node *right;
} HftNode;

HftNode* initHuffmanNode (void* data, int weight) {
  HftNode* node = (HftNode*)malloc(sizeof(HftNode));
  node->data = data;
  node->weight = weight;
  node->left = NULL;
  node->right = NULL;
  return node;
}

void insertHuffmanNode (BtNode* root, void* data, int weight) {
  
}

HftNode* createHuffmanTree (void* dataArray[], int weightArray[], int length) {
  int minWeight1, minWeight2 = weightArray[0];
  for (int i=1; i<length; i++) {
    // 5 3 7 6 1 9 2 4 0
    if (weightArray[i] < minWeight1) {
      minWeight1 = weightArray[i];
    }
  }
}



#endif
