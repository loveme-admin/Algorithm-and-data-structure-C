#include <stdio.h>
#include<stdlib.h>

typedef struct LNode {
	char data;
	struct LNode* next;
}LNode, * LinkList;

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

void SortList(LinkList head) //关键函数
{
	LNode* temp1 = head->next;
	LNode* temp2 = NULL;
	LNode* temp3 = NULL;
	char max = '\0';
	while (temp1)
	{
		max = temp1->data;
		temp3 = temp2 = temp1;
		while (temp2)
		{
			if (temp2->data > max)
			{
				temp3 = temp2;
				max = temp3->data;
			}
			temp2 = temp2->next;
		}
		temp3->data = temp1->data;
		temp1->data = max;
		temp1 = temp1->next;
	}
}

int main(void)
{
	LNode* head = NULL;
	InitList(&head);
	HeadList(head);
	PrintList(head);
	SortList(head);
	PrintList(head);
}