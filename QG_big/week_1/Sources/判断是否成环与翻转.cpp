#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkedList;
typedef enum Status{
    error,
    success
} Status;
Status InsertList(LNode *p, ElemType data);
Status IsLoopList(LinkedList L);
LNode* FindMidNode(LinkedList L);
void show(void);
int judge_int(void);
//初始化 
Status InitList(LinkedList *L) {
    LinkedList list;

    list = (LinkedList)malloc(sizeof(LNode));
    if(list == NULL)
    {
    	printf("内存分配失败\n");
        return error;
    }
    list->next = NULL;
    *L = list;

    return success;
}

//插入元素 
Status InsertList(LNode *p, ElemType data) {
    LinkedList current = p;
    LinkedList newNode = (LinkedList)malloc(sizeof(LNode));

    if(newNode == NULL)
    {
        printf("内存分配失败\n");
        return error;
    }
    newNode->data = data;
    newNode->next = NULL;
    while(current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
    return success;
}



LNode* FindMidNode(LinkedList L) {
    LinkedList slow = L, fast = L;
    while(fast != NULL && slow != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Status IsLoopList(LinkedList L) {
    LinkedList fast = L, slow = L;
    while(fast->next != NULL && slow->next != NULL)
    {
        slow = slow->next;
        if((fast = fast->next->next) == NULL)
        return error;
        if(fast == slow)
        return success;
    }
    return error;
}

void show(void)
{
    printf("1.创建一个空链表\n");
    printf("2.插入元素\n");
    printf("3.判断链表是否成环\n");
    printf("4.查找中间元素的值\n");
    printf("!!!!!退出请输入0 !!!!!\n");
    printf("请输入对应的数字(1-4):");
}

int judge_int(void)  //防止用户乱输入其他的字符
{
    int len, num = 0, arg = 1;
    char word[10];  
    int m, j= 1, k;
    while(j)
    {
        scanf("%s", word);
        len = strlen(word);
        for(m = 0;m<len;m++)
        {
            if(word[m]<'0' || word[m]>'9')  //检验是否有乱输入其他字符
            {
                printf("请输入整数：");
                break;
            }
            else 
            {
                if(m == len-1)
                    j = 0;
            }
        }
    }
    j = len-1;
    for(m=0;m<len;m++)  // 将字符重新转换为数字
    {
        for(k=0;k<j;k++)
            arg *= 10;
        num += (word[m]-'0')*arg;
        arg = 1;
        j--;
    }
    return num;
} 

int main(void)
{
    int choice, num = 0;
    LinkedList head = NULL;

    do
    {
        show();
        choice = judge_int();
        system("cls");
        switch(choice)
        {
            case 1://创建空链表
            {
                if(InitList(&head))
                {
                    printf("空链表创建成功\n");
                }
                else
                {
                    printf("空链表创建失败\n");
                }
                break;
            }
            case 2://插入数据
            {
                if(head == NULL)
                {
                    printf("链表为空， 请先创建链表\n");
                }
                else
                {
                    printf("请输入数据：");
                    scanf("%d", &num);
                    if(InsertList(head, num))
                    {
                        printf("数据插入成功\n");
                    }
                    else
                    {
                        printf("数据插入失败\n");
                    }
                }
                break;
            }
            
            case 3://判断链表是否成环
            {
                if(head == NULL || head->next == NULL)
                {
                    printf("链表为空\n");
                }
                else
                {
                    if(IsLoopList(head))
                    {
                        printf("链表成环\n");
                    }
                    else
                    {
                        printf("链表没有成环\n");
                    }
                }
                break;
            }
            case 4://查找中间结点
            {
                if(head == NULL || head->next == NULL)
                {
                    printf("这是空链表\n");
                }
                else
                {
                    printf("链表中间储存的值为%d\n", (FindMidNode(head))->data);
                }
                break;
            }
            default:
            {
                printf("请重新输入数字！(1-4)\n");
                break;
            }
        }
    } while (choice != 0);
    
    return 0;
}

