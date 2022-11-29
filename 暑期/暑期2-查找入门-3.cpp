//包含必要的头文件
#include <iostream>

using namespace std;

void compute(int data[],int n, int target)
{//在此处填写代码，在data数组中查找是否存在两个元素之和为target，并按要求输出
  /*-----------begin---------------*/ 
    for (int i = 0; i < n - 1 ; i ++)
      for (int j = i + 1; j < n; j ++)
        if (data[i] + data[j] == target){
           cout << i << ',' << j << endl;
           return ;
        }

  puts("-1,-1");
 /*-----------end---------------*/ 

}

int main(void)
{
    int a[]={-3,2,5,9,15,32};
    int x ;
    cin>>x;
    compute(a,6,x);
}
