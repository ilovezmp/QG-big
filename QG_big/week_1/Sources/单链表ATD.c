
 #include<iostream>
 using namespace std;
 typedef int DataType;
 #define Node ElemType
 #define ERROR NULL
 
 //����һ���ڵ���
 class Node
 {
 public:
     int data;     //������
     Node * next;  //ָ����
 };
 
 //����һ����������
 class LinkList
 {
 public:
     LinkList();                      //����һ��������;
     ~LinkList();                  //����һ��������;
     void CreateLinkList(int n);   //����һ��������
     void TravalLinkList();        //�������Ա�
     int GetLength();              //��ȡ���Ա���
     bool IsEmpty();               //�жϵ������Ƿ�Ϊ��
     ElemType * Find(DataType data); //���ҽڵ�
     void InsertElemAtEnd(DataType data);            //��β������ָ����Ԫ��
     void InsertElemAtIndex(DataType data,int n);    //��ָ��λ�ò���ָ��Ԫ��
     void InsertElemAtHead(DataType data);           //��ͷ������ָ��Ԫ��
     void DeleteElemAtEnd();       //��β��ɾ��Ԫ��
     void DeleteAll();             //ɾ����������
     void DeleteElemAtPoint(DataType data);     //ɾ��ָ��������
     void DeleteElemAtHead();      //��ͷ��ɾ���ڵ�
 private:
     ElemType * head;              //ͷ���
 };
 
 //��ʼ��������
 LinkList::LinkList()
 {
     head = new ElemType;
     head->data = 0;               //��ͷ������������Ϊ0
     head->next = NULL;            //ͷ������һ������ΪNULL
 }     
 
 //���ٵ�����
 LinkList::~LinkList()
 {
     delete head;                 //ɾ��ͷ���
 } 
 
 //����һ��������
 void LinkList::CreateLinkList(int n)
 {
     ElemType *pnew, *ptemp;
     ptemp = head;
     if (n < 0) {       //�������ֵ����ʱ�������쳣
         cout << "����Ľڵ��������" << endl;
     }
     for (int i = 1; i <= n;i++) {        //��ֵһ��һ�����뵥������
         pnew = new ElemType;
         cout << "�������" << i  << "��ֵ: " ;
         cin >> pnew->data;
         pnew->next = NULL;          //�½ڵ����һ����ַΪNULL
         ptemp->next = pnew;         //��ǰ������һ����ַ��Ϊ�½ڵ�
         ptemp = pnew;               //����ǰ�����Ϊ�½ڵ�
     }
 }
 
 //����������
 void LinkList::TravalLinkList()
 {
     if (head == NULL || head->next ==NULL) {
         cout << "����Ϊ�ձ�" << endl;
     }
     ElemType *p = head;                 //��ָ��ָ��ͷ���
     while (p->next != NULL)        //��ָ�����һ����ַ��Ϊ��ʱ��ѭ�����p��������
     {
         p = p->next;               //pָ��p����һ����ַ
         cout << p->data << " ";
     }
 }
 
 //��ȡ������ĳ���
 int LinkList::GetLength()
 {
     int count = 0;                  //����count����
     ElemType *p = head->next;           //����pָ��ͷ���
     while (p != NULL)                //��ָ�����һ����ַ��Ϊ��ʱ��count+1
     {
         count++;
         p = p->next;                //pָ��p����һ����ַ
     }
     return count;                   //����count������
 }
 
 //�жϵ������Ƿ�Ϊ��
 bool LinkList::IsEmpty()
 {
     if (head->next == NULL) {
         return true;
     }
     return false;
 }
 
 //���ҽڵ�
 ElemType * LinkList::Find(DataType data)
 {
     ElemType * p = head;
     if (p == NULL) {                           //��Ϊ�ձ�ʱ�����쳣
         cout << "������Ϊ������" << endl;
         return ERROR;
     }
     else
     {
         while (p->next != NULL)               //ѭ��ÿһ���ڵ�
         {
             if (p->data == data) {
                 return p;                     //����ָ����
             }
             p = p->next;
         }
         return NULL;                           //δ��ѯ�����
     }
 }
 
 //��β������ָ����Ԫ��
 void LinkList::InsertElemAtEnd(DataType data)
 {
     ElemType * newNode = new ElemType;    //����һ��Node���ָ��newNode
     newNode->next = NULL;         //����newNode���������ָ����
     newNode->data = data;
     ElemType * p = head;              //����ָ��pָ��ͷ���
     if (head == NULL) {           //��ͷ���Ϊ��ʱ������newNodeΪͷ���
         head = newNode;
     }
     else                          //ѭ��֪�����һ���ڵ㣬��newNode���������
     {
         while (p->next != NULL)
         {
             p = p->next;
         }
         p->next = newNode;
     }
 }
 
 //��ָ��λ�ò���ָ��Ԫ��
 void LinkList::InsertElemAtIndex(DataType data,int n)
 {
     if (n< 0|| n>GetLength())                   //���������쳣
         cout << "�����ֵ����" << endl;
     else
     {
         ElemType * ptemp = new ElemType;        //����һ���µĽڵ�
         ptemp->data = data;                     //����������
         ElemType * p = head;                    //����һ��ָ��ָ��ͷ���
         int i = 0;
         while (n > i)                           //������ָ����λ��
         {
             p = p->next;
             i++;
         }
         ptemp->next = p->next;                 //���½ڵ���뵽ָ��λ��
         p->next = ptemp;
     }
 }
 
 //��ͷ������ָ��Ԫ��
 void LinkList::InsertElemAtHead(DataType data)
 {
     ElemType * newNode = new ElemType;    //����һ��Node���ָ��newNode
     newNode->data = data;
     ElemType * p = head;              //����ָ��pָ��ͷ���
     if (head == NULL) {           //��ͷ���Ϊ��ʱ������newNodeΪͷ���
         head = newNode;
     }
     newNode->next = p->next;          //���½ڵ���뵽ָ��λ��
     p->next = newNode;
 }
 
 //��β��ɾ��Ԫ��
 void LinkList::DeleteElemAtEnd()
 {
     ElemType * p = head;          //����һ��ָ��ָ��ͷ���
     ElemType * ptemp = NULL;      //����һ��ռλ�ڵ�
     if (p->next == NULL) {        //�ж������Ƿ�Ϊ��
         cout << "�������" << endl;
     }
     else
     {
         while (p->next != NULL)   //ѭ����β����ǰһ��
         {
             ptemp = p;            //��ptempָ��β����ǰһ���ڵ�
             p = p->next;          //pָ�����һ���ڵ�
         }
         delete p;                //ɾ��β���ڵ�
         p = NULL;
         ptemp->next = NULL;
     }
 }
 
 //ɾ����������
 void LinkList::DeleteAll()
 {
     ElemType * p = head->next;
     ElemType * ptemp = new ElemType;
     while (p != NULL)                    //��ͷ������һ���ڵ����ɾ���ڵ�
     {
         ptemp = p;
         p = p->next;
         head->next = p;
         ptemp->next = NULL;
         delete ptemp;
     }
     head->next = NULL;                 //ͷ������һ���ڵ�ָ��NULL
 }
 
 //ɾ��ָ��������
 void LinkList::DeleteElemAtPoint(DataType data)
 {
     ElemType * ptemp = Find(data);    //���ҵ�ָ�����ݵĽڵ�λ��
     if (ptemp == head->next) {        //�ж��ǲ���ͷ������һ���ڵ㣬����Ǿʹ�ͷ��ɾ����
         DeleteElemAtHead();
     }
     else
     {
         ElemType * p = head;          //pָ��ͷ���
         while (p->next != ptemp)      //pѭ����ָ��λ�õ�ǰһ���ڵ�
         {
             p = p->next;
         }
         p->next = ptemp->next;         //ɾ��ָ��λ�õĽڵ�
         delete ptemp;
         ptemp = NULL;
     }
 
 }
 
 //��ͷ��ɾ���ڵ�
 void LinkList::DeleteElemAtHead()
 {
     ElemType * p = head;
     if (p == NULL || p->next == NULL) {   //�ж��Ƿ�Ϊ�ձ����쳣
         cout << "������Ϊ�ձ�" << endl;
     }
     else
     {
         ElemType * ptemp = NULL;      //����һ��ռλ�ڵ�
         p = p->next;
         ptemp = p->next;              //��ͷ�������¸��ڵ�ָ��ռλ�ڵ�
         delete p;                     //ɾ��ͷ������һ���ڵ�
         p = NULL;
         head->next = ptemp;           //ͷ����ָ�����
     }
 }
 
 //���Ժ���
 int main()
 {
     LinkList l;
     int i;
     cout << "1.����������   2.����������   3.��ȡ������ĳ���   4.�жϵ������Ƿ�Ϊ��   5.��ȡ�ڵ�\n";
     cout << "6.��β������ָ��Ԫ��   7.��ָ��λ�ò���ָ��Ԫ��   8.��ͷ������ָ��Ԫ��\n";
     cout<<"9.��β��ɾ��Ԫ��   10.ɾ������Ԫ��   11.ɾ��ָ��Ԫ��   12.��ͷ��ɾ��Ԫ��   0.�˳�" << endl;
     do
     {
         cout << "������Ҫִ�еĲ���: ";
         cin >> i;
         switch (i)
         {
         case 1:
             int n;
             cout << "�����뵥����ĳ���: ";
             cin >> n;
             l.CreateLinkList(n);
             break;
         case 2:
             l.TravalLinkList();
             break;
         case 3:
             cout << "�õ�����ĳ���Ϊ" << l.GetLength() << endl;
             break;
         case 4:
             if (l.IsEmpty() == 0)
                 cout << "�õ������ǿձ�" << endl;
             else
             {
                 cout << "�õ������ǿձ�" << endl;
             }
             break;
         case 5:
             DataType data;
             cout << "������Ҫ��ȡ�ڵ��ֵ: ";
             cin >> data;
             cout << "�ýڵ��ֵΪ" << l.Find(data)->data << endl;
             break;
         case 6:
             DataType endData;
             cout << "������Ҫ��β�������ֵ: ";
             cin >> endData;
             l.InsertElemAtEnd(endData);
             break;
         case 7:
             DataType pointData;
             int index;
             cout << "������Ҫ���������: ";
             cin >> pointData;
             cout << "������Ҫ�������ݵ�λ��: ";
             cin >> index;
             l.InsertElemAtIndex(pointData, index);
             break;
         case 8:
             DataType headData;
             cout << "������Ҫ��ͷ�������ֵ: ";
             cin >> headData;
             l.InsertElemAtHead(headData);
             break;
         case 9:
             l.DeleteElemAtEnd();
             break;
         case 10:
             l.DeleteAll();
             break;
         case 11:
             DataType pointDeleteData;
             cout << "������Ҫɾ��������: ";
             cin >> pointDeleteData;
             l.DeleteElemAtPoint(pointDeleteData);
             break;
         case 12:
             l.DeleteElemAtHead();
             break;
         default:
             break;
         }
     }while (i != 0);
 
     system("pause");
     return 0;
 }
