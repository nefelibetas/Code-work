#include <stdlib.h>
#include <stdio.h>
#include<string.h>
// 自己定义需要的栈结构，及栈基本操作函数，假设操作数都是整数
struct stack
{
   int MAXNUM;
   int top;
   int *element;
};

typedef struct stack *Stack;

Stack createNullStack(int m)
{
	if(m==0) return NULL;
	Stack s = (Stack)malloc(sizeof(struct stack));
	if(s == NULL)return NULL;
 	s->top=0;
 	s->MAXNUM=m;
 	s->element = (int *)malloc(sizeof(struct stack)*(m+1));
 	if(s->element==NULL)
 	{
   		free(s);
   		return NULL;
 	}
 	return s;
}

int push(Stack L ,int x)
{
  if(L->top != L->MAXNUM)
  {
    L->top+=1;
    L->element[L->top] = x;
    return 1;
  }
  return 0;
}

int pop(Stack L)
{
  int t = L->element[L->top];
  L->top-=1;
  return t;
}

int showTop(Stack L)
{
	return L->element[L->top];
}

void destroystack_seq(Stack L)
{
    free(L);
}
/*在此定义并完成第一关函数，参考main要求*/

//递归函数写法（每一站上车的人数）
/*int add(int a,int n,int sec)//求每一站上车的人数减去下车人数的函数
{
	if(n==3) return a;
	else if(n==4) return sec;
	else return add(a,n-1,sec)+add(a,n-2,sec);
}*/

int result(int n,int m,int a,int x)
{
	int sec=0;//第二站上车的人数 穷举以解出他的值
	while(1)
	{
		int sum = 0;
		Stack L = createNullStack(n);
		for(int i=0;i<n;i++)
		{
			int temp;
			if(i==0 || i==2 ) temp = a;
			else if(i==1 || i==n-1) temp = 0;
			else if(i==3) temp = sec;
			else
			{
				int t = pop(L);
			    temp = t + showTop(L);
				push(L,t);
			}
			push(L,temp);
			sum += temp;
		}
		if(sum == m)
		{
			for(int i=n;i>x;i--) pop(L);
			sum = 0;
			for(int i=0;i<x;i++) sum+=pop(L);
			return sum;
		}
		destroystack_seq(L);
		sec++;
		sum = 0;
	}
}



/*
   第二关
   函数名：inToPost，本函数名和参数不能更改
   函数功能：将中缀表达式转换为后缀表达式输出
   函数参数：中缀表达式，放在字符数组中
   返回值：返回放有后缀表达式的栈
*/
Stack  inToPost(char *expression)
{
   //在此处填写代码，完成中缀表达式转换为后缀表达式并输出
   /**********  Begin  **********/
    int num = strlen(expression);
	Stack L = createNullStack(num);
	Stack s = createNullStack(num*2);
	for(int i=0;i<num;i++)
	{
		if(expression[i]>='0'&&expression[i]<='9')
		{
			push(s,'#');
			int t = expression[i]-'0';
			while(expression[i+1]>='0'&&expression[i+1]<='9')
			{
				t = t*10 + (expression[i+1]-'0');
				i++;
			}
			push(s,t);
		}
		else if(expression[i] == ')')
		{
			while(showTop(L) != '(')
			{
				push(s,pop(L));
			}
			pop(L);
		}
		else
		{
			if(L->top!=0)
			{
				if(expression[i] == '+' || expression[i] == '-')
				{
					while(showTop(L) == '+' || showTop(L) == '-' || showTop(L) == '*' || showTop(L) == '/')
					{
						push(s,pop(L));
					}
				}
				else if(expression[i] == '*' || expression[i] == '/')
				{
					while(showTop(L) == '*' || showTop(L) == '/')
					{
						push(s,pop(L));
					}
				}
			}
			push(L,expression[i]);
		}
	}
	while(L->top != 0)
	{
		int t = pop(L);
		push(s,t);
	}
    return s;
   /**********  End  **********/
}

//print函数用于输出后缀表达式，参数是 inToPost的返回值

void print(Stack s)
{
	char c[100];
	int count=0;
	while(s->top != 0)
	{
		c[count++] = '#';
		int t = pop(s);
		if(showTop(s) == '#')
		{
			while(t)
			{
				c[count++] = t%10 + '0';
				t/=10;
			}
			pop(s);
		}
		else
		{
			c[count++] = t;
		}
	}
	for(int i=count-1;i>0;i--)
	{
		if(c[i]=='#')
		{
			 printf(" ");
			 continue;
		}
		printf("%c",c[i]);
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
    int ch[80];
    int num[80];
    int cc=0;
	int cn=0;
    Stack L = inToPost(express);
    while(L->top != 0)
	{
		int t = pop(L);
		if(showTop(L) == '#')
		{
			num[cn++]=t;
			pop(L);
		}
		else
		{
			num[cn]=t;
			ch[cc++]=cn;
			cn++;
		}
	}
	cc--;
	//
	while(cc!=-1)
	{
		switch(num[ch[cc]]){
			case '+':num[ch[cc]]=num[ch[cc]+2]+num[ch[cc]+1];break;
			case '-':num[ch[cc]]=num[ch[cc]+2]-num[ch[cc]+1];break;
			case '*':num[ch[cc]]=num[ch[cc]+2]*num[ch[cc]+1];break;
			case '/':num[ch[cc]]=num[ch[cc]+2]/num[ch[cc]+1];break;
		}
		for(int i=ch[cc]+3;i<=cn;i++)
		{
			num[i-2]=num[i];
		}
		cn--;
		cc--;
	}
    return num[0];
   /**********  End  **********/
}
