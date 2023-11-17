#include<stdio.h>//������Ȩͼ

#define OK -1001
#define ERROS -1002
#define TRUE -1003
#define FALSE -1004

typedef int Bool;

#define MaxVertex 20

typedef int EdegType;
typedef char VertexType;
typedef struct {
	VertexType vex[MaxVertex];
	EdegType edge[MaxVertex][MaxVertex];
	int vexnum, arcnum;
}MGraph;

Bool CreateMGraph(MGraph *); //����ͼ
Bool DestroyMGraph(MGraph*); //����ͼ

int LocateVex(MGraph*, VertexType);//����Ԫ���±�


Bool PrintfMGraph(MGraph);   //��ӡͼ

Bool CreateMGraph(MGraph *G)
{
	if (G == NULL)
		return FALSE;
	int vexnum, arcnum;
	printf("Input Vexnum and Arcnum:");
	scanf("%d%d",&vexnum,&arcnum);
	G->vexnum = vexnum;
	G->arcnum = arcnum;
	for (int i = 0; i < vexnum; i++)
		for (int j = 0; j < vexnum; j++)
			if (i == j)
				G->edge[i][j] = 0;
			else
				G->edge[i][j] = 65535;
	printf("Input Vex :" );
	getchar();
	for (int i = 0; i < vexnum; i++)
		scanf("%c",&(G->vex[i]));
	VertexType vex1, vex2;
	EdegType power;
	for (int k = 0; k < arcnum; k++)
	{
		printf("Input Edge(x,y,z):");
		getchar();
		scanf("%c,%c,%d",&vex1,&vex2,&power);
		int i = LocateVex(G,vex1);
		int j = LocateVex(G,vex2);
		G->edge[i][j] = power;
		G->edge[j][i] = power;
	}
	return TRUE;
}

Bool DestroyMGraph(MGraph* G)
{
	if (G == NULL)
		return FALSE;
	for (int i = 0; i < G->vexnum; i++)
	{
		G->vex[i] = 0;
		for (int j = 0; j < G->vexnum; j++)
			G->edge[i][j] = 0;
	}
	G->arcnum = 0;
	G->vexnum = 0;
	return TRUE;
}

int LocateVex(MGraph* G, VertexType vex)
{
	if (G == NULL)
		return FALSE;
	for (int i = 0; i < G->vexnum; i++)
		if (vex == G->vex[i])
			return i;
	return -1;
}


Bool PrintfMGraph(MGraph G)
{
	for (int i = 0; i < G.vexnum; i++)
		printf("%10c", G.vex[i]);
	printf("\n");
	for (int i = 0; i < G.vexnum; i++)
	{
		for (int j = 0; j < G.vexnum; j++)
			if (G.edge[i][j] == 65535)
				printf("         ��");
			else
				printf("%10d", G.edge[i][j]);
		printf("\n");
	}
	return TRUE;
}

int main(void)
{
	MGraph G;
	CreateMGraph(&G);
	PrintfMGraph(G);
	return 0;
}
