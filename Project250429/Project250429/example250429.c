#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
//DoublePointerAccess.c
int main(void)
{
	double num = 3.14;
	double* ptr = &num;
	double** dptr = &ptr;
	double* ptr2;

	printf("%9p %9p %9p \n",&num, ptr, *dptr);
	printf("%9g %9g %9g \n", num, *ptr , **dptr);
	ptr2 = *dptr;								//	ptr = ptr2 �� ����
	*ptr2 = 10.99;
	printf("%9g %9g \n", num, **dptr);

	return 0;
}


//PointerSwapFail.c
void SwapIntPtr(int* p1, int* p2)
{
	int* tmp = p1;
	p1 = p2;
	p2 = tmp;
}
int main(void)
{
	int num1 = 10, num2 = 20;
	int* ptr1, * ptr2;
	ptr1 = &num1, ptr2 = &num2;
	printf("*ptr1, *ptr2 : %d %d\n", *ptr1, *ptr2);

	SwapIntPtr(ptr1, ptr2);
	printf("*ptr1, *ptr2 : %d %d\n", *ptr1, *ptr2);

	return 0;
}


//PointerSwapSuccess.c
void SwapIntPtr(int** dp1, int** dp2)
{
	int* tmp = *dp1;
	*dp1 = *dp2;
	*dp2 = tmp;
}
int main(void)
{
	int num1 = 10, num2 = 20;
	int* ptr1, * ptr2;
	ptr1 = &num1, ptr2 = &num2;
	printf("*ptr1, *ptr2 : %d %d\n", *ptr1, *ptr2);

	SwapIntPtr(&ptr1, &ptr2);
	printf("*ptr1, *ptr2 : %d %d\n", *ptr1, *ptr2);

	return 0;
}


//PointerArrayType.c
int main(void)
{
	int num1 = 10, num2 = 20, num3 = 30;
	int* ptr1 = &num1;
	int* ptr2 = &num2;
	int* ptr3 = &num3;

	int* ptrArr[] = { ptr1, ptr2, ptr3 };
	int** dptr = ptrArr;

	printf("%d %d %d\n", *ptrArr[0], *ptrArr[1], *ptrArr[2]);
	printf("%d %d %d\n", *(dptr[0]), *(dptr[1]), *(dptr[2]));
	return 0;
}


//2DArrayAddress.c      => �ٽ�!
int main(void)
{
	int arr2d[3][3];
	printf("%lu \n", arr2d);
	printf("%lu \n", arr2d[0]);
	printf("%u \n\n", arr2d[0][0]);

	printf("%lu \n", arr2d[1]);
	printf("%lu \n\n", &arr2d[1][0]);

	printf("%d \n", arr2d[2]);
	printf("%d \n\n", &arr2d[2][0]);

	printf("sizeof(arr2d): %d \n", (unsigned)sizeof(arr2d));
	printf("sizeof(arr2d[0]): %d \n", (unsigned)sizeof(arr2d[0]));
	printf("sizeof(arr2d[1]): %d \n", (unsigned)sizeof(arr2d[1]));
	printf("sizeof(arr2d[2]): %d \n", (unsigned)sizeof(arr2d[2]));

	return 0;
}


//2DArrNameAndArrPtr.c
int main(void)
{
	int arr1[2][2] = {
		{1, 2}, {3,4}
	};
	int arr2[3][2] = {
		{1,2},{3,4},{5,6}
	};
	int arr3[4][2] = {
		{1,2},{3,4},{5,6},{7,8}
	};

	int(*ptr)[2];
	int i;

	ptr = arr1;
	printf("Show 2*2 arr1 \n");
	for (int i = 0;i < 2;i++) printf("%d %d\n", ptr[i][0], ptr[i][1]);

	ptr = arr2;
	printf("Show 3*2 arr2 \n");
	for (int i = 0;i < 3;i++) printf("%d %d\n", ptr[i][0], ptr[i][1]);

	ptr = arr3;
	printf("Show 4*2 arr3 \n");
	for (int i = 0;i < 4;i++) printf("%d %d\n", ptr[i][0], ptr[i][1]);

	return 0;
}


