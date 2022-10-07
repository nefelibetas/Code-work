#include <iostream>
using namespace std;
//第一关代码

struct node
{//此处填写代码，定义链表结点类型，包含一个存放整型数据的 成员，和一个指向下一个结点的成员
  int data;
  node *next;
};

struct node *mycreateList()
{//此处填写代码，创建一个只有一个头结点的空链表，头节点的数据域赋值为0，并将表头结点的地址返回
    node *head = new node();
    head->data = 0;
    head->next = NULL;
}


//第二关代码

void myinsertHead(struct node * head, int insData )
{
	/*在此处完成任务，实现在head为表头d 链表的头插数据元素insData的功能*/
	//begin
    node *p = new node();
    p->data = insData;
    p->next = head->next;
    head->next = p;
	
	//end 
}

void myinsertTail(struct node *  head , int insData )
{
	/*在此处完成任务，在head为表头的单链表表尾插入数据元素insData*/
	//begin
    node *p = head;
    p->data ++;
    node *n = new node();
    n->data = insData;
    for (; p->next != NULL ; p = p->next);
    p->next = n;
    n->next = NULL;
	//end 	
}

void myprintList(struct node *L)
{
     /*在此处完成任务，输出L为表头链表中的数据，每输出一个数据换一行*/
	//begin
	for (auto p = L; p != NULL; p = p->next)
      if (p != L) cout << p->data << endl;
	//end 
    
}



 
//第三关代码
 int myfindPos( struct node *L, int pos)
 {
    //请在此处填入代码，实现在链表中查找第pos个结点的功能 
 	//begin
    node *p = L;
   	for (int i = 1 ; i <= pos && p != NULL ; i ++)
      p = p->next;
   if (pos < 1) return -1;
   if (p == NULL) return -1;
    return p->data;
 	 
	//end 
 }

  int myfindKey( struct node *L, int key)
 {
    //请在此处填入代码，实现在链表中查找与key值相同的第一个结点的功能 
 	//begin
     node *p = L ;

 	for (; p->data != key && p->next != NULL;) p = p->next;

      if (p != NULL && p->data == key) return 1;
      
      return 0;
	//end 
 }

 //第四关代码
 int mydeletePos( struct node *L, int pos)
 {
    //请在此处填入代码，实现在链表中删除第pos个结点的功能 
 	//begin
 	node *p = L;
   node *pre = NULL;
   for (int i = 1 ; i <= pos && p->next != NULL ; i ++){
     pre = p;
     p = p->next;
   }

   pre->next = p->next;
   delete p;
   L->data --;
 	return 1;
	//end 
 }

  int mydeleteKey( struct node *L, int key)
 {
    //请在此处填入代码，实现在链表中删除与key值相同的第一个结点的功能 
 	//begin
   node *p = L;
   node *pre = NULL; 

 	for (; p->data != key && p != NULL;){
      pre = p;
      p = p->next;
    }
    if (p == NULL || p->data != key){
        return 0;
    }
   pre->next = p->next;
  delete p;
   L->data --;
   return 1;
	//end 
 }

//第五关代码
 void reverseList_link( struct node *L)
 {
    //请在此处填入代码，实现链表逆置功能 
 	//begin
 	node *p = L->next;
    node *pre = NULL;
   for (; p != NULL ; ){
     node *tmp = p->next;
     p->next = pre;
     pre = p;
     p = tmp;
   }
 	 L->next = pre;
	//end 
 }



 
