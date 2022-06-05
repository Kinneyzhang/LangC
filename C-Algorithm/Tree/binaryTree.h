#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

#include <stdlib.h>
#include <stdio.h>

typedef struct _btree_node {
  void* data;
  struct _btree_node *left;
  struct _btree_node *right;
} BtNode;

typedef int(*COMPARE)(void*, void*);
typedef void(*PRINT)(void*);

void insertTreeNode (BtNode** root, COMPARE compare, void* data);
void preOrderTraversal (BtNode* root, PRINT print);
void inOrderTraversal (BtNode* root, PRINT print);
void postOrderTraversal (BtNode* root, PRINT print);
void levelOrderTraversal (BtNode* root, PRINT print);
int treeHeight (BtNode* root);

#endif