//2DArrParam.c
void ShowArr2DStyle(int (*arr)[4], int column)
{
	int i, j;
	for (i = 0;i < column;i++) {
		for (j = 0;j < 4;j++) printf("%d ", arr[i][j]);
		printf("\n");
	}
	printf("\n");
}

int Sum2DArr(int arr[][4], int column)
{
	int i, j, sum = 0;
	for (i = 0;i < column;i++) {
		for (j = 0;j < 4;j++) sum += arr[i][j];
	}
	return sum;
}

int main(void)
{
	int arr1[2][4] = { 1,2,3,4,5,6,7,8 };
	int arr2[3][4] = { 1,1,1,1,3,3,3,3,5,5,5,5 };

	ShowArr2DStyle(arr1, (unsigned)sizeof(arr1) / (unsigned)sizeof(arr1[0]));
	ShowArr2DStyle(arr2, (unsigned)sizeof(arr2) / (unsigned)sizeof(arr2[0]));

	printf("arr1�� : %d\n", Sum2DArr(arr1, (unsigned)sizeof(arr1) / (unsigned)sizeof(arr1[0])));
	printf("arr2�� : %d\n", Sum2DArr(arr2, (unsigned)sizeof(arr2) / (unsigned)sizeof(arr2[0])));
}


//2DArrAccessType.c
int main(void)
{
	int a[3][2] = { {1,2},{3,4},{5,6} };

	printf("a[0]: %p\n", a[0]);
	printf("*(a+0): %p\n", *(a + 0));

	printf("a[1]: %p\n", a[1]);						//	��Ʈ���̴ϱ� 4����Ʈ�� �ٵ� �྿ �Ѿ(2��) �׷��� �ּҴ� 8����Ʈ ����
	printf("*(a+1): %p\n", *(a + 1));

	printf("a[2]: %p\n", a[2]);
	printf("*(a+2): %p\n", *(a + 2));

	printf("%d %d \n", a[2][1], (*(a + 2))[1]);
	printf("%d %d \n", a[2][1], *(a[2] + 1));
	printf("%d %d \n", a[2][1], *(*(a + 2))+1);

	return 0;
}


//18-1-1
int main(void)
{
	int* arr1[5];
	int* arr2[3][5];

	int* (*parr1) = arr1;
	int* (*parr2)[5] = arr2;

	return 0;
}


//18-1-2
void SimpleFuncOne(int *p1, int *p2)
{
	printf("��~");
}
void SimpleFuncTwo(int (*p1)[3], int(*p2)[2])
{
	printf("\n�³�?");
}

int main(void)
{
	int arr1[3];
	int arr2[4];
	int arr3[3][4];
	int arr4[2][4];

	SimpleFuncOne(arr1, arr2);
	SimpleFuncTwo(arr3, arr4);

	return 0;
}


//18-1-3
void ComplexFuncOne(int* a1, int(*a2)[3])
{

}
void ComplexFuncTwo(int)
{

}
int main(void)
{
	int* arr1[3];				//	arr1 �迭(3ĭ)�� ����Ű�� ������ ����
	int* arr2[3][5];			//	arr2 �迭(3x5ĭ)�� ����Ű�� ������ ����
	int** arr3[5];				//	arr3 �迭(5ĭ)�� ����Ű�� �����ͺ����� ����Ű�� �����ͺ���
	int*** arr4[3][5];			//	arr4 �迭(3x5ĭ)�� ����Ű�� ������ ������

	ComplexFuncOne(arr1, arr2);
	ComplexFuncTwo(arr3, arr4);
	return 0;
}


