#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"root.h"

//��������
Bool InitRandomStack(SqStack*);           //�����ʼ��
Bool ScanfPackage(ScanfQueue*, int);    //�������
Bool HelpStack();                        //�����˵�

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
	printf(" 1   ��ʼ���Ա� 2   �������Ա�\n");
	printf(" 3   ѹջ       4   ��ջ\n");
	printf(" 101 ��ӡ���Ա� 102 �����ʼ��\n");
	printf("-1   �˳����Ա� 0   �������Ա�\n");
	return TRUE;
}