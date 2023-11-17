#include<stdio.h>
#include<stdlib.h>
#include"root.h"
//基本操作
Bool InitList(LNode **,LNode**);                //初始化线性表
Bool DestoryList(LNode**);                      //销毁线性表
//常用操作
Bool InsertQueue(LNode**);                      //入队列
Bool DeleteQueue(LNode**,LNode**,EleType*);     //出队列
//辅助操作
Bool PrintList(LNode *);                        //打印线性表
Bool MenuList(LNode **,LNode**,ScanfQueue *);   //菜单

Bool InitList(LNode** head,LNode **tail)
{
	if (head == NULL)
		return FALSE;
	(*head) = (LNode*)malloc(sizeof(LNode));
	if (*head == NULL)
		return FALSE;
	(*head)->next = NULL;
	(*head)->data = 0;
	tail = head;
	return TRUE;
}

Bool DestroyList(LNode** head,LNode **tail)
{
	if (head == NULL)
		return FALSE;
	LNode* temp = *head;
	for (; temp != NULL; temp = *head)
	{
		(*head) = temp->next;
		free(temp);
	}
	*head = NULL;
	*tail = NULL;
	return TRUE;
}

Bool InsertQueue(LNode** tail)
{
	if (tail == NULL)
		return FALSE;
	LNode* temp = NULL;
	EleType data = 0;
	printf("Input Data:");
	scanf("%d", &data);
	temp = (LNode*)malloc(sizeof(LNode));
	if (temp == NULL)
		return FALSE;
	(* tail)->next = temp;
	temp->data = data;
	temp->next = NULL;
	*tail = (*tail)->next;
	return TRUE;
}

Bool DeleteQueue(LNode** head,LNode** tail, EleType *data)
{
	if (head == NULL)
		return FALSE;
	if ((*head)->next == NULL)
		return FALSE;
	LNode* temp = NULL;
	temp = (*head)->next;
	(*head)->next = (*head)->next->next;
	if ((*head)->next == NULL)
		*tail = *head;
	*data = temp->data;
	free(temp);
	(*head)->data--;
	return TRUE;
}

Bool PrintList(LNode* head)
{
	if (head == NULL)
		return FALSE;
	LNode* temp = head->next;
	for (; temp!= NULL; temp = temp->next)
	{
		printf("%2d ",temp->data);
	}
	return TRUE;
}

Bool MenuList(LNode** head, LNode** tail,ScanfQueue* queue)
{
	while (TRUE) {
		int num;
		printf("Input Num:");
		scanf("%d", &num);
		switch (num) {
		case 1: InitList(head,tail); break;
		case 2: DestroyList(head,tail); break;
		case 3:
		{
			InsertQueue(tail);
			break;
		}
		case 4:
		{
			queue->length++;
			DeleteQueue(head,tail, &(queue->data[0]));
			printf("%d\n", queue->data[0]);
			break;
		}
		case 101: PrintList(*head); break;
		case 102: InitRandomList(head,tail); break;
		case 0: HelpList(); break;
		case -1:return OK; break;
		default:printf("Num Error!\n");
		}
		printf("\n");
	}
}

int main(void)
{
	LNode* head = NULL;
	LNode* tail = NULL;
	ScanfQueue queue;
	HelpList();
	MenuList(&head,&tail,&queue);
	return 0;
}