#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
/*哈希结构*/
struct hashTable
{
  int *element;//存放键值的连续空间起始地址
  int maxNum;// 哈希表长度
  int curNum;//当前哈希表已有数据元素
};
struct node
{
  int data;
  struct node *next;
};

struct hashTable_link
{
  struct node *element;
  int maxNum;// 哈希表长度
};
/*第一关*/
//初始化一个哈希表，能满足线性探测再散列处理冲突法使用，初始化哈希表元素均为-1，表示该位置为空，可插入
struct hashTable* initHashTable_linear()
{
    struct hashTable *hashT=(struct hashTable *)malloc(sizeof(struct hashTable));
    hashT->maxNum=10;
    hashT->element=(int *)malloc(sizeof(int)*hashT->maxNum);

    for(int i=0;i<hashT->maxNum;i++)
    {
        hashT->element[i]=-1;
    }
    return hashT;
}

//初始化一个哈希表，能满足拉链法处理冲突法使用。初始化哈希表元素为0，用于计算该条链中数据个数，在插入时增加
struct hashTable_link * initHashTable_link()
{
    struct hashTable_link * hashL=(struct hashTable_link*)malloc(sizeof(struct hashTable_link));
    hashL->element=NULL;
    hashL->maxNum=10;
    hashL->element=(struct node*)malloc(sizeof(struct node)*hashL->maxNum);

    for(int i=0;i<hashL->maxNum;i++)
    {
        hashL->element[i].data=0;
        hashL->element[i].next=NULL;
    }
    return hashL;
}

/*第二关*/
//输出线性探测再散列法构建的哈希表,从下标为0的元素开始输出，每输出一个数据空一格
void printHashTable(struct hashTable *h)
{
    for(int i=0;i<h->maxNum;i++)
        printf("%d ",h->element[i]);
}


/*第三关*/
//哈希函数，h(key) = (key*3) %  7
int hashFun(int key)
{
    return (key*3)%11;
}

//函数功能：计算key的哈希地址，若发生冲突，则使用线性探测再散列的方法查找合适的插入位置下标，并返回该下标
int findPos(struct hashTable *h , int key)
{
    int k;
    k=hashFun(key);
    if(h->element[k]==-1)
    {
        h->element[k]=key;
        return k;
    }
    else
    {
        for(int i=k;i<h->maxNum;i++)
        {
            if(h->element[i]==-1)
            {
                h->element[i]=key;
                return i;
            }
        }
        for(int i=0;i<k;i++)
        {
            if(h->element[i]==-1)
            {
                h->element[i]=key;
                return i;
            }
        }
    }
    return -1;
}

//插入键值函数,若哈希表空间已满，则返回-1，否则返回插入位置下标
int insertKey(struct hashTable *h , int key)
{
    int pos;
    pos=findPos(h,key);
    return pos;
}
#endif // HASH_H_INCLUDED
