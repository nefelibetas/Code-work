#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
 /* 
 定义顺序存储结构
  */
  struct seqTree
  {
    int max;
    char *str;
  };

/*辅助功能：逐个输出顺序表的元素，元素之间以空格为界*/
void printTree(struct seqTree *T)
{
  for (int i = 0; i < T->max; i ++) printf("%c ", T->str[i]);

}

/*第一关*/
struct seqTree *createSeqTree()
{
  //此处编写代码实现二叉树的初始化，包括输入数据
  char arr[255];
  gets(arr);
  int len = strlen(arr);

  struct seqTree * tree = (struct seqTree *)malloc(sizeof(struct seqTree));
  tree->max = len;
  tree->str = (char *)malloc(sizeof(char) * (len + 1));
  for (int i = 0; i <= len ; i ++) tree->str[i] = arr[i];
  return tree;
}

/*第二关，返回二叉树的根结点的值，若二叉树为空，则返回#*/
char root(struct seqTree *T)
{
  if (T->max == 0 || T->str[0] == ' ') return '#';
  return T->str[0];
}

/*第二关，求二叉树T中指定结点ch的双亲结点，返回值是双亲结点的下标，若双亲不存在，则返回-1*/
int parent(struct seqTree *T ,char ch)
{
  for (int i = 0; i < T->max ; i ++) {
    if (ch == T->str[i]){
      int p = (i - 1) >> 1;
      if (T->str[p] == ' ') return -1;
      return p;
    }
  }
}

/*第二关，求二叉树T中指定结点ch的左孩子的下标，若左孩子不存在，则返回-1*/
int leftChild(struct seqTree *T ,char ch)
{
  for (int i = 0; i < T->max ; i ++) {
    if (ch == T->str[i]){
      int lc = i * 2  + 1;
      if (lc > T->max || T->str[lc] == ' ') return -1;
      return lc;
    }
  }

    
}

/*第二关，求二叉树T中指定结点ch的右孩子的下标，若左孩子不存在，则返回-1*/
int rightChild(struct seqTree *T ,char ch)
{
  for (int i = 0; i < T->max ; i ++) {
      if (ch == T->str[i]){
        int rc = i * 2  + 2;
        if (rc > T->max || T->str[rc] == ' ') return -1;
        return rc;
      }
  } 
}

/*第三关：层序遍历二叉树，输出遍历得到的结点，结点之间不需要空格*/
void levelOrder(struct seqTree *T )
{
  for (int i = 0; i < T->max; i ++ )
    if (T->str[i] != ' ') printf("%c", T->str[i]);
}

/*第四关：先序遍历二叉树，输出遍历得到的结点，结点之间不需要空格*/
void preOrder(struct seqTree *T, char r)
{
  
  int lc = leftChild(T, r);
  int rc = rightChild(T, r);
  if (r != '#') printf("%c", r);
  if (lc != -1) preOrder(T, T->str[lc]);
  if (rc != -1) preOrder(T, T->str[rc]);
}


int main(void)
{
  struct seqTree *T = createSeqTree();
  // printTree(T); //测评第一关时，把本行代码放开
  // printf("%c\n",root(T)); //  测评第二关时，把该代码块放开
  //   printf("%d\n",leftChild(T,'A'));
  //   printf("%d\n",rightChild(T,'A'));
  //   printf("%d\n",parent(T,'A'));
    
  // levelOrder(T); //测评第三关时，把本行代码放开 
  preOrder(T, T->str[0]); //测评第四关时，把本行代码放开 

}


