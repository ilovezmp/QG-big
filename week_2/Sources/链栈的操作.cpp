#include<iostream>
using namespace std;
#include "Stack.h"
 
void menu()
{
 cout << "***************************************************************************" << endl;
 cout << "***********************************1����ջ*********************************" << endl;
 cout << "***********************************2����ջ*********************************" << endl;
 cout << "***********************************3��ȡֵ*********************************" << endl;
 cout << "***********************************4���п�*********************************" << endl;
 cout << "***********************************5����*********************************" << endl;
 cout << "***********************************6�����*********************************" << endl;
 cout << "***********************************7������*********************************" << endl;
 cout << "***********************************8����ӡ*********************************" << endl;
 cout << "***********************************9���˳�*********************************" << endl;
 cout << "***************************************************************************" << endl;
}
 
int main()
{
 LinkStack S;
 InitStack(S);
 int select;
 while (1)
 {
  system("CLS");//��������
  menu();
  cout << "������˵���ţ�" << endl;
  cin >> select;
  switch (select)
  {
  case 1://��ջ
   Push(S);
   system("pause");//�����������
   break;
  case 2://��ջ
   Pop(S);
   system("pause");
   break;
  case 3://ȡֵ
   GetTop(S);
   system("pause");
   break;
  case 4://�ж���ջ�Ƿ�Ϊ��
   StackEmpty(S);
   system("pause");
   break;
  case 5://����ջ�ĳ���
   StackLength(S);
   system("pause");
   break;
  case 6://���
   ClearStack(S);
   system("pause");
   break;
  case 7://����
   DestroyStack(S);
   system("pause");
   return 0;
   break;
  case 8://��ӡ
   PrintStack(S);
   system("pause");
   break;
  case 9:
   cout << "��ӭ�´�ʹ��!" << endl;//�˳�
   system("pause");
   return 0;
   break;
  default:
   cout << "�˵������������" << endl;
   system("pause");
   break;
  }
 }
 system("pause");
 return 0;
}