//18-1-4
int main(void)
{
	int arr[3][2] = { {1,2}, {3,4}, {5,6} };
	printf("%d %d\n", arr[1][0], arr[0][1]);
	printf("%d %d\n", *(arr[2] + 1), *(arr[1] + 1));
	printf("%d %d\n", (*(arr + 2))[0], (*(arr + 0))[1]);
	printf("%d %d\n", **arr, *(*(arr + 0) + 0));

	return 0;
}


//18-1-5 : 3���� �迭 ���� �� ���� �ش��ϴ� ����, �� ���� "�ּ�"���� �ǹ�
int main(void)
{
	int arr[2][2][2] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	printf("%d\n", arr[1][0][1]);
	printf("%d\n", (*(arr + 1))[0][1]);     // 1  
	printf("%d\n", (*(arr[1] + 0))[1]);     // 2
	printf("%d\n", (*(*(arr + 1) + 0))[1]);   // 3
	printf("%d\n", *(*(*(arr + 1) + 0) + 1));   // 4
	printf("%d\n", (**(arr + 1 + 0))[1]);     // 3�� ����
	printf("%d \n", *(*arr[1]+1));			//	5
	printf("%d\n", *((arr[1][0]) + 0 + 1)); // 6
	printf("%d\n", *(&arr[0][0][0] + 1 + 0 * 2 + 1 * 4)); // 7
	return 0;
}

int main(void)
{
	int arr[2][3] = { 1,2,3,4,5,10 };
	int* p = arr;
	printf("%d", *(&arr[1][1] + 1));  // *,&�� ����� ��¥ �� �ش簪(�ε��� 1,1�� �ű�)���ٰ� 1�� ����

	return 0;
}


//�Լ� �ּ�
int main(void)
{
	printf("%p\n\n", main);
	printf("%p\n\n", printf);
	printf("%p\n\n", scanf_s);
	return 0;
}


//FunctionPointer.c
void SimpleAdder(int n1, int n2)
{
	printf("%d + %d = %d\n", n1, n2, n1 + n2);
}

void ShowString(char* s)
{
	printf("%s\n", s);
}

int main(void)
{
	const char* str = "Function Pointer";
	int num1 = 10, num2 = 20;

	void (*fptr1)(int, int) = SimpleAdder;
	void(*fptr2)(char*) = ShowString;

	//	�Լ� ������ ������ ���� ȣ��
	fptr1(num1, num2);
	fptr2(str);

	return 0;
}


int WhoIsFisrt(int age1, int age2, int (*cmp)(int n1, int n2))
{
	return cmp(age1, age2);
}

int OlderFirst(int age1, int age2)
{
	if (age1 > age2) return age1;
	else if (age1 < age2) return age2;
	else return 0;
}

int YoungerFirst(int age1, int age2)
{
	if (age1 < age2) return age1;
	else if (age1 > age2) return age2;
	else return 0;
}

int main(void)
{
	int age1 = 20, age2 = 30;
	int first;

	printf("������� 1:\n");
	first = WhoIsFisrt(age1, age2, OlderFirst);
	printf("%d , %d �� %d ���� ����!\n", age1, age2, first);

	printf("\n������� 2:\n");
	first = WhoIsFisrt(age1, age2, YoungerFirst);
	printf("%d , %d �� %d ���� ����!\n", age1, age2, first);

	return 0;
}


//	���� �����
float add(int n1, int n2);
float minus(int n1, int n2);
float multi(int n1, int n2);
float div(int n1, int n2);

int main(void)
{
	int num1, num2;
	float result;
	char op;

	printf("�� �Է� : ");
	scanf("%d %c %d", &num1, &op, &num2);

	switch (op) {
	case('+'): printf("%f", add(num1, num2));
		break;
	case('-'): printf("%f", minus(num1, num2));
		break;
	case('*'): printf("%f", multi(num1, num2));
		break;
	case('/'): printf("%f", div(num1, num2));
		break;
	default: return 0;
	}
}
float add(int n1, int n2) {
	return n1 + n2;
}
float minus(int n1, int n2) {
	return n1 - n2;
}
float multi(int n1, int n2) {
	return n1 * n2;
}
float div(int n1, int n2) {
	return (float) n1 / n2;
}


