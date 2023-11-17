#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"root.h"

//辅助操作
Bool InitRandomList(SqQueue*);           //随机初始化
Bool ScanfPackage(ScanfQueue*, int);    //输入队列
Bool HelpList();                        //帮助菜单

Bool InitRandomList(SqQueue* list)
{
	if (list == NULL)
		return FALSE;
	int count;
	printf("Input Data Num:");
	scanf("%d", &count);
	srand((unsigned)time(NULL));
	for (int i = 0; i < count; i++)
		list->data[i] = rand() % RANDOM;
	list->rear = 0;
	list->front = count;
	return TRUE;
}

Bool ScanfPackage(ScanfQueue* queue, int num)
{
	if (queue == NULL)
		return FALSE;
	if (num<1 || num>MAXSIZE)
		return FALSE;
	for (int i = 0; i < num; i++)
		scanf("%d", &(queue->data[i]));
	queue->length = num;
	return TRUE;
}

Bool HelpList()
{
	printf(" 1   初始线性表 2   销毁线性表\n");
	printf(" 3   入队列     4   出队列\n");
	printf(" 101 打印线性表 102 随机初始化\n");
	printf("-1   退出线性表 0   帮助线性表\n");
	return TRUE;
}