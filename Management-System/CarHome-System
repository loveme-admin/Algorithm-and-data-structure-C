#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct House* GET_HOUSE(struct House**);//车库信息创建
struct Car* GET_CAR(struct Car**);//车信息创建
void WRITE_HOUSE(struct House*);//车库信息写入信息
int WRITE_CARD(struct House*, char*, int);//车库信息写入车牌信息
void WRITE_CAR(struct Car*, char*);//以车牌信息写入车信息
void READ_HOUSE(struct House*);//读取车库信息
void UPDATE_HOUSE(struct House*, char*);//更新车库信息
void UPDATE_CAR(struct Car*, char*);//更新车信息
void SEARCH(struct House*, struct Car*, char*);//搜索车信息
void SEARCH_END(struct House*, struct Car*, char*);//结束停车信息
void PULL_HOUSE(struct House**);//删除车库信息
void PULL_CAR(struct Car**);//删除车信息


struct House
{
	char id[20];
	char card[20];
	int status;
	int big_small;
	struct House* next;
};

struct Date {
	int month;
	int day;
	int time;
	int minute;
};

struct Car {
	char card[20];
	char name[20];
	char phone[20];
	struct Date date_begin;
	struct Date date_end;
	struct Car* next;
};

struct House* head_house = NULL;
struct Car* head_car = NULL;

struct House* GET_HOUSE(struct House** head)
{
	struct House* house;
	static struct House* temp_house;
	house = (struct House*)malloc(sizeof(struct House));
	if (*head != NULL)
	{
		temp_house->next = house;
		house->next = NULL;
	}
	else
	{
		*head = house;
		house->next = NULL;
	}
	temp_house = house;
	return house;
}

struct Car* GET_CAR(struct Car** head)
{
	struct Car* car;
	static struct Car* temp_car;
	car = (struct Car*)malloc(sizeof(struct Car));
	if (*head != NULL)
	{
		temp_car->next = car;
		car->next = NULL;
	}
	else
	{
		*head = car;
		car->next = NULL;
	}
	temp_car = car;
	return car;
}

void WRITE_HOUSE(struct House* house)
{
	printf("\n请输入车位编号:");
	scanf("%s", house->id);
	printf("请输入车位状态(0启用-1停用):");
	scanf("%d", &house->status);
	printf("请输入车位大小(1大0中-1小):");
	scanf("%d", &house->big_small);
}

int WRITE_CARD(struct House* head, char* str, int num)
{
	while (head != NULL)
	{
		if (head->status == 0 && head->big_small == num)
		{
			strcpy(head->card, str);
			head->status = 1;
			break;
		}
		head = head->next;
	}
	if (head == NULL)
		return 0;
	else
		return 1;
}

void WRITE_CAR(struct Car* head, char* str)
{
	printf("\n请输入车主姓名:");
	scanf("%s", head->name);
	printf("请输入车主电话:");
	scanf("%s", head->phone);
	strcpy(head->card, str);
	printf("请输入开始时间(月-日-时-分):");
	scanf("%d-%d-%d-%d", &(head->date_begin.month), &(head->date_begin.day), &(head->date_begin.time), &(head->date_begin.minute));
	head->date_end.day = 0;
	head->date_end.month = 0;
	head->date_end.time = 0;
	head->date_end.minute = 0;
}

void READ_HOUSE(struct House* head)
{
	int num = 0;
	printf("id    big_small status \n");
	while (head != NULL)
	{
		printf("%-5s ", head->id);
		if (head->big_small == 1)
			printf("大        ");
		else if (head->big_small == 0)
			printf("中        ");
		else
			printf("小        ");
		if (head->status == 1)
			printf("使用中");
		else if (head->status == 0)
			printf("空闲中");
		else
			printf("停用中");
		printf("\n");
		if (head->status == 0)
			num++;
		head = head->next;
	}
	printf("当前可用车位:%d个\n", num);
}

