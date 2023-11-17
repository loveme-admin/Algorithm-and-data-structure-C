#include<stdio.h>
#include<stdlib.h>
#include"root.h"

//��������
Bool InitList(SqList*);                     //��ʼ�����Ա�
Bool DestroyList(SqList*);                   //�������Ա�
//���ò���
Bool InsertElem(SqList*, int, EleType);     //��λ����Ԫ��
Bool DeleteElem(SqList*, int, EleType*);    //ɾ��Ԫ�ز�����ֵ
int LocateElem(SqList, EleType);            //��ֵ����Ԫ��
EleType GetElem(SqList, int);               //��λ����Ԫ��
//��������
Bool PrintList(SqList);                     //��ӡ���Ա�
Bool MenuList(SqList*, ScanfQueue*);        //�˵�

Bool InitList(SqList* list)
{
	if (list == NULL)
		return FALSE;
	for (int i = 0; i < MAXSIZE; i++)
		list->data[i] = 0;
	list->length = 0;
	return TRUE;
}

Bool DestroyList(SqList* list)
{
	if (list == NULL)
		return FALSE;
	list->length = 0;
	return TRUE;
}

Bool InsertElem(SqList* list, int num, EleType data)
{
	if (list == NULL)
		return FALSE;
	if (num<1 || num>list->length + 1)
		return FALSE;
	if (list->length >= MAXSIZE)
		return FALSE;
	for (int i = list->length; i >= num; i--)
		list->data[i] = list->data[i - 1];
	list->data[num - 1] = data;
	list->length++;
	return TRUE;
}

Bool DeleteElem(SqList* list, int num, EleType* data)
{
	if (list == NULL)
		return FALSE;
	if (num<1 || num>list->length)
		return FALSE;
	*data = list->data[num - 1];
	for (int i = num; i < list->length; i++)
		list->data[i - 1] = list->data[i];
	list->length--;
	return TRUE;
}

int LocateElem(SqList list, EleType data)
{
	if (list.data == NULL)
		return FALSE;
	for (int i = 0; i < list.length; i++)
		if (list.data[i] == data)
			return i + 1;
	return FALSE;
}

EleType GetElem(SqList list, int num)
{
	if (list.data == NULL)
		return FALSE;
	if (num<1 || num>list.length)
		return FALSE;
	return list.data[num - 1];
}

Bool PrintList(SqList list)
{
	if (list.data == NULL)
		return FALSE;
	for (int i = 0; i < list.length; i++)
		printf("%2d ", list.data[i]);
	printf("\n");
	return TRUE;
}

Bool MenuList(SqList* list, ScanfQueue* queue)
{
	while (TRUE) {
		int num;
		printf("Input Num:");
		scanf("%d", &num);
		switch (num) {
		case 1: InitList(list); break;
		case 2: DestroyList(list); break;
		case 3:
		{
			printf("Input locate and data:");
			ScanfPackage(queue, 2);
			InsertElem(list, queue->data[0], queue->data[1]);
			break;
		}
		case 4:
		{
			printf("Input locate:");
			ScanfPackage(queue, 1);
			DeleteElem(list, queue->data[0], &(queue->data[0]));
			break;
		}
		case 5:
		{
			printf("Input data:");
			ScanfPackage(queue, 1);
			printf("%d\n", LocateElem(*list, queue->data[0]));
			break;
		}
		case 6:
		{
			printf("Input locate:");
			ScanfPackage(queue, 1);
			printf("%d\n", GetElem(*list, queue->data[0]));
			break;
		}

		case 101: PrintList(*list); break;
		case 102: InitRandomList(list); break;
		case 0: HelpList(); break;
		case -1:return OK; break;
		default:printf("Num Error!\n");
		}
		printf("\n");
	}
}

int main(void)
{
	SqList list;
	ScanfQueue queue;
	HelpList();
	MenuList(&list, &queue);
	return 0;
}