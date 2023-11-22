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
		if (data == -1)
			break;
		temp = (LNode*)malloc(sizeof(LNode));
		temp->data = data;
		temp->next = head->next;
		head->next = temp;
	}
}

int AddList(LinkList head) //关键函数
{
	int num = 0;
	head = head->next;
	while (head)
	{
		num += head->data;
		head = head->next;
	}
	return num;
}


int main(void)
{
	LNode* head = NULL;
	InitList(&head);
	HeadList(head);
	printf("%d",AddList(head));
}