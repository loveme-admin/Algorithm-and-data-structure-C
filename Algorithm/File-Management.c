#include<stdio.h>
#define MAX 16

void Print(int [MAX][MAX]);
void Write(int [MAX][MAX],int ,int);
int Delete(int file[MAX][MAX], int);
void Help();

void Print(int file[MAX][MAX])
{
	int i, j;
	for (i = 0; i < MAX; i++)
	{
		for (j = 0; j < MAX; j++)
			printf("%d ", file[i][j]);
		printf("\n");
	}
	printf("--------------------------------\n");
}
void Write(int file[MAX][MAX],int name,int length)
{
	int i, j,count=0;
	int left, right;
	int k = 0;
	for (i = 0; i < MAX; i++)
	{
		for (j = 0; j <MAX; j++)
		{
			if (file[i][j] == 0)
				count++;
			else
				count = 0;
			if (count == length)
			{
				left = i;
				right = j;
				break;
			}
		}
		if (count == length)
			break;
	}
	if (count == 0)
	{
		printf("No Place\n");
		return;
	}
	for (k = 0; k < length; k++)
	{
		file[left][right--] = name;
		if (j == 0)
		{
			i--;
			j = MAX;
		}
	}
}
int Delete(int file[MAX][MAX], int name)
{
	int i, j;
	int count=0;
	for (i = 0; i < MAX; i++)
		for (j = 0; j < MAX; j++)
			if (name == file[i][j])
			{
				file[i][j] = 0;
				count++;
			}
	return count;
}
void Help()
{
	printf("1 存储  2 删除\n3 输出  0 菜单\n");
}

int main(void)
{
	int num;
	int name, length;
	int max=MAX*MAX;
	int file[MAX][MAX] = { 0 };
	Help();
	while (1)
	{
		printf("Input Num:");
		scanf("%d",&num);
		switch (num)
		{
		case 1: {
			printf("Input Insert Name and Length:");
			scanf("%d%d", &name, &length);
			if (max - length < 0) 
			{
				printf("No Memory\n");
				break; 
			}
			max = max - length;
			Write(file, name, length);
		}break;
		case 2: {
			printf("Input Delete Name:");
			scanf("%d", &name);
			max+=Delete(file, name);
			
		}break;
		case 3: {
			Print(file);
		}break;
		case 0: {
			Help();
		}break;
		default: {
			printf("Num Error");
		}break;
		}
		printf("\n");
	}
	return 0;
}
