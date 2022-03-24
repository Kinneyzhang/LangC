#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//结构体的两种声明方式
/* struct _person { */
/*   char* firstName; */
/*   char* lastName; */
/*   char* title; */
/*   unsigned int age; */
/* }; */

/* typedef struct _person { */
/*   char* firstName; */
/*   char* lastName; */
/*   char* title; */
/*   unsigned int age; */
/* } Person; */

/* int main() { */
/*   /\* //结构体简单声明 *\/ */
/*   /\* Person person; *\/ */
/*   /\* person.firstName = (char*)malloc(strlen("Zhang")+1); *\/ */
/*   /\* strcpy(person.firstName, "Zhang"); *\/ */
/*   /\* person.lastName = (char*)malloc(strlen("Kai")+1); *\/ */
/*   /\* strcpy(person.lastName, "Kai"); *\/ */
/*   /\* person.title = (char*)malloc(strlen("Geekinney")+1); *\/ */
/*   /\* strcpy(person.title, "Geekinney"); *\/ */
/*   /\* person.age = 26; *\/ */
/*   /\* printf("name: %s %s\n", person.firstName, person.lastName); *\/ */
/*   /\* printf("title: %s\n", person.title); *\/ */
/*   /\* printf("age: %u\n", person.age); *\/ */

/*   /\* //结构体指针 *\/ */
/*   /\* Person *person; *\/ */
/*   /\* person  = (Person*)malloc(sizeof(Person)); *\/ */
/*   /\* person->firstName = (char*)malloc(strlen("Zhang")+1); *\/ */
/*   /\* strcpy(person->firstName, "Zhang"); *\/ */
/*   /\* person->lastName = (char*)malloc(strlen("Kai")+1); *\/ */
/*   /\* strcpy(person->lastName, "Kai"); *\/ */
/*   /\* person->title = (char*)malloc(strlen("Geekinney")+1); *\/ */
/*   /\* strcpy(person->title, "Geekinney"); *\/ */
/*   /\* person->age = 26; *\/ */
/*   /\* printf("name: %s %s\n", person->firstName, person->lastName); *\/ */
/*   /\* printf("title: %s\n", person->title); *\/ */
/*   /\* printf("age: %u\n", person->age); *\/ */
/*   /\* // '->'表示指针指向的结构体变量，等同于指针解引后再用点运算符。 *\/ */
/*   return 0; */
/* } */

/* //为结构体分配内存 */
/* typedef struct _alterPerson { */
/*   char* firstName; */
/*   char* lastName; */
/*   char* title; // char* 8个字节 */
/*   short age; // 对齐到8个字节 */
/* } AlterPerson; */

/* int main() { */
/*   AlterPerson otherPerson; */
/*   printf("%d\n", sizeof(AlterPerson)); */
/* } */

/* //结构体释放问题★★★ */
/* typedef unsigned int uint; */

/* typedef struct _person { */
/*   char* firstName; */
/*   char* lastName; */
/*   char* nickName; */
/*   uint age; */
/* } Person; */

/* void initPerson(Person *person, const char* fn, */
/*                 const char* ln, const char* nn, uint age) { */
/*   person->firstName = (char*)malloc(sizeof(strlen(fn)+1)); */
/*   strcpy(person->firstName, fn); */
/*   person->lastName = (char*)malloc(sizeof(strlen(ln)+1)); */
/*   strcpy(person->lastName, ln); */
/*   person->nickName = (char*)malloc(sizeof(strlen(nn)+1)); */
/*   strcpy(person->nickName, nn); */
/*   person->age = age; */
/* } */

/* void processPerson(Person *person) { */
/*   initPerson(person, "Zhang", "Kai", "Geekinney", 25); */
/* } */

/* void deletePerson(Person *person) { */
/*   free(person->firstName); */
/*   free(person->lastName); */
/*   free(person->nickName); */
/* } */

/* void printPerson(Person *person) { */
/*   printf("fullname: %s %s\n", person->firstName, person->lastName); */
/*   printf("nickname: %s\n", person->nickName); */
/*   printf("age: %u\n", person->age); */
/* } */

/* int main() { */
/*   /\* Person person; *\/ */
/*   /\* processPerson(&person); *\/ */
/*   /\* printPerson(&person); *\/ */
/*   /\* deletePerson(&person); *\/ */

