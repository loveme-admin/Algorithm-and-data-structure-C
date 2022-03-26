#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int ElemType;
typedef struct Node {
	ElemType data;
	struct Node* last;
	struct Node* next;
}ListNode;
ListNode* head = NULL;

void InitList(ListNode** head)
{
	ListNode* temp = NULL;
	temp = (ListNode*)malloc(sizeof(ListNode));
	(*head) = temp;
	(*head)->data = 0;
	temp->last = NULL;
	temp->next = NULL;
}
void LengthList(ListNode* head)
{
	printf("Length is:%d\n", head->data);
}
void PrintList(ListNode* head)
{
	ListNode* temp = head->next;
	printf("Data is:\n");
	while (temp->next!= NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("%d ", temp->data);
	printf("\n");
	while (temp->last != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->last;
	}
	printf("%d ", temp->data);
	printf("\n");
}
ListNode* CreateList(ListNode* head)
{
	ListNode* length = head;
	ListNode* temp = NULL;
	while (head->next != NULL)
		head = head->next;
	temp = (ListNode*)malloc(sizeof(ListNode));
	head->next = temp;
	temp->next = NULL;
	temp->last = head;
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
	InitList(&head);
	WriteList(CreateList(head));
	WriteList(CreateList(head));
	WriteList(CreateList(head));
	PrintList(head);
	LengthList(head);
}
