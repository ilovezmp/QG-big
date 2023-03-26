
#define SElemType int
 
typedef struct StackNode
{
 SElemType data;//结点的数据域
 struct StackNode* next;//结点的指针域
}StackNode, * LinkStack;//LinkStack为指向结构体StackNode的指针类型
 
//链栈的初始化
void InitStack(LinkStack& S)
{
 //构造一个空栈，栈顶指针置空
 S = NULL;
}
 
//链栈的入栈
bool Push(LinkStack& S, SElemType e)
{
 //在栈顶插入元素e
 StackNode* p;
 p = new StackNode;
 p->data = e;
 p->next = S;
 S = p;//修改栈顶指针为p
 return true;
}
 
//链栈的出栈
bool Pop(LinkStack& S, SElemType &e)
{
 //删除栈顶元素，并用e返回其值
 if (S == NULL)
  return false;
 e = S->data;
 StackNode* p = S;//用p临时保存栈顶元素空间，以备释放
 S = S->next;
 delete p;//释放原栈顶元素空间
 return true;
}
 
//取栈顶元素
bool GetTop(LinkStack S, SElemType &e)
{
 //返回S的栈顶元素，不修改栈顶指针
 if (S == NULL)
  return false;//栈空，取值失败
 e = S->data;
 return true;
}
 

//1、入栈
void Push(LinkStack& S)
{
 
 SElemType e;
 bool flag;
 cout << "请输入要入栈的元素：" << endl;
 cin >> e;
 flag = Push(S, e);
 if (flag)
  cout << "入栈成功！" << endl;
 else
  cout << "入栈失败！" << endl;
}
 
//2、出栈
void Pop(LinkStack& S)
{
 SElemType e;
 bool flag;
 flag = Pop(S, e);
 if (flag)
  cout << "出栈元素为：" << e<<endl;
 else
  cout << "出栈失败！" << endl;
}
 
//3、取值
void GetTop(LinkStack S)
{
 SElemType e;
 bool flag;
 flag = GetTop(S, e);
 if (flag)
  cout << "取得的栈顶元素为：" << e << endl;
 else
  cout << "取栈顶元素失败！" << endl;
}
 
//4、判空
void StackEmpty(LinkStack S)
{
 if (S==NULL)
  cout << "链栈为空！" << endl;
 else
  cout << "链栈不为空！" << endl;
}
 
//5、求长
void StackLength(LinkStack S)
{
 int i = 0;
 while (S)//遍历链栈，统计结点数
 {
  i++;
  S = S->next;
 }
 cout << "链栈的长度为：" << i << endl;
}
 
//6、清空
void ClearStack(LinkStack &S)
{
 StackNode* p;
 while (S)//从栈顶开始，依次删除
 {
  p = S->next;
  delete S;
  S = p;
 }
}
 
//7、销毁
void DestroyStack(LinkStack& S)
{
 StackNode* p;
 while (S)//从栈顶开始，依次删除
 {
  p = S->next;
  delete S;
  S = p;
 }
 delete S;
}
 
//8、打印
void PrintStack(LinkStack S)
{
 int i=0;
 while (S)//遍历链栈
 {
  i++;
  cout << "链栈第" << i << "个数据为：" << S->data << endl;
  S = S->next;
 }
}
 