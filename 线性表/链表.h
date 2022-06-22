#ifndef FUN_H_INCLUDED
#define FUN_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
//第一关代码
struct node
{//此处填写代码，定义链表结点类型，包含一个存放整型数据的 data 成员，和一个指向下一个结点的next成员

    int data;
    struct node *next;
};
typedef struct node *List;

struct node *mycreateList()
{//此处填写代码，创建一个只有一个头结点的空链表，头节点的数据域赋值为0，并将表头结点的地址返回
    List head=(List)malloc(sizeof(struct node));
    head->data=0;
    head->next=NULL;
    return head;
}


//第二关代码

void myinsertHead(struct node * head, int insData )
{
	/*在此处完成任务，实现在head为表头d 链表的头插数据元素insData的功能*/
	//begin
    List p=(List)malloc(sizeof(struct node));
    p->data=insData;
    p->next=head->next;
    head->next=p;
	//end
}

void myinsertTail(struct node *  head , int insData )
{
	/*在此处完成任务，在head为表头的单链表表尾插入数据元素insData*/
	//begin
    List p=(List)malloc(sizeof(struct node));
    List tail=(List)malloc(sizeof(struct node));
    tail=head;
    while(tail->next!=NULL)
        tail=tail->next;

    p->data=insData;
    p->next=NULL;
    tail->next=p;
    tail=p;
	//end
}

void myprintList(struct node *L)
{
     /*在此处完成任务，输出head为表头链表中的数据，每输出一个数据换一行*/
	//begin
    List p;
    for(p=L->next;p!=NULL;p=p->next)
    {
        printf("%d\n",p->data);
    }
	//end
}

//第三关代码
 void reverseList_link( struct node *L)
 {
    //请在此处填入代码，实现链表逆置功能
 	//begin
    List pHead,p,q;
    pHead=L;
    p=pHead->next;
    pHead->next=NULL;
    while(p!=NULL)
    {
        q=p;
        p=p->next;
        q->next=pHead->next;
        pHead->next=q;
    }
	//end
 }


//第四关代码
int locateAndChange( struct node *L, int data)
 {
    //请在此处填入代码，在头结点为L的链表中查找 与data值相等的第一个结点，若能找到该结点，则将该结点的值与前驱结点的值交换
    //若未找到与data值相等的结点，则返回值为-1，若找到的结点无前驱结点，则返回值为0，否则返回值为前驱结点的值
 	//begin
    List p,q;
    int temp;
    for(p=L->next;p->next!=NULL;p=p->next)
    {
        if(p->next->data==data)
        {
            temp=p->data;
            p->data=p->next->data;
            p->next->data=temp;
            return temp;
        }
        if(L->next->data==data)
            return 0;
    }
    return -1;
	//end
 }

//第五关代码
int destroyList(struct node *L)
{
  //请在此处填写代码，实现将链表L的结点空间回收
 //返回值为回收结点的个数，含头结点在内
    List p,q;
    int i;
    for(p=L,i=0;p!=NULL;i++)
    {
        q=p;
        p=p->next;
        free(q);
    }
    return i;
}
#endif // FUN_H_INCLUDED
