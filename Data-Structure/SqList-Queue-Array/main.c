#include<stdio.h>
#include<stdlib.h>
#include"root.h"

//基本操作
Bool InitList(SqQueue*);                      //初始化线性表
Bool DestroyList(SqQueue*);                   //销毁线性表
//常用操作
Bool InsertQueue(SqQueue*,EleType);           //入队列
Bool DeleteQueue(SqQueue*,EleType*);          //出队列
//辅助操作
Bool PrintList(SqQueue);                      //打印线性表
Bool MenuList(SqQueue*, ScanfQueue*);         //菜单

Bool InitList(SqQueue* list)
{
	if (list == NULL)
		return FALSE;
	for (int i = 0; i < MAXSIZE; i++)
		list->data[i] = 0;
	list->rear  = 0;
	list->front = 0;
	return TRUE;
}

Bool DestroyList(SqQueue* list)
{
	if (list == NULL)
		return FALSE;
	list->rear = 0;
	list->front = 0;
	return TRUE;
}

Bool InsertQueue(SqQueue* list, EleType data)
{
	if (list == NULL)
		return FALSE;
	if ((list->front+1)%MAXSIZE==list->rear)
		return FALSE;
	list->data[list->front] = data;
	list->front = (list->front + 1) % MAXSIZE;
	return TRUE;
}

Bool DeleteQueue(SqQueue* list, EleType* data)
{
	if (list == NULL)
		return FALSE;
	if (list->rear==list->front)
		return FALSE;
	*data = list->data[list->rear];
	list->rear = (list->rear + 1) % MAXSIZE;
	return TRUE;
}

Bool PrintList(SqQueue list)
{
	if (list.data == NULL)
		return FALSE;
	for (int i = list.rear; i != list.front; i=(i+1)%MAXSIZE)
		printf("%2d ", list.data[i]);
	printf("\n");
	return TRUE;
}

Bool MenuList(SqQueue* list, ScanfQueue* queue)
{
	while (TRUE) {
		int num;
		printf("Input Num:");
		scanf("%d", &num);
		switch (num) {
		case 1: InitList(list); break;
		case 2: DestroyList(list); break;
		case 3:
		{
			printf("Input data:");
			ScanfPackage(queue, 1);
			InsertQueue(list, queue->data[0]);
			break;
		}
		case 4:
		{
			queue->length++;
			DeleteQueue(list, &(queue->data[0]));
			printf("%d\n",queue->data[0]);
			break;
		}

		case 101: PrintList(*list); break;
		case 102: InitRandomList(list); break;
		case 0: HelpList(); break;
		case -1:return OK; break;
		default:printf("Num Error!\n");
		}
		printf("\n");
	}
}

int main(void)
{
	SqQueue list;
	ScanfQueue queue;
	HelpList();
	MenuList(&list, &queue);
	return 0;
}