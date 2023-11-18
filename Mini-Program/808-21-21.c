#include<stdio.h>

#define MAXSIZE 20

typedef struct {
	int data[MAXSIZE];
	int length;
}List;

void InitList(List* list)
{
	int data = 0;
	list->length = 0;
	printf("Input Data:");
	while (1)
	{
		scanf("%d",&data);
		if (data == -99)
			return;
		list->data[list->length++] = data;
	}
}

void DelElem(List* list)  //关键函数
{
	for (int i = 0; i < list->length; i++)
	{
		int j = i + 1;
		while ( j < list->length)
		{
			if (list->data[i] == list->data[j])
			{
				list->data[--list->length] = list->data[j];
					continue;
			}
			j++;
		}
	}
}

int main(void)
{
	List list;
	InitList(&list);
	for (int i = 0; i < list.length; i++)
		printf("%d ",list.data[i]);
	DelElem(&list);
	printf("\n");
	for (int i = 0; i < list.length; i++)
		printf("%d ", list.data[i]);
	return 0;
}