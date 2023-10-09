#include<stdio.h>
#include<stdlib.h>
#include"root.h"

#include<time.h>

void InitSqList(LNode **);
void BuildSqList(LNode*);
void InputSqList(LNode*);

void InitSqList(LNode** head)
{
	(*head) = (LNode*)malloc(sizeof(LNode));
	(*head)->next = NULL;
	(*head)->data = 0;
}

void BuildLNode(LNode* head)
{
	LNode *temp = head->next;
	head->next = (LNode*)malloc(sizeof(LNode));
	head->next->next = temp;
	InputSqList(head->next);
}

void BuildLNodeAlter(LNode* head)
{
	LNode* temp = head;
	for (; temp->next != NULL; temp=temp->next);
	temp->next= (LNode*)malloc(sizeof(LNode));
	temp->next->next = NULL;
	InputSqList(temp->next);
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

int main(void)
{
	LNode* head = NULL;
	ScanfQueue queue;
	InitSqList(&head);
	BuildLNode(head);
	BuildLNodeAlter(head);
	BuildLNodeAlter(head);
	BuildLNode(head);
	PrintSqList(head);
	return 0;
}