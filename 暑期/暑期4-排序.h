#include <iostream>
using namespace std;

/*数据结构定义*/
typedef int DataType;
typedef struct
{
  DataType *data; //用于存放待排序关键字的起始地址
  int NUM; //待排序关键字的个数 
} SortObject;

typedef struct node //用于表插入排序的数据结构
{
  DataType  info;  
  struct node *next;  
} linkObject;

//输出顺序表
void print(SortObject *p)
{
 for(int i=0;i<p->NUM;i++)
   cout<<p->data[i]<<" ";
 cout<<endl;  
}

//输出链表
void printLink(linkObject *Head)
{
  linkObject *p = Head->next ;
  while(p)
  {
    cout<<p->info<<" ";
    p = p->next;
  }
  cout<<endl;
}

/*第一关
此处请填写代码实现递增序进行直接插入排序,
 要求每趟排序后 调用print函数，输出关键字的排列情况*/
void insertSort( SortObject *Rec )
{
    cout<<"the result of insertSort:\n";
    /*----begin------*/

    for (int i = 1; i < Rec->NUM; i ++){
        int now = Rec->data[i];
        int pre = i - 1;
        while (pre >= 0 && Rec->data[pre] > now){
            Rec->data[pre+1] = Rec->data[pre];
            pre --;
        }
        Rec->data[pre+1] = now;
        print(Rec);
    } 
    
 /*-----end------*/

}

/*第二关
此处请填写代码实现递增序进行二分插入排序,
 
  实质是在已经有序的表中采用二分法查找插入位置
  要求每趟排序后 调用print函数，输出关键字的排列情况*/
void binInsertSort(  SortObject *Rec )
{
    cout<<"the result of binInsertSort:\n";
     /*----begin------*/
    for (int i = 1; i < Rec->NUM; i ++ ) {
        int now = Rec->data[i];
        int l = 0, r = i - 1;
        
        while (l < r) {
            int mid = (l + r) >> 1;
            if (Rec->data[mid] >= now) r = mid;
            else l = mid + 1;
        }
        if (Rec->data[l] >= now) {
            int pot = i - 1;
            while (pot >= l) Rec->data[pot+1] = Rec->data[pot], pot --;
            Rec->data[l] = now;
        }
        print(Rec);
    }
    
 
 /*-----end------*/

}



/*第三关
此处请填写代码实现递增序进行表插入排序,
  返回值是关键字比较次数
  Head是表头结点，不存放数据，info是待插入数据
  要求每趟排序后 调用printLink函数，输出关键字的排列情况
  */
void listSort(linkObject *plist )
{
    cout<<"the result of listSort:\n";
    /*----begin------*/
    auto head = plist;
    auto p = plist->next;
  
    head->next = NULL;
    for (; p != NULL; p = p->next){
      int now = p->info;
      auto tt = head->next;
      auto pt = head;
      for (; tt != NULL && tt->info <= now; pt = tt, tt = tt->next);
      
          auto tmp = new linkObject();
          tmp->info = now;
          pt->next = tmp;
          tmp->next = tt;  
   
      printLink(head);
    }
    
    /*-----end------*/

}

/*第四关
此处请填写代码实现递增序进行冒泡排序,
 要求每趟排序后 调用print函数，输出关键字的排列情况
  */
void bubbleSort(  SortObject *Rec )
{
    cout<<"the result of bubbleSort:\n";
    /*----begin------*/
    auto arr = Rec->data;
    for (int i = 0; i < Rec->NUM - 1; i ++){
        for (int j = 0; j < Rec->NUM - 1 - i; j ++)
            if (arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
        print(Rec);
    }
    /*-----end------*/

}

/*第五关
此处请填写代码实现递增序进行改进的冒泡排序,
 要求每趟排序后 调用print函数，输出关键字的排列情况
  */
void qbubbleSort(  SortObject *Rec )
{
    cout<<"the result of qbubbleSort:\n";
    /*----begin------*/
    auto arr = Rec->data;
    int shit = 0;
    for (int i = 0; i < Rec->NUM - 1; i ++){
        int flag = 0;
        for (int j = 0; j < Rec->NUM - 1 - i; j ++)
            if (arr[j] > arr[j+1]) swap(arr[j], arr[j+1]), flag ++;

        
        if (!flag) {
            if (!shit) print(Rec);
            break;
        }
        shit = max(shit, flag);
        print(Rec);
    }

    /*-----end------*/

}


/*第六关
此处请填写代码实现递增序进行选择排序,
 要求每趟排序后 调用print函数，输出关键字的排列情况
  */
void selectSort(  SortObject *Rec )
{
    cout<<"the result of selectSort:\n";
    /*----begin------*/
    auto arr = Rec->data;
    int cnt = 0;
    for (int i = 0; i < Rec->NUM; i ++){
        int min = i;
        for (int j = i + 1; j < Rec->NUM; j ++) {
            if (arr[min] > arr[j]) min = j;
        }
        swap(arr[i], arr[min]);
        if (cnt ++ == 5) break;
        print(Rec);
    }
    /*-----end------*/

}
