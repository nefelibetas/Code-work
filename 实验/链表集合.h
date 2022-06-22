#ifndef _LINKSET_H_
#define _LINKSET_H_
#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
//自定义整型名

struct  node
{
    DataType  element;
    //集合内的元素
    struct node  *next;
};
typedef struct node * SET;
//自定义结构体名

void insert(DataType datax, SET set);
//插入函数
/*
  函数名： InitSet
  函数功能：根据参数num，初始化集合
  函数参数：集合元素的个数
  返回值：集合头指针
*/
SET InitSet(int num)
{
    SET p;
    p = ( struct  node *)malloc(sizeof(struct node)) ;
    p->next = NULL;
    p->element = num;
    //头节点的元素域放的是集合中的元素个数
    int temp;
    for(int i =0;i<num;i++)
    {
        scanf("%d",&temp);
        insert(temp, p); //调用insert函数，将输入数据插入集合
    }
    return p;
}


/*
  函数名： find
  函数功能：在集合中查找值为datax的成员
  函数参数：datax:待查找的值 ； set：集合的头结点
  返回值：找到值为datax的成员返回1，否则返回0
*/
int find(DataType datax, SET  set)
{
    //请在此处填写代码，在set集合中查找值为datax的成员，若找到返回1，否则返回0
    /**********  Begin  **********/
    SET p=set->next;
    for(p;p!=NULL;p=p->next)
    {
        if(p->element==datax)
            return 1;
    }
    return 0;
    /**********   End   **********/
}

/*
  函数名： insert
  函数功能：在集合set中插入值为datax的成员 ，插入位置在表头
  函数参数：datax:待插入的值 ； set：集合的头结点
  返回值：无  时间复杂度：O（1）
*/
void insert(DataType datax, SET set)
{
    //请在此处填写代码，将datax插入集合set， 注意因集合元素是无序的，只需将新成员插入表头
    /**********  Begin  **********/
    SET p=(SET)malloc(sizeof(struct node));
    p->element=datax;
    p->next=set->next;
    set->next=p;
    /**********   End   **********/
 }

/*
  函数名： copyList
  函数功能：将集合setA复制生成集合setB
  函数参数：setA 、setB的头结点
  返回值：无
*/
void copySet(SET setA, SET setB)
{
    //请在此处填写代码，实现将集合setA的成员复制到集合setB的功能
    /**********  Begin  **********/
    SET A=setA->next;
    SET B=setB->next;
    while(A)
    {
        if(find(A->element,B)!=1)
        {
            insert(A->element,B);
        }
        A=A->next;
    }
    /**********   End   **********/
}

/*
  函数名： printSet
  函数功能：输出集合的元素，以空格作为元素之间分界符
  函数参数：set的头结点
  返回值：无
*/
void printSet(SET set)
{
    //请在此处填写代码，实现输出集合元素的功能，元素之间以空格为分界符
    /**********  Begin  **********/
    for(SET p=set->next;p!=NULL;p=p->next)
        printf("%d ",p->element);
    /**********  End  **********/
}

/*
  函数名： setUnion
  函数功能：求两个集合setA 和 setB的并集
  函数参数：setA和setB的头结点
  返回值：并集集合的头结点
*/
SET setUnion(SET setA ,SET setB)
{
    //请在此处填写代码，可直接使用上面已经实现的各操作
    /**********  Begin  **********/
    SET A=setA->next;
    SET B=setB->next;
    SET res=(SET)malloc(sizeof(struct node));
    res->next=NULL;
    while(A)
    {
        insert(A->element,res);
        A=A->next;
    }
    while(B)
    {
        if(find(B->element,setA->next)!=1)
        {
            insert(B->element,res);
        }
        B=B->next;
    }
    return res;
    /**********  End  **********/
}

/*
  函数名： setIntersect
  函数功能：求两个集合setA 和 setB的交集
  函数参数：setA和setB的头结点
  返回值：交集集合的头结点
*/
SET setIntersect(SET setA ,SET setB)
{
    //请在此处填写代码，可直接使用上面已经实现的各操作
    /**********  Begin  **********/
    SET A=setA->next,B=setB->next;
    SET res=(SET)malloc(sizeof(struct node));
    res->next=NULL;
    while(A)
    {
        if(find(A->element,B))
        {
            insert(A->element,res);
        }
        A=A->next;
    }
    return res;
    /**********  End  **********/
}

/*
  函数名： setExcept
  函数功能：求两个集合setA 和 setB的差
  函数参数：setA和setB的头结点
  返回值：结果集合的头结点
*/
SET setExcept(SET setA ,SET setB)
{
    //请在此处填写代码，可直接使用上面已经实现的各操作
    /**********  Begin  **********/
    SET A=setA->next,B=setB->next;
    SET res=(SET)malloc(sizeof(struct node));
    while(A)
    {
        if(find(A->element,B)!=1)
            insert(A->element,res);
        A=A->next;
    }
    return res;
    /**********  End  **********/
}

void destroySet(SET set)
{
//释放存储集合的链表空间，表头为set
    SET p=set;
    while(p)
    {
        SET t=p;
        p=p->next;
        free(t);
    }
}

#endif
