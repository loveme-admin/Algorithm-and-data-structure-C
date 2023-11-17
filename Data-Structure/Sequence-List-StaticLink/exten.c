#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"root.h"

//辅助操作
Bool InitRandomList(LNode*);            //随机初始化
Bool ScanfPackage(ScanfQueue*, int);    //输入队列
Bool HelpList();                        //帮助菜单

Bool InitRandomList(LNode* head)
{
	if (head == NULL)
		return FALSE;
	head->data = 0;
	head->next = -1;
	for (int i = 1; i < MAXSIZE; i++) {
		(head+i)->next = -2;
		(head+i)->data = 0;
	}
	int count=0;
	printf("Input Data Num:");
	scanf("%d", &count);
	srand((unsigned)time(NULL));
	for (int i = 1; i <= count; i++)
	{
		(head+i)->next = i + 1;
		(head+i)->data = rand() % 100;
	}
	(head + count)->next = -1;
	head->next = 1;
	head->data = count;
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
	printf(" 7   按顺序插入数据\n");
	printf(" 101 打印线性表 102 随机初始化\n");
	printf("-1   退出线性表 0   帮助线性表\n");
	return TRUE;
}