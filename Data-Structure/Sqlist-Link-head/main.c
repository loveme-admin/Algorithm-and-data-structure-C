#include<stdio.h>
#include<stdlib.h>
#include"root.h"

#include<time.h>

Bool InitSqList(LNode **);
Bool InsertTailSqList(LNode*);

Bool InitSqList(LNode** head)
{
	(*head) = (LNode*)malloc(sizeof(LNode));
	if (*head == NULL)
		return FALSE;
	(*head)->next = NULL;
	(*head)->data = 0;
	return TRUE;
}

Bool InsertTailLNode(LNode* head)
{
	if (head == NULL)
		return FALSE;
	LNode* temp = NULL;
	LNode* tail = head;
	EleType data = 0;
	printf("Input Data:");
	scanf("%d", &data);
	while (data != -1)
	{
		temp = (LNode*)malloc(sizeof(LNode));
		if (temp == NULL)
			return FALSE;
		tail->next = temp;
		temp->data = data;
		temp->next = NULL;
		tail = tail->next;
		head->data++;
		scanf("%d", &data);
	}
	return TRUE;
}

LNode * BuildLNodeAlter(LNode* head)
{
	LNode* temp = head;
	for (; temp->next != NULL; temp=temp->next);
	temp->next= (LNode*)malloc(sizeof(LNode));
	temp->next->next = NULL;
	head->data++;
	return temp->next;
}

void InputSqList(LNode* temp)
{
	printf("Input Data:");
	scanf("%d",&(temp->data));
}

void PrintSqList(LNode* head)
{
	LNode* temp = head->next;
	for (; temp!= NULL; temp = temp->next)
	{
		printf("%2d ",temp->data);
	}
}

void InsertLNode(LNode *head,int num)
{
	LNode* temp = head;
	LNode* temp2, *temp3;
	for (int i = 1; i < num; i++)
		temp=temp->next;
	temp2= (LNode*)malloc(sizeof(LNode));
	InputSqList(temp2);
	temp3=temp->next;
	temp->next = temp2;
	temp2->next = temp3;
	head->data++;
}

int main(void)
{
	LNode* head = NULL;
	LNode* temp = NULL;
	ScanfQueue queue;
	InitSqList(&head);
	InsertTailLNode(head);
	PrintSqList(head);
	return 0;
}