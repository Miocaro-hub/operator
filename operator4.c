#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//
//单目操作符:只有一个操作数
//! - 逻辑反操作 ,  -  - 负值 , +  - 正值，  & - 取地址 , 
//sizeof - 操作数的类型长度（以字节为单位）
// ~ - 对一个数的二进制按位取反
// --  -  前置,后置 , ++  - 前置,后置
// * - 简介访问操作符（解引用操作符）
//(类型) - 强制类型转换


//a+b  +是双目操作符

int main()
{
	int a = 19;
	/*printf("%d\n", !a); */ //把真变假，把假变真

	//a为真值
	if (a)
	{
		printf("hi,siri");  
	}
	//a为假
	if (!a)
	{
		printf("hello world\n");
	}

	int b = 10;
	int*p = &b;//取地址操作符  p被称为指针变量
    //解引用操作符,表示对其所选变量的引用
	//*p就是b的引用，*p的值发生变化，b的值也会随之发生改变
	return 0;
}

int main()
{
	int a = 10;
	char c = 'r';
	char*p = &c;
	int arr[10] = { 0 };
	//sizeof计算变量所占内存的大小，单位是字节
	printf("%d\n", sizeof(a)); //4   sizeof(a) = sizeof(int) 
	printf("%d\n", sizeof(c)); //1   sizeof(b) = sizeof(char)
	printf("%d\n", sizeof(p)); //4   sizeof(p) = sizeof(char*)
	printf("%d\n", sizeof(arr)); //40  sizeof(arr) = sizeof(int [10])
	//sizeof计算变量时可以省去括号,计算类型时不可

	short s = 0;
	int d = 10;
	printf("%d\n", sizeof(s = d + 5));  //2  short类型所占大小为两个字节  sizeof不会影响参数的值，不参与运算
	printf("%d\n", s);  //0
	return 0;
}

//  ~ 对一个数的二进制按位取反
int main()
{
	int a = 0;
	//a
	//a的二进制表示形式
	//00000000000000000000000000000000  (补码)
	//11111111111111111111111111111111 -补码  (按位取反之后的结果)
	//11111111111111111111111111111110 - 反码
	//10000000000000000000000000000001 - 原码
	// -1
	printf("%d\n", ~a);  //按二进制位取反,打印时候打印的是原码


	int b = 11; 
	//00000000000000000000000000001011  如何将倒数第三位变为1
	//只需按位或上
	//00000000000000000000000000000100
	//1<<2
	b = b | ((1 << 2));
	printf("%d\n", b);  //15



	//00000000000000000000000000001111  如何再将倒数第三位变为0
	//只需与上
	//11111111111111111111111111111101
	//可得
	//00000000000000000000000000001101  
	//11111111111111111111111111111101 只需   00000000000000000000000000000010按位取反就可得到
	b = b & (~(1 << 2));
	printf("%d\n", b);  //11
	return 0;
}



//++  --  前置、后置
int main()
{
	int a = 10;
	printf("%d\n", ++a);  //前置++,先++,后使用  打印出来的值为11
	printf("%d\n", a++);  //后置++,先使用,后++  打印出来的值为10
	return 0;
}



//（类型） - 强制类型转换
int main()
{
	int a =(int)3.14;
	return 0;
}


//例题：程序输出的结果是什么
void test1(int arr[])
{
	printf("%d\n", sizeof(arr));
}

void test2(char ch[])
{
	printf("%d\n", sizeof(ch));
}

int main()
{
	int arr[10] = { 0 };
	char ch[10] = { 0 };
	printf("%d\n", sizeof(arr));  //40
	printf("%d\n", sizeof(ch));  //10
	test1(arr);  //数组在传参是传的是首元素的地址,传过去arr作为指针接收  指针所占字节为4(默认32位),所以结果为4
	test2(ch);  //同理为4
	return 0;
}