#include<stdio.h>//无向有权图

#define MaxVertex 20

typedef int EdegType;
typedef int VertexType;
typedef struct {
	VertexType vex[MaxVertex];
	EdegType edge[MaxVertex][MaxVertex];
	int vexnum, arcnum;
}MGraph;

void CreateMGraph(MGraph* G)
{

	int vexnum, arcnum;
	printf("Input Vexnum and Arcnum:");
	scanf("%d%d", &vexnum, &arcnum);
	G->vexnum = vexnum;
	G->arcnum = arcnum;
	for (int i = 0; i < vexnum; i++)
		G->vex[i] = i;
	for (int i = 0; i < vexnum; i++)
		for (int j = 0; j < vexnum; j++)
			if (i == j)
				G->edge[i][j] = 0;
			else
				G->edge[i][j] = 65535;

	VertexType vex1, vex2;
	EdegType power;
	for (int k = 0; k < arcnum; k++)
	{
		printf("Input Edge(x,y,z):");
		scanf("%d,%d,%d", &vex1, &vex2, &power);
		G->edge[vex1][vex2] = power;
	}
}

void PrintMGraph(MGraph G)
{
	int count = 0;
	for (int i = 0; i < G.vexnum; i++)
	{
		for (int j = 0; j < G.vexnum; j++)
			if (G.edge[i][j] == 65535)
				printf(" ∞");
			else	
				printf("%2d", G.edge[i][j]);
		printf("\n");
	}
	printf("\n");
}

void floyd(MGraph G, int *path[])  //关键函数
{
	for (int i = 0; i < G.vexnum; i++)
		for (int j = 0; j < G.vexnum; j++)
			*(*(path + i)+j) = -1;
	for (int k = 0; k < G.vexnum; k++)
		for (int i = 0; i < G.vexnum; i++)
			for (int j = 0; j < G.vexnum; j++)
				if (G.edge[i][j] > G.edge[i][k] + G.edge[k][j])
				{
					G.edge[i][j] > G.edge[i][k] + G.edge[k][j];
					path[i][j] = k;
				}
}

int main(void)
{
	MGraph G;
	int path[MaxVertex][MaxVertex];
	CreateMGraph(&G);
	PrintMGraph(G);
	floyd(G, path);
	for (int i = 0; i < G.vexnum; i++)
	{
		for (int j = 0; j < G.vexnum; j++)
			printf("%2d", path[i][j]);
		printf("\n");
	}
	return 0;
}