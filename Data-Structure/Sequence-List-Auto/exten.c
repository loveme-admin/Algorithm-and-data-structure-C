#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"root.h"

//辅助操作
Bool InitRandomList(SqList*);           //随机初始化
Bool ScanfPackage(ScanfQueue*, int);    //输入队列
Bool HelpList();                        //帮助菜单

Bool InitRandomList(SqList* list)
{
	if (list == NULL)
		return FALSE;
	list->data = (int*)malloc(sizeof(int) * MAXSIZE);
	int count;
	printf("Input Data Num:");
	scanf("%d", &count);
	srand((unsigned)time(NULL));
	for (int i = 0; i < count; i++)
		list->data[i] = rand() % RANDOM;
	list->length = count;
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
	printf(" 3   按位插入值 4   按位删除值\n");
	printf(" 5   按值查找位 6   按位查找值\n");
	printf(" 101 打印线性表 102 随机初始化\n");
	printf("-1   退出线性表 0   帮助线性表\n");
	return TRUE;
}