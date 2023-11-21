#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef int ElemType;
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;


void EnQueue(LinkList* tail, ElemType e)
{
	LNode* temp = NULL;
	if (*tail == NULL) 
	{
		*tail = (LNode*)malloc(sizeof(LNode));
		(*tail)->data = e;
		(*tail)->next = *tail;
	}
	else
	{
		temp= (LNode*)malloc(sizeof(LNode));
		temp->data = e;
		temp->next = (*tail)->next;
		(*tail)->next = temp;
		*tail = temp;
	}
}

void DeQueue(LinkList* tail, ElemType *e)
{
	LNode* temp = NULL;
	if ( (* tail)->next== *tail)
	{
		*e = (*tail)->data;
		free(*tail);
	}
	else
	{
		temp = (*tail)->next;
		*e = temp->data;
		(*tail)->next = (*tail)->next->next;
		free(temp);
	}
}

int main(void)
{
	LNode* head = NULL;
	ElemType e;
	EnQueue(&head, 1);
	EnQueue(&head, 2);
	EnQueue(&head, 3);
	DeQueue(&head, &e);
	printf("%d ",e);
	DeQueue(&head, &e);
	printf("%d ", e);
	DeQueue(&head, &e);
	printf("%d ", e);
}