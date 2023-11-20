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

void HeadList(LinkList head)
{
	int data = 0;
	LNode* temp = NULL;
	printf("Input Data:");
	while (1)
	{
		scanf("%d", &data);
		if (data == -99)
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
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

void DeleteElem(LinkList head, ElemType e) //关键函数
{
	LNode* front = head;
	LNode* temp = head->next;
	while (temp)
		if (temp->data == e)
		{
			front->next = temp->next;
			free(temp);
			temp = front->next;
		}
		else
		{
			front = front->next;
			temp = temp->next;
		}
}

int main(void)
{
	LNode* head = NULL;
	InitList(&head);
	HeadList(head);
	PrintList(head);
	DeleteElem(head,1);
	PrintList(head);
}