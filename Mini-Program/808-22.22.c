#include <stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAXSIZE 20

typedef struct LNode {
	int data;
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
	LNode* temp = NULL;
	for (int i=0;i<MAXSIZE;i++)
	{
		temp = (LNode*)malloc(sizeof(LNode));
		temp->data = rand()%100;
		temp->next = head->next;
		head->next = temp;
	}
}

void PrintList(LinkList head)
{
	head = head->next;
	while (head)
	{
		printf("%4d ", head->data);
		head = head->next;
	}
	printf("\n");
}

void Union(LinkList head1, LinkList  head2, LinkList  head3) //关键函数
{
	head1 = head1->next;
	head2 = head2->next;
	LNode* temp = head2;
	while (head1)
	{
		temp = head2;
		while (temp)
		{
			if (head1->data == temp->data)
			{
				LNode* p = NULL;
				p = (LNode*)malloc(sizeof(LNode));
				p->data = temp->data;
				p->next = head3->next;
				head3->next = p;
			}
			temp = temp->next;
		}
		head1 = head1->next;
	}
}

int main(void)
{
	LNode* head1 = NULL;
	LNode* head2 = NULL;
	LNode* head3 = NULL;
	srand((unsigned)time);
	InitList(&head1);
	InitList(&head2);
	InitList(&head3);
	HeadList(head1);
	HeadList(head2);
	Union(head1, head2, head3);
	PrintList(head1);
	PrintList(head2);
	PrintList(head3);
}