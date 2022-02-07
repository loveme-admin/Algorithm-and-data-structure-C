#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct Student *GET(struct Student**);
void WRITE_HAND(struct Student*);
void WRITE_RAND(struct Student*);//测试使用系统随机初始化
void READ(struct Student*);
void SEARCH_SAVG(struct Student*);
void SEARCH_GAVG(struct Student*);
void SEARCH_P(struct Student*);
void SEARCH_NAME(struct Student*);
void PULL(struct Student**);

struct Student
{
	char name[20];
	float Math;
	float Physics;
	float English;
	float Clanguage;
	float Moral;
	struct Student* next;
};
struct Student* head = NULL;

struct Student* GET(struct Student** head)
{
	struct Student* student;
	static struct Student* temp;
	student = (struct Student*)malloc(sizeof(struct Student));
	if (*head != NULL)
	{
		temp->next = student;
		student->next = NULL;
	}
	else
	{
		*head = student;
		student->next = NULL;
	}
	temp = student;
	return student;
}

void WRITE_HAND(struct Student* student)
{
	printf("\n请输入姓名:");
	scanf("%s", student->name);
	printf("请输入Math:");
	scanf("%f", &student->Math);
	printf("请输入Physics:");
	scanf("%f", &student->Physics);
	printf("请输入English:");
	scanf("%f", &student->English);
	printf("请输入Clanguage:");
	scanf("%f", &student->Clanguage);
	printf("请输入Moral:");
	scanf("%f", &student->Moral);
}

void WRITE_RAND(struct Student* student)
{
	static int num = 1;
	itoa(num, student->name, 10);
	student->Math = (float)(rand() % (50 - 0)) + 50;
	student->Physics = (float)(rand() % (50 - 0)) + 50;
	student->English = (float)(rand() % (50 - 0)) + 50;
	student->Clanguage = (float)(rand() % (50 - 0)) + 50;
	student->Moral = (float)(rand() % (50 - 0)) + 50;
	num++;
}

void READ(struct Student* head)
{
	printf("Name    Math    Physics  English Clanguage Moral\n");
	while (head != NULL)
	{
		printf("%3s    ", head->name);
		printf("%5.2f    ", head->Math);
		printf("%5.2f    ", head->Physics);
		printf("%5.2f    ", head->English);
		printf("%5.2f    ", head->Clanguage);
		printf("%5.2f    ", head->Moral);
		printf("\n");
		head = head->next;
	}
}

void SEARCH_GAVG(struct Student* head)
{
	int i = 1;
	float Math, Physics, English, Clanguage, Moral;
	Math = Physics = English = Clanguage = Moral = 0;
	printf("           GAVG\n");
	while (head != NULL)
	{
		Math += head->Math;
		Physics += head->Physics;
		English += head->English;
		Clanguage += head->Clanguage;
		Moral += head->Moral;
		head = head->next;
		i++;
	}
	i--;
	printf("Math       %5.2f\n", Math / i);
	printf("Physics    %5.2f\n", Physics / i);
	printf("English    %5.2f\n", English / i);
	printf("Clanguage  %5.2f\n", Clanguage / i);
	printf("Moral      %5.2f\n", Moral / i);
	printf("\n");
}

void SEARCH_SAVG(struct Student* head)
{
	float num;
	printf("Name  GAVG\n");
	while (head != NULL)
	{
		num = (head->Math + head->Physics + head->English + head->Clanguage + head->Moral) / 5;
		printf("%3s   ", head->name);
		printf("%5.2f  ", num);
		printf("\n");
		head = head->next;
	}
}