/*   //注意这两种方式的内存分配情况★★★ */
  
/*   Person *ptrPerson; */
/*   ptrPerson = (Person*)malloc(sizeof(Person)); */
/*   initPerson(ptrPerson, "Zhang", "Kai", "Geekinney", 25); */
/*   printPerson(ptrPerson); */
/*   deletePerson(ptrPerson); */
/*   free(ptrPerson); */
/* } */

/* //避免malloc/free开销 */
/* #define LIST_SIZE 10 */
/* Person *list[LIST_SIZE]; */

/* void initList() { */
/*   for(int i=0; i<LIST_SIZE; i++) { */
/*     list[i] = NULL; */
/*   } */
/* } */

/* Person *getPerson() { */
/*   for(int i=0; i<LIST_SIZE; i++) { */
/*     if(list[i] != NULL) { */
/*       Person *ptr = list[i]; */
/*       list[i] = NULL; */
/*       return ptr; */
/*     } */
/*   } */
/*   Person *person = (Person*)malloc(sizeof(Person)); */
/*   return person; */
/* } */

/* Person *returnPerson(Person *person) { */
/*   for(int i=0; i<LIST_SIZE; i++) { */
/*     if(list[i] == NULL) { */
/*       list[i] = person; */
/*       return person; */
/*     } */
/*   } */
/*   deletePerson(person); */
/*   free(person); */
/*   return NULL; */
/* } */

/* int main() { */
/*   initList(); */
/*   Person *ptrPerson; */
/*   ptrPerson = getPerson(); */
/*   initPerson(ptrPerson, "Zhang", "Kai", "geekinney", 25); */
/*   printPerson(ptrPerson); */
/*   returnPerson(ptrPerson); */
/* } */

/* ================================================== */
/* 用指针支持数据结构 */
typedef struct _employee {
  char name[22];
  unsigned char age;
} Employee;

int compareEmployee(Employee *e1, Employee *e2) {
  return strcmp(e1->name, e2->name);
}

void printEmployee(Employee* employee) {
  printf("%s\t%d\n", employee->name, employee->age);
}

typedef void(*PRINT)(void*);
typedef int(*COMPARE)(void*, void*);

//单链表
typedef struct _node {
  void *data;
  struct _node *next;
} Node;

typedef struct _linkedList {
  Node *head;
  Node *tail;
  Node *current;
} LinkedList;

void initList(LinkedList*);
void addHead(LinkedList*, void*);
void addTail(LinkedList*, void*);
void delete(LinkedList*, Node*);
Node *getNode(LinkedList*, COMPARE, void*);
void printLinkedList(LinkedList*, PRINT);

void initList(LinkedList *list) {
  list->head = NULL;
  list->tail = NULL;
  list->current = NULL;
}

void addHead(LinkedList* list, void* data) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->data = data;
  if(list->head == NULL) {
    list->tail = node;
    node->next = NULL;
  } else {
    node->next = list->head;
  }
  list->head = node;
}

void addTail(LinkedList *list, void* data) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;
  if(list->head == NULL) {
    list->head = node;
  } else {
    list->tail->next = node;
  }
  list->tail = node;
}

Node *getNode(LinkedList* list, COMPARE compare, void* data) {
  Node *node  = list->head;
  while(node != NULL) {
    if(compare(node->data, data) == 0)
      return node;
    node = node->next;
  }
  return NULL;
}

void delete(LinkedList* list, Node* node) {
  if(node == list->head) {
    if(list->head->next == NULL)
      list->head = list->tail = NULL;
    else
      list->head = list->head->next;
  } else {
    Node *tmp = list->head;
    while(tmp != NULL && tmp->next != node)
      tmp = tmp->next;
    if(tmp != NULL)
      tmp->next = node->next;
  }
  free(node);
}

void printLinkedList(LinkedList *list, PRINT print) {
  Node *current = list->head;
  if (current != NULL) {
    printf("\n---Linked List---\n");
    while(current != NULL) {
      print(current->data);
      current = current->next;
    }
  }
}

/* int main() { */
/*   LinkedList list; */

