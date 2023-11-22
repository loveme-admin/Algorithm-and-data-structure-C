#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAXSIZE 20

typedef int ElemType;
typedef struct LNode {
	ElemType data[MAXSIZE];
	int length;
}List;

void DelElem(List* list, int i, int k) //关键函数
{
	for (int j = i-1; j < list->length; j++)
	{
		list->data[j] = list->data[j+k];
	}
	list->length -= k;
}

int main(void)
{
	List list;
	for (int i = 0; i < MAXSIZE; i++)
		list.data[i]=i;
	list.length = MAXSIZE;
	DelElem(&list, 5, 5);
	for (int i = 0; i < list.length; i++)
		printf("%2d ",list.data[i]);
}