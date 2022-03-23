#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100//最大数组长度
#define UP 200//范围上限
#define DOWN -200//范围下限
void CreateList(int[], int);
void PrintList(int[], int);
void HelpList();
void Sort1(int[], int);//冒泡排序
void Sort2(int[], int, int);//快速排序
void Sort3(int[], int);//插入排序
void Sort4(int[], int);//希尔排序
void Sort5(int[], int);//选择排序
void Sort6(int[], int);//大堆排序
void Sort6_C(int[], int, int);
void Sort7(int[], int);//二路归并
void Sort7_C(int[], int[], int, int);
void Sort8(int[], int);//三路归并
void Sort8_C(int[], int[], int, int);
void Sort9(int[], int);//基数排序
void Sort10(int[], int);//计数排序
void Sort11(int[], int);//分桶排序
void Sort12(int[], int);//幸运排序

void CreateList(int num[], int length)
{
	int i = 0;
	for (i = 0; i < length; i++)
		num[i] = (rand() % (UP+1 - DOWN)) + DOWN;
}
void PrintList(int num[], int length)
{
	int i = 0;
	for (i = 0; i < length; i++)
		printf("%d ", num[i]);
	printf("\n");
}
void HelpList()
{
	printf(" -1.线性表帮助   -2.初始线性表\n");
	printf("  1.冒泡排序      2.快速排序\n");
	printf("  3.插入排序      4.希尔排序\n");
	printf("  5.选择排序      6.大堆排序\n");
	printf("  7.二路归并      8.三路归并\n");
	printf("  9.基数排序     10.计数排序\n");
	printf(" 11.分桶排序     12.幸运排序\n");
	printf(" -3.打印线性表    0.退出程序\n");
}

