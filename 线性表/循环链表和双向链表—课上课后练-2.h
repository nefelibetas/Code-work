#include <stdio.h>
#include <stdlib.h>
struct node
{//链表结点类型，包含一个存放整型数据的 data 成员，和指向前驱和后继结点的指针
    int data ;
    struct node *llink, *rlink ;   
};

struct Hnode
{
    //双向链表头结点,有两个指针成员，分别指向双向链表的第一个结点和最后一个结点
    struct node *head, *tail;
};

//第二关代码
struct Hnode *createDlist()
{//函数功能：创建一个带头结点的双向链表，tail指向尾结点；head指针指向第一个结点，返回值是指向头结点的指针
  struct Hnode *headNode = (struct Hnode*)malloc(sizeof(struct Hnode));
  headNode->head = NULL;
  headNode->tail = NULL;
  return headNode;
}


void insertDlist(struct Hnode *list, int insData)
{
 //在双向链表的表头插入数据
    struct node *p = (struct node *)malloc(sizeof (struct node));
    p->data = insData;
    if (list->head == NULL){
        list->head = list->tail = p;
        p->llink = NULL;
        p->rlink = NULL;
    } else {
        p->llink = NULL;
        list->head->llink = p;
        p->rlink = list->head;
        list->head = p;
    }
}

int deleteData(struct Hnode  *list, int delData)
{
    //在双向链表中删除值为delData的第一个结点，若删除成功返回1，否则返回0
    for (struct node *p = list->head; p != list->tail; p = p->rlink)
    if (p->data == delData){
        if (p == list->head) list->head = p->rlink;
      if (p == list->tail) list->tail = p->llink;
        if (p->llink != NULL) p->llink->rlink = p->rlink;
        if (p->rlink != NULL) p->rlink->llink = p->llink;
        free(p);
        return 1;
    }
    return 0;
}

void printDlist(struct Hnode *list)
{
 //输出双向循环链表中各数据元素的值，每输出一个数据元素换行
    for (struct node *p = list->head; p != list->tail; p = p->rlink)
    printf("%d\n", p->data);
    printf("%d\n", list->tail->data);
}

int destroyDlist(struct Hnode *list)
{//释放双向链表占用的存储空间，释放所有结点,返回释放的结点数，不含list本身
    int cnt = 0;
    for (struct node *p = list->head, *next = NULL; p->rlink != NULL;){
        next = p->rlink;
        free(p);
        p = next;
        cnt ++;
        
    }
    cnt ++;
    // free(list->tail);
    return cnt;
}
