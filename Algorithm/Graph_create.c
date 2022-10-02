#include<graphics.h>
#include<conio.h>

void Bresenhamline(int, int, int, int, int);
int C_X(int );
int C_Y(int );
void circlepoints(int, int, int);
void MidPointCircle(int, int);

void Bresenhamline(int x0, int y0, int x1, int y1, int color)
{
	int x, y, dx, dy;
	float k, e;
	dx = x1 - x0;
	dy = y1 - y0;
	k = dy / dx;
	e = -0.5;
	x = x0;
	y = y0;
	for (int i = 0; i <= dx; i++)
	{
		putpixel(x, y, color);
		x = x + 1;
		e = e + k;
		if (e >= 0)
		{
			e = e - 1;
			y++;
		}
	}
}
int C_X(int x)
{
	int xmax = 800,px=150;
	return xmax / 2 + x+px;
}
int C_Y(int y)
{
	int ymax = 500,py=-50;
	return (ymax / 2 - y+py);
}
void circlepoints(int x, int y, int color)
{
	putpixel(C_X(x), C_Y(y), color);
	putpixel(C_X(x), C_Y(-y), color);
	putpixel(C_X(-x), C_Y(y), color);
	putpixel(C_X(-x), C_Y(-y), color);
	putpixel(C_X(y), C_Y(x), color);
	putpixel(C_X(y), C_Y(-x), color);
	putpixel(C_X(-y), C_Y(x), color);
	putpixel(C_X(-y), C_Y(-x), color);
}
void MidPointCircle(int r ,int color)
{
	int x, y;
	float d;
	x = 0;
	y=r;
	d = 1.25 - r;
	circlepoints(x, y, color);
	while (x <= y)
	{	
		if (d < 0)
			d += 2 * x + 3;
		else
		{
			d += 2 * (x - y) + 5;
			y--;
		}
		x++;
		circlepoints(x, y, color); 
	}
}

int main(void)
{
	initgraph(800,500);
	setbkcolor(WHITE);
	cleardevice();
	//Bresenhamline
	Bresenhamline(50,50,350,750,RED);
	//getch();
	//中点画圆
	MidPointCircle(150,BLUE);
	getch();

	closegraph();
	return 0;
}
