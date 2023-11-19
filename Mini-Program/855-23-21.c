#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef char ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode* next;
}LNode,*LinkList;

typedef struct Stack{
	LNode * data;
	struct Stack* next;
}Stack;

void InitStack(Stack** head)
{
	*head = (Stack*)malloc(sizeof(Stack));
	(*head)->data = NULL;
	(*head)->next = NULL;
}

void Push(Stack *head, LNode* data)
{
	Stack* temp = NULL;
	temp = (Stack*)malloc(sizeof(Stack));
	temp->data = data;
	temp->next = head->next;
	head->next = temp;
}

void Pop(Stack *head, LNode** data)
{
	Stack* temp = NULL;
	temp = head->next;
	head->next = head->next->next;
	*data = temp->data;
	free(temp);
}

int IsEmpty(Stack *stack)
{
	if (stack->next == NULL)
		return 1;
	return 0;
}

void InitList(LinkList* head)
{
	*head = (LNode*)malloc(sizeof(LNode));
	(*head)->data = '\0';
	(*head)->next = NULL;
}

void HeadList(LinkList head)
{
	char data = '\0';
	LNode* temp = NULL;
	printf("Input Data:");
	while (1)
	{
		scanf("%c", &data);
		if (data == '\n')
			break;
		temp = (LNode*)malloc(sizeof(LNode));
		temp->data = data;
		temp->next = head->next;
		head->next = temp;
	}
}

void PrintList(LinkList head)
{
	head = head->next;
	while (head)
	{
		printf("%c ", head->data);
		head = head->next;
	}
	printf("\n");
}

int SelectElem(Stack* stack, LinkList head) //关键函数
{
	LNode* temp = head;
	int count = 0;
	int i = 0;
	while (temp)
	{
		Push(stack, temp);
		temp = temp->next;
	}
	printf("Input Count:");
	scanf("%d", &count);
	for (i = 0; i < count; i++)
		if (!IsEmpty(stack))
			Pop(stack, &temp);
		else
			break;
	if (i == count)
	{
		printf("%c", temp->data);
		return 1;
	}
	return 0;
}

int main(void)
{
	Stack* stack;
	LNode* head = NULL;
	InitList(&head);
	InitStack(&stack);
	HeadList(head);
	PrintList(head);
	SelectElem(stack, head);
}