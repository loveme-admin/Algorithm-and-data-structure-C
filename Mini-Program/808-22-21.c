#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAXSIZE 20

void Sort(int* arr, int begin, int end,int e) //关键函数
{
	int temp = arr[begin];
	while (begin < end)
	{
		while (begin < end && arr[end] >= e)
			end--;
		arr[begin] = arr[end];
		while (begin < end && arr[begin] <= e)
			begin++;
		arr[end] = arr[begin];
	}
	arr[begin] = temp;
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
	Sort(arr,0,19,50);
	printf("\n");
	for (int i = 0; i < MAXSIZE; i++)
	{
		printf("%3d",arr[i]);
	}
	return 0;
}