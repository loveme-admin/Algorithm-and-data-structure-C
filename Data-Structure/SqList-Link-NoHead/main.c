#include<stdio.h>
#include<stdlib.h>
#include"root.h"
//基本操作
Bool DestoryList(LNode**);              //销毁线性表
//常用操作
Bool InsertTailList(LNode**);            //头插法建立线性表
Bool InsertHeadList(LNode**);            //尾插法建立线性表
Bool InsertElem(LNode**, int, EleType);  //按位插入元素
Bool DeleteElem(LNode**, int);           //删除元素并返回值
LNode* LocateElem(LNode*, EleType);     //按值查找元素
LNode* GetElem(LNode*, int);            //按位查找元素
//辅助操作
Bool PrintList(LNode *);                //打印线性表
Bool MenuList(LNode **,ScanfQueue *);   //菜单

Bool DestroyList(LNode** head)
{
	if (head == NULL)
		return FALSE;
	LNode* temp = *head;
	for (; temp != NULL; temp = *head)
	{
		(*head) = temp->next;
		free(temp);
	}
	return TRUE;
}

Bool InsertHeadList(LNode** head)
{
	if (head == NULL)
		return FALSE;
	LNode* temp = NULL;
	EleType data=0;
	printf("Input Data:");
	scanf("%d",&data);
	while (data != -1)
	{
		if (*head == NULL)
		{
			(*head) = (LNode*)malloc(sizeof(LNode));
			if (*head == NULL)
				return TRUE;
			(*head)->data = data;
			(*head)->next = NULL;
		}
		else {
			temp = (LNode*)malloc(sizeof(LNode));
			if (temp == NULL)
				return FALSE;
			temp->data = data;
			temp->next = *head;
			*head = temp;
		}
		scanf("%d", &data);
	}
	return TRUE;
}

Bool InsertTailList(LNode** head)
{
	if (head == NULL)
		return FALSE;
	LNode* temp = NULL;
	LNode* tail = NULL;
	EleType data = 0;
	printf("Input Data:");
	scanf("%d", &data);
	while (data != -1)
	{
		if (*head == NULL)
		{
			(*head) = (LNode*)malloc(sizeof(LNode));
			if (*head == NULL)
				return FALSE;
			(*head)->data = data;
			(*head)->next = NULL;
			tail = *head;
		}
		else {
			temp = (LNode*)malloc(sizeof(LNode));
			if (temp == NULL)
				return FALSE;
			tail->next = temp;
			temp->next = NULL;
			tail = tail->next;
			temp->data = data;
		}
		scanf("%d", &data);
	}
	return TRUE;
}

Bool InsertElem(LNode** head, int num, EleType data)
{
	if (head == NULL)
		return FALSE;
	if (num<1)
		return FALSE;
	LNode* temp = NULL;
	LNode* front = *head;
	if (num == 1)
	{
		temp = (LNode*)malloc(sizeof(LNode));
		if (temp == NULL)
			return FALSE;
		temp->data = data;
		temp->next = *head;
		(*head) = temp;
	}
	else {
		for (int i = 2; i < num; i++, front = front->next);
		temp = (LNode*)malloc(sizeof(LNode));
		if (temp == NULL)
			return FALSE;
		temp->data = data;
		temp->next = front->next;
		front->next = temp;
	}
	return TRUE;
}

Bool DeleteElem(LNode** head, int num)
{
	if (head == NULL)
		return FALSE;
	if (num < 1)
		return FALSE;
	LNode* temp = NULL;
	LNode* front = *head;
	if (num == 1)
	{
		temp = *head;
		(*head) = (*head)->next;
		free(temp);
	}
	else 
	{
		for (int i = 2; i < num; i++, front = front->next);
		temp = front->next;
		front->next = front->next->next;
		free(temp);
	}
	return TRUE;
}

LNode* LocateElem(LNode* head, EleType data)
{
	if (head == NULL)
		return FALSE;
	LNode* temp = head;
	for (; temp != NULL; temp = temp->next)
		if (temp->data == data)
			return temp;
	return FALSE;
}

LNode* GetElem(LNode* head , int num)
{
	if (head == NULL)
		return FALSE;
	if (num<1)
		return FALSE;
	LNode* temp = head;
	for (int i = 1; i < num; i++, temp = temp->next)
	return temp;
}

Bool PrintList(LNode* head)
{
	if (head == NULL)
		return FALSE;
	LNode* temp = head;
	for (; temp!= NULL; temp = temp->next)
	{
		printf("%2d ",temp->data);
	}
	return TRUE;
}

Bool MenuList(LNode** head, ScanfQueue* queue)
{
	while (TRUE) {
		int num;
		printf("Input Num:");
		scanf("%d", &num);
		switch (num) {
		case 1: break;
		case 2: DestroyList(head); break;
		case 3:
		{
			printf("Input locate and data:");
			ScanfPackage(queue, 2);
			InsertElem(head, queue->data[0], queue->data[1]);
			break;
		}
		case 4:
		{
			printf("Input locate:");
			ScanfPackage(queue, 1);
			DeleteElem(head, queue->data[0]);
			break;
		}
		case 5:
		{
			printf("Input data:");
			ScanfPackage(queue, 1);
			printf("%p\n", LocateElem(*head, queue->data[0]));
			break;
		}
		case 6:
		{
			printf("Input locate:");
			ScanfPackage(queue, 1);
			printf("%d\n", (GetElem(*head, queue->data[0]))->data);
			break;
		}
		case 7:
		{
			InsertHeadList(head);
			break;
		}
		case 8:
		{
			InsertTailList(head);
			break;
		}
		case 101: PrintList(*head); break;
		case 102: InitRandomList(head); break;
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
	ScanfQueue queue;
	HelpList();
	MenuList(&head,&queue);
	return 0;
}