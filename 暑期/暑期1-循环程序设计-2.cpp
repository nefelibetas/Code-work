//包含必要的头文件
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

bool judge(string data)
{
    //请在此填写函数，用户判断data是否是回文，若是回文，返回true，否则返回false
    /*------begin--------*/
    string tmp = data;
    reverse(tmp.begin(), tmp.end());
    
    return tmp == data;
    
    /*------end--------*/
}

int main(void)
{
    string x;
    //请在此书写代码，从键盘读入一个字符串放入变量x
    cin >> x;
    if (judge(x)) puts("true");
    else puts("false");
    //在此书写代码，输出调用函数judge的结果 
    
    
    return 1;
}
