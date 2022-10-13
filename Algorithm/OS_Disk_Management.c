#include<stdio.h>
#include<math.h>
#define MAX 10

 typedef struct HardWare
{
	int data[MAX];
	int range[MAX];
	int length;
}Track;

 void Write(Track*);
 void Sstf(Track*,int);
 void Look(Track*, int);
 void C_Look(Track*, int);
 void Sort1(int [], int, int);
 void Sort2(int [], int, int);

void Write(Track *track)
{
	track->data[0] = 143;
	track->data[1] = 147;
	track->data[2] = 150;
	track->data[3] = 175;
	track->data[4] = 177;
	track->data[5] = 86;
	track->data[6] = 91;
	track->data[7] = 94;
	track->data[8] = 102;
	track->data[9] = 130;
	track->length = 10;
}
void Sstf(Track *track,int data)
{
	int i = 0;
	int key = 0;
	int sub = 0;
	int min = 65535;
	int count = 0;
	for (i = 0; i < track->length; i++)
		if (track->data[i] == data)
		{
			sub = i;
			break;
		}
	if (i == track->length)
	{
		printf("Data Not Found\n");
		return;
	}
	printf("SSTF:");
	while (track->length)
	{
		min = 65535;
		if(track->length!=1)
			printf("%d->", track->data[sub]);
		else
			printf("%d\n", track->data[sub]);
		key = track->data[sub];
		track->data[sub] = track->data[--track->length];
		for (i = 0; i < track->length; i++)
		{
			track->range[i] = abs(track->data[i]-key);
			if (min > track->range[i])
			{
				min = track->range[i];
				sub = i;
			}
		}
		if(track->length)
			count += track->range[sub];
	}
	printf("Move Length :%d\n", count);
}
void Look(Track* track, int data)
{
	int i = 0, x=0,y=0;
	int key = 0;
	int sub = 0;
	int min = 65535;
	int count = 0;
	for (i = 0; i < track->length; i++)
		if (track->data[i] == data)
		{
			sub = i;
			break;
		}
	if (i == track->length)
	{
		printf("Data Not Found\n");
		return;
	}
	key = track->data[sub];
	track->data[sub] = track->data[--track->length];
	for (i = 0 ,x=0,y = track->length - 1; i<track->length;i++)
		if (track->data[i] > key) 
		{
			track->range[x] = track->data[i];
			x++;
		}
		else
		{
			track->range[y] = track->data[i];
			y--;
		}
	Sort1(track->range,0,x-1);
	Sort2(track->range, y+1, track->length-1);
	printf("LOOK:");
	printf("%d->",key);
	count = abs(track->range[0]-key);
	for (i = 0; i < track->length; i++)
	{
		if (i != track->length - 1)
			printf("%d->", track->range[i]);
		else
			printf("%d\n", track->range[i]);
		if(i!=track->length-1)
			count += (abs(track->range[i + 1] - track->range[i]));
	}
	printf("Move Length :%d\n",count);
}
void C_Look(Track* track, int data)
{
	int i = 0, x = 0, y = 0;
	int key = 0;
	int sub = 0;
	int min = 65535;
	for (i = 0; i < track->length; i++)
		if (track->data[i] == data)
		{
			sub = i;
			break;
		}
	if (i == track->length)
	{
		printf("Data Not Found\n");
		return;
	}
	key = track->data[sub];
	track->data[sub] = track->data[--track->length];
	for (i = 0, x=0,y = track->length - 1; i < track->length; i++)
		if (track->data[i] > key)
		{
			track->range[x] = track->data[i];
			x++;
		}
		else
		{
			track->range[y] = track->data[i];
			y--;
		}
	Sort1(track->range, 0, x - 1);
	Sort1(track->range, y + 1, track->length - 1);
	printf("C-LOOK:");
	printf("%d->", key);
	for (i = 0; i < track->length; i++)
		if (i != track->length - 1)
			printf("%d->", track->range[i]);
		else
			printf("%d\n", track->range[i]);
}
void Sort1(int num[], int begin, int end)
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
			if (i != j)
			{
				num[j] = num[i];
				j--;
			}
		}
		num[i] = key;
		Sort1(num, begin, i - 1);
		Sort1(num, i + 1, end);
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
			while (i < j && num[j] < key)
				j--;
			if (i != j)
			{
				num[i] = num[j];
				i++;
			}
			while (i < j && num[i] > key)
				i++;
			if (i != j)
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
int main(void)
{
	Track track;
	int data = 143;//初始位置
	Write(&track);
	Sstf(&track,data);
	Write(&track);
	Look(&track, data);
	Write(&track);
	C_Look(&track, data);
	return 0;
}
