 #include <stdio.h>
 #include <stdlib.h>
 #define swap(A, B) ((A)^=(B),(B)^=(A),(A)^=(B))
 /*----------------*/
 //若采取顺序存储结构，集合最多存放的元素个数，可自定义
 const int N = 25, M = 1e3;
 
struct SetNode//若采用链式存储结构，则头结点不存储集合元素，存储集合中元素的个数，且数据成员命名为info
//若采用顺序存储结构，则应有成员变量记录当前集合中数据元素个数，且该成员命名为info
 {
    int cur;
    int *info;
    char *st;
 };
 typedef struct SetNode *Set;
 
 int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
 void printSet(Set A)
 {
  //根据自定义数据结构，请先完成本函数，逐个输出集合元素，以一个空格为分界，最后一个元素输出后，追加输出一个换行符
  qsort(A->info, A->cur, sizeof(int), cmpfunc);
  for (int i = 0; i < A->cur; i ++){
    if (i) printf(" ");
    printf("%d", A->info[i]);
  }
 }
 
 
 //第1关，创建一个空集合 
 Set createEmptySet()
 {
  /*----------------*/
    Set a = (Set)malloc(sizeof(struct SetNode));
    if (!a) return a;
    a->cur = 0;
    /* 第一关，如果过不了，请把下面两行注释掉orz */
    a->info = (int*)malloc(sizeof(int)*N);
    a->st = (char*)malloc(sizeof(char)*M);

    return a;
  /*----------------*/
 }
 
 //第2关，向集合中插入元素

 void insert(int data, Set A)
 {
  /*----------------*/
  if (A->st[data]) return;
  A->info[A->cur ++] = data, A->st[data] = 1;

 }
 
 //第3关，判断数据元素是否属于集合 
 int member(int data,Set A)
 {
  /*----------------*/
  if (!A || !A->cur) return 0;
  return A->st[data];
  
  return 0;
 }
 
  //第4关，从集合A中删除指定数据元素，返回集合
 Set delete(int data, Set A)
 {
  /*----------------*/
  if (!A->st[data]) return A;
  for (int i = 0; i < A->cur; i ++)
    if (A->info[i] == data){
      A->st[data] = 0;
      swap(A->info[i], A->info[A->cur - 1]);
      A->cur --;
      break;
    }
  return A;
 
 }
 
  //第5关，求集合A,B的并集
  void Union(Set A, Set B, Set C)
 {
  /*----------------*/
  for (int i = 0; i < A->cur; i ++)
    insert(A->info[i], C);
  for (int i = 0; i < B->cur; i ++)
    if (!member(B->info[i], A)) insert(B->info[i], C);
 }
 
   //第6关，求集合A,B的交集
 void intersect(Set A, Set B, Set C)
 {
  /*----------------*/
  for (int i = 0; i < A->cur; i ++)
    if (member(A->info[i], B)) insert(A->info[i], C);
 }
 
    //第7关，求集合A,B的差集
 void difference(Set A, Set B, Set C)
 {
  /*----------------*/
  for (int i = 0; i < A->cur; i ++)
    if (!member(A->info[i], B)) insert(A->info[i], C);
 
 }
 
