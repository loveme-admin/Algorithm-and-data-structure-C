#include <stdio.h>
#define Y 1024
struct PAGE{
    int page;
    int block;
}A[10] = { {0,8},{9,1},{3,6},{4,0xA} ,{5,7},{1,9} ,{6,0xB},{8,2},{7,5} };
int main(void)
{
    struct
    {
        int x;
        int y;
        int p;
        int w;
    }B;
    int i;
    printf("逻辑地址:");
    scanf("%x", &B.x);
    if (B.x < 0)
        printf("输入非法！\n");
    else {
        B.p = B.x / Y;
        B.w = B.x % Y;
        for (i = 0; i < 10; i++)
            if (B.p == A[i].page)
                break;
        if (i >= 10)
            printf("查无此记录！\n");
        else
        {
            B.y = A[i].block * Y + B.w;
            printf("页号:%x 块号:%x 偏移量:%xH\n", A[i].page,A[i].block,B.w);
            printf("物理地址:%xH\n", B.y);
        }
    }
    return 0;
}
