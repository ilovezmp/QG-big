#include<iostream>
using namespace std;
#include "queue.h"
void menu()
{
 cout << "***************************************************************************" << endl;
 cout << "***********************************1、入队*********************************" << endl;
 cout << "***********************************2、出队*********************************" << endl;
 cout << "***********************************3、判满*********************************" << endl;
 cout << "***********************************4、判空*********************************" << endl;
 cout << "***********************************5、访问队头***************************** "<< endl;
 cout << "***********************************6、清空*********************************" << endl;
 cout << "***********************************7、销毁*********************************" << endl;
 cout << "***********************************8、打印遍历*********************************" << endl;
 cout << "***********************************9、退出*********************************" << endl;
 cout << "****************************************************************************"<<endl;
}
int main()
{
    ypedef struct Aqueue
{
    void *data[MAXQUEUE];//泛型的数据域
    int front;
    int rear;
    size_t length;//队列的长度
    //一个节点可以存放不同的数据类型
    int type[MAXQUEUE];
}AQueue;
void InitAQueue(AQueue *Q);
int select;
 while (1)
 {
  system("CLS");//清屏操作
  menu();
  cout << "请输入菜单序号：" << endl;
  cin >> select;
  switch (select)
  {
  case 1://入队
   Status EnAQueue(AQueue *Q, void *data);
   system("pause");//按任意键继续
   break;
  case 2://出队
   Status popAQueue(AQueue *Q);
   system("pause");
   break;
  case 3://判满
   Status IsFullAQueue(const AQueue *Q);
   system("pause");
   break;
  case 4://判断队列是否为空
   Status IsEmptyAQueue(const AQueue *Q);
   system("pause");
   break;
  case 5://取头
   Status GetHeadAQueue(AQueue *Q, void *e);
   system("pause");
   break;
  case 6://清空
   void ClearAQueue(AQueue *Q);
   system("pause");
   break;
  case 7://销毁
   void DestoryAQueue(AQueue *Q);
   system("pause");
   return 0;
   break;
  case 8://打印  
   Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q, int typeData));
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
