#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode* next;
}LNode,*LinkList;

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

void DeleteElem(LinkList head) //关键函数
{
	LNode* temp1 = head->next;
	LNode* front = NULL;
	LNode* temp2 = NULL;
	while (temp1)
	{
		front = temp1;
		temp2 = temp1 -> next;
		while (temp2)
		{
			if (temp1->data == temp2->data || temp1->data == -temp2->data)
			{
				front->next = temp2->next;
				free(temp2);
				temp2 = front->next;
			}
			else
			{
				front = front->next;
				temp2 = temp2->next;
			}
		}
		temp1 = temp1->next;
	}
}

int main(void)
{
	LNode* head = NULL;
	InitList(&head);
	HeadList(head);
	PrintList(head);
	DeleteElem(head);
	PrintList(head);
}