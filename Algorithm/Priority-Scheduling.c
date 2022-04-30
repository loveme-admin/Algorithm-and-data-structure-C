#include<stdio.h>
#include<stdlib.h>

typedef struct PCB { //带头结点的单链表
	int pid;
	char state;
	int priority;
	int runtime;
	int worktime;
	struct PCB* next;
}PCB;
PCB* head = NULL;

void InitList(PCB**); //初始化队列
PCB* CreateList(PCB*);//创建队列
void WriteList(PCB*);//写入数据
void SortList(PCB*);//队列优先级排序
void PrintList(PCB*);//打印单链表
float Avg_StopTime(PCB*);//等待时间计算
void PriorityRun(PCB*);//优先级调度算法

void InitList(PCB** head)
{
	PCB* temp = NULL;
	temp = (PCB*)malloc(sizeof(PCB));
	(*head) = temp;
	(*head)->pid = 0;
	(*head)->next = NULL;
}
PCB* CreateList(PCB* head)
{
	PCB* last = head;
	while (last->next != NULL)
		last = last->next;
	PCB* temp = NULL;
	PCB* length = head;
	temp = (PCB*)malloc(sizeof(PCB));
	if (last == NULL)
		head->next = temp;
	else
		last->next = temp;
	temp->next = NULL;
	length->pid++;
	return temp;
}
void WriteList(PCB* head)
{
	printf("Input (识别码 优先级 运行时间):");
	scanf("%d%d%d", &head->pid, &head->priority, &head->runtime);
	head->worktime = 0;
	head->state = 'W';
}
void SortList(PCB* head)
{
	if (head->next != NULL)
	{
		PCB* p = NULL, * q = NULL, * node = NULL;
		node = head->next->next;
		head->next->next = NULL;
		while (node != NULL)
		{
			q = node->next;
			p = head;
			while (p->next != NULL && p->next->priority < node->priority)
				p = p->next;
			node->next = p->next;
			p->next = node;
			node = q;
		}
	}
}
void PrintList(PCB* head) 
{
	head = head->next;
	while (head != NULL)
	{
		printf(" %d    ", head->pid);
		printf(" %c    ", head->state);
		printf("%d    ", head->priority);
		printf("%d        ", head->runtime);
		printf("%d    ", head->runtime - head->worktime);
		printf("\n");
		head = head->next;
	}
}
float Avg_StopTime(PCB *head)
{
	float sum = 0;
	head = head->next;
	while (head != NULL)
	{
		sum += head->runtime;
		head = head->next;
	}
	return sum;
}
void PriorityRun(PCB* head)
{
	int  num = 1;
	float  avg_runtime = 0;
	float avg_stoptime = Avg_StopTime(head);
	int length = head->pid;
	SortList(head);
	printf("——————————优先级调度算法———————————\n");
	printf("\nPID    状态    优先级    运行时间    剩余时间\n");
	printf("————————————————————————————\n");
	while ((head->pid != 0) && (head->next != NULL))
	{
		PCB* temp = head->next;
		head->next->state = 'R';
		printf("运行次数:%d\n", num);
		PrintList(head);
		temp->worktime++;
		if (temp->worktime == temp->runtime) 
		{
			avg_runtime+= num;
			head->next = head->next->next;
			head->pid--;
			printf("进程%d 已结束.\n", temp->pid);
			free(temp);
		}
		else 
		{
			temp->priority++;
			temp->state = 'W';
			SortList(head);
		}
		num++;
	}
	printf("\n进程已经完成\n");
	printf("进程平均周转时间:%.2f\n",avg_runtime/length);
	printf("进程平均等待时间:%.2f\n", avg_stoptime / length);
}
int main(void)
{
	int num = 0;
	InitList(&head);
	printf("Input Num:");
	scanf("%d", &num);
	for (int i = 1; i <= num; i++)
		WriteList(CreateList(head));
	PriorityRun(head);
}
