#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct City* GET(struct City**);//创建链表
void WRITE_HAND(struct City*);//写入数据
void READ(struct City*);//读取数据
void SEARCH(struct City*, char*);//搜索道路
void DONE(struct City*, char*);//停用道路
void UPDATE(struct City*, char*);//更新道路
void PULL(struct City**);//删除道路

struct City
{
	char name[20];
	char time[20];
	char place[20];
	int num;
	int direct;
	int status;
	struct City* next;
};
struct City* head = NULL;

struct City* GET(struct City** head)
{
	struct City* road;
	static struct City* temp;
	road = (struct City*)malloc(sizeof(struct City));
	if (*head != NULL)
	{
		temp->next = road;
		road->next = NULL;
	}
	else
	{
		*head = road;
		road->next = NULL;
	}
	temp = road;
	return road;
}

void WRITE_HAND(struct City* road)
{
	printf("\n请输入道路名称:");
	scanf("%s", road->name);
	printf("请输入建造时间:");
	scanf("%s", road->time);
	printf("请输入起止坐标:");
	scanf("%s", road->place);
	printf("请输入车道数量:");
	scanf("%d", &road->num);
	printf("请输入车道方向(双向1,单向-1):");
	scanf("%d", &road->direct);
	printf("请输入道路状态(使用1,停用-1):");
	scanf("%d", &road->status);
}

void READ(struct City* head)
{
	printf("name            time            place             num     direct  status\n");
	while (head != NULL)
	{
		printf("%-12s    ", head->name);
		printf("%-12s    ", head->time);
		printf("%-12s      ", head->place);
		printf("%-2d      ", head->num);
		if (head->direct == 1)
			printf("双向    ");
		else
			printf("单向    ");
		if (head->status == 1)
			printf("使用中");
		else
			printf("停用中");
		printf("\n");
		head = head->next;
	}
}

void SEARCH(struct City* head,char *str)
{
	printf("name            time            place             num     direct  status\n");
	while (head != NULL)
	{
		if (strcmp(head->name, str) == 0 || strcmp(head->place, str) == 0)
		{
			printf("%-12s    ", head->name);
			printf("%-12s    ", head->time);
			printf("%-12s      ", head->place);
			printf("%-2d      ", head->num);
			if (head->direct == 1)
				printf("双向    ");
			else
				printf("单向    ");
			if (head->status == 1)
				printf("使用中");
			else
				printf("停用中");
			printf("\n");
		}
		head = head->next;
	}
}

void DONE(struct City* head, char* str)
{
	while (head != NULL)
	{
		if (strcmp(head->name, str) == 0 || strcmp(head->place, str) == 0)
		{
			head->status = -1;
		}
		head = head->next;
	}
}

void UPDATE(struct City* head, char* str)
{
	char str_s[20];
	while (head != NULL)
	{
		if (strcmp(head->name, str) == 0 || strcmp(head->place, str) == 0)
		{
			while (1) {
				printf("输入需要更改的名称(name,time,place,num,direct,status,exit(退出)):");
				scanf("%s", str_s);
				printf("输入值(字符/1,-1):");
				if (strcmp("name", str_s) == 0)
					scanf("%s", head->name);
				else if (strcmp("time", str_s) == 0)
					scanf("%s", head->time);
				else if (strcmp("place", str_s) == 0)
					scanf("%s", head->place);
				else if (strcmp("num", str_s) == 0)
					scanf("%d", &head->num);
				else if (strcmp("direct", str_s) == 0)
					scanf("%d", &head->direct);
				else if (strcmp("status", str_s) == 0)
					scanf("%d", &head->status);
				else if (strcmp("exit", str_s) == 0)
					break;
				else
					printf("NOT FOUND\n");
			}
			break;
		}
		head = head->next;
	}
}

void PULL(struct City** head)
{
	struct City* temp;
	while (*head != NULL)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}

int main()
{
	int num;
	char str[20];
	struct City* temp;
	while (1)
	{
		printf("-----道路管理系统------\n");
		printf("1.录入道路信息  2.修改道路信息\n");
		printf("3.停用道路信息  4.所有道路信息\n");
		printf("5.查找道路信息  6.清除道路信息\n");
		printf("0.退出\n");
		printf("\n请输入:");
		scanf("%d", &num);
		switch (num)
		{
		case 1:
		{
			printf("输入个数:");
			scanf("%d", &num);
			while (num) {
				temp = GET(&head);
				WRITE_HAND(temp);
				num--;
			}
			break;
		}
		case 2:
		{
			printf("输入名称:");
			scanf("%s", str);
			UPDATE(head, str);
			break;
		}
		case 3:
		{
			printf("输入名称:");
			scanf("%s", str);
			DONE(head, str);
			break;
		}
		case 4:READ(head); break;
		case 5: 
		{
			printf("输入名称:");
			scanf("%s", str);
			SEARCH(head, str); 
			break;
		}
		case 6:PULL(&head);break;
		case 0:PULL(&head); exit(1);
		default:printf("输入错误\n");
		}
		printf("        OVER\n");
	}
}
