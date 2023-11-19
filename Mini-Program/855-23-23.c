#include<stdio.h>
#include<stdlib.h>

typedef char TElemtype;

typedef struct BitNode {
	TElemtype data;
	struct BitNode* lchild, * rchild;
}BiTNode, * BiTree;

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

void PreTree(BiTree head)
{
	if (head) 
	{
		printf("%c ",head->data);
		PreTree(head->lchild);
		PreTree(head->rchild);
	}
}

void TranTree(BiTree head)  //关键函数
{
	BiTNode* temp;
	if (head)
	{
		TranTree(head->lchild);
		TranTree(head->rchild);
		temp = head->lchild;
		head->lchild = head->rchild;
		head->rchild = temp;
	}
}

int main(void)
{
	int count = 0;
	BiTNode* head = NULL;
	InitTree(&head);
	PreTree(head);
	TranTree(head);
	PreTree(head);
	return 0;
}