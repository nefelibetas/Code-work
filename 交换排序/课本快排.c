#include <stdio.h>
/*10 49 38 65 97 49 13 27 76 90 12*/
void print(int a[] ,int n)
{//输出数组元素，数字之间以一个空格为界，输出结束后换一行
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}

void qSort(int a[] ,int left, int right) //
{
    if(left>=right) return;
    int i=left,j=right;
    int temp=a[i];

    while(i!=j)
    {
        while(i<j&&a[j]>=temp)
            j--;
        if(i<j)
            a[i++]=a[j];
        while(i<j&&a[i]<=temp)
            i++;
        if(i<j)
            a[j--]=a[i];
    }
    a[i]=temp;
    print(a,right+1);
    printf("\n");
    qSort(a,left,i-1);
    qSort(a,i+1,right);
}

int main(void)
{
  int num ;
  scanf("%d",&num);
  int data[num];
  for(int i=0;i<num;i++)
    scanf("%d",&data[i]);

  qSort(data ,0,num-1);
  print(data,num);
}
