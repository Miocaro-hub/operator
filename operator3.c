#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//赋值操作符
//赋值操作符是一个很棒的操作符，他可以让你得到一个你之前不满意的值，也就是你可以给自己重新赋值

int weight = 120; //初始化
weight = 89;//不满意就赋值
double salary = 10000.0;
salary = 20000.0; //使用赋值操作符赋值

//赋值操作符可以连续使用，比如：
int main()
{
	int a = 10;
	int x = 0;
	int y = 20;
	a = x = y + 1; //连续赋值
	printf("a = %d , x = %d , y = %d",a,x,y);
	return 0;
}

//复合赋值符
//例如： += -= *=  >>=  &=  ^=   这些运算符都可以写成复合的效果

int main()
{
	int a = 1;
	a = a + 2;
	a += 2;  //复合赋值符
	a = a >> 2;
	a >>= 2;
	a = a & 1;
	a &= 1;
	return 0;
}




