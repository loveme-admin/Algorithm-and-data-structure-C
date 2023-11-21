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
		printf("%c ", head->data);
		PreTree(head->lchild);
		PreTree(head->rchild);
	}
}

int IsSortTree(BiTree head)
{
	if (head)
	{
		if (head->lchild && head->lchild->data > head->data)
			return 0;
		if (head->rchild && head->rchild->data <  head->data)
			return 0;
		if(!IsSortTree(head->lchild))
			return 0;
		if(!IsSortTree(head->rchild))
			return 0;
	}
	return 1;
}

int main(void)
{
	int count = 0;
	BiTNode* head = NULL;
	InitTree(&head);
	PreTree(head);
	printf("%d",IsSortTree(head));
	return 0;
}