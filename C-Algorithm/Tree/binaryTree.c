/**
 * 二叉树 - BinaryTree
 * 数结构可以极大的提高搜索的效率
 * 
 **/

#include "binaryTree.h"
#include "../LinkedList/queue.h"

void insertTreeNode (BtNode** root, COMPARE compare, void* data) {
  // 重要：root中存放的是指向节点指针的指针
  BtNode* node = (BtNode*)malloc(sizeof(BtNode));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  if (*root == NULL) {
    *root = node;
    return;
  }

  BtNode* curr = *root; // 获取根节点指针
  
  while (1) {
    // 1. 和当前节点比较，如果小，如果有左孩子节点，赋为当前节点；如果没有左孩子节点，插入node
    // 2. 和当前节点比较，如果大，如果有右孩子节点，赋为当前节点；如果没有右孩子节点，插入node
    if (compare(data, curr->data) < 0) {
      if (curr->left != NULL) {
        curr = curr->left;
      } else {
        // printf("left  of %d: %d\n", *(int*)curr->data, *(int*)node->data);
        curr->left = node;
        break;
      }
    } else {
      if (curr->right != NULL) {
        curr = curr->right;
      } else {
        // printf("right of %d: %d\n", *(int*)curr->data, *(int*)node->data);
        curr->right = node;
        break;
      }
    }
  }
}

void preOrderTraversal (BtNode* root, PRINT print) {
  if (root == NULL) {
    return;
  } else {
    print(root->data);
    preOrderTraversal(root->left, print);
    preOrderTraversal(root->right, print);
  }
}

void inOrderTraversal (BtNode* root, PRINT print) {
  if (root == NULL) {
    return;
  } else {
    inOrderTraversal(root->left, print);
    print(root->data);
    inOrderTraversal(root->right, print);
  }
}

void postOrderTraversal (BtNode* root, PRINT print) {
  if (root == NULL) {
    return;
  } else {
    postOrderTraversal(root->left, print);
    postOrderTraversal(root->right, print);
    print(root->data);
  }
}

void levelOrderTraversal (BtNode* root, PRINT print) {
  if (root == NULL) {
    return;
  } else {
    Queue queue;
    initQueue(&queue);
    enqueue(&queue, root);
    BtNode* treeNode = queue.head->data;

    /**
     * 传入队列的是指向树节点的指针，即 (BtNode*)queue.head->data
     * printf("root value: %d\n", *(int*)((BtNode*)(queue.head->data))->data);
     */
    
    while (!isQueueEmpty(&queue)) {
      treeNode = queue.head->data;
      print(treeNode->data);
      dequeue(&queue);
      if (treeNode->left != NULL)
        enqueue(&queue, (void*)treeNode->left);
      if (treeNode->right != NULL)
        enqueue(&queue, (void*)treeNode->right);
    }
  }
}

int treeHeight (BtNode* root) {
  
  return 0;
}

// -----------------------------------

int compareInt (int* a, int* b) {
  if (*a < *b) return -1;
  if (*a > *b) return 1;
  return 0;
}

void printInt (int* data) {
  printf("%d ", *data);
}


int main () {
  BtNode* root = NULL;
  int r = 5;
  int a = 3; int b = 2; int c = 6; int d = 9;
  int e = 7; int f = 1; int g = 5; int h = 4;
  insertTreeNode(&root, (COMPARE)compareInt, &r);
  insertTreeNode(&root, (COMPARE)compareInt, &a);
  insertTreeNode(&root, (COMPARE)compareInt, &b);
  insertTreeNode(&root, (COMPARE)compareInt, &c);
  insertTreeNode(&root, (COMPARE)compareInt, &d);
  insertTreeNode(&root, (COMPARE)compareInt, &e);
  insertTreeNode(&root, (COMPARE)compareInt, &f);
  insertTreeNode(&root, (COMPARE)compareInt, &g);
  insertTreeNode(&root, (COMPARE)compareInt, &h);
  
  preOrderTraversal(root, (PRINT)printInt);
  printf("\n");
  inOrderTraversal(root, (PRINT)printInt);
  printf("\n");
  postOrderTraversal(root, (PRINT)printInt);
  printf("\n");
  levelOrderTraversal(root, (PRINT)printInt);
  printf("\n");
}
