#include <stdio.h>
#include <stdlib.h>

struct node
{//链表结点类型，包含一个存放整型数据的 data 成员，和一个指向下一个结点的next成员
    int data ;
    struct node *next ;   
};

//第一关代码
struct node *createRlist()
{//函数功能：创建一个有一个空循环链表，返回值为头指针
  struct node *head = (struct node*)malloc(sizeof(struct node));
  head->data = 0;
  head->next = head;
  return head;
}


struct node * insertOrder(struct node *list, int insData)
{
 //在单向递增有序的循环链表（表头指针list）中插入数据元素insData，使之依然有序 。返回值是头指针

    struct node *p = (struct node *)malloc(sizeof (struct node));
    p->data = insData;
    
    struct node *q = list;
    while (q->next->data < insData && q->next != list){
        q = q->next;
    }
    p->next = q->next;
    q->next = p;


    return list;
}

int deleteData(struct node  *list, int delData)
{
    //在单向递增有序循环链表（表头指针list）中删除所有值为delData的结点,返回值为删除结点的个数
    int cnt = 0;
    struct node* p = list->next;
    struct node* q = list;
    while(p!=list){
        if(p->data==delData){
            struct node* k = p;
            p=p->next;
            q->next = p;
            free(k);
            cnt++;
            continue;
        }
        p = p->next;
        q = q->next;
    }
    return cnt;

}

void printRlist(struct node *list)
{
 //从链表第一个结点开始输出单向循环链表中各数据元素的值，每输出一个数据元素空一格
    struct node* p = list->next;
    while(p!=list){
        printf("%d ",p->data);
        p = p->next;
    }

}

int destroyRlist(struct node *list)
{
    //从第一个结点开始释放循环链表各结点占用的空间,返回值为最后一个结点的值
    struct node* p = list->next;
    while(p->next!=list){
        struct node* q = p;
        p = p->next;
        free(q);
    }
    int temp = p->data;
    free(p);
    free(list);
    return temp;

    
}
