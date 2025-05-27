#include <stdio.h>
#include <stdbool.h>
#include <stdint.h> //c99ǥ�� ����
#define _USE_MATH_DEFINES // math.h������ (ǥ�� �ƴ϶�)
#include <math.h> //M_PI ���� ����


/*
//OperatorFour.c
int main(void)
{
	int num1 = 12;
	int num2 = 12;

	printf("num1: %d \n", num1);
	printf("num1++: %d \n", num1++);								//	��������
	printf("num1: %d \n\n", num1);

	printf("num2: %d \n", num2);
	printf("++num2: %d \n", ++num2);								//	��������
	printf("num12 %d \n\n", num2);

	return 0;
}


//OperatorSeven.c
int main(void)
{
	int num1 = 10;
	int num2 = 12;
	int result1, result2, result3;

	result1 = (num1 == 10 && num2 == 12);
	result2 = (num1 < 12 || num2 > 12);
	result3 = (!num1);

	printf("result1: %d \n", result1);
	printf("result2: %d \n", result2);
	printf("result3: %d \n", result3);

	return 0;
}


//CommaOp.c ��Ģ�� printf�� ������ ��� ��
int main(void)
{
	int num1 = 1, num2 = 2;
	printf("Hello "), printf("world!  \n");
	num1++, num2++;
	printf("%d ", num1), printf("%d ", num2), printf("\n");

	return 0;
}


//SimpleAddThree.c
int main(void)
{
	int result;
	int num1, num2;

	printf("���� one: ");
	scanf_s("%d", &num1);
	printf("���� two: ");
	scanf_s("%d", &num2);

	result = num1 + num2;
	printf("%d + %d = %d \n", num1, num2, result);

	return 0;
}


// 4-3-1 01001111=79 00110011=51
// 4-3-2 10101001=-41 11110000=-112 �ٽ� Ȯ��

//�Ǽ��� ���� ����
int main(void)
{
	float f = 0.0F;
	int i = 0;
	for (f = 0.0;f < 100.0f; f+=.1f, i++) {
		printf("f : %f\n", f);
	}

	printf("i: %d\n", i);
	return 0;
}


//BitAndOperation.c -> �� 4�� ���? ������� 00000100 �̶�!
int main(void)
{
	int num1 = 15;
	int num2 = 20;
	int num3 = num1 & num2;
	printf("AND ������ ���: %d \n", num3);

	return 0;
	
}


//BitNotOperation.c
int main(void)
{
	int num1 = 15;
	int num2 = ~num1;
	printf("NOT������ ��� %d \n", num2);

	return 0;
}


//BitLeftShift.c
int main(void)
{
	int num = 15;

	int result1 = num << 1;
	int result2 = num << 2;
	int result3 = num << 3;

	printf("1ĭ �̵� : %d \n", result1);
	printf("2ĭ �̵� : %d \n", result2);
	printf("3ĭ �̵� : %d \n", result3);

	return 0;
}


//SizeOfOperator.c
int main(void)
{
	char ch = 9;
	int inum = 1052;
	double dnum = 3.1415;

	printf("���� chũ�� : %d \n", sizeof(ch));
	printf("���� inumũ�� : %d \n", sizeof(inum));
	printf("���� dnumũ�� : %d \n", sizeof(dnum));

	printf("charũ�� : %d \n", sizeof(int8_t));
	printf("shortũ�� : %d \n", sizeof(int16_t));
	printf("intũ�� : %d \n", sizeof(int32_t));
	printf("longũ�� : %d \n", sizeof(int64_t));
	printf("long longũ�� : %d \n", sizeof(long long));
	printf("floatũ�� : %d \n", sizeof(float));
	printf("doubleũ�� : %d \n", sizeof(double));

	return 0;
}


//CharShortBaseAdd.c
int main(void)
{
	char num1 = 1, num2 = 2, result1 = 0;
	short num3 = 300, num4 = 400, result2 = 0;

	printf("size of num1 & num2 : %d %d \n", sizeof(num1), sizeof(num2));
	printf("size of num3 & num4 : %d %d \n", sizeof(num3), sizeof(num4));

	printf("size of char add : %d \n", sizeof(num1 + num2));
	printf("size of short add: %d \n", sizeof(num3 + num4));

	result1 = num1 + num2;
	result2 = num3 + num4;
	printf("size of result1 & result2 : %d %d\n", sizeof(result1), sizeof(result2));
	
	return 0;
}


//CircleArea.c
int main(void)
{
	double rad;
	double area;
	printf("���� ������ �Է�: ");
	scanf_s("%lf", &rad);

	area = rad * rad * M_PI;
	printf("���� ����: %f", area);
	
	return 0;
}


//HowChar.c
int main(void)
{
	char ch1 = 'A', ch2 = 65;
	int ch3 = 'Z', ch4 = 90;

	printf("%c %d \n", ch1, ch1);
	printf("%c %d \n", ch2, ch2);
	printf("%c %d \n", ch3, ch3);
	printf("%c %d \n", ch4, ch4);
	
	return 0;
}


//5-1-1
int main(void)
{
	int lx = 0, ly = 0, rx = 0, ry = 0;
	int area = 0;

	printf("�»���� x, y ��ǥ : ");
	scanf_s("%d %d", &lx, &ly);
	printf("���ϴ��� x, y ��ǥ : ");
	scanf_s("%d %d", &rx, &ry);

	area = (rx - lx) * (ry - ly);
	printf("\n���̴� %d", area);

	return 0;
}


//5-1-2
int main(void)
{
	double f1 = 0, f2 = 0;
	printf("�Ǽ� �� �� �Է� : ");
	scanf_s("%lf %lf", &f1, &f2);

	printf("%f + %f = %f\n", f1, f2, f1 + f2); //.2f �̷� ������ ���� �Ҽ��� 2����
	printf("%f - %f = %f\n", f1, f2, f1 - f2);
	printf("%f x %f = %f\n", f1, f2, f1 * f2);
	printf("%f �� %f = %f\n", f1, f2, f1 / f2);

	return 0;
}


//5-1-3
//1: 0 ~ 127
//2: 1��Ʈ�� ����
//3: a(97) A(65) 32���� ����: ���ĺ� ���� 25, �߰��� Ư������

//5-1-4
int main(void)
{
	int asc = 0;
	printf("�ƽ�Ű�ڵ� ���� �� ���� �Է�: ");
	scanf_s("%d", &asc);

	printf("%c", asc);

	return 0;
}


//5-1-5
int main(void)
{
	char alphabet = '0';

	printf("���ĺ� ���� �ϳ� �Է� : ");
	scanf_s("%c", &alphabet);

	printf("\n������ %d", alphabet);

	return 0;
}


//AutoConvOne.c
int main(void)
{
	double num1 = 245;
	int num2 = 3.1415;							//	�Ҽ��� �ս�
	int num3 = 129;								//	������Ʈ�� �ս�
	char ch = num3;

	printf("���� 245 �Ǽ��� : %f\n", num1);
	printf("�Ǽ� 3.1415 ������ : %d\n", num2);
	printf("ū ���� 129 ���� ������ : %d\n", ch); 

	return 0;
}


//ConvDiv.c
int main(void)
{
	int num1 = 3, num2 = 4;
	double divResult;

	divResult = num1 / num2;
	printf("������ ��� : %f \n", divResult);
	
	return 0;
}


//ConvDiv2.c
int main(void)
{
	int num1 = 3, num2 = 4;
	double divResult;

	divResult = (double)num1 / (double)num2; //�� �� �ϳ����� ��������ȯ �ص� ���� �������!
	printf("������ ��� : %f \n", divResult);

	return 0;
}


//OctHex.c
int main(void)
{
	int num1 = 7, num2 = 13;
	printf("%o %#o \n", num1, num1);
	printf("%x %#x \n", num2, num2);

	return 0;
}


//UsingPG.c
int main(void)
{
	double d1 = 1.23e-3;		//	0.00123
	double d2 = 1.23e-4;		//	0.000123
	double d3 = 1.23e-5;		//	0.0000123
	double d4 = 1.23e-6;		//	0.00000123

	printf("%g \n", d1);		//	%f��Ÿ�� ���
	printf("%g \n", d2);		//	%f��Ÿ�� ���
	printf("%g \n", d3);		//	%e��Ÿ�� ���
	printf("%g \n", d4);		//	%e��Ÿ�� ���

	return 0;
}


//FiedlWidth.c
int main(void)
{
	printf("%-8s %14s %5s \n", "��  ��", "�����а�", "�г�");
	printf("%-8s %14s %5d \n", "�赿��", "���ڰ���", 3);
	printf("%-8s %14s %5d \n", "������", "��ǻ�Ͱ���", 2);
	printf("%-8s %14s %5d \n", "�Ѽ���", "�̼�������", 4);

	return 0;
}


//SimpleWhile.c
int main(void)
{
	int num = 0;
	while (num < 5)
	{
		printf("Hello World! %d\n", num);
		num++;
	}
	return 0;
}


//NineNineDan.c
int main(void)
{
	int dan = 0, num = 1;
	printf("�� ��? ");
	scanf_s("%d", &dan);

	while (num < 10)
	{
		printf("%d X %d = %d \n", dan, num, dan * num);
		num++;
	}
	return 0;
}


//7-1-1
int main(void)
{
	int num = 0;
	int index = 0;

	printf("���� ���� �ϳ� �Է� : ");
	scanf_s("%d", &num);

	while (index < num)
	{
		printf("Hello World!\n");
		index++;
	}

	return 0;
}


//7-1-2
int main(void)
{
	int num = 0;
	int index = 1;

	printf("���� ���� �ϳ� �Է�: ");
	scanf_s("%d", &num);

	while (index < num+1) {
		printf("%d ", 3 * index);
		index++;
	}

	return 0;
}


//7-1-3
int main(void)
{
	int integer = 0;
	int add = 0;
	printf("���� �Է� : ");
	scanf_s("%d", &integer);
	add = integer + add;

	while (integer != 0) {
		printf("���� �Է� : ");
		scanf_s("%d", &integer);
		add = integer + add;
	}
	printf("���� %d\n", add);

	return 0;
}


//7-1-4
int main(void)
{
	int index = 9;
	int num = 1;

	printf("�ڿ��� �Է� : ");
	scanf_s("%d", &num);

	while (index > 0) {
		printf("%d x %d = %2d\n", num, index, num*index);
		index--;
	}

	return 0;
}


//7-1-5
int main(void)
{
	int howmany = 1;
	int index = 0;
	int tmp = 0;
	double sum = 0;

	printf("�� �� ����? : ");
	scanf_s("%d", &howmany);

	while (index < howmany) {
		printf("���� �Է� : ");
		scanf_s("%d", &tmp);
		sum += tmp;
		index++;
	}
	printf("����� : %f", sum/index);

	return 0;
}
*/