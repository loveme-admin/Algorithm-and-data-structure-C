#include<stdio.h>
#include<stdlib.h>
#include"root.h"

//基本操作
Bool InitStack(SqStack*);                     //初始化线性表
Bool DestroyStack(SqStack*);                  //销毁线性表
//常用操作
Bool Push(SqStack*, EleType);            //压栈
Bool Pop(SqStack*, EleType*);            //弹栈
//辅助操作
Bool PrintStack(SqStack);                     //打印线性表
Bool MenuStack(SqStack*, ScanfQueue*);        //菜单

Bool InitStack(SqStack* stack)
{
	if (stack == NULL)
		return FALSE;
	for (int i = 0; i < MAXSIZE; i++)
		stack->data[i] = 0;
	stack->top = -1;
	return TRUE;
}

Bool DestroyStack(SqStack* stack)
{
	if (stack == NULL)
		return FALSE;
	stack->top = -1;
	return TRUE;
}

Bool Push(SqStack* stack ,EleType data)
{
	if (stack == NULL)
		return FALSE;
	if (stack->top == MAXSIZE - 1)
		return FALSE;
	stack->top++;
	stack->data[stack->top] = data;
	return TRUE;
}

Bool Pop(SqStack* stack, EleType * data)
{
	if (stack == NULL)
		return FALSE;
	if (stack->top == -1)
		return FALSE;
	*data=stack->data[stack->top];
	stack->top--;
	return TRUE;
}

Bool PrintStack(SqStack stack)
{
	if (stack.data == NULL)
		return FALSE;
	for (int i = 0; i <= stack.top; i++)
		printf("%2d ", stack.data[i]);
	printf("\n");
	return TRUE;
}

Bool MenuStack(SqStack* stack, ScanfQueue* queue)
{
	while (TRUE) {
		int num;
		printf("Input Num:");
		scanf("%d", &num);
		switch (num) {
		case 1: InitStack(stack); break;
		case 2: DestroyStack(stack); break;
		case 3:
		{
			printf("Input data:");
			ScanfPackage(queue, 1);
			Push(stack, queue->data[0]);
			break;
		}
		case 4:
		{
			queue->length++;
			Pop(stack, &(queue->data[0]));
			printf("%d\n", queue->data[0]);
			break;
		}

		case 101: PrintStack(*stack); break;
		case 102: InitRandomStack(stack); break;
		case 0: HelpStack(); break;
		case -1:return OK; break;
		default:printf("Num Error!\n");
		}
		printf("\n");
	}
}

int main(void)
{
	SqStack stack;
	ScanfQueue queue;
	HelpStack();
	MenuStack(&stack, &queue);
	return 0;
}