void SEARCH_P(struct Student* head)
{
	int Math_9 = 0, Math_8 = 0, Math_7 = 0, Math_6 = 0, Math_0 = 0;
	int Physics_9 = 0, Physics_8 = 0, Physics_7 = 0, Physics_6 = 0, Physics_0 = 0;
	int English_9 = 0, English_8 = 0, English_7 = 0, English_6 = 0, English_0 = 0;
	int Clanguage_9 = 0, Clanguage_8 = 0, Clanguage_7 = 0, Clanguage_6 = 0, Clanguage_0 = 0;
	int Moral_9 = 0, Moral_8 = 0, Moral_7 = 0, Moral_6 = 0, Moral_0 = 0;
	printf("           >=90 >=80 >=70 >=60 >=0\n");
	while (head != NULL)
	{
		if (head->Math >= 90)
			Math_9++;
		else if (head->Math >= 80)
			Math_8++;
		else if (head->Math >= 70)
			Math_7++;
		else if (head->Math >= 60)
			Math_6++;
		else
			Math_0++;
		if (head->Physics >= 90)
			Physics_9++;
		else if (head->Physics >= 80)
			Physics_8++;
		else if (head->Physics >= 70)
			Physics_7++;
		else if (head->Physics >= 60)
			Physics_6++;
		else
			Physics_0++;
		if (head->English >= 90)
			English_9++;
		else if (head->English >= 80)
			English_8++;
		else if (head->English >= 70)
			English_7++;
		else if (head->English >= 60)
			English_6++;
		else
			English_0++;
		if (head->Clanguage >= 90)
			Clanguage_9++;
		else if (head->Clanguage >= 80)
			Clanguage_8++;
		else if (head->Clanguage >= 70)
			Clanguage_7++;
		else if (head->Clanguage >= 60)
			Clanguage_6++;
		else
			Clanguage_0++;
		if (head->Moral >= 90)
			Moral_9++;
		else if (head->Moral >= 80)
			Moral_8++;
		else if (head->Moral >= 70)
			Moral_7++;
		else if (head->Moral >= 60)
			Moral_6++;
		else
			Moral_0++;
		head = head->next;
	}
	printf("Math       %2d   %2d   %2d   %2d   %2d\n", Math_9, Math_8, Math_7, Math_6, Math_0);
	printf("Physics    %2d   %2d   %2d   %2d   %2d\n", Physics_9, Physics_8, Physics_7, Physics_6, Physics_0);
	printf("English    %2d   %2d   %2d   %2d   %2d\n", English_9, English_8, English_7, English_6, English_0);
	printf("Clanguage  %2d   %2d   %2d   %2d   %2d\n", Clanguage_9, Clanguage_8, Clanguage_7, Clanguage_6, Clanguage_0);
	printf("Moral      %2d   %2d   %2d   %2d   %2d\n", Moral_9, Moral_8, Moral_7, Moral_6, Moral_0);
}

void SEARCH_NAME(struct Student* head)
{
	int num;
	printf("Name\n");
	while (head != NULL)
	{
		num = 0;
		if (head->Math < 60)
			num = 1;
		if (head->Physics < 60)
			num = 1;
		if (head->English < 60)
			num = 1;
		if (head->Clanguage < 60)
			num = 1;
		if (head->Moral < 60)
			num = 1;
		if (num == 1)
			printf("%s\n", head->name);
		head = head->next;
	}
}

void PULL(struct Student** head)
{
	struct Student* temp;
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
	srand((unsigned)time(NULL));
	struct Student* temp;
	while (1)
	{
		printf("-----考试管理系统------\n");
		printf("1.录入学生成绩  2.个人平均成绩\n");
		printf("3.各科平均成绩  4.各分数段人数\n");
		printf("5.不及格人名字  6.查看学生成绩\n");
		printf("7.清除表格成绩\n");
		printf("9.TEST--随机初始化录入成绩学生成绩(调试使用)\n");
		printf("0.退出\n");
		printf("\n请输入:");
		scanf("%d", &num);
		switch (num)
		{
		case 1: 
		{
			printf("输入人数:"); 
			scanf("%d", &num); 
			while (num) {
				temp = GET(&head);
				WRITE_HAND(temp);
				num--;
			}
			break; 
		}
		case 2:SEARCH_SAVG(head); break;
		case 3:SEARCH_GAVG(head); break;
		case 4:SEARCH_P(head); break;
		case 5:SEARCH_NAME(head); break;
		case 6:READ(head); break;
		case 7:PULL(&head); break;
		case 9: 
		{
			PULL(&head); 
			printf("输入人数:"); 
			scanf("%d", &num); 
			while (num) {
				temp = GET(&head);
				WRITE_RAND(temp);
				num--;
			}
			break; 
		}
		case 0:PULL(&head); exit(1);
		default:printf("输入错误\n");
		}
		printf("        OVER\n");
	}
}
