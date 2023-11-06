#include<stdio.h>
#include<stdlib.h>

#define OK 1001
#define ERROR 1002
#define TRUE 1003
#define FALSE 1004

void SortQuick(int* num, int begin,int end)
{
	int temp;
	for (int i = 1; i <= end; i++)
	{
		temp = num[i];
		int j;
		for (j = i - 1; j>=0 && temp < num[j]; j--)
		{
			num[j + 1] = num[j];
		}
		num[j+1] = temp;
		for (int i = 0; i <= 9; i++)
			printf("%d", num[i]);
		printf("\n");
	}
}

void SortXier(int* arr, int num)
{
	int i, j, k;
	for(i=num/2;i>=1;i/=2)
		for (j = i; j < num; j++)
		{
			int temp = arr[j];
			for (k = j - i; k >= 0 && arr[k] > temp; k -= i)
					arr[k + i] = arr[k];
			arr[k + i] = temp;
		}
}

void SortGudo(int* arr, int num)
{
	int temp;
	int i, j;
	for (i = 1; i < num; i++) {
		temp = arr[i];
		for (j = i - 1; j >= 0 && arr[j] >temp; j--)
			arr[j + 1] = arr[j];
		arr[j + 1] = temp;
	}
}

int main(void)
{
	int arr[10] = {1,1,7,4,2,6,9,7,3,4};
	SortGudo(arr,10);
	for(int i=0;i<=9;i++)
		printf("%d",arr[i]);
	return 0;
}