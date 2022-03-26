#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int ElemType;
typedef struct Node {
	ElemType data;
	struct Node* next;
}ListNode;
ListNode* head = NULL;
ListNode* tail = NULL;

void InitList(ListNode** head,ListNode** tail)
{
	ListNode* temp = NULL;
	temp = (ListNode*)malloc(sizeof(ListNode));
	(*head) = temp;
	(*tail) = temp;
	(*head)->data = 0;
	(*head)->next =(*head);
}
void LengthList(ListNode* head)
{
	printf("Length is:%d\n", head->data);
}
void PrintList(ListNode* head)
{
	ListNode* temp = head->next;
	printf("Data is:\n");
	while (temp != head)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
ListNode* CreateList(ListNode** tail)
{
	ListNode* length = (*tail)->next;
	ListNode* temp = NULL;
	temp = (ListNode*)malloc(sizeof(ListNode));
	temp->next = (*tail)->next;
	(*tail)->next = temp;
	(*tail) = temp;
	length->data++;
	return temp;
}
void WriteList(ListNode* head)
{
	printf("\n");
	printf("Input a Data:");
	scanf("%d", &head->data);
	printf("\n");
}
int main(void)
{
	InitList(&head, &tail);
	WriteList(CreateList(&tail));
	WriteList(CreateList(&tail));
	WriteList(CreateList(&tail));
	PrintList(head);
	LengthList(head);
}
