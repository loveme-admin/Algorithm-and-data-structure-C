#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"root.h"

//辅助操作
Bool InitRandomList(LNode**,LNode **);  //随机初始化
Bool ScanfPackage(ScanfQueue*, int);    //输入队列
Bool HelpList();                        //帮助菜单

Bool InitRandomList(LNode** head,LNode **tail)
{
	if (head == NULL)
		return FALSE;
	*head = (LNode*)malloc(sizeof(LNode));
	if (*head == NULL)
		return FALSE;
	(*head)->data = 0;
	(*head)->next = NULL;
	LNode* temp = NULL;
	int count=0;
	printf("Input Data Num:");
	scanf("%d", &count);
	srand((unsigned)time(NULL));
	for (int i = 1; i <= count; i++)
	{
		temp = (LNode*)malloc(sizeof(LNode));
		if (temp == NULL)
			return FALSE;
		temp->data = rand() % 100;
		temp->next = (*head)->next;
		(*head)->next = temp;
		(*head)->data++;
	}
	for (temp = *head; temp->next != NULL; temp = temp->next);
	*tail = temp;
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
	printf(" 3   入队列     4   出队列    \n");
	printf(" 101 打印线性表 102 随机初始化\n");
	printf("-1   退出线性表 0   帮助线性表\n");
	printf("-1   结束输入值\n");
	return TRUE;
}