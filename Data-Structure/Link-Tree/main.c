#include<stdio.h>
#include<stdlib.h>
#include"root.h"
//基本操作
Bool InitTree(TNode**);
//常用操作

//辅助操作
Bool PrintTree(TNode*);

Bool InitTree(TNode** head)
{
	if (head == NULL)
		return FALSE;
	char data='\0';
	scanf("%c",&data);
	if (data == '#') 
	{
		*head = NULL;
		return TRUE;
	}
	*head = (TNode*)malloc(sizeof(TNode));
	if (*head == NULL)
		return FALSE;
	(*head)->data = data;
	InitTree(&(*head)->lchild);
	InitTree(&(*head)->rchild);
	return TRUE;
}

Bool PrintTree(TNode* head)
{
	if (head)
	{
		printf("%c",head->data);
		PrintTree(head->lchild);
		PrintTree(head->rchild);
	}
	return TRUE;
}


Bool MenuList(TNode** head, ScanfQueue* queue)
{
	while (TRUE) {
		int num;
		printf("Input Num:");
		scanf("%d", &num);
		switch (num) {
		case 1: 
			{
				getchar(); 
				printf("Input Data:"); 
				InitTree(head); 
				break; 
			}
		case 101: PrintTree(*head); break;
		case 102: break;
		case 0: HelpList(); break;
		case -1:return OK; break;
		default:printf("Num Error!\n");
		}
		printf("\n");
	}
}

int main(void)
{
	TNode* head = NULL;
	ScanfQueue queue;
	HelpList();
	MenuList(&head,&queue);
	return 0;
}