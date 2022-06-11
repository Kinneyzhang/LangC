#ifndef __HUFFMAN_TREE_H__
#define __HUFFMAN_TREE_H__

#include <stdlib.h>
#include <stdio.h>
/* #include "binaryTree.h" */

// http://data.biancheng.net/view/33.html

typedef struct _huffman_tree_node {
  char data;
  int weight;
  struct _huffman_tree_node *left;
  struct _huffman_tree_node *right;
} HftNode;

typedef struct _minWeightData {
  char data;
  int weight;
  char* rest_data_array;
  int* rest_weight_array;
} MinWData;


HftNode* initHuffmanNode (char data, int weight);
MinWData* findMinAndDelete (char dataArray[], int weightArray[], int size);
void createHuffmanTree (char dataArray[], int weightArray[], int size, HftNode* root);
void preOrderHuffmanTree (HftNode* root);

#endif
