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

int MGraphDu(MGraph G, VertexType e) //关键函数
{
	int count = 0;
	for (int i = 0; i < G.vexnum; i++)
		for (int j = 0; j < G.vexnum; j++)
			if ((i == e || j == e) && G.edge[i][j] != 0 && G.edge[i][j] != 65535)
				count++;
	return count;
}

int main(void)
{
	MGraph G;
	CreateMGraph(&G);
	printf("%d", MGraphDu(G, 0));
	return 0;
}