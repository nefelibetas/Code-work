#ifndef FUN_H_INCLUDED
#define FUN_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
/*此处是顺序线性表数据结构定义*/
typedef int DataType;
struct seqList
{//有3个数据成员
  int MAXNUM;//用于记录顺序线性表中能存放的最大元素个数的 整型 MAXNUM
  int curNum;//用于存放顺序线性表中数据元素的个数  整型  curNum
  DataType *element;//用于存放顺序线性表数据元素的连续空间的起始地址
};

typedef struct seqList *PseqList;
//第一关
PseqList createNullList_seq(int m)
{//此处填写代码，创建一个空的顺序线性表，能存放的最大元素个数为 m
 //若m=0，则返回NULL
    if(m==0)
        return NULL;
    else
    {
        PseqList L=(PseqList)malloc(sizeof(struct seqList));
        if(L!=NULL)
        {
            L->element=(DataType*)malloc(sizeof(DataType)*m);
            if(L->element)
            {
                L->MAXNUM=m;
                L->curNum=0;
                return L;
                }
            else
            free(L);
        }
        else
            return NULL;
        }
}

//第二关
int isFullList_seq(PseqList L)
{
  //判断顺序线性表是否已满，若已满，返回值为1，否则返回值为0
    return(L->curNum>=L->MAXNUM);
}


int insertP_seq(PseqList L , int p ,int x)
{// 在线性表L中下标为p的位置插入数据元素x，若下标p非法或线性表已满无法插入数据，返回0；插入成功返回值为1
   //如果线性表满了， 还需输"list is full"的提示
  //如果插入位置非法，需输出提示"position is illegel"
   if(p<0||p>L->curNum)
   {
       printf("position is illegel");
       return 0;
   }
   if(isFullList_seq(L))
   {
       printf("list is full");
       return 0;
   }
   for(int k=L->curNum-1;k>=p;k--)
        L->element[k+1]=L->element[k];
    L->element[p]=x;
    L->curNum=L->curNum+1;
    return 1;
}

int insertPre_seq(PseqList L , int p ,int x)
{
 // 在线性表L中下标为p的位置的前面插入数据元素x，若下标p非法或线性表已满无法插入数据，返回0；插入成功返回值为1
//提示：直接调用insertP函数实现即可
    int q=p-1;
    return (insertP_seq(L,q,x));
}

int insertPost_seq(PseqList L , int p ,int x)
{
 // 在线性表L中下标为p的位置的后面插入数据元素x，若下标p非法或线性表已满无法插入数据，返回0；插入成功返回值为1
//提示：直接调用insertP函数实现即可
    int q=p+1;
    return (insertP_seq(L,q,x));
}

void printList_seq(PseqList L)
{//逐个输出线性表的元素，相邻的两个数据元素之间以一个空格为分隔符隔开
    int i;
    for(i=0;i<L->curNum;i++)
        printf("%d ",L->element[i]);
}

//第三关
int destroyList_seq(PseqList L)
{
    //返回值为销毁的线性表中现有数据元素的个数，若待销毁的线性表不存在，则返回0
    if(L!=NULL)
    {
        int m=L->curNum;
        free(L);
        return m;
    }
    else return 0;
}

//第四关
int locate_seq(PseqList L,int x)
{//在顺序表L中查找给定值x首次出现的位置，若不存在给定值，则返回-1
    int i;
    for(i=0;i<L->curNum;i++)
    {
        if(L->element[i]==x)
        return i;
    }
    return -1;
}

DataType locatePos_seq(PseqList L,int pos)
{// 在顺序表L中查找指定位置pos处的数据元素，若位置非法，则返回第0个数据元素
    if(pos<0||pos>L->curNum)
    {
        return L->element[0];
    }
    else
        return (L->element[pos]);
}

//第五关
int deletePos_seq(PseqList L,int pos)
{//在顺序表L中删除与下标pos处的数据元素，若pos非法，则返回-1；否则返回1
    int i;
    if(pos<0||pos>L->curNum)
    return -1;
    else
    {
        for(i=pos;i<L->curNum-1;i++)
        {
            L->element[i]=L->element[i+1];
        }
        L->element[L->curNum-1]=0;
        L->curNum=L->curNum-1;
        return 1;
    }
}

int delete_seq(PseqList L,int x)
{//在顺序表L中删除与参数x值相同的数据元素，返回删除数据元素的个数
  //可以使用之前已完成的操作
  int num = 0;
while(locate_seq(L,x)!=-1){
	deletePos_seq(L,locate_seq(L,x));
	num++;
}
return num;	
}


//第六关
void replace_seq(PseqList L,int x,int y)
{//将顺序表L中值为x的数据元素替换为y
    int i;
    for(i=0;i<L->curNum;i++)
    {
        if(L->element[i]==x)
        {
            L->element[i]=y;
        }
    }
}

void delDuplicate_seq(PseqList L)
{//移除线性表中的所有重复元素；不要使用额外的数组空间，必须在原地修改输入数组 并在使用 O(1) 额外空间的条件下完成
  //使用常规删除即可，已修改测试用例
int i,p,q;
for(q=0;q<L->curNum;q++){
for(p=q+1;p<L->curNum;p++){
    if(L->element[q]==L->element[p]){
      delete_seq(L,L->element[p]);
  }
}
}
}
#endif // FUN_H_INCLUDED
