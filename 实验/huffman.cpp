/*请在此处编写代码，完成哈夫曼编码，并能输出每个叶子结点的编码*/
/**********  Begin  *********/
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

int N; //全局变量N表示输入数据个数

struct node
{
    float data;
    char code[20]; //存放哈夫曼编码
    struct node *left, *right;//左右节点
    struct node *next;//用链表去构造哈夫曼树
    int code_n;
    //做编码数组下标
};
typedef struct node* PHT;
typedef struct node NODE;

 // 哈夫曼树的结点定义
struct node *Head; //头结点

void printcode(struct node *p)//输出哈夫曼编码
{
    int i;
    if(p==NULL) return ;
    for(i= p->code_n-1;i>=0 ;i--)
        cout<<p->code[i];
    //逆序输出每个哈夫曼码
}

void Insert(struct node *b) //插入结点，保持递增
{
    struct node *p,*q;
    p=Head->next;
    q = Head;
    if(p == NULL)
    {
        Head->next = b;
    }
    else
    {
        while(p!=NULL && p->data < b->data)
        {
            q = p;
            p = p->next;
        }
        b->next = p;
        q->next = b;
        //找到合适b的位置
    }
}


void code(struct node *a,int flag) //编码过程
{
    if (a==NULL) return ;
    //空的哈夫曼树
    if(flag==1)  //flag为 1 表示左子树
    {
        a->code[a->code_n] = '0';
    }
    else if(flag==2)//flag为2 表示右子树
    {
        a->code[a->code_n] = '1';
    }
    a->code_n++;
    //对应节点下标索引自增，进行反向编码（由树的最下层到根节点）
    code(a->left, flag);
    code(a->right,flag);
}

void InitNode( ) //初始化结点
{
    struct node *p;
    int i;
    float m;
    Head =(PHT)malloc(sizeof(NODE));
    Head->left =Head->right = Head->next =NULL ;
    //初始化三个指针
    for(i=0;i<N;i++)
    {
        cin>>m;
        p = (PHT)malloc(sizeof(NODE));
        p->data = m;
        //数据输入
        p->left = p->right = p->next =NULL;
        //左右置空
        p->code_n = 0;
        //下标置0
        Insert( p);
        //通过数据大小选择合适的位置
    }
}


void InOrder(struct node *T)
{
    //中序遍历
    if(T==NULL) return;
    else
    {
        if(T->left == T->right && T->left == NULL)
        {
            cout<<T->data<<" ";
            printcode(T);
            cout<<endl;
            //当遍历到外部节点(用来构造哈夫曼树的节点)时输出这个 节点的数据 以及 哈夫曼编码。
        }
        InOrder(T->left);
        InOrder(T->right);
    }
}


void Huffman()//创建haffman树
{
    struct node *temp;
    struct node  *p,*q;
    while(1)
    {
        p = Head->next;
        q = p->next;
        //此处的Head是全局变量
        if(q!=NULL)
            Head->next = q->next;
        else
            Head->next = NULL;
            //让最小和次小的两个节点断开，然后开始构造哈夫曼树。
        temp = (PHT)malloc(sizeof(NODE));
        temp->data = p->data + q->data ;
        temp->left = p;
        temp->right = q;
        temp->code_n = 0;
        //由于按顺序存放节点，因此可以直接构造。
        //并且利用temp节点存放数据。
        code(p,1);
        code(q,2);
        //将左右树放入进行编码
        temp->next = NULL;
        Insert(temp);
        //将temp节点插入到合适位置，从小到大。
        if(Head->next->next == NULL)//就只剩下一个哈夫曼树和头结点时结束循环。
            break;
    }
}


int main(void)
{
    cin>>N;
    //对全局变量N进行重构，重新定义最大数量。
    InitNode();
    //初始化创建节点。
    Huffman();
    //构造哈夫曼树和哈夫曼编码。
    InOrder(Head->next);
    //从根开始中序遍历。
}
/**********  End  *********/

