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

#endif
