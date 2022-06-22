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
  返回值：二叉树根结点指针*/
BiTree createBiTree(void)
{
	char ch ;
	BiTree  root ;
	cin>>ch ;
	if(ch == '#') return NULL;
	else
    {
        root = new struct node ;
        root->info = ch ;
        root->lchild = createBiTree() ;
        root->rchild = createBiTree();
	}
}

void visit(BiTree T)
{
	cout<<T->info ;
}

int countFullNode(BiTree root)
{
	//请在此处填写代码，计算二叉树中满结点的个数
    /********** Begin **********/
    BiTree t=root;
    if(t==NULL)
    {
        return 0;
    }
    else if(t->lchild && t->rchild)
    {
        return countFullNode(t->lchild)+countFullNode(t->rchild)+1;
    }
    else
    {
        return countFullNode(t->lchild)+countFullNode(t->rchild);
    }
    /*********** End-**********/
}

int main(void)
{
	BiTree root = createBiTree();
	cout<<countFullNode(root) ;
}
