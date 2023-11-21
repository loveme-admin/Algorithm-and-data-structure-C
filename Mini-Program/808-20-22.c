#include<stdio.h>

void SortGudo(int* arr, int num)
{
	int temp;
	int i, j;
	for (i = 1; i < num; i++) {
		temp = arr[i];
		for (j = i - 1; j >= 0 && arr[j] < temp; j--)
			arr[j + 1] = arr[j];
		arr[j + 1] = temp;
	}
}

int main(void)
{
	int arr[10] = { 1,1,7,4,2,6,9,7,3,4 };
	SortGudo(arr, 10);
	for (int i = 0; i <= 9; i++)
		printf("%d", arr[i]);
	return 0;
}