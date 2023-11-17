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

void DelElem(LinkList head, char emin, char emax)  //关键函数
{
	LNode* front = head;
	LNode* temp = head->next;
	while (temp != NULL)
	{
		if (temp->data >= emin && temp->data <= emax)
		{
			front->next = temp->next;
			free(temp);
			temp = front->next;
		}
		else
		{
			front=temp;
			temp = temp->next;
		}
	}
}

int main(void)
{
	LNode* head = NULL;
	InitList(&head);
	HeadList(head);
	PrintList(head);
	DelElem(head,'e','x');
	PrintList(head);
}