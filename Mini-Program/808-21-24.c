#include <stdio.h> //关键程序
#include<stdlib.h>

typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;

void InitList(LinkList list[])
{
	for (int i = 0; i < 13; i++) {
		list[i] = (LNode*)malloc(sizeof(LNode));
		list[i]->data = 0;
		list[i]->next = NULL;
	}
}

void InsertElem(LinkList list[],int data)
{
	LNode *temp = (LNode*)malloc(sizeof(LNode));
	temp->data = data;
	temp->next = list[data%13]->next;
	list[data % 13]->next = temp;
}

void SelectElem(LinkList list[], int data)
{
	LNode* temp = list[data % 13]->next;
	while (temp)
	{
		if (temp->data == data)
		{
			printf("YES!\n");
			return;
		}
		temp = temp->next;
	}
	if(temp==NULL)
		printf("NO!\n");
}

int main(void)
{
	LinkList list[13];
	InitList(list);
	int data=0;
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &data);
		InsertElem(list, data);
	}
	printf("\n");
	scanf("%d", &data);
	SelectElem(list,data);
}