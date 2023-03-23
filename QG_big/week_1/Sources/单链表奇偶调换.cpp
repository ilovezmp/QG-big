#include <iostream>
#include <stdio.h>
#include <malloc.h>
 
using namespace std;

typedef struct LNode
{
    int data;
    struct LNode *next;
}
LNode, *LinkList;
 
int n;
 
void Init_LinkList(LinkList & L)
{
    L = (LinkList) malloc (sizeof(LNode));
    L->next = NULL;
}
 
void Creat_HLinkList(LinkList & L, int n)
{
    LNode *r = L;
    for(int i = 1; i <= n; i ++ )
    {
    	int x;
        scanf("%d", &x);
        LNode *s = (LinkList) malloc (sizeof(LNode));
        s->data = x;
        r->next = s;
        s->next = NULL;
        r = s;
        cout << "输入前的顺序为:" <<x ;
    }
}
 
void Change_LinkList(LinkList & L) //交换节点
{
    LNode *p = L->next;  int j = 0;
    while(p)
    {
        j ++;
        if(j % 2 == 1 && p->next != NULL)  swap(p->data, p->next->data);
        p = p->next;
    }
}
 
void Travers_LinkList(LinkList & L)
{
    LNode *p = L->next;
    while(p)
    {
        cout <<"表换后的顺序为:" << p->data << ' ';
        p = p->next;
    }
}
 
signed main()
{
    LNode *L;
    cout << "请输入链表的长度（后续的插入元素元素必须满足长度，如若不满足，程序不会结束！！！！)" << ":"; 
    cin >> n;
    Init_LinkList(L);
    Creat_HLinkList(L, n);
    Change_LinkList(L);
    Travers_LinkList(L);
}


