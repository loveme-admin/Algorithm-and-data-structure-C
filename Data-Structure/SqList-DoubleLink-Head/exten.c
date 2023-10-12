#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"root.h"

//��������
Bool InitRandomList(LNode**);            //�����ʼ��
Bool ScanfPackage(ScanfQueue*, int);    //�������
Bool HelpList();                        //�����˵�

Bool InitRandomList(LNode** head)
{
	if (head == NULL)
		return FALSE;
	*head = (LNode*)malloc(sizeof(LNode));
	if (*head == NULL)
		return FALSE;
	(*head)->data = 0;
	(*head)->next = NULL;
	(*head)->front = NULL;
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
		temp->front = *head;
		if(temp->next!=	NULL)
			temp->next->front = temp;
		(*head)->data++;
	}
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
	printf(" 7   ͷ�彨���� 8   β�彨����\n");
	printf(" 101 ��ӡ���Ա� 102 �����ʼ��\n");
	printf("-1   �˳����Ա� 0   �������Ա�\n");
	printf("-1   ��������ֵ\n");
	return TRUE;
}