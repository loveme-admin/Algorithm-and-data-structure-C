#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef int ElemType;
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;

void InitList(LinkList* head)
{
	*head = (LNode*)malloc(sizeof(LNode));
	(*head)->data = 0;
	(*head)->next = NULL;
}

void InsertSortList(LinkList head) //关键函数
{
	int data = 0;
	LNode* temp = NULL;
	LNode* front = head;
	printf("Input Data:");
	scanf("%d", &data);
	temp = (LNode*)malloc(sizeof(LNode));
	temp->data = data;
	for (front = head; front->next && front->next->data > data; front = front->next);
	temp->next = front->next;
	front->next = temp;
}

void PrintList(LinkList head)
{
	head = head->next;
	while (head)
	{
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

int main(void)
{
	LNode* head = NULL;
	InitList(&head);
	while (1)
	{
		InsertSortList(head);
		PrintList(head);
	}
}