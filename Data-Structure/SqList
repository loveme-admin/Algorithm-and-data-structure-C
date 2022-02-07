#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAXSIZE 5 //存储空间初始分配量
#define TURE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1 //不可实施
#define OVERFLOW -2  //溢出elem

typedef int ElemType; //定义数据类型别名
typedef int Status;
typedef struct
{
	ElemType *elem;//数组存储数据元素,最大值为MAXSIZE
	int length;//线性表当前长度
}SqList;

void CreateList(SqList *L);//利用数组初始化Sqlist
Status exist(SqList L);//自动检测创建
void menu(void);

Status InitList(SqList *L);              //初始化，动态分配一块存储空间
Status DestroyList(SqList *L);        //释放这一段存储空间（撤销对应于动态）
Status ClearList(SqList *L); //清空线性表
Status ListEmpty(SqList L);  //线性表是否有数据
Status ListLength(SqList L);  //线性表长度
Status GetElem(SqList L, int i,int *e); //根据位置查找元素值
Status LocateList(SqList L, int e); //根据元素值查找位置
Status PriorElem(SqList L, int cur_e, int *pri_e);
Status NextElem(SqList L, int cur_e, int *Nex_e);
Status ListInsert(SqList *L, int i, int e);
Status ListDelete(SqList *L, int i, int *e);
Status TravelList(SqList L); //历遍顺序表

void CreateList(SqList *L)
{
	srand(time(0));
	for (int i = 0; i < MAXSIZE; i++)
	{
		L->elem[i] = (rand() % (1000 - 0)) + 0; //(rand() % (b - a)) + a结果值将含a，不含b
	}
	L->length = MAXSIZE;
}

Status exist(SqList L)
{
	if (L.elem == NULL)
	{
		return FALSE;
	}
	return TURE;
}


//------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------

Status InitList(SqList *L)
{
	L->elem = (ElemType*)malloc(MAXSIZE * sizeof(ElemType));
	if (!L->elem)
	{
		printf("FALSE");
		exit(FALSE);
	}
	return TURE;
}

Status DestroyList(SqList *L)
{

	if (L->elem != NULL) //检测上一次申请内存是否释放，如果没有释放则自动释放(自优化)
	{	
		printf("顺序表 IS FOUND 系统自动删除中......\n");
		free(L->elem);
		printf("删除成功\n");
		L->elem = NULL;
		L->length = 0;
	}
	return TURE;
}

Status ClearList(SqList *L)
{
	L->length = 0;
	return TURE;
}

Status ListEmpty(SqList L)
{
	if (L.length == 0)
	{
		return TURE;
	}
	return FALSE;
}

Status ListLength(SqList L)
{
	return L.length;
}

Status GetElem(SqList L, int i, int *e)
{
	if (L.length == 0)
		return FALSE;
	if (i<1 || i>L.length)
		return FALSE;
	*e = L.elem[i - 1];
	return TURE;
}

Status LocateList(SqList L, int e)
{
	int i;
	for (i = 0; i < L.length; i++)
	{
		if (L.elem[i] == e)
			return i + 1;
	}
	return FALSE;
}

Status PriorElem(SqList L, int cur_e, int *pri_e)
{
	int i;
	if (L.elem[0] == cur_e)
		return FALSE;
	for (i = 1; i < L.length;i++)
		if (L.elem[i] == cur_e)
		{
			*pri_e = L.elem[i - 1];
			return TURE;
		}
	return FALSE;
}

Status NextElem(SqList L, int cur_e, int *Nex_e)
{
	int i;
	if (L.elem[L.length-1] == cur_e)
		return FALSE;
	for (i = 0; i < L.length-1; i++)
		if (L.elem[i] == cur_e)
		{
			*Nex_e = L.elem[i + 1];
			return TURE;
		}
	return FALSE;
}

Status ListInsert(SqList *L, int i, int e)
{
	int temp;
	if (L->length == MAXSIZE)
		return FALSE;
	if (i < 1 || i > L->length + 1)
		return FALSE;
	if (i <= L->length)
	{
		for (temp = L->length - 1; temp >= i - 1; temp--)
			L->elem[temp + 1] = L->elem[temp]; //从后往前后移一格
	}
	L->elem[i - 1] = e;
	L->length++;
	return TURE;
}

