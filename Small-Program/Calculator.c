#include<stdio.h>

int add(int, int);
int sub(int, int);
int mul(int, int);
int div(int, int);
int(*symbol(char))(int, int);

int add(int x, int y)
{
	return x + y;
}

int sub(int x, int y)
{
	return x - y;
}

int mul(int x, int y)
{
	return x * y;
}

int div(int x, int y)
{
	return x / y;
}

int(*symbol(char z))(int, int)
{
	switch(z)
	{
		case '+': return(add);
		case '-': return(sub);
		case '*': return(mul);
		case '/': return(div);
	}
}

int main(void)
{
	int x, y;
	char character;
	int(*swap)(int, int);
	printf("请输入一个运算式(2+3):");
	scanf("%d%c%d",&x,&character,&y);
	swap = symbol(character);
	printf("%d%c%d=%d",x,character,y,swap(x,y));
	return 0;
}
