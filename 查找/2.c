#include <stdio.h>

int find_pos(int data[] ,int n, int key)
{//在数组data中查找给定数据key，n是数组中数据元素的个数，返回值是数据元素比较的次数.
    
 /*------------begin-----------------*/
  int l = 0, r = n - 1;
  int cnt = 0;
  while (l < r){
    int mid = (l + r) >> 1;
    if (data[mid] == key) return cnt + 1;
    else if(data[mid] < key) l = mid + 1;
    else if(data[mid] > key) r = mid - 1;
    cnt ++;
  }
  if (data[l] != key) return 0;
  return cnt + 1;
 /*------------end-----------------*/
}

int main(void)
{
int a[]={-1,15,66,99,122,189};
int x;
scanf("%d",&x);
//此处填写代码，调用find_pos，在a数组中查找给定数据x的位置，并输出函数返回值
  /*------------begin-----------------*/
printf("%d", find_pos(a, 6, x));
 /*------------end-----------------*/   
    
return 1;
}