Status ListDelete(SqList *L, int i, int *e)
{
	int temp;
	if (i<1 || i>L->length)
		return FALSE;
	*e = L->elem[i - 1];
	if (i < L->length)
	{
		for (temp = i; temp < L->length; temp++)
		{
			L->elem[temp - 1] = L->elem[temp];
		}
	}
	L->length--;
	return TURE;
}

Status TravelList(SqList L)
{
	int i;
	for (i = 0; i < L.length; i++)
	{
		printf("%d ", L.elem[i]);
	}
	printf("\n");
	return TURE;
}

//------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------

void menu(void)
{
	printf("顺序表抽象数据类型测试系统\n\n");
	printf("a    退出主程序    b    创建顺序表\n");
	printf("c    随机初始化    d    打印顺序表\n");
	printf("e    清空顺序表    f    表是否为空\n");
	printf("g    顺序表长度    h    位置查看值\n");
	printf("i    看元素位置    j    反元素前驱\n");
	printf("k    反后继元素    l    线性表插入\n");
	printf("m    线性表删除    n    线性表帮助\n");
	printf("z    删除顺序表\n");
}

int main(void)
{
	ElemType e, cur_e, pri_e, Nex_e;
	int i, number;
	SqList L = {NULL,0};
	menu();
	while (1)
	{
		do
		{
			printf("[root@localhost ~]# ");
			number = getchar();
			rewind(stdin);
		} while (number =='\n');
		switch (number)
		{
		case 'a': DestroyList(&L); return TURE; break;
		case 'b': DestroyList(&L); InitList(&L); break;
		case 'c': if (number = exist(L) == FALSE) { printf("调用失败\n"); break; } CreateList(&L); break;
		case 'd': if (number = exist(L) == FALSE) { printf("调用失败\n"); break; } TravelList(L); break;
		case 'e': if (number = exist(L) == FALSE) { printf("调用失败\n"); break; } ClearList(&L); break;
		case 'f': if (number = exist(L) == FALSE) { printf("调用失败\n"); break; } printf("%d\n", ListEmpty(L)); break;
		case 'g': if (number = exist(L) == FALSE) { printf("调用失败\n"); break; } printf("%d\n", ListLength(L)); break;
		case 'h': if (number = exist(L) == FALSE) { printf("调用失败\n"); break; } printf("输入元素位置:"); scanf("%d", &i); rewind(stdin); if (number = GetElem(L, i, &e) == FALSE) { printf("调用失败\n"); break; }printf("%d\n", e); break;
		case 'i': if (number = exist(L) == FALSE) { printf("调用失败\n"); break; } printf("输入元素的值:"); scanf("%d", &e); rewind(stdin); number = LocateList(L, e); if (number == FALSE) { printf("调用失败\n"); break; }printf("%d\n", number); break;
		case 'j': if (number = exist(L) == FALSE) { printf("调用失败\n"); break; } printf("输入元素的值:"); scanf("%d", &cur_e); rewind(stdin); if (number = PriorElem(L, cur_e, &pri_e) == FALSE) { printf("调用失败\n"); break; }printf("%d\n", pri_e); break;
		case 'k': if (number = exist(L) == FALSE) { printf("调用失败\n"); break; } printf("输入元素的值:"); scanf("%d", &cur_e); rewind(stdin); if (number = NextElem(L, cur_e, &Nex_e) == FALSE) { printf("调用失败\n"); break; }printf("%d\n", Nex_e); break;
		case 'l': if (number = exist(L) == FALSE) { printf("调用失败\n"); break; } printf("输入元素位置:"); scanf("%d", &i); rewind(stdin); printf("输入元素的的值:"); scanf("%d", &e); rewind(stdin); if (number = ListInsert(&L, i, e) == FALSE) { printf("调用失败\n"); } break;
		case 'm': if (number = exist(L) == FALSE) { printf("调用失败\n"); break; } printf("输入元素位置:"); scanf("%d", &i); rewind(stdin);	if (number = ListDelete(&L, i, &e) == FALSE) { printf("调用失败\n"); break; } printf("%d\n", e); break;
		case 'n': menu(); break;
		case 'z': DestroyList(&L); break;
		default : printf("COMMAND NOT FOUND\n"); break;
		}
	}
}
