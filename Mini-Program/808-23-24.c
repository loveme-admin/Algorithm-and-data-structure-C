#include<stdio.h>  //关键程序
#include<stdlib.h>


typedef struct LNode{
	char data;
	struct LNode* next;
}Stack;

void InitStack(Stack** head)
{
	*head = (Stack*)malloc(sizeof(Stack));
	(*head)->data = '\0';
	(*head)->next = NULL;
}

void Push(Stack *head, char data)
{
	Stack* temp = NULL;
	temp = (Stack*)malloc(sizeof(Stack));
	temp->data = data;
	temp->next = head->next;
	head->next = temp;
}

void Pop(Stack *head, char* data)
{
	Stack* temp = NULL;
	temp = head->next;
	head->next = head->next->next;
	*data = temp->data;
	free(temp);
}

int IsEmpty(Stack* head)
{
	if (head->next == NULL)
		return 1;
	return 0;
}

void Tran(Stack* stack1, Stack* stack2, char* arr)
{
	char data;
	for (int i = 0; arr[i] != '\0'; i++)
		Push(stack1, arr[i]);
	while (!IsEmpty(stack1))
	{
		Pop(stack1, &data);
		if (data != '.')
			Push(stack2, data);
		else
		{
			while (!IsEmpty(stack2))
			{
				Pop(stack2, &data);
				printf("%c", data);
			}
			printf(".");
		}
	}
	while (!IsEmpty(stack2))
	{
		Pop(stack2, &data);
		printf("%c", data);
	}
}

int main(void)
{
	Stack *stack1;
	Stack *stack2;
	InitStack(&stack1);
	InitStack(&stack2);
	char arr[100];
	scanf("%s", arr);
	Tran(stack1, stack2, arr);
	return 0;
}