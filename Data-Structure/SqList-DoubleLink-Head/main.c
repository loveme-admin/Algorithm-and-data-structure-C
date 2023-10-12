#include<stdio.h>
#include<stdlib.h>
#include"root.h"
//��������
Bool InitList(LNode **);                //��ʼ�����Ա�
Bool DestoryList(LNode**);              //�������Ա�
//���ò���
Bool InsertTailList(LNode*);            //ͷ�巨�������Ա�
Bool InsertHeadList(LNode*);            //β�巨�������Ա�
Bool InsertElem(LNode*, int, EleType);  //��λ����Ԫ��
Bool DeleteElem(LNode*, int);           //ɾ��Ԫ�ز�����ֵ
LNode* LocateElem(LNode*, EleType);     //��ֵ����Ԫ��
LNode* GetElem(LNode*, int);            //��λ����Ԫ��
//��������
Bool PrintList(LNode *);                //��ӡ���Ա�
Bool MenuList(LNode **,ScanfQueue *);   //�˵�

Bool InitList(LNode** head)
{
	if (head == NULL)
		return FALSE;
	(*head) = (LNode*)malloc(sizeof(LNode));
	if (*head == NULL)
		return FALSE;
	(*head)->next = NULL;
	(*head)->data = 0;
	return TRUE;
}

Bool DestroyList(LNode** head)
{
	if (head == NULL)
		return FALSE;
	LNode* temp = *head;
	for (; temp != NULL; temp = *head)
	{
		(*head) = temp->next;
		free(temp);
	}
	return TRUE;
}

Bool InsertHeadList(LNode* head)
{
	if (head == NULL)
		return FALSE;
	LNode* temp = NULL;
	EleType data=0;
	printf("Input Data:");
	scanf("%d",&data);
	while (data != -1)
	{
		temp = (LNode*)malloc(sizeof(LNode));
		if (temp == NULL)
			return FALSE;
		temp->data = data;
		temp->next = head->next;
		head->next = temp;
		head ->data++;
		scanf("%d",&data);
	}
	return TRUE;
}

Bool InsertTailList(LNode* head)
{
	if (head == NULL)
		return FALSE;
	LNode* temp = NULL;
	LNode* tail = head;
	EleType data = 0;
	printf("Input Data:");
	scanf("%d", &data);
	while (data != -1)
	{
		temp = (LNode*)malloc(sizeof(LNode));
		if (temp == NULL)
			return FALSE;
		tail->next = temp;
		temp->data = data;
		temp->next = NULL;
		tail = tail->next;
		head->data++;
		scanf("%d", &data);
	}
	return TRUE;
}

Bool InsertElem(LNode* head, int num, EleType data)
{
	if (head == NULL)
		return FALSE;
	if (num<1 || num>head->data)
		return FALSE;
	LNode* front = head;
	LNode* temp = NULL;
	for (int i = 1; i < num; i++, front = front->next);
	temp = (LNode*)malloc(sizeof(LNode));
	if (temp == NULL)
		return FALSE;
	temp->data = data;
	temp->next = front->next;
	front->next = temp;
	return TRUE;
}

Bool DeleteElem(LNode* head, int num)
{
	if (head == NULL)
		return FALSE;
	if (num < 1 || num >head->data)
		return FALSE;
	LNode* front = head;
	LNode* temp = NULL;
	for (int i = 1; i < num; i++, front = front->next);
	temp = front->next;
	front->next = front->next->next;
	free(temp);
	head->data--;
	return TRUE;
}

LNode* LocateElem(LNode* head, EleType data)
{
	if (head == NULL)
		return FALSE;
	LNode* temp = head->next;
	for (; temp != NULL; temp = temp->next)
		if (temp->data == data)
			return temp;
	return FALSE;
}

LNode* GetElem(LNode* head , int num)
{
	if (head == NULL)
		return FALSE;
	if (num<1 || num>head->data)
		return FALSE;
	LNode* temp = head;
	for (int i = 1; i <= num; i++, temp = temp->next);
	return temp;
}

Bool PrintList(LNode* head)
{
	if (head == NULL)
		return FALSE;
	LNode* temp = head->next;
	for (; temp!= NULL; temp = temp->next)
	{
		printf("%2d ",temp->data);
	}
	return TRUE;
}

Bool MenuList(LNode** head, ScanfQueue* queue)
{
	while (TRUE) {
		int num;
		printf("Input Num:");
		scanf("%d", &num);
		switch (num) {
		case 1: InitList(head); break;
		case 2: DestroyList(head); break;
		case 3:
		{
			printf("Input locate and data:");
			ScanfPackage(queue, 2);
			InsertElem(*head, queue->data[0], queue->data[1]);
			break;
		}
		case 4:
		{
			printf("Input locate:");
			ScanfPackage(queue, 1);
			DeleteElem(*head, queue->data[0]);
			break;
		}
		case 5:
		{
			printf("Input data:");
			ScanfPackage(queue, 1);
			printf("%p\n", LocateElem(*head, queue->data[0]));
			break;
		}
		case 6:
		{
			printf("Input locate:");
			ScanfPackage(queue, 1);
			printf("%d\n", (GetElem(*head, queue->data[0]))->data);
			break;
		}
		case 7:
		{
			InsertHeadList(*head);
			break;
		}
		case 8:
		{
			InsertTailList(*head);
			break;
		}
		case 101: PrintList(*head); break;
		case 102: InitRandomList(head); break;
		case 0: HelpList(); break;
		case -1:return OK; break;
		default:printf("Num Error!\n");
		}
		printf("\n");
	}
}

int main(void)
{
	LNode* head = NULL;
	ScanfQueue queue;
	HelpList();
	MenuList(&head,&queue);
	return 0;
}