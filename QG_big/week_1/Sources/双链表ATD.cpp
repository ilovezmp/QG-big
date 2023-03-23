#include<bits/stdc++.h>
using namespace std;

typedef struct DNode{
    int data;
    struct DNode *prior,*next;
}DNode, *DLinkList;

//��ʼ��
void InitList(DLinkList &L){
    L = (DNode *)malloc(sizeof(DLinkList));
    L->prior = NULL;
    L->next = NULL;
}

//��������
void PrintList(DLinkList L){
    DNode *p = L->next;
    while(p){
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

//��˫����ĳ���
int Length(DLinkList L){
    DNode *p = L->next;
    int len = 0;
    while(p){
        len++;
        p = p->next;
    }
    return len;
}

//ͷ�巨����˫����
DLinkList HeadInsert(DLinkList &L){
    InitList(L); //��ʼ��
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

//β�巨����˫����
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

//��ֵ���ң�����x�������е�λ��
DNode *LocateElem(DLinkList L, int x){
    DNode *p = L->next;
    while(p && p->data != x){
        p = p->next;
    }
    return p;
}

//��λ���� 
DNode *GetElem(DLinkList L, int i){
    int j=1;
    DNode *p = L->next;
    if(i==0)return L;
    if(i<1)return NULL;
    while(p && j<i){
        p = p->next;
        j++;
    }
    return p; //���i���ڱ���p=NULL,ֱ�ӷ���p����
}

//��x���뵽˫����L��*p������һ�����
void Insert(DLinkList &L, DNode *p, int x){
    DNode *s = (DNode *)malloc(sizeof(DNode));
    s->data = x;
    s->next = p->next;
    p->next->prior = s;
    s->prior = p;
    p->next = s;
}

//ɾ������:��˫�����еĵ�i�����ɾ��
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

//�пղ���
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
     cout << "1.ͷ�巨����˫����   2.����˫����   3.β�巨����˫˫����   4.�жϵ������Ƿ�Ϊ��  5.��˫����ĳ���\n";
     cout << "6.��ָ��λ�ò���ָ��Ԫ��   7.��ֵ����  8.��λ����  9.ɾ��ָ��Ԫ��    0.�˳� \n";
     cout <<"����0��������˫����Ĳ���";
     do
     {
         cout << "������Ҫִ�еĲ���: ";
         cin >> i;
         switch (i)
         {
         case 1:
             int n;
             cout << "����������ĳ���: ";
             cin >> n;
            void Insert(DLinkList &L, DNode *p, int x);
             break;
         case 2:
            void PrintList(DLinkList L);
             break;
         case 3:
             cout << "����������ĳ���: ";
             cin >> n;
             DLinkList TailInsert(DLinkList &L);
             break;
			
         case 5:
             int Length(DLinkList L); 
             break;
         case 6:
             void Insert(DLinkList &L, DNode *p, int x);
             cout << "������Ҫ�����ֵ: ";
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



