#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 13 //散列函数模除数
typedef int ElemType;

struct Block {
	ElemType data;
	struct Block* next;
};
struct Group {
	struct Block* head;
	int length;
};
struct Chunk {
	int length;
	struct  Group* head;
};

void Init_Chunk(struct Chunk**);
void Init_Group(struct Chunk*);
void Insert_Block(struct Chunk*, int, ElemType);
void Select_Block(struct Chunk*, int, ElemType);
void Print_Block(struct Chunk*);
int Hash(ElemType);

void Init_Chunk(struct Chunk** head)
{
	(*head) = (struct Chunk*)malloc(sizeof(struct Chunk));
	(*head)->length = 0;
	(*head)->head = NULL;
}
void Init_Group(struct Chunk* head)
{
	head->head = (struct Group*)malloc(sizeof(struct Group[MAX]));
	for (int i = 0; i < MAX; i++)
	{
		((head->head) + i)->head = NULL;
		((head->head) + i)->length = 0;
	}
}
void Insert_Block(struct Chunk* head, int place, ElemType data)
{
	head->length++;
	((head->head) + place)->length++;
	struct Block* temp = NULL;
	temp = (struct Block*)malloc(sizeof(struct Block));
	temp->data = data;
	if (((head->head) + place)->head == NULL)
	{
		((head->head) + place)->head = temp;
		temp->next = NULL;
	}
	else
	{
		temp->next = ((head->head) + place)->head;
		((head->head) + place)->head = temp;
	}
}
void Select_Block(struct Chunk* head, int place, ElemType data)
{
	struct Block* temp = ((head->head) + place)->head;
	printf("%d ", data);
	if (((head->head) + place)->length == 0)
		printf("Not Data");
	else if (((head->head) + place)->length == 1)
	{
		printf("Not Have Clash ");
		if (temp->data == data)
			printf("Found");
		else
			printf("Not Found");
	}
	else
	{
		printf("Have Clash ");
		while (temp != NULL)
		{
			if (temp->data == data)
			{
				printf("Found\n");
				return;
			}
			temp = temp->next;
		}
		printf("Not Found");
	}
	printf("\n");
}
void Print_Block(struct Chunk* head)
{
	struct Block* temp = NULL;
	if (head->length == 0)
		return;
	for (int i = 0; i < MAX; i++)
	{
		temp = ((head->head) + i)->head;
		printf("%2d (%2d) ", i,((head->head) + i)->length);
		while (temp != NULL)
		{
			printf("%d ", temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
	printf("\n(%d)\n", head->length);
}
int Hash(ElemType data)
{
	return data % MAX;
}
void Help()
{
	printf("1.插入数据 2.查找数据\n");
	printf("3.打印数据 0.退出程序\n");
	printf("-1.帮助菜单\n");
}

int main(void)
{
	srand((unsigned int)time(NULL));
	int data = 0;
	int num = 0;
	struct Chunk* head = NULL;
	Init_Chunk(&head);
	Init_Group(head);
	Help();
	while (1)
	{
		printf("Input Num:");
		scanf("%d", &num);
		switch (num)
		{
		case 1: {
			printf("Input Data:");
			scanf("%d", &data);
			Insert_Block(head, Hash(data), data);
		} break;
		case 2: {
			printf("Input Data:");
			scanf("%d", &data);
			Select_Block(head, Hash(data), data);
		} break;
		case 3:	Print_Block(head); break;
		case 100:{
			for (int i = 0; i < 10; i++)
			{
				data = rand() % 1000;
				Insert_Block(head, Hash(data), data);
			}
		} break;
		case 0:break;
		case -1: Help(); break;
		default:printf("Num Not Found\n");
			break;
		}
	}
	return 0;
}
