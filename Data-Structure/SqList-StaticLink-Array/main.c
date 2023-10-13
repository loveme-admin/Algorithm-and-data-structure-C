#include<stdio.h>
#include<stdlib.h>
#include"root.h"

//基本操作
Bool InitList(LNode*);                      //初始化线性表
Bool DestroyList(LNode*);                   //销毁线性表
//常用操作
Bool OrderElem(LNode*, EleType);            //末尾插入数据
Bool InsertElem(LNode*, int, EleType);      //按位插入元素
Bool DeleteElem(LNode*, int, EleType*);     //删除元素并返回值
int LocateElem(LNode*, EleType);            //按值查找元素
EleType GetElem(LNode*, int);               //按位查找元素
//辅助操作
Bool PrintList(LNode*);                     //打印线性表
Bool MenuList(LNode*, ScanfQueue*);         //菜单

Bool InitList(LNode* head)
{
	if (head == NULL)
		return FALSE;
	head->data = 0;
	head->next = -1;
	for (int i = 1; i < MAXSIZE; i++) {
		(head + i)->next = -2;
		(head + i)->data = 0;
	}
	return TRUE;
}

Bool DestroyList(LNode* head)
{
	if (head == NULL)
		return FALSE;
	head->data = 0;
	head->next = -1;
	for (int i = 1; i < MAXSIZE; i++) {
		(head + i)->next = -2;
		(head + i)->data = 0;
	}
	return TRUE;
}

Bool OrderElem(LNode* head, EleType data)
{
	if (head == NULL)
		return FALSE;
	if (head->data >= MAXSIZE-1)
		return FALSE;
	LNode *tail=head;
	LNode *temp=NULL;
	for (int i = 1; i < MAXSIZE; i++)
		if ((head + i)->next == -2)
		{
			temp = head + i;
			break;
		}
	for (; tail->next != -1; tail = head+tail->next);
	temp->data = data;
	temp->next = -1;
	tail->next = temp - head;
	head->data++;
	return TRUE;
}

Bool InsertElem(LNode* head, int num, EleType data)
{
	if (head == NULL)
		return FALSE;
	if (num<1 || num>=MAXSIZE-1)
		return FALSE;
	if (head->data >= MAXSIZE - 1)
		return FALSE;
	LNode* front = head;
	LNode* temp = NULL;
	for (int i = 1; i < MAXSIZE; i++)
		if ((head + i)->next == -2)
		{
			temp = head + i;
			break;
		}
	for (int i = 1; i < num; i++, front = head + front->next);
	temp->data = data;
	temp->next = front->next;
	front->next = temp - head;
	head->data++;
	return TRUE;
}

Bool DeleteElem(LNode* head, int num, EleType* data)
{
	if (head == NULL)
		return FALSE;
	if (num<1||num > head->data)
		return FALSE;
	LNode* front = head;
	int temp = -2;
	for (int i = 1; i < num; i++, front = head + front->next);
	temp =(head + front->next)->next;
	(head + front->next)->next = -2;
	front->next = temp;
	head->data--;
	return TRUE;
}

int LocateElem(LNode *head, EleType data)
{
	if (head == NULL)
		return FALSE;
	LNode* temp = head + head->next;
	int i = 0;
	for (i=1; temp->next != -1; i++,temp = head + temp->next)
	{
		if (temp->data == data)
			return i;
	}
	if (temp->data == data)
		return i;
	return FALSE;
}

EleType GetElem(LNode *head, int num)
{
	if (head == NULL)
		return FALSE;
	if (num<1 || num>head->data)
		return FALSE;
	LNode* temp = head + head->next;
	for (int i = 1; i < num; i++, temp = head + temp->next);
		return temp->data;
	return FALSE;
}

Bool PrintList(LNode *head)
{
	if(head == NULL)
		return FALSE;
	LNode *temp = head+head->next;
	for (; temp->next != -1; temp = head + temp->next)
	{
		printf("%2d ", temp->data);
	}
	printf("%2d ", temp->data);
	printf("\n");
	return TRUE;
}

Bool MenuList(LNode* head, ScanfQueue* queue)
{
	while (TRUE) {
		int num;
		printf("Input Num:");
		scanf("%d", &num);
		switch (num) {
		case 1: InitList(head); break;
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
			DeleteElem(head, queue->data[0], &(queue->data[0]));
			break;
		}
		case 5:
		{
			printf("Input data:");
			ScanfPackage(queue, 1);
			printf("%d\n", LocateElem(head, queue->data[0]));
			break;
		}
		case 6:
		{
			printf("Input locate:");
			ScanfPackage(queue, 1);
			printf("%d\n", GetElem(head, queue->data[0]));
			break;
		}
		case 7:
		{
			printf("Input data:");
			ScanfPackage(queue, 1);
			OrderElem(head,queue->data[0]);
			break;
		}
		case 101: PrintList(head); break;
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
	LNode list[MAXSIZE];
	ScanfQueue queue;
	HelpList();
	MenuList(list, &queue);
	return 0;
}