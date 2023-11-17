#include<stdio.h>
#include<stdlib.h>

typedef char TElemtype;

typedef struct BitNode {
	TElemtype data;
	struct BitNode* lchild, * rchild;
}BiTNode, * BiTree;

void InitTree(BiTree* head)//关键函数
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

void PreTree(BiTree head) //关键函数
{
	if (head)
	{
		printf("%c ", head->data);
		PreTree(head->lchild);
		PreTree(head->rchild);
	}
}

int main(void)
{
	BiTNode* head = NULL;
	InitTree(&head);
	PreTree(head);
	return 0;
}