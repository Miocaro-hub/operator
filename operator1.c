#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//�������ͱ���ʽ
//1.���ֲ������Ľ���
//2.����ʽ��ֵ

//���ݷ����ࣺ��������������λ��������λ����������ֵ����������Ŀ����������ϵ��������
//            �߼������������������������ű���ʽ���±����á��������úͽṹ��Ա


//����������
//  +  -  *  /  %
//1.����%������֮�⣬�����������������������������͸�����
//2.����/�����������������������Ϊ������ִ����������.��ֻҪ�и�����ִ�еľ��Ǹ���������
//3.%����������������������Ϊ���������ص�������֮�������
int main()
{
	int a = 5 / 2;  //��2��1
	printf("a = %d\n", a);
	int b = 5 % 2;
	printf("b = %d\n", b);
	double c = 5 / 2.0;  //��������
	printf("c = %lf\n", c);

	double d = 5 % 2; //ȡģ����Ⱥ����߱�����ͬһ���ͣ����ܳ�����������ұ�С��
	printf("d = %lf\n", d);
	return 0;
}


//��λ������
// <<���Ʋ�����  >>���Ʋ�����

//  ���Ʋ�������1.��������  2.�߼�����
//  �������ƣ��ұ߶�������߲�ԭ����λ   �߼���λ���ұ߶�������߲�0
int main()
{
	int a = 16;
	int b = a >> 1;  //����һλ
	//>> -- ���Ʋ��������ƶ����Ƕ�����λ
	//a = 00000000000000000000000000010000
	printf("%d\n", b);

	int c = -1;
	//�����Ķ����Ʊ�ʾ�У�ԭ��,����,����
	//�洢���ڴ���ǲ���
	//10000000000000000000000000000001 - ԭ��
	//11111111111111111111111111111110 - ����  ����λ���䣬����λ��λȡ��
	//11111111111111111111111111111111 - ���� - �����Ĳ���=ԭ��  �����Ĳ���[x]�� = [x]��+1
	int d = c >> 2;
	printf("%d\n", c);
	//����c = -1 ����ǲ��룬������ʱ����λ���䣬����λ��Ȼ��1
	return 0;
}

//���Ʋ�����:��߶������ұ߲�0  �г�2��Ч��
int main()
{
	int a = -5;
	int b = a << 1;
	//00000000000000000000000000000101
	printf("%d\n", b);
	return 0;
}

//ps��������λ���������Ҫ�ƶ�����λ������Ǳ�׼δ�����
//���磺
int num = 10;
num >> -1; //error