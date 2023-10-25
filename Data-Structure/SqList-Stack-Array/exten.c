#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"root.h"

//辅助操作
Bool InitRandomStack(SqStack*);           //随机初始化
Bool ScanfPackage(ScanfQueue*, int);    //输入队列
Bool HelpStack();                        //帮助菜单

Bool InitRandomStack(SqStack* stack)
{
	if (stack == NULL)
		return FALSE;
	int count;
	printf("Input Data Num:");
	scanf("%d", &count);
	srand((unsigned)time(NULL));
	for (int i = 0; i < count; i++)
		stack->data[i] = rand() % RANDOM;
	stack->top = count-1;
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

Bool HelpStack()
{
	printf(" 1   初始线性表 2   销毁线性表\n");
	printf(" 3   压栈       4   弹栈\n");
	printf(" 101 打印线性表 102 随机初始化\n");
	printf("-1   退出线性表 0   帮助线性表\n");
	return TRUE;
}