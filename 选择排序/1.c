#include <stdio.h>
#define MIN(A, B) (a[(A)]<=a[(B)]?(A):(B))
#define SWAP(A, B) ((A)^=(B), (B)^=(A), (A)^=(B))
void print(int a[] ,int n)
{//输出数组元素，数字之间以一个空格为界，输出结束后换一行
  for (int i = 0; i < n ;i ++)
    printf("%d ", a[i]);
  puts("");

}

void selectSort(int a[] ,int n) //对数组a中的n个元素进行排序，调用print函数输出每趟排序后的结果
{
  for (int i = 0; i < n - 1; i ++){
    int min = i;
    for (int j = i + 1; j < n ; j ++)
      min = MIN(min, j);
    
    i != min && SWAP(a[i], a[min]);
    print(a, n);
  }


}


int main(void)
{
  int num ;
  scanf("%d",&num);
  int data[num];
  for(int i=0;i<num;i++)
    scanf("%d",&data[i]);

  selectSort(data ,num);
}
