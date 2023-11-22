#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAXSIZE 20

void Sort(int* arr, int begin, int end) //关键函数
{
	int temp = arr[begin];
	while (begin < end)
	{
		while (begin < end && arr[end] >= 0)
			end--;
		arr[begin] = arr[end];
		while (begin < end && arr[begin] <= 0)
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
		arr[i] = rand() % 100-50;
	}
	for (int i = 0; i < MAXSIZE; i++)
	{
		printf("%5d", arr[i]);
	}
	Sort(arr, 0, 19);
	printf("\n");
	for (int i = 0; i < MAXSIZE; i++)
	{
		printf("%5d", arr[i]);
	}
	return 0;
}