#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int ElemType;
typedef struct Node {
	ElemType data;
	struct Node* next;
}ListNode;
ListNode* head = NULL;

void Help();//                                    帮助菜单
void InitList(ListNode**);//                      初始初始
void LengthList(ListNode*);//                     链表长度
void PrintList(ListNode*);//                      打印链表
void Check_Place(ListNode*, int, int*);//         插入位置检测
void Check_Data(ElemType*, int);//                插入数据检测
ListNode* CreateList(ListNode*);//                创建并写入
ListNode* InsertList(ListNode*, int);//           按位置插入
void WriteList(ListNode*);//                      单个写入
void WriteList_ALL(ListNode*);//                  批量写入
void SortList1(ListNode*);//                      冒泡排序
void SortList2(ListNode*);//                      直接插入排序
void DeleteList_Place(ListNode*, int);//          按位置删除
void DeleteList_Data(ListNode*, ElemType);//      按元素删除
void FreeList(ListNode*);//                       释放链表

void InitList(ListNode** head)
{
	ListNode* temp = NULL;
	temp = (ListNode*)malloc(sizeof(ListNode));
	(*head) = temp;
	(*head)->data = 0;
	(*head)->next = NULL;
}
void LengthList(ListNode* head)
{
	printf("Length is:%d\n", head->data);
}
void PrintList(ListNode* head)
{
	head = head->next;
	printf("Data is:\n");
	while (head != NULL)
	{
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}
void Check_Place(ListNode* head, int num, int* place)
{
	ListNode* length = head;
	if (num == 4 || num == 6)
	{
		while (1) {
			printf("Input a Place:");
			scanf("%d", place);
			if (*place > 0 && *place <= length->data)
				break;
			else
				printf("Error\n");
		}
	}
}
void Check_Data(ElemType* data, int num)
{
	if (num == 5)
	{
		printf("Input a Data:");
		scanf("%d", data);
	}
}
ListNode* CreateList(ListNode* head)
{
	ListNode* last = head;
	while (last->next != NULL)
		last = last->next;
	ListNode* temp = NULL;
	ListNode* length = head;
	temp = (ListNode*)malloc(sizeof(ListNode));
	if (last == NULL)
		head->next = temp;
	else
		last->next = temp;
	temp->next = NULL;
	length->data++;
	return temp;
}
ListNode* InsertList(ListNode* head, int place)
{
	ListNode* length = head;
	ListNode* temp = NULL;
	ListNode* node = NULL;
	int i=0;
	for (i = 1; i <= length->data; i++)
		if (i != place)
			head = head->next;
		else
			break;
	node = (ListNode*)malloc(sizeof(ListNode));
	temp = head->next;
	head->next = node;
	node->next = temp;
	length->data++;
	return node;
}
void WriteList(ListNode* head)
{
	printf("\n");
	printf("Input a Data:");
	scanf("%d", &head->data);
	printf("\n");
}
void WriteList_ALL(ListNode* head)
{
	int data;
	printf("Input a Data(-1 exit):");
	while (1)
	{
		scanf("%d", &data);
		if (data == -1)
			break;
		CreateList(head)->data = data;
	}
}
void SortList1(ListNode* head)
{
	int length = head->data;
	ListNode* node;
	ListNode* p=NULL, * q=NULL;
	int i = 0, j = 0;
	for (i = 0; i < length - 1; i++)
	{
		node = head;
		p = node->next;
		q = p->next;
		for (j = 0; j < length - i - 1; j++)
		{
			if (p->data > q->data)
			{
				p->next = q->next;
				q->next = p;
				node->next = q;
			}
			node = node->next;
			p = node->next;
			q = p->next;
		}
	}
}
void SortList2(ListNode* head)//直接插入排序
{
	if (head->next != NULL)
	{
		ListNode* p=NULL, * q=NULL, * node=NULL;
		node = head->next->next;
		head->next->next = NULL;
		while (node != NULL)
		{
			q = node->next;
			p = head;
			while (p->next != NULL && p->next->data < node->data)
				p = p->next;
			node->next = p->next;
			p->next = node;
			node = q;
		}
	}
}
void DeleteList_Place(ListNode* head, int place)
{
	ListNode* temp=NULL;
	ListNode* length=head;
	int i=0;
	for (i = 1; i <= length->data; i++)
		if (i != place)
			head = head->next;
		else
			break;
	length->data--;
	temp = head->next;
	head->next = head->next->next;
	free(temp);
}
void DeleteList_Data(ListNode* head, ElemType data)
{
	ListNode* temp=NULL;
	ListNode* length = head;
	if (head != NULL)
	{
		while (1)
		{
			while (head->next != NULL && head->next->data != data)
				head = head->next;
			if (head->next != NULL)
			{
				length->data--;
				temp = head->next;
				head->next = head->next->next;
				free(temp);
			}
			else
				break;
		}
	}
}
void FreeList(ListNode* head)
{
	ListNode* length = head;
	length->data = 0;
	head = head->next;
	ListNode* temp;
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

void Help()
{
	printf("-1.打印链表    0.退出主程序\n");
	printf(" 1.初始链表    2.创建节点\n");
	printf(" 3.删除链表    4.按位置删除\n");
	printf(" 5.按数据删除  6.按位置插入\n");
	printf(" 7.冒泡排序    8.插入排序\n");
	printf(" 9.链表长度\n");
	printf("-2.帮助\n");
}

int main(void) 
{
	int num = 0;
	int place=0;
	ElemType data=0;
	Help();
	while (1)
	{
		printf("Input Num:");
		scanf("%d", &num);
		Check_Place(head,num,&place);
		Check_Data(&data,num);
		switch (num)
		{
			case 0:return 0; break;
			case 1:DeleteList_Data(head, data); InitList(&head); break;
			case 2:WriteList_ALL(head); break;
			case 3:FreeList(head); break;
			case 4:DeleteList_Place(head, place); break;
			case 5:DeleteList_Data(head, data); break;
			case 6:WriteList(InsertList(head, place)); break;
			case 7:SortList1(head); break;
			case 8:SortList2(head); break;
			case 9:LengthList(head); break;
			case -1:PrintList(head); break;
			case -2:Help(); break;
			default:printf("Error\n");
				break;
		}
	}
}
