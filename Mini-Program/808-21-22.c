#include<stdio.h>      //关键程序
#include<string.h>

#define MAXSIZE 20

typedef struct {
	char arr[MAXSIZE];
	int top;
}Stack,List;

void InitStack(Stack* stack)
{
	stack->top = 0;
}

void Push(Stack* stack,char data)
{
	if (stack->top > MAXSIZE)
		return;
	stack->arr[stack->top++] = data;
}

void Pop(Stack* stack, char* data)
{
	if (stack->top <= 0)
		return;
	*data = stack->arr[--stack->top];
}

int IsEmpty(Stack* stack)
{
	if (stack->top == 0)
		return 1;
	return 0;
}

int main(void)
{
	Stack stack;
	InitStack(&stack);

	char data[100];
	printf("Input Data:");
	scanf("%s", data);
	for (int i = 0; i <strlen(data); i++)
	{
		char temp = 0;
		if (data[i] == '(')
			Push(&stack, data[i]);
		else
		{
			Pop(&stack, &temp);
			if (temp !='(')
			{
				Push(&stack, data[i]);
			}
		}
	}
	if (!IsEmpty(&stack) )
	{
		printf("NO!");
		return 3;
	}
	else
		printf("YES!");
	return 0;
}
