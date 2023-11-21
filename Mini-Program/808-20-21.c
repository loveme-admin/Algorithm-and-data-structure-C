#include<stdio.h>

#define MAXSIZE 5

int main(void)
{
	int arr[MAXSIZE] = { 5,6,8,3,9 };
	int max = 0;
	int mid = 0;
	for (int i = 0; i < MAXSIZE; i++) {
		if (arr[i] > max)
		{
			mid = max;
			max = arr[i];
		}
		else if (arr[i] > mid)
		{
			mid = arr[i];
		}
	}
	printf("max=%d,mid=%d\n", max, mid);
	return 0;
}