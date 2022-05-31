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

void insertNode (BtNode** root, COMPARE compare, void* data);
BtNode* createByPreOrder (void* arr[]);
BtNode* createByInOrder (void* arr[]);
BtNode* createByPostOrder (void* arr[]);
void preOrderTraversal (BtNode* root);
void inOrderTraversal (BtNode* root);
void postOrderTraversal (BtNode* root);
void levelOrderTraversal (BtNode* root);
int treeHeight (BtNode* root);

#endif
