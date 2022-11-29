#include <stdio.h>
#include <stdlib.h>
//数据结构定义
struct node
{
    int data ;
    struct node *lchild ,*rchild ;
};

typedef struct node *pTree;
/*第一关*/


/*1.创建一个二叉树结点,值为element*/ 
pTree createTreeNode(int element)
{
    pTree tree = (pTree) malloc(sizeof(struct node));
    tree->data = element;
    return tree;
}

/*2.在二叉排序树中插入一个数据元素,若二叉树为空，则新建根节点*/
pTree insertData(int x , pTree T)
{
    if (T) {
        if (x < T->data){
            T->lchild = insertData(x, T->lchild);
        }
        else T->rchild = insertData(x, T->rchild);
        
    } else {
        return createTreeNode(x);
    }
    return T;
}

/*3.先序遍历和中序遍历函数*/
void preOrder( pTree T)
{
    if (!T) return;
    printf("%d ", T->data);
    preOrder(T->lchild);
    preOrder(T->rchild);


}
void inOrder( pTree T)
{

    if (!T) return;
    inOrder(T->lchild);
    printf("%d ", T->data);
    inOrder(T->rchild);

}


/*第二关*/
/*1.在二叉排序树T中查找最小值，返回该结点*/
pTree findMin(pTree T)
{
    if (!T) return NULL;
    if (!T->lchild) return T;

    return findMin(T->lchild);
}

/*2.在二叉排序树T中查找最大值，返回该结点*/
pTree findMax(pTree T)
{
    if (!T) return NULL;
    if (!T->rchild) return T;
    return findMax(T->rchild);
}


/*3.在二叉排序树T中查找指定数据元素，若未找到，则返回NULL*/
pTree findData(pTree T, int element)
{
    if (!T) return NULL;

    if (T->data == element) return T;
    else if (T->data > element) return findData(T->lchild, element);
    else return findData(T->rchild, element);
}

/*第三关*/
/*在二叉排序树T中删除指定元素的结点,若删除成功则返回该结点，否则返回NULL*/
pTree deleteData(pTree T, int element)
{
    if (!T) return NULL;
    if (element < T->data){
         T->lchild = deleteData(T->lchild, element);
         return T;
    }
    if (element > T->data){
         T->rchild = deleteData(T->rchild, element);
         return T;
    }

    if (!T->lchild && !T->rchild){
        free(T);
        return NULL;
    }
    if (T->lchild && !T->rchild) return T=T->lchild;
    if (!T->lchild && T->rchild) return T=T->rchild;

    if (T->lchild && T->rchild) {
        pTree r = findMin(T->rchild);
        T->data = r->data;
        T->rchild = deleteData(T->rchild, r->data);
        return T;
    }
    return T;
}
