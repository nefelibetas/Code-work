//头文件自己根据需要包含
#循环链表和双向链表—课上课后练include <string>
#include <iostream>


using namespace std;

//请阅读main程序，判断并在此设计函数，实现将参数data的值反转，并返回反转后的结果
/*---------begin------------*/
string reverse(int x){
  string res;
  bool flag = false;
  if (x < 0) flag = true, x *= -1;
  while (x > 0){
    res += (x % 10) + '0';
    x /= 10;
  }
  
  while(res[0]=='0' && res.size() > 0 ) res.erase(res.begin());
  
  res = flag ? ("-" + res) : res;
  return res;
}
/*---------end------------*/

/*---------end------------*/



//下面的main函数请勿修改
int main(void)
{
  int  x ;
 cin>>x;
 cout<<reverse(x);
 return 1;
}
