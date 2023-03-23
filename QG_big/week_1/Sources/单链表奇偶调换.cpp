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
        cout << "����ǰ��˳��Ϊ:" <<x ;
    }
}
 
void Change_LinkList(LinkList & L) //�����ڵ�
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
        cout <<"�����˳��Ϊ:" << p->data << ' ';
        p = p->next;
    }
}
 
signed main()
{
    LNode *L;
    cout << "����������ĳ��ȣ������Ĳ���Ԫ��Ԫ�ر������㳤�ȣ����������㣬���򲻻������������)" << ":"; 
    cin >> n;
    Init_LinkList(L);
    Creat_HLinkList(L, n);
    Change_LinkList(L);
    Travers_LinkList(L);
}


