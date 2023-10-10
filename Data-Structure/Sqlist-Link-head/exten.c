#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"root.h"

//��������
Bool InitRandomList(LNode*);            //�����ʼ��
Bool ScanfPackage(ScanfQueue*, int);    //�������
Bool HelpList();                        //�����˵�

Bool InitRandomList(LNode* list)
{
	if (list == NULL)
		return FALSE;
	int count;
	printf("Input Data Num:");
	scanf("%d", &count);
	srand((unsigned)time(NULL));
	//for (int i = 0; i < count; i++)
	//	list->data[i] = rand() % RANDOM;
	//list->length = count;
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
	printf(" 3   ��λ����ֵ 4   ��λɾ��ֵ\n");
	printf(" 5   ��ֵ����λ 6   ��λ����ֵ\n");
	printf(" 101 ��ӡ���Ա� 102 �����ʼ��\n");
	printf("-1   �˳����Ա� 0   �������Ա�\n");
	return TRUE;
}