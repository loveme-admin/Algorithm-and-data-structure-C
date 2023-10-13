#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"root.h"

//��������
Bool InitRandomList(LNode*);            //�����ʼ��
Bool ScanfPackage(ScanfQueue*, int);    //�������
Bool HelpList();                        //�����˵�

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
	printf(" 1   ��ʼ���Ա� 2   �������Ա�\n");
	printf(" 3   ��λ����ֵ 4   ��λɾ��ֵ\n");
	printf(" 5   ��ֵ����λ 6   ��λ����ֵ\n");
	printf(" 7   ��˳���������\n");
	printf(" 101 ��ӡ���Ա� 102 �����ʼ��\n");
	printf("-1   �˳����Ա� 0   �������Ա�\n");
	return TRUE;
}