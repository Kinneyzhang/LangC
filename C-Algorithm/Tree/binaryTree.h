#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct _btree_node {
  void* data;
  struct _btree_node *left;
  struct _btree_node *right;
  // bool isDeleted;
} BtNode;

typedef int(*COMPARE)(void*, void*);
typedef void(*PRINT)(void*);

BtNode* initTreeNode (void* data);
// 这是根据大小构建二叉树，实际上是一个二叉查找树
// 需要寻找更普遍的构建二叉树的方法，根据实际会用到的情况
void insertTreeNode (BtNode** root, COMPARE compare, void* data);
void preOrderTraversal (BtNode* root, PRINT print);
void inOrderTraversal (BtNode* root, PRINT print);
void postOrderTraversal (BtNode* root, PRINT print);
void levelOrderTraversal (BtNode* root, PRINT print);
BtNode* findNodeByData (BtNode* root, COMPARE compare, void* data);
int treeHeight (BtNode* root);

#endif
