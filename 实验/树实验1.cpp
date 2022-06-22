#include <iostream>
using namespace std;

typedef char DataType;

//二叉树结点定义 
struct node
{
    DataType data; //存放结点数据 
    struct node* lchild, * rchild; //左右孩子指针 
};
typedef struct  node  BiTree;
typedef struct  node* ptree;

//函数可直接使用，功能：输出结点数据
void print(DataType d)
{
    cout << d << " ";
}

/*
函数名：createBiTree
函数功能：创建二叉树，并返回二叉树的根结点指针
参数：无
返回值：二叉树的根结点指针
*/
BiTree* createBiTree() {
    //请在此处填写代码，完成创建二叉树并返回二叉树根结点指针的功能    
    /*-------begin--------*/
    char ch;
    ptree root;
    cin >> ch;
    if (ch == '#')  root = NULL;
    else
    {
        root = new BiTree;
        root->data = ch;
        root->lchild = createBiTree();
        root->rchild = createBiTree();
    }
    return root;
    /*-------end--------*/
}

/*
函数名：preOrder
函数功能：先根遍历二叉树
参数：二叉树根结点指针
返回值：无
*/
void preOrder(BiTree* T)
{
    //请在此处填写代码，完成先根遍历二叉树功能    
    /*-------begin--------*/
    if (T == NULL)
        return;
    print(T->data);
    preOrder(T->lchild);
    preOrder(T->rchild);
    /*-------end--------*/
}

/*
函数名： inOrder
函数功能：中根遍历二叉树
参数：二叉树根结点指针
返回值：无
*/
void inOrder(BiTree* T)
{
    //请在此处填写代码，完成中根遍历二叉树功能    
    /*-------begin--------*/
    if (T == NULL)
        return;
    inOrder(T->lchild);
    print(T->data);
    inOrder(T->rchild);
    /*-------end--------*/
}

/*
函数名：postOrder
函数功能：后根遍历二叉树
参数：二叉树根结点指针
返回值：无
*/
void postOrder(BiTree* T)
{
    //请在此处填写代码，完成后根遍历二叉树功能    
    /*-------begin--------*/
    if (T == NULL)
        return;
    postOrder(T->lchild);
    postOrder(T->rchild);
    print(T->data);
    /*-------end--------*/
}



int main(void)
{
    BiTree* T;
    T = createBiTree(); //调用创建二叉树功能，得到二叉树的根结点指针


    preOrder(T);//调用先根遍历二叉树，按先根遍历顺序输出二叉树结点功能 
    cout << endl; //换行
    inOrder(T);//调用中根遍历二叉树，按中根遍历顺序输出二叉树结点功能 
    cout << endl;
    postOrder(T);//调用后根遍历二叉树，按后根遍历顺序输出二叉树结点功能 

    return 1;
}