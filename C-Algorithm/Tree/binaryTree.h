#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

#include <stdlib.h>
#include <stdio.h>

typedef struct _btree_node {
  void* data;
  struct _btree_node *left;
  struct _btree_node *right;
} BtNode;

BtNode* createByPreOrder (void* arr[]);
BtNode* createByInOrder (void* arr[]);
BtNode* createByPostOrder (void* arr[]);
void preOrderTraversal (TreeNode* root);
void inOrderTraversal (TreeNode* root);
void postOrderTraversal (TreeNode* root);
void levelOrderTraversal (TreeNode* root);
int treeHeight (TreeNode* root);

#endif;
