#include<stdio.h>
#include<stdlib.h>

typedef char TElemtype;

typedef struct BitNode {
	TElemtype data;
	struct BitNode* lchild, * rchild;
}BiTNode, * BiTree;

typedef struct LNode {
	BiTNode* data;
	struct LNode* next;
}LNode, * Stack;

void InitStack(Stack* head)
{
	*head = (LNode*)malloc(sizeof(LNode));
	(*head)->data = NULL;
	(*head)->next = NULL;
}

void Push(Stack head, BiTNode* data)
{
	LNode* temp = NULL;
	temp = (LNode*)malloc(sizeof(LNode));
	temp->data = data;
	temp->next = head->next;
	head->next = temp;
}

void Pop(Stack head, BiTNode** data)
{
	LNode* temp = NULL;
	temp = head->next;
	head->next = head->next->next;
	*data = temp->data;
	free(temp);
}

int IsEmpty(Stack head)
{
	if (head->next == NULL)
		return 1;
	return 0;
}


void InitTree(BiTree* head)
{
	char data;
	scanf("%c", &data);
	if (data == '#')
	{
		*head = NULL;
		return;
	}
	*head = (BiTNode*)malloc(sizeof(BiTNode));
	(*head)->data = data;
	InitTree(&(*head)->lchild);
	InitTree(&(*head)->rchild);
}

void PreNoTree(BiTree head)    //关键函数
{
	Stack stack = NULL;
	BiTNode* temp = head;
	int i = 0;
	InitStack(&stack);
	while (temp || !IsEmpty(stack))
	{
		if (temp)
		{
			Push(stack, temp);
			printf("%c", temp->data);
			temp = temp->lchild;
		}
		else
		{
			Pop(stack, &temp);
			temp = temp->rchild;
		}
	}
	printf("\n");
}

int main(void)
{
	int count = 0;
	BiTNode* head = NULL;
	InitTree(&head);
	PreNoTree(head);
	return 0;
}