/* Employee *kinney = (Employee*)malloc(sizeof(Employee)); */
/* strcpy(kinney->name, "Kinney"); */
/* kinney->age = 25; */

/* Employee *nancy = (Employee*)malloc(sizeof(Employee)); */
/* strcpy(nancy->name, "Nancy"); */
/* nancy->age = 24; */

/* Employee *jack = (Employee*)malloc(sizeof(Employee)); */
/* strcpy(jack->name, "Jack"); */
/* jack->age = 25; */

/* Employee *lucy = (Employee*)malloc(sizeof(Employee)); */
/* strcpy(lucy->name, "Lucy"); */
/* lucy->age = 29; */

/* Employee *zacray = (Employee*)malloc(sizeof(Employee)); */
/* strcpy(zacray->name, "Zacray"); */
/* zacray->age = 33; */

/*   initList(&list); */
/*   addTail(&list, kinney); */
/*   addTail(&list, nancy); */
/*   addHead(&list, jack); */
/*   addHead(&list, lucy); */
/*   addTail(&list, zacray); */
/*   // lucy -> jack -> kinney -> nancy -> zacray */

/*   printLinkedList(&list, (PRINT)printEmployee); */
  
/*   /\* Node *node = getNode(&list, (int(*)(void*,void*))compareEmployee, nancy); *\/ */
/*   Node *node = getNode(&list, (COMPARE)compareEmployee, nancy); */
/*   delete(&list, node); */

/*   printLinkedList(&list, (PRINT)printEmployee); */
/* } */
/* ================================================== */

/* 用指针支持队列 */
typedef LinkedList Queue;

void initQueue(Queue *queue) {
  initList(queue);
}

void enqueue(Queue *queue, void *node) {
  addHead(queue, node);
}

void* dequeue(Queue *queue) {
  Node *tmp = queue->head;
  void *data;
  if (queue->head == NULL)
    data = NULL;
  else if (queue->head == queue->tail) {
    queue->head = queue->tail = NULL;
    data = tmp->data;
  } else {
    while (tmp->next != queue->tail)
      tmp = tmp->next;
    queue->tail = tmp;
    tmp = tmp->next;
    queue->tail->next = NULL;
    data = tmp->data;
    free(tmp);
  }
  return data;
}

/* int main() { */
/*   Queue queue; */
/*   initQueue(&queue); */

/* Employee *kinney = (Employee*)malloc(sizeof(Employee)); */
/* strcpy(kinney->name, "Kinney"); */
/* kinney->age = 25; */

/* Employee *nancy = (Employee*)malloc(sizeof(Employee)); */
/* strcpy(nancy->name, "Nancy"); */
/* nancy->age = 24; */

/* Employee *jack = (Employee*)malloc(sizeof(Employee)); */
/* strcpy(jack->name, "Jack"); */
/* jack->age = 25; */

/* Employee *lucy = (Employee*)malloc(sizeof(Employee)); */
/* strcpy(lucy->name, "Lucy"); */
/* lucy->age = 29; */

/* Employee *zacray = (Employee*)malloc(sizeof(Employee)); */
/* strcpy(zacray->name, "Zacray"); */
/* zacray->age = 33; */

/*   enqueue(&queue, kinney); */
/*   enqueue(&queue, nancy); */
/*   enqueue(&queue, jack); */
/*   enqueue(&queue, lucy); */
/*   enqueue(&queue, zacray); */
  
/*   printLinkedList(&queue, (PRINT)printEmployee); */

/*   void *data = dequeue(&queue); */
/*   printf("\nDequeued %s\n", ((Employee*)data)->name); */
/*   data = dequeue(&queue); */
/*   printf("\nDequeued %s\n", ((Employee*)data)->name); */

/*   printLinkedList(&queue, (PRINT)printEmployee); */
/* } */

/* ================================================== */

/* 用指针支持栈 */
typedef LinkedList Stack;

void initStack(Stack *stack) {
  initList(stack);
}

void push(Stack *stack, void *data) {
  addHead(stack, data);
}

void *pop(Stack *stack) {
  Node *node = stack->head;
  if (node == NULL) {
    return NULL;
  } else if (node == stack->tail) {
    stack->head = stack->tail = NULL;
    void *data = node->data;
    free(node);
    return data;
  } else {
    stack->head = node->next;
    void *data = node->data;
    free(node);
    return data;
  }
}

