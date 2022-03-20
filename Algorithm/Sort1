#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void swap(int*, int*);
int use(int*,int);

void swap(int *a,int *b) 
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int use(int* num, int x)
{
	int i;
	for (i = 0; i < x - 1; i++)
		if (num[i] > num[i + 1])
			return 0;
	return 1;
}

int main(void)
{
	int num[] = {1,5,3,4,2,6};//加入数据
	int i=0, j = 0,sum=0;
	srand((unsigned int)time(NULL));
	while (1) {
		for (i = 0; i < sizeof(num) / 4; i++)
		{
			j = rand() % (sizeof(num) / 4);
			swap(&num[i], &num[j]);
		}
		sum++;
		printf("第%d次:",sum);
		for (i = 0; i < sizeof(num) / 4; i++)
		{
			printf("%d ", num[i]);
		}
		if (use(num, sizeof(num) / 4))
			break;
		printf("\n");
	}
	return 0;
}
