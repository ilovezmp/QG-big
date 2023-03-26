#include<iostream>
using namespace std;
#include "Stack.h"
 
void menu()
{
 cout << "***************************************************************************" << endl;
 cout << "***********************************1、入栈*********************************" << endl;
 cout << "***********************************2、出栈*********************************" << endl;
 cout << "***********************************3、取值*********************************" << endl;
 cout << "***********************************4、判空*********************************" << endl;
 cout << "***********************************5、求长*********************************" << endl;
 cout << "***********************************6、清空*********************************" << endl;
 cout << "***********************************7、销毁*********************************" << endl;
 cout << "***********************************8、打印*********************************" << endl;
 cout << "***********************************9、退出*********************************" << endl;
 cout << "***************************************************************************" << endl;
}
 
int main()
{
 LinkStack S;
 InitStack(S);
 int select;
 while (1)
 {
  system("CLS");//清屏操作
  menu();
  cout << "请输入菜单序号：" << endl;
  cin >> select;
  switch (select)
  {
  case 1://入栈
   Push(S);
   system("pause");//按任意键继续
   break;
  case 2://出栈
   Pop(S);
   system("pause");
   break;
  case 3://取值
   GetTop(S);
   system("pause");
   break;
  case 4://判断链栈是否为空
   StackEmpty(S);
   system("pause");
   break;
  case 5://求链栈的长度
   StackLength(S);
   system("pause");
   break;
  case 6://清空
   ClearStack(S);
   system("pause");
   break;
  case 7://销毁
   DestroyStack(S);
   system("pause");
   return 0;
   break;
  case 8://打印
   PrintStack(S);
   system("pause");
   break;
  case 9:
   cout << "欢迎下次使用!" << endl;//退出
   system("pause");
   return 0;
   break;
  default:
   cout << "菜单序号输入有误！" << endl;
   system("pause");
   break;
  }
 }
 system("pause");
 return 0;
}
