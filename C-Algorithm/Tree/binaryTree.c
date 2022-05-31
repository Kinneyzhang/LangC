/**
 * 二叉树 - BinaryTree
 * 数结构可以极大的提高搜索的效率
 * 
**/

#include "binaryTree.h"

void insertNode (BtNode** root, COMPARE compare, void* data) {
  // 重要：root中存放的是节点的指针
  BtNode* node = (BtNode*)malloc(sizeof(BtNode));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  if (root == NULL) {
    *root = &node;
  }
  
  BtNode* curr = *root; // 获取根节点
  
  while (curr) {
    // 1. 和当前节点比较，如果小，如果有左孩子节点，赋为当前节点；如果没有左孩子节点，插入node
    // 2. 和当前节点比较，如果大，如果有右孩子节点，赋为当前节点；如果没有右孩子节点，插入node
    if (compare(node, curr) < 0) {
      if (curr->left) {
        curr = curr->left;
      } else {
        curr->left = node;
      }
    } else {
      
    }
  }
}

int compareInt (int* a, int* b) {
  if (*a < *b) {
    return -1;
  }
  return 1;
}


/* int main () { */
/*   int a = 3; */
/*   BtNode* root = (BtNode*)malloc(sizeof(BtNode)); */
/*   root->data = &a; */
/*   root->left = NULL; */
/*   root->right = NULL; */

/*   int data = 5; */
/*   insertNode(&root, (COMPARE)compareInt, &data); */
/* } */
