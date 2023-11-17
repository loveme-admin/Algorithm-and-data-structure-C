#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"root.h"

//辅助操作

Bool HelpList()
{
	printf(" 1   初始线性表 2   销毁线性表\n");
	printf(" 3   按位插入值 4   按位删除值\n");
	printf(" 5   按值查找位 6   按位查找值\n");
	printf(" 7   头插建立表 8   尾插建立表\n");
	printf(" 101 打印线性表 102 随机初始化\n");
	printf("-1   退出线性表 0   帮助线性表\n");
	printf("-1   结束输入值\n");
	return TRUE;
}