void Sort1(int num[], int length)
{
	int i = 0, j = 0, temp = 0;
	for (i = 0; i < length; i++)
		for (j = 0; j < length - i - 1; j++)
			if (num[j] > num[j + 1])
			{
				temp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = temp;
			}
}
void Sort2(int num[], int begin, int end)
{
	if (begin < end)
	{
		int i = begin;
		int j = end;
		int key = num[begin];
		while (i < j)
		{
			while (i < j && num[j] > key)
				j--;
			if (i != j)
			{
				num[i] = num[j];
				i++;
			}
			while (i < j && num[i] < key)
				i++;
			if (i < j)
			{
				num[j] = num[i];
				j--;
			}
		}
		num[i] = key;
		Sort2(num, begin, i - 1);
		Sort2(num, i + 1, end);
	}
}
void Sort3(int num[], int length)
{
	int i = 0, j = 0, key = 0;
	for (i = 0; i < length - 1; i++)
	{
		key = num[i + 1];
		for (j = i; j >= 0 && num[j] > key; j--)
			num[j + 1] = num[j];
		num[j + 1] = key;
	}
}
void Sort4(int num[], int length)
{
	int inc = length / 2;
	int i = 0, j = 0, key;
	while (inc != 0)
	{
		for (i = 0; i < length - inc; i++)
		{
			key = num[i + inc];
			for (j = i; j >= 0 && num[j] > key; j -= inc)
				num[j + inc] = num[j];
			num[j + inc] = key;
		}
		inc /= 2;
	}
}
void Sort5(int num[], int length)
{
	int sub = 0, min = 0, temp = 0;
	int i = 0, j = 0;
	for (i = 0; i < length - 1; i++)
	{
		min = num[i];
		sub = i;
		for (j = i + 1; j < length; j++)
			if (num[j] < min)
			{
				min = num[j];
				sub = j;
			}
		temp = num[i];
		num[i] = num[sub];
		num[sub] = temp;
	}
}
void Sort6(int num[], int length)
{
	int i = 0, temp = 0;
	for (i = length / 2 - 1; i >= 0; i--)
	{
		Sort6_C(num, length, i);
	}
	for (i = length - 1; i > 0; i--)
	{
		temp = num[i];
		num[i] = num[0];
		num[0] = temp;
		Sort6_C(num, i, 0);
	}
}
void Sort6_C(int num[], int length, int i)
{
	int temp = 0;
	int largest = i;
	int left = i * 2 + 1;
	int right = i * 2 + 2;
	if (left<length && num[left]>num[i])
	{
		largest = left;
		if (right < length && num[left] < num[right])
			largest = right;
	}
	else if (right < length && num[left] < num[right])
		largest = right;
	if (largest != i)
	{
		temp = num[i];
		num[i] = num[largest];
		num[largest] = temp;
		Sort6_C(num, length, largest);
	}
}
void Sort7(int num[], int length)
{
	int* temp_num = (int*)malloc(length * sizeof(int));
	if (temp_num)
	{
		Sort7_C(num, temp_num, 0, length - 1);
		free(temp_num);
	}
	else
		printf("Error\n");
}
void Sort7_C(int num[], int temp_num[], int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		int p_left = left;
		int p_right = mid + 1;
		int p = left;
		Sort7_C(num, temp_num, left, mid);
		Sort7_C(num, temp_num, mid + 1, right);
		while (p_left <= mid && p_right <= right)
		{
			if (num[p_left] < num[p_right])
				temp_num[p++] = num[p_left++];
			else
				temp_num[p++] = num[p_right++];
		}
		while (p_left <= mid)
			temp_num[p++] = num[p_left++];
		while (p_right <= right)
			temp_num[p++] = num[p_right++];
		while (left <= right)
		{
			num[left] = temp_num[left];
			left++;
		}
	}
}
void Sort8(int num[], int length)
{
	int* temp_num = (int*)malloc(length * sizeof(int));
	if (temp_num)
	{
		Sort8_C(num, temp_num, 0, length - 1);
		free(temp_num);
	}
	else
		printf("Error\n");
}
void Sort8_C(int num[], int temp_num[], int left, int right)
{
	if (left < right)
	{
		int mid1 = left + (right - left) / 3;
		int mid2 = right - (right - left) / 3;
		int p_left = left;
		int p_mid = mid1 + 1;
		int p_right = mid2 + 1;
		int p = left;
		Sort8_C(num, temp_num, left, mid1);
		Sort8_C(num, temp_num, mid1 + 1, mid2);
		Sort8_C(num, temp_num, mid2 + 1, right);
		while (p_left <= mid1 && p_mid <= mid2 && p_right <= right)
		{
			if (num[p_left] <= num[p_mid] && num[p_left] <= num[p_right])
				temp_num[p++] = num[p_left++];
			else if (num[p_mid] <= num[p_left] && num[p_mid] <= num[p_right])
				temp_num[p++] = num[p_mid++];
			else
				temp_num[p++] = num[p_right++];
		}
		while (p_left <= mid1 && p_mid <= mid2)
		{
			if (num[p_left] <= num[p_mid])
				temp_num[p++] = num[p_left++];
			else
				temp_num[p++] = num[p_mid++];
		}
		while (p_mid <= mid2 && p_right <= right)
		{
			if (num[p_mid] <= num[p_right])
				temp_num[p++] = num[p_mid++];
			else
				temp_num[p++] = num[p_right++];
		}
		while (p_left <= mid1 && p_right <= right)
		{
			if (num[p_left] <= num[p_right])
				temp_num[p++] = num[p_left++];
			else
				temp_num[p++] = num[p_right++];
		}
		while (p_left <= mid1)
			temp_num[p++] = num[p_left++];
		while (p_mid <= mid2)
			temp_num[p++] = num[p_mid++];
		while (p_right <= right)
			temp_num[p++] = num[p_right++];
		while (left <= right)
		{
			num[left] = temp_num[left];
			left++;
		}
	}
}
void Sort9(int num[], int length)
{
	int max = num[0];
	int bit = 1;
	int p_num = 0;
	int i = 0, j = 0, k = 0;
	int* temp_num1[10];
	int* temp_num2[10];
	for (i = 0; i < 10; i++)
	{
		temp_num1[i] = (int*)malloc(sizeof(int) * length);
		temp_num2[i] = (int*)malloc(sizeof(int) * length);
	}
	int* temp_count1 = (int*)malloc(10 * sizeof(int));
	int* temp_count2 = (int*)malloc(10 * sizeof(int));
	if (temp_count1 && temp_count2) 
	{
		for (i = 0; i < 10; i++)
		{
			temp_count1[i] = 0;
			temp_count2[i] = 0;
		}
		for (i = 0; i < length; i++)
		{
			if (max < num[i] && num[i] >= 0)
				max = num[i];
			else if (max < (num[i] * -1) && num[i] < 0)
				max = num[i] * -1;
		}
		while (max / 10 != 0)
		{
			bit++;
			max /= 10;
		}
		for (i = 1; bit--; i *= 10)
		{
			p_num = 0;
			for (j = 0; j < length; j++)
			{
				if (num[j] < 0)
				{
					num[j] *= -1;
					temp_num2[num[j] / i % 10][temp_count2[num[j] / i % 10]++] = num[j];
				}
				else
					temp_num1[num[j] / i % 10][temp_count1[num[j] / i % 10]++] = num[j];
			}
			for (j = 9; j >= 0; j--)
			{
				for (k = 0; temp_count2[j] > 0; temp_count2[j]--)
				{
					temp_num2[j][k] *= -1;
					num[p_num++] = temp_num2[j][k++];
				}
			}
			for (j = 0; j < 10; j++)
			{
				for (k = 0; temp_count1[j] > 0; temp_count1[j]--)
					num[p_num++] = temp_num1[j][k++];
			}
		}
		for (i = 0; i < 10; i++)
		{
			free(temp_num1[i]);
			free(temp_num2[i]);
		}
		free(temp_count1);
		free(temp_count2);
	}
	else
		printf("Error\n");
}
void Sort10(int num[], int length)
{
	int max=num[0], min =num[0];
	int i = 0,p_num=0;
	for (i = 1; i < length; i++)
	{
		if (min > num[i])
			min = num[i];
		if (max < num[i])
			max = num[i];
	}
	int *temp_num = (int*)malloc(sizeof(int) *(max - min + 1));
	if (temp_num) {
		for (i = 0; i < max - min + 1; i++)
			temp_num[i] = 0;
		for (i = 0; i < length; i++)
			temp_num[num[i] - min]++;
		for (i = 0; i < max - min + 1; i++)
			while (temp_num[i])
			{
				num[p_num++] = i + min;
				temp_num[i]--;
			}
		free(temp_num);
	}
	else
		printf("Error\n");
}
void Sort11(int num[], int length)
{
	int i = 0,j=0, p_num = 0,bucket=0;
	int* temp_num[UP-DOWN/25+1];
	bucket = (UP - DOWN + 1)/25+1;
	for (i = 0; i < bucket; i++) 
		temp_num[i] = (int*)malloc(sizeof(int) * length);
	int* temp_count= (int*)malloc(bucket * sizeof(int));
	for (i = 0; i < bucket; i++)
		temp_count[i] = 0;
	for (i = 0; i < length; i++)
		temp_num[(num[i]-DOWN) / 25 ][temp_count[(num[i]-DOWN) / 25 ]++] = num[i];
	for (i = 0; i < bucket; i++)
		Sort2(temp_num[i], 0, temp_count[i]-1);
	for (i = 0; i < bucket; i++)
		for (j=0;temp_count[i]>0; temp_count[i]--)
			num[p_num++] = temp_num[i][j++];
	for (i = 0; i < bucket; i++)
		free(temp_num[i]);
	free(temp_count);
}
void Sort12(int num[], int length)
{
	int i = 0, j = 0, temp = 0, sum = 0;
	while (1)
	{
		for (i = 0; i < length; i++)
		{
			j = rand() % length;
			temp = num[i];
			num[i] = num[j];
			num[j] = temp;
		}
		sum++;
		printf("第%d次:", sum);
		for (i = 0; i < length; i++)
			printf("%d ", num[i]);
		for (i = 0; i < length - 1; i++)
			if (num[i] > num[i + 1])
				j = 0;
		printf("\n");
		if (j != 0)
			break;
	}
}

int main(void)
{
	int num[MAX], i = 0;
	srand((unsigned int)time(NULL));
	HelpList();
	while (1) {
		printf("Input num:");
		scanf("%d", &i);
		if (i == 0)
			break;
		switch (i)
		{
		case -1:HelpList(); break;
		case -2:CreateList(num, MAX); break;
		case 1:Sort1(num, MAX); break;
		case 2:Sort2(num, 0, MAX - 1); break;
		case 3:Sort3(num, MAX); break;
		case 4:Sort4(num, MAX); break;
		case 5:Sort5(num, MAX); break;
		case 6:Sort6(num, MAX); break;
		case 7:Sort7(num, MAX); break;
		case 8:Sort8(num, MAX); break;
		case 9:Sort9(num, MAX); break;
		case 10:Sort10(num, MAX); break;
		case 11:Sort11(num, MAX); break;
		case 12:Sort12(num, MAX); break;
		case -3:PrintList(num, MAX); break;
		default:printf("Error\n");
			break;
		}
	}
	return 0;
}