/* int main() { */
/*   Stack stack; */
/*   initStack(&stack); */
  
/*   Employee *kinney = (Employee*)malloc(sizeof(Employee)); */
/*   strcpy(kinney->name, "Kinney"); */
/*   kinney->age = 25; */

/*   Employee *nancy = (Employee*)malloc(sizeof(Employee)); */
/*   strcpy(nancy->name, "Nancy"); */
/*   nancy->age = 24; */

/*   Employee *jack = (Employee*)malloc(sizeof(Employee)); */
/*   strcpy(jack->name, "Jack"); */
/*   jack->age = 25; */

/*   Employee *lucy = (Employee*)malloc(sizeof(Employee)); */
/*   strcpy(lucy->name, "Lucy"); */
/*   lucy->age = 29; */

/*   Employee *zacray = (Employee*)malloc(sizeof(Employee)); */
/*   strcpy(zacray->name, "Zacray"); */
/*   zacray->age = 33; */

/*   push(&stack, kinney); */
/*   push(&stack, nancy); */
/*   push(&stack, jack); */
/*   push(&stack, lucy); */
/*   push(&stack, zacray); */
/*   printLinkedList(&stack, (PRINT)printEmployee); */

/*   Employee *employee; */

/*   for(int i=0; i<5; i++) { */
/*     employee = (Employee*)pop(&stack); */
/*     printf("\nPoped: %s %u\n", employee->name, employee->age); */
/*     printLinkedList(&stack, (PRINT)printEmployee); */
/*   } */
  
/*   free(employee); */
/* } */

/* ================================================== */

/* 用指针支持树 */
typedef struct _tree {
  void* data;
  struct _tree *left;
  struct _tree *right;
} TreeNode;

void insertNode(TreeNode **root, COMPARE compare, void* data) {
  TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  if (*root == NULL) {
    *root = node;
    return;
  }
  while(1) {
    if(compare((*root)->data, data) > 0) {     
      if ((*root)->left != NULL)
        *root = (*root)->left;
      else {
        (*root)->left = node;
        break;
      }
    } else {
      if ((*root)->right != NULL)
        *root = (*root)->right;
      else {
        (*root)->right = node;
        break;
      }
    }
  }
}

void preOrder(TreeNode *root, PRINT print) {
  if (root != NULL) {
    print(root->data);
    preOrder(root->left, print);
    preOrder(root->right, print);
  }
}

void inOrder(TreeNode *root, PRINT print) {
  if (root != NULL) {
    inOrder(root->left, print);
    print(root->data);
    inOrder(root->right, print);
  }
}

void postOrder(TreeNode *root, PRINT print) {
  if (root != NULL) {
    postOrder(root->left, print);
    postOrder(root->right, print);
    print(root->data);
  }
}

int main() {
  TreeNode *tree = NULL;
  
  Employee *kinney = (Employee*)malloc(sizeof(Employee));
  strcpy(kinney->name, "Kinney");
  kinney->age = 25;

  Employee *nancy = (Employee*)malloc(sizeof(Employee));
  strcpy(nancy->name, "Nancy");
  nancy->age = 24;

  Employee *jack = (Employee*)malloc(sizeof(Employee));
  strcpy(jack->name, "Jack");
  jack->age = 25;

  Employee *lucy = (Employee*)malloc(sizeof(Employee));
  strcpy(lucy->name, "Lucy");
  lucy->age = 29;

  Employee *zacray = (Employee*)malloc(sizeof(Employee));
  strcpy(zacray->name, "Zacray");
  zacray->age = 33;
  
  insertNode(&tree, (COMPARE)compareEmployee, kinney);
  insertNode(&tree, (COMPARE)compareEmployee, nancy);
  insertNode(&tree, (COMPARE)compareEmployee, jack);
  insertNode(&tree, (COMPARE)compareEmployee, lucy);
  insertNode(&tree, (COMPARE)compareEmployee, zacray);

  preOrder(tree, (PRINT)printEmployee);
  printf("\n");
  inOrder(tree, (PRINT)printEmployee);
  printf("\n");
  postOrder(tree, (PRINT)printEmployee); //??????
}
