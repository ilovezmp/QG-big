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
//��ʼ�� 
Status InitList(LinkedList *L) {
    LinkedList list;

    list = (LinkedList)malloc(sizeof(LNode));
    if(list == NULL)
    {
    	printf("�ڴ����ʧ��\n");
        return error;
    }
    list->next = NULL;
    *L = list;

    return success;
}

//����Ԫ�� 
Status InsertList(LNode *p, ElemType data) {
    LinkedList current = p;
    LinkedList newNode = (LinkedList)malloc(sizeof(LNode));

    if(newNode == NULL)
    {
        printf("�ڴ����ʧ��\n");
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
    printf("1.����һ��������\n");
    printf("2.����Ԫ��\n");
    printf("3.�ж������Ƿ�ɻ�\n");
    printf("4.�����м�Ԫ�ص�ֵ\n");
    printf("!!!!!�˳�������0 !!!!!\n");
    printf("�������Ӧ������(1-4):");
}

int judge_int(void)  //��ֹ�û��������������ַ�
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
            if(word[m]<'0' || word[m]>'9')  //�����Ƿ��������������ַ�
            {
                printf("������������");
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
    for(m=0;m<len;m++)  // ���ַ�����ת��Ϊ����
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
            case 1://����������
            {
                if(InitList(&head))
                {
                    printf("���������ɹ�\n");
                }
                else
                {
                    printf("��������ʧ��\n");
                }
                break;
            }
            case 2://��������
            {
                if(head == NULL)
                {
                    printf("����Ϊ�գ� ���ȴ�������\n");
                }
                else
                {
                    printf("���������ݣ�");
                    scanf("%d", &num);
                    if(InsertList(head, num))
                    {
                        printf("���ݲ���ɹ�\n");
                    }
                    else
                    {
                        printf("���ݲ���ʧ��\n");
                    }
                }
                break;
            }
            
            case 3://�ж������Ƿ�ɻ�
            {
                if(head == NULL || head->next == NULL)
                {
                    printf("����Ϊ��\n");
                }
                else
                {
                    if(IsLoopList(head))
                    {
                        printf("����ɻ�\n");
                    }
                    else
                    {
                        printf("����û�гɻ�\n");
                    }
                }
                break;
            }
            case 4://�����м���
            {
                if(head == NULL || head->next == NULL)
                {
                    printf("���ǿ�����\n");
                }
                else
                {
                    printf("�����м䴢���ֵΪ%d\n", (FindMidNode(head))->data);
                }
                break;
            }
            default:
            {
                printf("�������������֣�(1-4)\n");
                break;
            }
        }
    } while (choice != 0);
    
    return 0;
}

