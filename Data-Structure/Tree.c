#include<stdio.h>
#include<stdlib.h>

typedef char ElemType;
typedef struct node{
	ElemType data;
	struct node *lchild;
	struct node *rchild;
} BiTreeNode;
BiTreeNode* head = NULL;

void CreateTnode(BiTreeNode** head)
{
	ElemType data;
	scanf("%c", &data);
	if (data == '$')
	{
		(*head) = NULL;
		return ;
	}
	else
	{
		(*head) = (BiTreeNode*)malloc(sizeof(BiTreeNode));
		(*head)->data = data;
		CreateTnode(&((*head)->lchild));
		CreateTnode(&((*head)->rchild));
	}
}
void Printf1(BiTreeNode *head)
{
	if (head)
	{
		printf("%c ",head->data);
		Printf1(head->lchild);
		Printf1(head->rchild);
	}
}
void Printf2(BiTreeNode* head)
{
	if (head)
	{
		Printf2(head->lchild);
		printf("%c ", head->data);

		Printf2(head->rchild);
	}
}
void Printf3(BiTreeNode* head)
{
	if (head)
	{
		Printf3(head->lchild);
		Printf3(head->rchild);
		printf("%c ", head->data);
	}
}
int main(void)
{
	printf("Input data:");
	CreateTnode(&head);
	Printf1(head);
	printf("\n");
	Printf2(head);
	printf("\n");
	Printf3(head);
	printf("\n");
	return 0;
}
