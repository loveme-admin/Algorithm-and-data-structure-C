#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"root.h"

//��������
Bool InitRandomList(SqQueue*);           //�����ʼ��
Bool ScanfPackage(ScanfQueue*, int);    //�������
Bool HelpList();                        //�����˵�

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
	printf(" 1   ��ʼ���Ա� 2   �������Ա�\n");
	printf(" 3   �����     4   ������\n");
	printf(" 101 ��ӡ���Ա� 102 �����ʼ��\n");
	printf("-1   �˳����Ա� 0   �������Ա�\n");
	return TRUE;
}