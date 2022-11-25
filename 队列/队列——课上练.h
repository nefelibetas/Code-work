#include <stdio.h>

/*此处是顺序队列数据结构定义*/
typedef int DataType;
struct seqQueue//请完成数据结构定义
{
   int MAXNUM;
   int front, rear;
   DataType  *element;
};

typedef struct seqQueue *PseqQueue;
//第一关
PseqQueue createNullQueue_seq(int m)
{//此处填写代码，创建一个空的顺序队列，能存放的最大元素个数为 m
 //若m=0，则返回NULL 
  if (m == 0) return NULL;
  PseqQueue queue = (PseqQueue)malloc(sizeof(struct seqQueue));
  queue->MAXNUM = m;
  queue->front = 0;
  queue->rear = 0;
  queue->element = (DataType*)malloc(sizeof(DataType) * m);
  return queue;

}
//第二关
int isNullQueue_seq(PseqQueue Q)
{
  //判断顺序（环形）队列是否为空，若为空，返回值为1，否则返回值为0,若队列不存在，则返回-1
  if (Q == NULL) return -1;
  if (Q->rear == Q->front ) return 1;
  else return 0;
}


//第三关 
int isFullQueue_seq(PseqQueue Q)
{
  //判断环形队列是否已满，若已满，返回值为1，否则返回值为0
  if (Q->rear - Q->front + 1 == Q->MAXNUM) return 1;
  else return 0;
}


//第四关
int enQueue_seq(PseqQueue Q ,DataType x)
{//在环形队列中插入数据元素x，若插入不成功，返回0；插入成功返回值为1
    if (Q == NULL || Q->rear + 1 >= Q->MAXNUM) return 0;
    Q->element[Q->rear ++] = x;
    return 1;
}
 


//第五关
DataType delQueue_seq(PseqQueue Q)
{//出队并返回删除元素，若队列为空，则返回-1
    if (Q == NULL || Q->front == Q->rear) return -1;
    return Q->element[Q->front ++];
}

//第六关
DataType front_seq(PseqQueue Q)
{// 取队首元素返回，若队列为空，则返回-1
    if (Q == NULL || Q->front == Q->rear) return -1;
    
    return Q->element[Q->front];
}

//销毁顺序队列，释放队列所占存储空间
int destroyQueue_seq(PseqQueue Q)
{
    //返回值为销毁的栈中现有数据元素的个数，若待销毁的线性表不存在，则返回0
    if (Q == NULL) return 0;
    for (int i = 0; i < Q->MAXNUM; i ++)
      free(Q->element + i);
    if (Q->rear == Q->front) return 0;
    return Q->rear - Q->front + 1;
}


//第七关
void queueApp(int a[],int n)
{
//参数用于传递顾客编号和顾客人数，输出顾客接受服务后离开顺序
  PseqQueue A = createNullQueue_seq(n + 1);
  PseqQueue B = createNullQueue_seq(n + 1);

  for (int i = 0; i < n; i ++) {
    if (a[i] & 1) enQueue_seq(A, a[i]);
    else enQueue_seq(B, a[i]);
  }

  while (!isNullQueue_seq(A) || !isNullQueue_seq(B)) {
    if (!isNullQueue_seq(A)){
      printf("%d ", delQueue_seq(A));
    }
    if (!isNullQueue_seq(A)){
      printf("%d ", delQueue_seq(A));
    }
    if (!isNullQueue_seq(B)){
      printf("%d ", delQueue_seq(B));
    }
  }

}










