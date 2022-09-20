#include <graphics.h>
#include <conio.h>
#include <math.h>

void Encode(int[][2], int*, int*);
void Cohen_sutherland(int[][2],int *,int*);

void Encode(int rect[][2], int* xy, int* code)
{
    int c = 0;
    if (*xy < *(*rect))
        c |= byte(1);
    else if (*xy > *(*(rect + 1)))
        c |= byte(2);
    if (*(xy + 1) < *((*rect) + 1))
        c |= byte(4);
    else if (*(xy + 1) > *(*(rect + 1) + 1))
        c |= byte(8);
    *code = c;
}
void Cohen_sutherland(int rect[][2],int *xy1,int *xy2)
{
    int code1 = 0, code2 = 0, code = 0;
    int xytemp[2] = {0};
    line(xy1[0], xy1[1], xy2[0], xy2[1]);
    Encode(rect, xy1, &code1);
    Encode(rect, xy2, &code2);
    while ((code1 != 0) || (code2 != 0))
    {
        if ((code1 & code2) != 0)
           return;
        code = code1;
        if (code1 == 0)
            code = code2;
        if ((byte(1) & code) != 0)
        {
            xytemp[0] = *(*rect);
            xytemp[1] = xy1[1] + (xy2[1] - xy1[1]) * (*(*rect) - xy1[0]) / (xy2[0] - xy1[0]);
        }
        else if ((byte(2) & code) != 0)
        {
            xytemp[0] = *(*(rect + 1));
            xytemp[1] = xy1[1] + (xy2[1] - xy1[1]) * (*(*(rect + 1)) - xy1[0]) / (xy2[0] - xy1[0]);
        }
        else if ((byte(4) & code) != 0)
        {
            xytemp[1] = *(*(rect)+1);
            xytemp[0] = xy1[0] + (xy2[0] - xy1[0]) * (*(*(rect)+1) - xy1[1]) / (xy2[1] - xy1[1]);
        }
        else if ((byte(8) & code) != 0)
        {
            xytemp[1] = *(*(rect + 1) + 1);
            xytemp[0] = xy1[0] + (xy2[0] - xy1[0]) * (*(*(rect + 1) + 1) - xy1[1]) / (xy2[1] - xy1[1]);
        }
        if (code == code1)
        {
            xy1[0] = xytemp[0];
            xy1[1] = xytemp[1];
            Encode(rect, xytemp, &code1);
        }
        else
        {
            xy2[0] = xytemp[0];
            xy2[1] = xytemp[1];
            Encode(rect, xytemp, &code2);
        }
    }
    cleardevice();
    setcolor(RED);
    line(xy1[0], xy1[1], xy2[0], xy2[1]);
}

int main(void)
{
    initgraph(600, 600);
    setbkcolor(YELLOW);
    cleardevice();
    int xy[][2] = { {100,100},
                    {400,300}};
    int xy1[] = { 150  , 50 };
    int xy2[] = { 450 , 150 };
    setcolor(BLACK);
    rectangle(xy[0][0], xy[0][1], xy[1][0], xy[1][1]);
    getch();
    setcolor(RED);
    line(xy1[0], xy1[1], xy2[0], xy2[1]);
    getch();

    Cohen_sutherland(xy,xy1,xy2);
    setcolor(BLACK);
    rectangle(xy[0][0], xy[0][1], xy[1][0], xy[1][1]);
    getch();
    closegraph();
    return 0;
}
