#include<stdio.h>
#include<stdlib.h>
#include"root.h"

#include<time.h>

void InitSqList(LNode **);
LNode * BuildSqList(LNode*);
void InputSqList(LNode*);

void InitSqList(LNode** head)
{
	(*head) = (LNode*)malloc(sizeof(LNode));
	(*head)->next = NULL;
	(*head)->data = 0;
}

LNode* BuildLNode(LNode* head)
{
	LNode *temp = head->next;
	head->next = (LNode*)malloc(sizeof(LNode));
	head->next->next = temp;
	head->data++;
	return head->next;
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
	temp = BuildLNode(head);
	InputSqList(temp);
	temp=BuildLNodeAlter(head);
	InputSqList(temp);
	temp=BuildLNodeAlter(head);
	InputSqList(temp);
	temp=BuildLNode(head);
	InputSqList(temp);
	InsertLNode(head, 2);
	PrintSqList(head);
	return 0;
}