#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<stdio.h>

#define MAX 5                         //5边形图

void InitGraph(int* );
void Change(int*,int [][2]);
void BaseGraph(int* );
void Matrix_revolve(int[][2], int*, int[][2]);
void Matrix_tran(int[][2], int*, int[][2]);
void DrawGraph(int[][2]);

void InitGraph(int* xymax)
{
	initgraph(*xymax, *(xymax+1));
	setbkcolor(YELLOW);
	setcolor(RED);
	cleardevice();
}
void Change(int* xymax,int xy2[][2])
{
	for(int i=0;i<=MAX;i++)
	{
		*(*(xy2 + i)) = *xymax / 2 + *(*(xy2 + i));
		*(*(xy2 + i)+1) = *(xymax+1) / 2 - *(*(xy2 + i) + 1);
	}
}
void BaseGraph(int* xymax)
{
	line(0, *(xymax + 1)/2, *xymax, *(xymax + 1)/2);
	line(*xymax/2, 0, *xymax/2, *(xymax + 1));
}
void Matrix_revolve(int xy1[][2], int* angle, int xy2[][2])
{
	int h = 1;
	double th = *angle / 180.0 * 3.1415926;
	double mat[3][3] = {{cos(th),sin(th),0},
						{-sin(th),cos(th),0},
						{0,0,1}};
	for (int i = 0; i <= MAX; i++)
	{
		*(*(xy2+i)) = *(*(xy1+i)) * mat[0][0] + *(*(xy1 + i)+1) * mat[1][0] + h * mat[2][0];
		*(*(xy2+i)+1)= *(*(xy1 + i)) * mat[0][1] + *(*(xy1 + i)+1) * mat[1][1] + h * mat[2][1];
	}
}
void Matrix_tran(int xy1[][2], int* dxy, int xy2[][2])
{
	int h = 1;
	double mat[3][3] = { {1,0,0},
						 {0,1,0},
						 {*dxy,*(dxy+1),1} };
	for (int i = 0; i <= MAX; i++)
	{
		*(*(xy2 + i)) = *(*(xy1 + i)) * mat[0][0] + *(*(xy1 + i) + 1) * mat[1][0] + h * mat[2][0];
		*(*(xy2 + i) + 1) = *(*(xy1 + i)) * mat[0][1] + *(*(xy1 + i) + 1) * mat[1][1] + h * mat[2][1];
	}
}
void DrawGraph(int xy2[][2])
{
	for (int i = 0; i <= MAX - 1; i++)
		line(*(*(xy2 + i)), *(*(xy2 + i) + 1), *(*(xy2 + i + 1)), *(*(xy2 + i + 1) + 1));
}
int main(void)
{
	int xymax[]={ 800,800 };        //显示器长宽
	InitGraph(xymax);
	BaseGraph(xymax);
	int xy1[MAX+1][2] = {{50,100},  //多边形顶点
						 {120,10},
						 {150,50},
					 	 {150,150},
						 {120,190},
					 	 {50,100}};
	int xy2[MAX+1][2] = {0};
	int dxy[2] = {0};
	//图形平移
	for (int count = 0; count <= 50; count ++)
	{
		dxy[0] += 0;                //平移偏移量
		dxy[1] += 8;
		Matrix_tran(xy1, dxy, xy2);
		Change(xymax, xy2);
		DrawGraph(xy2);
		getch();
	}
	//图形旋转
	for (int angel = 0; angel < 360; angel += 3)
	{
		Matrix_revolve(xy1, &angel, xy2);
		Change(xymax,xy2);
		DrawGraph(xy2);
		getch();
	}

	getch();
	closegraph();
	return 0;
}
