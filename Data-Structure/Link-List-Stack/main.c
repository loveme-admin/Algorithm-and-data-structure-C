#include<stdio.h>
#include<stdlib.h>
#include"root.h"
//��������
Bool InitList(LNode **);                //��ʼ�����Ա�
Bool DestoryList(LNode**);              //�������Ա�
//���ò���
Bool Push(LNode*);                      //ѹջ
Bool Pop(LNode*, EleType *);            //��ջ
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

Bool Push(LNode* head)
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

Bool Pop(LNode* head, EleType* data)
{
	if (head == NULL)
		return FALSE;
	if (head->next == NULL)
		return FALSE;
	LNode *temp = head->next;
	head->next = head->next->next;
	*data = temp->data;
	free(temp);
	head->data--;
	return TRUE;
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
			Push(*head);
			break;
		}
		case 4:
		{
			queue->length++;
			Pop(*head,&(queue->data[0]));
			printf("%d\n", queue->data[0]);
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