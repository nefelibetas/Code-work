#include <iostream>
using namespace std;

typedef char DataType;

//二叉树数据结构
struct node
{
	DataType info ; //存放结点数据
	struct node *lchild , *rchild ; //指向左右孩子的指针
};

typedef struct node *BiTree ;

/*创建二叉树
  函数名：createBiTree
  参数：无
  返回值：二叉树根结点指针
  */
BiTree createBiTree(void)
{
	//请在此处填写代码， 完成二叉树和创建，返回值是二叉树的根结点指针
	//分析：前序创建
    /********** Begin **********/
    char ch;
    BiTree T;
    cin>>ch;
    if(ch=='#') return T=NULL;
    else
    {
        T=new struct node;
        T->info=ch;
        T->lchild=createBiTree();
        T->rchild=createBiTree();
    }
    /********** End *********/
}

void visit(BiTree T) //输出结点T的数据
{
	cout<<T->info ;
}

void inOrder(BiTree root)//进入下一个节点，中序遍历。
{
	if(root == NULL) return ;
	inOrder(root->lchild);
	visit(root);
	inOrder(root->rchild);
}

int main(void)
{
	BiTree root = createBiTree();
	inOrder(root);
}
