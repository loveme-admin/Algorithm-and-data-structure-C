#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAXSIZE 20

void Sort(int* arr) //关键函数
{
	int i, j;
	for (i = 0; i < MAXSIZE; i++)
	{
		int min = arr[i];
		int key = i;
		for(j=i;j<MAXSIZE;j++)
		{
			if (arr[j] < min)
			{
				min = arr[j];
				key = j;
			}
		}
		arr[key] = arr[i];
		arr[i] = min;
	}
}

int main(void)
{
	srand((unsigned)time);
	int arr[MAXSIZE];
	for (int i = 0; i < MAXSIZE; i++)
	{
		arr[i] = rand() % 100;
	}
	for (int i = 0; i < MAXSIZE; i++)
	{
		printf("%3d", arr[i]);
	}
	Sort(arr);
	printf("\n");
	for (int i = 0; i < MAXSIZE; i++)
	{
		printf("%3d", arr[i]);
	}
	return 0;
}