#include <stdio.h>								//	stdio.h ������� ����

/*
//2-1
int main(void) {
	printf("������\n�� �� ��\n��  ��  ��");
	return 0;
}


//2-2
int main(void) {
	printf("������\n");
	printf("����Ư����\n");
	printf("01012345678");
	return 0;
}


//HelloComment.c
int main(void) {								//	main �Լ��� ����
//	printf �Լ��� ����ͷ� ����� �ϴ� ��쿡 ����.
//	���ڷ� ���ڿ��� �����ϸ� ���ڿ��� ����Ѵ�.
	
//	printf("Hello World!\n");					//	����ͷ� ���ڿ� ���
	return 0;									//	0�� ��ȯ�Ѵ�.
}
												//	main �Լ��� ��
												

//PrintfOne.c
int main(void) {
	printf("Hello Everybody\n");
	printf("%d \n", 1234);
	printf("%d %d\n", 10, 20);

	return 0;
}

//PrintfTwo.c
int main(void) {
	printf("My age : %d \n", 20);
	printf("%d is my point\n", 100);
	printf("Good \nmorning \neverybody");
	return 0;
}


//ex2-2-1
int main(void) {
	printf("�� �Ƹ��� ȫ�浿�Դϴ�.\n");
	printf("�� ���� %d���̰��.\n", 20);
	printf("���� ��� ���� �������� %d-%d �Դϴ�.\n", 123, 456);

	return 0;
}


//2-2-2
int main(void) {
	printf("%dX%d=%d\n", 4, 5, 20);
	printf("%dX%d=%d\n", 7, 9, 63);

	return 0;
}


//VarDeclAndInin.c
int main(void) {
	int num1, num2;								//	���� num1, num2�� ����
	int num3 = 30, num4 = 40;					//	���� num3, num4�� ���� �� �ʱ�ȭ

	printf("num1: %d, num2: %d\n", num1, num2);
	num1 = 10;									//	���� num1�� �ʱ�ȭ
	num2 = 20;									//	���� num1�� �ʱ�ȭ

	printf("num1: %d , num2: %d \n", num1, num2);
	printf("num3: %d , num4: %d \n", num3, num4);

	return 0;
}
*/

//SimpleAddTwo.c
int main(void) {
	int num1 = 3;								//	��������
	int num2 = 4;
	int result = num1 + num2;					

	printf("���� ���: %d \n", result);
	printf("%d+%d=%d\n", num1, num2, result);
	printf("%d��(��) %d�� ���� %d�Դϴ�.\n", num1, num2, result);

	return 0;
}