#include <iostream>
using namespace std;

int find_pos(int data[] ,int n, int key)
{//在数组data中查找给定数据key，n是数组中数据元素的个数，返回值是数据元素比较的次数.
    
 /*------------begin-----------------*/
  int l = 0, r = n - 1;
  int mid;
  int res = 0;
  while (l < r){
    res ++;
    mid = l + r >> 1;
    if (data[mid] == key) break;
    else if (data[mid] > key) r = mid - 1;
    else if (data[mid] < key) l = mid + 1;
  }
  if (data[mid] == key) return res;
  else if (data[mid + 1] == key) return res + 1;
  else return 0;
 /*------------end-----------------*/
}

int main(void)
{
int a[]={-1,15,66,99,122,189};
int x;
cin>>x;
//此处填写代码，调用find_pos，在a数组中查找给定数据x的位置，并输出函数返回值
  /*------------begin-----------------*/
cout << find_pos(a, 6, x) << endl;
 /*------------end-----------------*/   
    
return 1;
}
