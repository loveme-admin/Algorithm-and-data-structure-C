#include<stdio.h>

#define MAXSIZE 10

typedef int VexType;
typedef int EdegType;
typedef struct MGraph {
	VexType vex[MAXSIZE];
	EdegType edge[MAXSIZE][MAXSIZE];
	int vexnum, edgenum;
}MGraph;

void InitMGraph(MGraph* G)
{
	int vexnum, edgenum;
	int vex1, vex2;
	printf("Input Vexnum and Edgenum:");
	scanf("%d%d",&vexnum,&edgenum);
	G->edgenum = vexnum;
	G->edgenum = edgenum;
	for (int i = 0; i < G->edgenum; i++)
		for (int j = 0; j < G->edgenum; j++)
			if (i == j)
				G->edge[i][j] = 0;
			else
				G->edge[i][j] = 65535;
	for (int i = 0; i < G->edgenum; i++)
	{
		printf("Input Edge(x,y):");
		scanf("%d,%d",&vex1,&vex2);
		G->edge[vex1][vex2] = 1;
		G->edge[vex2][vex1] = 1;
	}
}

void CountMGraph(MGraph *G, int* count) //关键函数
{
	int temp;
	for (int i = 0; i < G->edgenum; i++)
	{
		temp = 0;
		for (int j = 0; j < G->edgenum; j++)
			if (G->edge[i][j] == 1)
				temp++;
		if (temp == 2)
			(* count)++;
	}
}

int main(void)
{
	MGraph G;
	int count = 0;
	InitMGraph(&G);
	CountMGraph(&G, &count);
	printf("%d",count);
	return 0;
}