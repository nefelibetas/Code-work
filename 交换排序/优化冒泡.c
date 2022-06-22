#include <stdio.h>
void print(int a[] ,int n)
{//输出数组元素，数字之间以一个空格为界，输出结束后换一行
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

void bubbleSort(int a[] ,int n) //对数组a中的n个元素进行排序，调用print函数输出每趟排序后的结果
{
    for(int i=0;i<n-1;i++)
    {
        int IsSorted=1;
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                IsSorted=0;
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
        if(!IsSorted)
            print(a,n);
        else if((IsSorted)&&(i==0))
            print(a,n);
        else
            break;
    }
}
int main(void)
{
  int num ;
  scanf("%d",&num);
  int data[num];
  for(int i=0;i<num;i++)
    scanf("%d",&data[i]);
  bubbleSort(data ,num);
}
