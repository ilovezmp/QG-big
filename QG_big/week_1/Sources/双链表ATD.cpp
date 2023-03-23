#include<bits/stdc++.h>
using namespace std;

typedef struct DNode{
    int data;
    struct DNode *prior,*next;
}DNode, *DLinkList;

//初始化
void InitList(DLinkList &L){
    L = (DNode *)malloc(sizeof(DLinkList));
    L->prior = NULL;
    L->next = NULL;
}

//遍历操作
void PrintList(DLinkList L){
    DNode *p = L->next;
    while(p){
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

//求双链表的长度
int Length(DLinkList L){
    DNode *p = L->next;
    int len = 0;
    while(p){
        len++;
        p = p->next;
    }
    return len;
}

//头插法建立双链表
DLinkList HeadInsert(DLinkList &L){
    InitList(L); //初始化
    int x;
    cin>>x;
    while(x!=0){
        DNode *s = (DNode *)malloc(sizeof(DNode));
        s->data = x;
        if(L->next == NULL){
            s->next = NULL;
            s->prior = L;
            L->next = s;
        }else{
            for(int i=0;i<x;i++)
		{
			s->next = L->next;
            L->next->prior = s;
            s->prior = L;
            L->next = s;
		} 
        	 }
        
    }
    return L;
}

//尾插法建立双链表
DLinkList TailInsert(DLinkList &L){
    InitList(L);
    DNode *s,*r=L;
    int x;
    cin>>x;
    while(x!=0){
        s = (DNode *)malloc(sizeof(DNode));
        s->data = x;
        s->next = NULL;
        s->prior = r;
        r->next = s;
        r = s;
        cin>>x;
    }
    return L;
}

//按值查找：查找x在链表中的位置
DNode *LocateElem(DLinkList L, int x){
    DNode *p = L->next;
    while(p && p->data != x){
        p = p->next;
    }
    return p;
}

//按位查找 
DNode *GetElem(DLinkList L, int i){
    int j=1;
    DNode *p = L->next;
    if(i==0)return L;
    if(i<1)return NULL;
    while(p && j<i){
        p = p->next;
        j++;
    }
    return p; //如果i大于表长，p=NULL,直接返回p即可
}

//将x插入到双链表L中*p结点的下一个结点
void Insert(DLinkList &L, DNode *p, int x){
    DNode *s = (DNode *)malloc(sizeof(DNode));
    s->data = x;
    s->next = p->next;
    p->next->prior = s;
    s->prior = p;
    p->next = s;
}

//删除操作:将双链表中的第i个结点删除
void Delete(DLinkList &L, int i){
    if(i<1 || i>Length(L)){
        cout<<"delete failed: index is wrong."<<endl;
        return;
    }
    DNode *p = GetElem(L,i-1);
    DNode *q = p->next;
    p->next = q->next;
    q->next->prior = p;
    free(q);
}

//判空操作
bool Empty(DLinkList L){
    if(L->next == NULL){
        cout<<"L is null"<<endl;
        return true;
    }else{
        cout<<"L is not null"<<endl;
        return false;
    }
}


int main()
{
    void InitList(DLinkList &L); 
     int i ;
     cout << "1.头插法创建双链表   2.遍历双链表   3.尾插法创建双双链表   4.判断单链表是否为空  5.求双链表的长度\n";
     cout << "6.在指定位置插入指定元素   7.按值查找  8.按位查找  9.删除指定元素    0.退出 \n";
     cout <<"输入0结束创建双链表的操作";
     do
     {
         cout << "请输入要执行的操作: ";
         cin >> i;
         switch (i)
         {
         case 1:
             int n;
             cout << "请输入链表的长度: ";
             cin >> n;
            void Insert(DLinkList &L, DNode *p, int x);
             break;
         case 2:
            void PrintList(DLinkList L);
             break;
         case 3:
             cout << "请输入链表的长度: ";
             cin >> n;
             DLinkList TailInsert(DLinkList &L);
             break;
			
         case 5:
             int Length(DLinkList L); 
             break;
         case 6:
             void Insert(DLinkList &L, DNode *p, int x);
             cout << "请输入要插入的值: ";
             break;
         case 7:
             DNode *LocateElem(DLinkList L, int x);
             break;
         case 8:
             DNode *GetElem(DLinkList L, int i);
             break;
         case 9:
             void Delete(DLinkList &L, int i);
             break;
         }
     }while (i != 0);
 
     system("pause");
     return 0;
    
}



