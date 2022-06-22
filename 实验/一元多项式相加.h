#ifndef FUN1_H_INCLUDED
#define FUN1_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>



//存放多项式某项的结点结构
struct node
{
  int exp ;  // 表示指数
  int coef ; //表示系数
  struct node *next;  //指向下一个结点的指针
};

typedef  struct node * PNODE ;

/*
  函数功能：生成多项式
  函数名：createPoly
  函数参数：无
  返回值：指向多项式的头指针
*/
PNODE createPoly(void)
{
    //在此处填写代码，能实现创建一个多项式并返回多项式头指针的函数
	//注意：头指针不存放多项式的项。
	//exp表示指数,coef表示系数。
    /**********  Begin **********/
    PNODE head,t;
    int exp,coef;

    scanf("%d",&coef);
    scanf("%d",&exp);

    head=(PNODE)malloc(sizeof(struct node));
    if(head==NULL) return 0;

    head->next=NULL; t=head;

    while(coef!=0||exp!=0)
    {
        PNODE p=(PNODE)malloc(sizeof(struct node));
        p->next=NULL;
        if(p==NULL) return 0;

        p->exp=exp;
        p->coef=coef;

        if(head->next==NULL)
        {
            t->next=p;
            t=p;
        }
        else if(t->next==NULL)
        {
            t->next=p;
            t=p;
        }

        scanf("%d",&coef);
        scanf("%d",&exp);
    }
    return head;
    /**********  End  **********/
}

/*
   函数功能：进行多项式相加
   函数名：addPoly
   函数参数：polyAddLeft ：加法左边多项式头指针, polyAddRight：加法右边多项式头指针
   返回值：指向结果多项式的头指针
*/
PNODE addPoly(PNODE polyAddLeft , PNODE polyAddRight)
{
    //在此处填写代码，能实现创两个多项式相加并返回结果多项式头指针的函数
    /**********  Begin **********/
    PNODE res=(PNODE)malloc(sizeof(struct node)),tail;
    PNODE l=polyAddLeft->next,r=polyAddRight->next;
    res->next=NULL;
    tail=res;
    while(l||r)
    {
        PNODE p=(PNODE)malloc(sizeof(struct node));
        p->next=NULL;

        if(l==NULL)
        {
            p->coef=r->coef;
            p->exp=r->exp;
            tail->next=p;
            tail=p;
            r=r->next;
        }
        else if(r==NULL)
        {
            p->coef=l->coef;
            p->exp=l->exp;
            tail->next=p;
            tail=p;
            l=l->next;
        }
        else if(l->exp==r->exp)
        {
            int sum=l->coef+r->coef;
            if(sum==0)
            {
                l=l->next;
                r=r->next;
            }
            else
            {
                p->exp=l->exp;
                p->coef=sum;
                tail->next=p;
                tail=p;
                l=l->next;
                r=r->next;
            }
        }
        else if(l->exp > r->exp)
        {
            p->exp=r->exp;
            p->coef=r->coef;
            tail->next=p;
            tail=p;
            r=r->next;
        }
        else if(l->exp < r->exp)
        {
            p->coef=l->coef;
            p->exp=l->exp;
            tail->next=p;
            tail=p;
            l=l->next;
        }
    }
    return res;
    /**********  End **********/
}

/*
   函数功能：输出多项式
   函数名：printPoly
   函数参数：待输出多项式的头指针poly
   返回值：无
*/
 void printPoly(PNODE poly)
 {
 	//在此处填写代码，能实现按格式输出多项式的功能，输出格式样例见说明
    /**********  Begin **********/
    PNODE p=poly->next;
    while(p)
    {
        if(p->next==NULL)
        {
            printf("%dx^%d",p->coef,p->exp);
        }
        else
        {
            printf("%dx^%d+",p->coef,p->exp);
        }
        p=p->next;
    }

    /**********  End **********/
}

void destroyPoly(PNODE poly)
{
//释放存储多项式的链表空间
    PNODE p=poly,t;
    while(p)
    {
        t=p;
        p=p->next;
        free(t);
    }
}


#endif // FUN1_H_INCLUDED
