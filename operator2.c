#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//位操作符：
// 按位与&   按位或|  按位异或^  （他们的操作数必须是整数）

int main()
{
	//& - 按二进制位与
	int a = 3;
	int b = 5;
	int c = a & b;
	//00000000000000000000000000000011
	//00000000000000000000000000000101
	//对应的二进制位有0就是0，全是1才为1
	//00000000000000000000000000000001
	printf("%d\n", c);

	//| - 按二进制位或
	int d = 3;
	int e = 5;
	int f = 3 | 5;
	//对应的二进制位有1就为1，全是0才为0
	printf("%d\n", f);

	//^ - 按二进制位异或
	int g = 3;
	int h = 5;
	int i = g ^ h;
	//对应的二进制位相同为0，相异为1
	printf("%d\n", i);
	return 0;
}


//例题：交换两个int变量的值，不能使用第三个变量，即a=3,b=5,交换之后a=5,b=3
int main()
{
	//加减法有缺陷 - 加法有可能超出整形变量的最大值,可能会溢出
	int a = 3;
	int b = 5;
	a = a + b;
	b = a - b;
	a = a - b;
	printf("a = %d , b =%d ",a, b);

	//异或的方法
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("a = %d , b =%d ", a, b);
	return 0;
}


//例题：编写代码实现：求一个整数存储在内存中的二进制中1的个数

//方法1：
int main()
{
	int num = 0;
	int count = 0;
	scanf("%d", &num);
	//需要统计num的补码中有几个1

	while (num)
	{
		if (num % 2 == 1)  //类似于十进制，通过不断地%2，/2就可以得到从低位开始的每个数字
		{
			count++;
			num = num / 2;
		}
	}
	printf("二进制中1的个数 = %d\n", count);
	return 0;
}


//方法2：
int main()
{
	//整型变量32个bit位
	//if num&1 == 1
	//00000000000000000000000000000011
	//00000000000000000000000000000001
	//按位与
	//00000000000000000000000000000001  只有在二进制对应位都为1时才会按位与1
	//so我们可以让num的补码全部与1，然后进行移位操作，就可得到32位1的个数
	int num = 0;
	int count = 0;
	scanf("%d", &num);
	int i = 0;
	for (i = 0; i < 32; i++)
	{
		if (1 == ((num>>i)&1))
			count++;
	}
	printf("二进制中1的个数 = %d\n", count);
	return 0;
}


//方法3：
int main()
{
	int num = -1;
	int i = 0;
	scanf("%d", &num);
	int count = 0;
	while (num)
	{
		count++;
		num = num & (num - 1);
	}
	printf("二进制中1的个数 = %d\n", count);
	return 0;
}