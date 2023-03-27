#include "linkstack.h"

int Priority(char ch)
{
	switch(ch)
	{
		case '(':
			return 3;
		case '*':
			return 2;
		case '/':
			return 2;
		case '+':
			return 1;
		case '-':
			return 1;
		default:
			return 0;
	}
}

int main()
{
	Stack s_num,s_opt;	//��������ջ������ջ  
	
	if (InitStack(&s_num) == FAILURE || InitStack(&s_opt) == FAILURE)
	{
		printf("��ʼ��ʧ�ܣ�\n");
		return -1;
	}
	
	char opt[128] = {0};
	int i = 0, tmp = 0, num1, num2;
	
	printf("��������ʽ������:\n");
	scanf("%s", opt);
	
	while (opt[i] != '\0' || EmptyStack(&s_opt) != SUCCESS) //���ʽ��Ϊ�ջ�ջ��Ϊ�վͼ��� 
	{
		if (opt[i] >= '0' && opt[i] <= '9')	//����λ�����֣����asc�� 
		{
			tmp = opt[i] - '0';
			i++;
			if (opt[i] < '0' || opt[i] > '9')	//����λ�������֣���tmp��ջ������λ�����ּ���ѭ�� 
			{
				push(&s_num, tmp);
				tmp = 0;
			}
		}
		else	//������ 
		{
			if (EmptyStack(&s_opt) == SUCCESS || Priority(opt[i]) > Priority(GetTop(&s_opt)) ||
				(GetTop(&s_opt) == '(') && (opt[i] != ')'))
			{
				push(&s_opt, opt[i]);
				i++;
				continue;	
			}
			
			if (GetTop(&s_opt) == '(' && opt[i] == ')')  
			{
				pop(&s_opt);
				i++;
				continue;
			}
			
			//�˴���ֱ����else�ж� 
			if (Priority(opt[i]) <= Priority(GetTop(&s_opt)) || ((opt[i] == ')') && GetTop(&s_opt) != ')') ||
				opt[i] == '\0' && EmptyStack(&s_opt) != SUCCESS)
			{
				switch(pop(&s_opt))
				{
					case '+':
						num1 = pop(&s_num);
						num2 = pop(&s_num);
						push(&s_num, num1 + num2);
						break;
					case '-':
						num1 = pop(&s_num);
						num2 = pop(&s_num);
						push(&s_num, num2 - num1);
						break;
					case '*':
						num1 = pop(&s_num);
						num2 = pop(&s_num);
						push(&s_num, num1 * num2);
						break;
					case '/':
						num1 = pop(&s_num);
						num2 = pop(&s_num);
						push(&s_num, num2 / num1);
						break;
				}
			}
		}
	}
	printf("%d\n", GetTop(&s_num));
	
	return 0;
}


