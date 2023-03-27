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
	Stack s_num,s_opt;	//定义数字栈、符号栈  
	
	if (InitStack(&s_num) == FAILURE || InitStack(&s_opt) == FAILURE)
	{
		printf("初始化失败！\n");
		return -1;
	}
	
	char opt[128] = {0};
	int i = 0, tmp = 0, num1, num2;
	
	printf("请输入表达式！！！:\n");
	scanf("%s", opt);
	
	while (opt[i] != '\0' || EmptyStack(&s_opt) != SUCCESS) //表达式不为空或栈不为空就继续 
	{
		if (opt[i] >= '0' && opt[i] <= '9')	//若下位是数字，求出asc码 
		{
			tmp = opt[i] - '0';
			i++;
			if (opt[i] < '0' || opt[i] > '9')	//若下位不是数字，将tmp入栈；若下位是数字继续循环 
			{
				push(&s_num, tmp);
				tmp = 0;
			}
		}
		else	//操作符 
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
			
			//此处可直接用else判断 
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


