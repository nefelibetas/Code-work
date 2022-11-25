#include <stdio.h>
void compute(int data[],int n, int target)
{//在此处填写代码，在data数组中查找是否存在两个元素之和为target，并按要求输出
  /*-----------begin---------------*/ 
    for (int i = 0; i < n; i ++)
    {
      int x = target - data[i];
      int l = 0, r = n - 1;
    
      while(l < r){
        int mid = l + r >> 1;
        if (data[mid] >= x) r = mid;
        else l = mid + 1;
       
      }
      if (l != i && data[l] == x){
        printf("%d,%d", i, l);
        return;
      }
    }
   
    puts("-1,-1");
    return ;    
 /*-----------end---------------*/ 

}

int main(void)
{
    int a[]={-3,2,5,9,15,32};
    int x ;
    scanf("%d",&x);
    compute(a,6,x);
}
