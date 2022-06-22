#include <stdlib.h>
#include <stdio.h>
#include <string.h>
struct stack
{
  int Max;
  int top;
  char *elem;
};
typedef struct stack *Stack;

Stack init(int m)
//栈的初始化
{
   if(m==0) return NULL;
   Stack s=(struct stack*)malloc(sizeof(struct stack));
   s->top=0;
   s->Max=m;
   //赋最大值
   s->elem=(char*)malloc(sizeof(char)*m);
   //申请数组的空间
   return s;
}

int isNull(Stack s)
//栈的判空
{
   if(s->top==0) return 1;
   else return 0;
}
int isFull(Stack s)
//栈的判满
{
   if(s->top==s->Max) return 1;
   else return 0;
}

char top(Stack s)
//取栈顶元素
{
   if(isNull(s)) return '\0';
   else return s->elem[s->top-1];
}

void push(Stack s ,char ch)
//进栈
{
   if(isFull(s)) return;
   s->elem[s->top]=ch ;
   s->top++;
}

void pop(Stack s)
//出栈
{
   if(isNull(s)) return;
   else s->top--;
}

/*
   函数功能：将中缀表达式转换为后缀表达式输出
   函数参数：中缀表达式，放在字符数组中
   返回值：返回放有后缀表达式的栈
*/
Stack inToPost(char *expression)
{
   Stack s = init(100);
   Stack t = init(100);
   //一个存放操作符，一个存放结果。
   int i = 0;
   char ch ;
    while((expression[i])!='\0')
    {
    //从左到右遍历字符串
        ch=expression[i];
        if(ch>='0' && ch<='9')
        {
            while(ch>='0' && ch<='9')
            {
                push(s,ch);
                i++;
                ch=expression[i];
            }
        push(s,' ');
        i--;
        //将数字输入进结果栈，当下一个字符不是数字时放置空格。
        }
        else
        {
            if(ch=='(')
                push(t,'(');
            //当是(时直接入操作符栈
            else if(ch==')')
            {
                while(isNull(t)==0 && top(t)!='(')
                {
                    //操作符栈非空并且字符不等于（时
                    push(s ,top(t));
                    push(s,' ');
                    pop(t);
                }
                pop(t);
                //到（位置时弹出操作符
                //当是）是要把非（的字符全部压入操作符栈，压入后弹出当前操作符栈顶。
            }
            else if(ch=='+'||ch=='-')
            {
                while(isNull(t)==0)
                {
                    //当操作符栈非空时，把操作符栈顶压入，并且置空格。
                    push(s ,top(t));
                    push(s,' ');
                    pop(t);
                }
                push(t,ch);
                //遇到+、-时先把操作符栈元素压入结果栈，再把加减压入操作符栈。
            }
            else if(ch=='*' || ch=='/')
            {
                while(isNull(t)==0 && (top(t)=='*' || top(t)=='/'))
                {
                    //非空，仅仅压入操作符为*、/的元素
                    push(s ,top(t));
                    push(s,' ');
                    pop(t);
                }
                push(t,ch) ;
                //再将操作符压入操作符栈
            }
        }
        i++;
    }
   while(isNull(t)==0)
    {
        push(s ,top(t));
        push(s,' ');
        pop(t);
    }
   while(isNull(s)==0)
   {
        push(t,top(s));
        pop(s);
   }
   return t;
}

void print(Stack s)
{
  while(isNull(s)==0)
  {
        printf("%c",top(s));
        pop(s);
  }
}
/*
   第三关
   函数名：calExp，本函数名和参数不能更改
   函数功能：调用inToPost函数求解后缀表达式，并求解后缀表达式的值返回
   函数参数：
   返回值：无
*/
int calExp(char *express)
{
   //在此处填写代码，完成表达式求值并输出
   /**********  Begin  **********/



   /**********  End  **********/
}
