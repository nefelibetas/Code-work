//包含必要的头文件
#include <iostream>

using namespace std;


 //根据main程序的提示，此处输入代码，设计一个能输出参数n项斐波那契数列，两个数之间有一个空格，最后一个数后面不需要空格
  /*-----begin---------*/  
    void fib(int x){
        int pre = 0, now = 1;
        
        
        for (int i = 0 ; i < x ; i ++){
            if (i) cout << ' ';
            cout << now;
            swap(pre, now);
            now = pre + now;
        }
    }
    
    
 /*-----end---------*/  
    


int main(void)
{
int i;
    cin>>i;
    fib(i);  
return 1;
}
