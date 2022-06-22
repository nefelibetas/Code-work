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
	char ch ;
	BiTree  root ;
	cin>>ch ;
	if(ch == '#') return root = NULL;
	else{
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

int countLeaf(BiTree root)
{
    //请在此处填写代码， 计算二叉树中树叶的个数
    /********** Begin **********/
    BiTree t=root;

    int count=0;

    if(t==NULL)
    {
        return 0;
    }
    else if((t->lchild==NULL)&&(t->rchild==NULL))
    {
        return count+1;
    }
    else
    {
        count=countLeaf(t->lchild) + countLeaf(t->rchild);
        return count;
    }
    /********** End **********/
}

int main(void)
{
	BiTree root = createBiTree();
	cout<<countLeaf(root);
}

//AB#DF###CE#G###