//�Լ� �����͸� �̿��� ����
float add(int n1, int n2);
float minus(int n1, int n2);
float multi(int n1, int n2);
float div(int n1, int n2);

int main(void)
{
	int num1, num2;
	float result;
	char op;
	float (*funcPtr)(int, int);

	printf("�� �Է� : ");
	scanf("%d %c %d", &num1, &op, &num2);

	switch (op) {
	case('+'): funcPtr = add;
		break;
	case('-'): funcPtr = minus;
		break;
	case('*'): funcPtr = multi;
		break;
	case('/'): funcPtr = div;
		break;
	default: return 0;
	}
	result = funcPtr (num1, num2);
	printf("%f", result);
}
float add(int n1, int n2) {
	return n1 + n2;
}
float minus(int n1, int n2) {
	return n1 - n2;
}
float multi(int n1, int n2) {
	return n1 * n2;
}
float div(int n1, int n2) {
	return (float)n1 / n2;
}


//�������α׷���3
//����1
int main()
{
	int arr[4][4] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };

	printf("�⺻ ���\n");
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			printf("%2d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n\n�ð� 90��\n");
	for (int i = 0;i < 4;i++) {
		for (int j = 3;j > -1;j--) {
			printf("%2d ", arr[j][i]);
		}
		printf("\n");
	}
	printf("\n\n�ð� 180��\n");
	for (int i = 3;i > -1;i--) {
		for (int j = 3;j > -1;j--) {
			printf("%2d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n\n�ð� 270��\n");
	for (int i = 3;i > -1;i--) {
		for (int j = 0;j < 4;j++) {
			printf("%2d ", arr[j][i]);
		}
		printf("\n");
	}

	return 0;
}
*/
/*
//����2
void snailNum(int n, int* arr);
int main(void)
{
	int num;
	int* arr[BUFSIZ] = { '0' };
	printf("���� �Է�:");
	scanf_s("%d", &num);
	
	snailNum(num, *arr);

}
void snailNum(int n, int **parr)
{
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			// printf("! ");			//	�Լ��� n���ڴ� ����� ���޵�
		}
		printf("\n");
	}
}


//ReadWriteChar.c
//file���� �ݴ� fopen, fclose
//fputc�� ���Ͽ� ���ڸ� �ϳ��� ���� �Լ�. �ι�° ���ڿ� ���� ������(fopen���� ��ȯ����)
int main(void)
{
	int ch1, ch2;

	ch1 = getchar();				//	���� �Է�
	//ch2 = fgetc(stdin);				//	���� Ű �Է� -> ������ ���̰� ���µ� ���ϱ�?
	//fgetc�� ���ڸ� �а� ���� ���ڸ� ����Ű���� ������ ���� ������(�ִٸ�) ������Ų��. getc()�� �����ϳ� �׻� ��� ȣ��� ����

	putchar(ch1);					//	���� ���
	//fputc(ch2, stdout);				//	���� Ű ��� ---> �׷��� �Է¹��� �ڿ� ����ó�� �� ��(���� ���� �־����ϱ� �� ���Ͱ� ���)

	return 0;
}



//ConsoleEOF.c
int main(void)
{
	int ch;

	while (1) {
		ch = getchar();
		if (ch == EOF)break;			//	ctrl+z������ ����Ű ����� �����(���͵� �ڵ��Էµǳ�����? -> �����ϰ� ���� �����ϱ�)
		putchar(ch);
	}
	return 0;
}


//	21-1
int main(void)
{
	int diff = 'a' - 'A';
	char tmpC;
	scanf("%d", &tmpC);

	tmpC = getchar();
	if (tmpC > 'z' || tmpC < 'A') printf("���ĺ� �ƴ�!\n");

	if(tmpC >= 'a' && tmpC <= 'z') putchar(tmpC - diff);
	else putchar(tmpC + diff);

	return 0;
}
*/
