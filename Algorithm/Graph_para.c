#include<graphics.h>
#include<conio.h>

void Para(void);
void B(void);

void Para(void)
{
    int x, y1, y2, p = 25;
    float t = 0;
    setcolor(BLUE);
    line(0, 300, 350, 300);
    line(50, 100, 50, 450);
    setcolor(BLACK);
    //getch(); 
    for (float i = 0; i < 2.5; i = i + 0.1)
    {
        t = i;
        x = 2 * p * t * t;
        y1 = 300 + 2 * p * t;
        y2 = 300 - 2 * p * t;
        moveto(2 * p * (t - 0.1) * (t - 0.1), 300 + 2 * p * (t - 0.1));
        lineto(x, y1);
        moveto(2 * p * (t - 0.1) * (t - 0.1), 300 - 2 * p * (t - 0.1));
        lineto(x, y2);
        //getch();
    }
}

void B(void)
{
    float x0 = 380, x1 = 520, x2 = 720;
    float y0 = 350, y1 = 130, y2 = 250;
    float t;
    int xx, yy;
    setcolor(BLUE);
    fillcircle(x0, y0, 3); 
    fillcircle(x1, y1, 3); 
    fillcircle(x2, y2, 3); 
    line(x0, y0, x1, y1); 
    line(x1, y1, x2, y2);
    //getch();
    setcolor(BLACK);
    for (float i = 0; i <= 10; i++)
    {
        t = i / 10;
        xx = 0.5 * (t - 1) * (t - 1) * x0 + 0.5 * (-2 * t * t + 2 * t + 1) * x1 + 0.5 * t * t * x2;
        yy = 0.5 * (t - 1) * (t - 1) * y0 + 0.5 * (-2 * t * t + 2 * t + 1) * y1 + 0.5 * t * t * y2;
        if(i==0)
            moveto(xx, yy);
        lineto(xx, yy); 
        //getch();
    }
}

int main(void)
{
    initgraph(800, 600);
    setbkcolor(YELLOW);
    cleardevice();
    setfillcolor(BLUE);
    Para();
    B();
    getch();
    closegraph();
    return 0;
}
