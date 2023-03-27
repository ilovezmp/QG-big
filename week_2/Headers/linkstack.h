
#define LINKSTACK_H

#include <stdio.h> 
#include <stdlib.h>

#define SUCCESS 1000
#define FAILURE 1001

struct Node	//表示结点信息 
{
	int data;
	struct Node *next;
};
typedef struct Node Node;

struct Stack	//表示栈信息 
{
	Node *top;
	int length;
};
typedef struct Stack Stack;

int InitStack(Stack *stack);
int push(Stack *s, int num);
int GetTop(Stack *s);
int pop(Stack *s);
int EmptyStack(Stack *s);

int InitStack(Stack *s)
{
	if (NULL == s)
	{
		return FAILURE;
	}
	
	s->top = NULL;
	s->length = 0;	//表示空栈 
	
	return SUCCESS;
}

int push(Stack *s, int num)
{
	if (NULL == s)
	{
		return FAILURE;
	}
	
	Node *n = (Node *)malloc(sizeof(Node) * 1);
	if (NULL == n)
	{
		return FAILURE;
	}
	
	n->data = num;
	n->next = s->top;
	s->top = n;	//更新栈顶指针 
	s->length++;
	
	return SUCCESS;
}

int GetTop(Stack *s)
{
	if (NULL == s)
	{
		return FAILURE;
	}
	
	if (s->top == NULL)
	{
		return FAILURE;
	}
	
	return s->top->data;
}

int pop(Stack *s)
{
	if (NULL == s)
	{
		return FAILURE;
	}
	
	if (s->top == NULL)	//空栈不能出栈 
	{
		return FAILURE;
	}
	
	Node *n = s->top;
	int data = n->data;
	s->top = n->next;
	free(n);
	s->length--;

	return data;
}

int EmptyStack(Stack *s)
{
	if (NULL == s)
	{
		return FAILURE;
	}
	
	return (s->top == NULL) ? SUCCESS : FAILURE;
}




