#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//关系操作符
//  >  >=  <  <=  !=用于测试“不相等”   ==用于测试“相等”


//逻辑操作符
//  && - 逻辑与  || - 逻辑或
//需要区分逻辑与和按位与，逻辑或和按位或

/*相同点：&和&&都可以用作逻辑与的运算符，表示逻辑与（and）
  不同点：
（1）&&具有短路的功能,而&不具备短路功能.
（2）当&运算符两边的表达式的结果都为true时,整个运算结果才为true.而&&运算符第一个表达式为false时,则结果为false,不再计算第二个表达式.
（3）&还可以用作位运算符,当&操作符两边的表达式不是boolean类型时,&表示按位与操作，我们通常使用0x0f来与一个整数进行&运算,来获取该整数的最低4个bit位,例如：0x31 & 0x0f的结果为0x01.*/

int main()
{
	int a = 0;
	int b = 5;
	int c = a && b;
	int d = a || b;
	printf("%d\n", c);  //a,b都为真时结果为真,输出结果为1  a,b有一个为假则结果为假,输出结果为0
	printf("%d\n", d);  //a,b有一个为真则结果为真,输出结果为1  a,b同时为假的时候才为假,输出结果为0
	return 0;
}


//例题：输出结果是什么
int main()
{
	int i = 0, a = 0, b = 2, c = 3, d = 4; 
	i = a++ && ++b && d++;  //a++先使用和++,所以使用时a的值为0,这是已经进行逻辑与运算,结果为假, 后面都不进行计算,值不变
	printf("a = %d  b = %d  c = %d d = %d", a, b, c, d);   //a = 1 , b = 2 , c = 3 , d = 4

	int i = 0, a = 1, b = 2, c = 3, d = 4;
	i = a++ && ++b && d++;
	printf("a = %d  b = %d  c = %d d = %d", a, b, c, d);  //a = 2 , b = 3 , c = 3 , d = 5

	int i = 0, a = 1, b = 2, c = 3, d = 4;
	i = a++ || ++b || d++;  //a为真,结果就为真,后面的结果都不计算
	printf("a = %d  b = %d  c = %d d = %d", a, b, c, d);  //a = 2 , b = 2 , c = 3 , d = 4

	return 0;
}



//条件操作符(三目操作符)
//exp1 ? exp2 : exp3  意思为exp1的结果若为真,计算exp2,exp2的结果作为整个的结果.exp1的结果若为假,计算exp3,exp3的结果作为整个的结果

//例题：
int main()
{
	int a = 0, b = 0;

	if (a > 5)
		b = 3;
	else
		b = -3;

	//转换成条件表达式,是什么样
	b = (a > 5 ? 3 : -3);
	printf("%d\n", b);

	//如何利用条件表达式求出两个值中的最大值
	int a = 10, b = 20,max = 0;
	max = (a > b ? a : b);
	return 0;
}

 
//逗号表达式
//exp1,exp2,exp3,...exp4
//用逗号隔开的多个表达式.逗号表达式,从左向右依次执行.整个表达式的结果是最后一个表达式的结果

int main()
{
	int a = 1;
	int b = 2;
	int c = (a > b , a = b + 10, a , b = a + 1);  //逗号表达式  最终结果为13

	//if(a = b+1,c = a/2 ,d>0)  最终的判定条件为d>0,但前面需要进行计算
	return 0;
}


int main()
{
	int a = 9;
	a = get_val();
	count_val(a);
	while (a > 0)
	{
		//业务处理
		a = get_val();
		count_val(a);
	}

	//如果用逗号表达式改写:
	while (a = get_val(a),count_val(a),a>0)
	{
		//业务处理
	}
	return 0;
}