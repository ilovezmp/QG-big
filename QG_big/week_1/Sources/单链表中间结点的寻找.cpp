#include <iostream>
#include <stdio.h>
#include <malloc.h>
 
using namespace std;

typedef struct LNode 
{
    int data;
    struct LNode *next;
}LNode, *LinkList;
	int x;
void Init_LinkList(LinkList & L)//初始化 
{
    L = (LinkList) malloc (sizeof(LNode));
    L->next = NULL;
}
void Creat_HLinkList(LinkList & L)
{
    LNode *r = L;
    while( x!=0)
    {
    	int x;
        scanf("%d", &x);
        LNode *s = (LinkList) malloc (sizeof(LNode));
        s->data = x;
        r->next = s;
        s->next = NULL;
        r = s;
    }
}
void Find_Mi_Improve()
{
    struct Node *Fast ;
    struct Node *Slow ;
    while (Fast->next!=NULL)
    {
        if (Fast->next->next!=NULL)
        {
            Fast=Fast->next->next;
        }
        else
        {
            Fast=Fast->next;
        }
        Slow=Slow->next;
    }
    printf("%d\n",Slow->a);
}

signed main()
{
    LNode *L;
    cout << "请输入元素（当输入0结束输入元素）"; 
    Init_LinkList(L);
    Creat_HLinkList(L);
    void Find_Mi_Improve();
}



