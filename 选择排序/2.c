#include <stdio.h>
void print(int a[] ,int n)
{//输出数组元素，数字之间以一个空格为界，输出结束后换一行
  for (int i = 0; i < n; i++) {
    printf("%d ",a[i]);
  }
  printf("\n");
}

void sift(int a[],int size,int p) {
  int tmp = a[p];
  int lchild = 2*p+1,rchild = 2*p+2;
  while(lchild < size) {
    if (lchild < size-1 && a[lchild] < a[rchild]) lchild = rchild;
    if (tmp < a[lchild]) {
      a[p] = a[lchild];
      p = lchild;
      lchild = 2*p+1;
      rchild = 2*p+2;
    } else break;
  }
  a[p] = tmp;
}

void heapSort(int a[] ,int n) //
{
  int i,tmp;
  for (i = n/2-1; i >= 0; i--) 
    sift(a,n,i);
  for (i = n-1; i > 0; i--) {
    tmp = a[i];
    a[i] = a[0];
    a[0] = tmp;
    sift(a,i,0);
    print(a,n);
  }
}

//根据需要自己添加其他需要的函数



int main(void)
{
  int num ;
  scanf("%d",&num);
  int data[num];
  for(int i=0;i<num;i++)
    scanf("%d",&data[i]);

  heapSort(data ,num);
}
