#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define MAXSIZE 20

typedef int KeyType;

typedef struct {
	KeyType key;
}RedType;

typedef struct {
	RedType r[MAXSIZE + 1];
	int length;
}SqList;

void InitRandomSqList(SqList* sqlist)
{	
	sqlist->length = MAXSIZE;
	srand((unsigned)time);
	for (int i = 0; i < sqlist->length; i++)
	{
		sqlist->r[i].key = rand() % 100;
	}
}

void Sort(SqList* sqlist, int begin, int end)  //关键代码
{
	if (begin >= end)
		return;
	int a = begin;
	int b = end;
	int key = sqlist->r[begin].key;
	while (a < b)
	{
		while (a < b && sqlist->r[b].key >= key)
			b--;
		sqlist->r[a].key = sqlist->r[b].key;
		while (a < b && sqlist->r[a].key  <= key)
			a++;
		sqlist->r[b].key = sqlist->r[a].key;
	}
	sqlist->r[a].key = key;
	Sort(sqlist, begin, a - 1);
	Sort(sqlist, a+1, end);
}

int main(void)
{
	SqList sqlist;
	InitRandomSqList(&sqlist);
	for (int i = 0; i < sqlist.length; i++)
	{
		printf("%d ",sqlist.r[i].key);
	}
	printf("\n");
	Sort(&sqlist,0,19);
	for (int i = 0; i < sqlist.length; i++)
	{
		printf("%d ", sqlist.r[i].key);
	}
}