void UPDATE_HOUSE(struct House* head, char* str)
{
	char str_s[20];
	while (head != NULL)
	{
		if (strcmp(head->id, str) == 0)
		{
			while (1) {
				printf("输入需要更改的名称(id,status,exit(退出)):");
				scanf("%s", str_s);
				printf("输入值(字符/0,-1):");
				if (strcmp("id", str_s) == 0)
					scanf("%s", head->id);
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

void UPDATE_CAR(struct Car* head, char* str)
{
	char str_s[20];
	while (head != NULL)
	{
		if (strcmp(head->name, str) == 0)
		{
			while (1) {
				printf("输入需要更改的名称(name,phone,exit(退出)):");
				scanf("%s", str_s);
				printf("输入值(字符/0,-1):");
				if (strcmp("name", str_s) == 0)
					scanf("%s", head->name);
				else if (strcmp("phone", str_s) == 0)
					scanf("%s", head->phone);
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

void SEARCH(struct House* head_house, struct Car* head_car, char* str)
{
	printf("name            car            phone            begin      end\n");
	while (head_house != NULL)
	{
		if (strcmp(head_house->id, str) == 0)
			strcpy(str, head_house->card);
		head_house = head_house->next;
	}
	while (head_car != NULL)
	{
		if (strcmp(head_car->name, str) == 0 || strcmp(head_car->card, str) == 0)
		{
			printf("%-12s    ", head_car->name);
			printf("%-12s    ", head_car->card);
			printf("%-12s    ", head_car->phone);
			printf("%d-%d-%d-%d   ", head_car->date_begin.month, head_car->date_begin.day, head_car->date_begin.time, head_car->date_begin.minute);
			printf("%d-%d-%d-%d", head_car->date_end.month, head_car->date_end.day, head_car->date_end.time, head_car->date_end.minute);
			printf("\n");
		}
		head_car = head_car->next;
	}
}

void SEARCH_END(struct House* head_house, struct Car* head_car, char* str)
{
	struct House* head_house_2 = head_house;
	while (head_house_2 != NULL)
	{
		if (strcmp(head_house_2->id, str) == 0)
		{
			strcpy(str, head_house_2->card);
			head_house_2 = 0;
		}
		if (head_house_2 == NULL)
			break;
		head_house_2 = head_house_2->next;
	}
	while (head_car != NULL)
	{
		if (strcmp(head_car->name, str) == 0 || strcmp(head_car->card, str) == 0)
		{

			printf("\n请输入结束时间(月-日-时-分):");
			scanf("%d-%d-%d-%d", &(head_car->date_end.month), &(head_car->date_end.day), &(head_car->date_end.time), &(head_car->date_end.minute));
			strcpy(str, head_car->card);
			break;
		}
		head_car = head_car->next;
	}
	head_house_2 = head_house;
	while (head_house_2 != NULL)
	{
		if (strcmp(head_house_2->card, str) == 0)
		{
			head_house_2->status = 0;
		}
		if (head_house_2 == NULL)
			break;
		head_house_2 = head_house_2->next;
	}
}

void PULL_HOUSE(struct House** head)
{
	struct House* temp;
	while (*head != NULL)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}

void PULL_CAR(struct Car** head)
{
	struct Car* temp;
	while (*head != NULL)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}

int main(void)
{
	int num;
	char str[20];
	struct House* temp_house;
	struct Card* temp_card;
	while (1)
	{
		printf("-----车库管理系统------\n");
		printf("1.录入车位信息  2.修改车位信息\n");
		printf("3.搜索车位信息  4.所有车位信息\n");
		printf("5.录入停车信息  6.修改停车信息\n");
		printf("7.停车结束信息  8.清除停车信息\n");
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
				temp_house = GET_HOUSE(&head_house);
				WRITE_HOUSE(temp_house);
				num--;
			}
			break;
		}
		case 2:
		{
			printf("输入车位id:");
			scanf("%s", str);
			UPDATE_HOUSE(head_house, str);
			break;
		}
		case 3:
		{
			printf("输入信息:");
			scanf("%s", str);
			SEARCH(head_house, head_car, str);
			break;
		}
		case 4:READ_HOUSE(head_house); break;
		case 5:
		{
			printf("输入车牌号:");
			scanf("%s", str);
			printf("请输入车位大小(1大0中-1小):");
			scanf("%d", &num);
			if (WRITE_CARD(head_house, str, num))
			{
				temp_card = GET_CAR(&head_car);
				WRITE_CAR(temp_card, str);
			}
			break;
		}
		case 6:
		{
			printf("输入姓名:");
			scanf("%s", str);
			UPDATE_CAR(head_car, str);
			break;
		}
		case 7:
		{
			printf("输入信息:");
			scanf("%s", str);
			SEARCH_END(head_house, head_car, str);
			break;
		}
		case 8: PULL_HOUSE(&head_house); PULL_CAR(&head_car); break;
		case 0: PULL_HOUSE(&head_house); PULL_CAR(&head_car); break;
		default:printf("输入错误\n");
		}
		printf("        OVER\n");
	}
	return 0;
}
