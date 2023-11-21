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

void DelElem(BiTree *head)
{
	if (*head)
	{
		DelElem(&((*head)->lchild));
		DelElem(&((*head)->rchild));
		free(*head);
	}
}

void DelTree(BiTree *head, TElemtype e)
{
	if (*head)
	{
		if (( * head)->data == e)
		{
			DelElem(head);
			*head = NULL;
		}
		else
		{
			DelTree(&((*head)->lchild), e);
			DelTree(&((*head)->rchild), e);
		}
	}
}

int main(void)
{
	int count = 0;
	BiTNode* head = NULL;
	InitTree(&head);
	PreTree(head);
	printf("\n");
	DelTree(&head,'b');
	PreTree(head);
	return 0;
}