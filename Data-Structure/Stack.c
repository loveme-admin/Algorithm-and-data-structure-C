#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 10
typedef int ElemType;
typedef struct {
	ElemType stack[MAXSIZE];
	ElemType* top;
	ElemType* bottom;
	int length;
}Stack;
Stack *head;

void InitStack(Stack** head)
{
	(*head) = (Stack*)malloc(sizeof(Stack));
	(*head)->top = (*head)->stack;
	(*head)->bottom = (*head)->stack;
	(*head)->length = 0;
}

void PullStack(Stack* head)
{
	printf("Input Data:");
	scanf("%d", & (head->stack[head->length]));
	head->length++;
	head->top= head->stack  + head->length;
}
void PopStack(Stack* head)
{
	head->length--;
	printf("%d\n", head->stack[head->length]);
	head->top = head->stack + head->length;
}
void PrintStack(Stack* head)
{
	int i = 0;
	for (i = 0; i < head->length; i++)
		printf("%d ",head->stack[i]);
}

int main(void)
{
	InitStack(&head);
	PullStack(head);
	PullStack(head);
	PullStack(head);
	PullStack(head);
	PullStack(head);
	PopStack(head);
	PopStack(head);
	PrintStack(head);
}
