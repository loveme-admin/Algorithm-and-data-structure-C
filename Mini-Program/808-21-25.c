#include<stdio.h>  //关键程序

#define MAXSIZE 20

typedef struct {
	int data[MAXSIZE];
	int length;
}List;

void Sort(List *list) 
{
	int temp;
	for(int i=0;i<list->length-1;i++)
		for (int j = 0; j < list->length - 1-i; j++)
			if (list->data[j] > list->data[j + 1])
			{
				temp = list->data[j];
				list->data[j] = list->data[j + 1];
				list->data[j + 1] = temp;
			}
}

int main(void)
{
	List list;
	list.length = 0;
	int data = 0;
	while(1)
	{
		scanf("%d", &data);
		if (data == 0)
			break;
		list.data[list.length++] = data;
	}
	printf("\n");
	Sort(&list);
	for (int i = 0; i < list.length; i++)
	{
		printf("%3d", list.data[i]);
	}
	return 0;
}