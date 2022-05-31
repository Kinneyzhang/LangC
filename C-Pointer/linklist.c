// 线性表的单链表存储结构

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LNode {
  ElemType data;
  struct LNode *next;
}LNode, LinkList;

typedef LinkList Status;

// 创建链表
void CreateLinkList(LinkList *L, ElemType *a) {
  L = malloc(sizeof(LNode));
  L->next = NULL;
  int len = sizeof(*a)/sizeof(a[0]);
  for(int i=0; i<len; ++i) {
    LinkList *p = malloc(sizeof(LNode));
    p->data = a[i];
    p->next = L->next;
    L->next = p;
  }
}

int main() {
  printf("Linked List Test:\n");
  LinkList *L;
  ElemType a[5] = {1,2,3,4,5};
  CreateLinkList(L, a);
  printf("the data of first node is %d", L->data);
  return 0;
}

////////////////////
//声明节点结构
typedef struct Link{
  int  elem;//存储整形元素
  struct Link *next;//指向直接后继元素的指针
}link;
//创建链表的函数
link * initLink(){
  link * p=(link*)malloc(sizeof(link));//创建一个头结点
  link * temp=p;//声明一个指针指向头结点，用于遍历链表
  //生成链表
  for (int i=1; i<5; i++) {
    //创建节点并初始化
    link *a=(link*)malloc(sizeof(link));
    a->elem=i;
    a->next=NULL;
    //建立新节点与直接前驱节点的逻辑关系
    temp->next=a;
    temp=temp->next;
  }
  return p;
}
