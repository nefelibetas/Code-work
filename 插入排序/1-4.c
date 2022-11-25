#include <stdio.h>
#include <stdlib.h>

/*数据结构定义*/
typedef int DataType;
typedef struct
{
  DataType *data; //用于存放待排序关键字的起始地址
  int NUM; //待排序关键字的个数 
} SortObject;

typedef struct node //用于表插入排序的数据结构
{
  DataType  info;  
  struct node *next;  
} linkObject;

//输出顺序表
void print(SortObject *p)
{
 for(int i=0;i<p->NUM;i++)
   printf("%d ",p->data[i]);
 printf("\n");  
}

//输出链表
void printLink(linkObject *Head)
{
  linkObject *p = Head->next ;
  while(p)
  {
    printf("%d ",p->info);
    p = p->next;
  }
   printf("\n");
}

/*第一关
此处请填写代码实现递增序进行直接插入排序,
 要求每趟排序后 调用print函数，输出关键字的排列情况*/
void insertSort( SortObject *Rec )
{
  
 /*----begin------*/
  for (int i = 1; i < Rec->NUM; i ++){
    int key = Rec->data[i];
    int pre = i - 1;
    while ( pre >= 0 && key < Rec->data[pre]) {
      Rec->data[pre+1] = Rec->data[pre];
      pre --;
    }
    Rec->data[pre+1] = key;
    print(Rec);
  }
 
 /*-----end------*/

}

/*第二关
此处请填写代码实现递增序进行二分插入排序,
 
  实质是在已经有序的表中采用二分法查找插入位置
  要求每趟排序后 调用print函数，输出关键字的排列情况*/
void binInsertSort(  SortObject *Rec )
{
 printf("the result of binInsertSort:\n");
 /*----begin------*/
 for (int i = 1; i < Rec->NUM; i ++){
    int key = Rec->data[i];
    int pre = i - 1;

    int l = 0, r = i;
    while (l < r) {
      int mid = l + r >> 1;
      if (Rec->data[mid] >= key) r = mid;
      else l = mid + 1;
    }
    int idx;
    if (Rec->data[l] >= key){
      idx = l;
    } else {
      idx = i + 1;
    }

    while ( pre >= idx && key < Rec->data[pre]) {
      Rec->data[pre+1] = Rec->data[pre];
      pre --;
    }
    Rec->data[pre+1] = key;
    print(Rec);
  }
 
 
 /*-----end------*/

}

/* 第四关
此处请填写代码实现递增序进行shell排序,
  
  要求每趟排序后 调用print函数，输出关键字的排列情况
  */
void shellSort( SortObject *Rec,int d )
{
  int num = 2*d;
  while(d > 0) {
    for (int i = 0; i < d; i++) {
      for (int j = i+d; j < num; j+=d) {
        int temp = Rec->data[j];
        int k;
        for (k = j-d; k >= 0; k-=d) {
          if (Rec->data[k] > Rec->data[j]) {
            Rec->data[k+d] = Rec->data[k];
          } else break;
        }

        Rec->data[k+d] = temp;
      }
    }
    d = d / 2;
    print(Rec);
  }
  
}

/*第三关
此处请填写代码实现递增序进行表插入排序,
  返回值是关键字比较次数
  Head是表头结点，不存放数据，info是待插入数据
  要求每趟排序后 调用printLink函数，输出关键字的排列情况
  */
void listSort(linkObject *plist )
{
 /*----begin------*/
  linkObject *p = plist->next;
  printLink(plist);

  while( p->next != NULL) {
    while(p->info < p->next->info) {
      p = p->next;
    }

    linkObject *tmp = (linkObject *)malloc(sizeof(linkObject));
    tmp->info = p->next->info;
    p->next = p->next->next;
    // p = p->next;

    linkObject *q = plist;
    while(q->next->info < tmp->info) {
      q = q->next;
    }

    tmp->next = q->next;
    q->next = tmp;

    printLink(plist);
  }
 /*-----end------*/

}

