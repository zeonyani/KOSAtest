#include <stdio.h>
/*
//��ø
int main(void)
{
	int i = 0, j = 0, num = 0;
	while (i < 10) {
		while (j < 10) {
			num++;
			j++;
		}
		i++;
		j = 0;
	}

	printf("%d %d %d", i, j, num);

	return 0;
}


//UsefulDoWhile.c
int main(void)
{
	int total = 0, num = 0;

	do
	{
		printf("���� �Է� (0 to quit) : ");
		scanf_s("%d", &num);
		total += num;
	} while (num != 0);

	printf("�հ� : %d\n", total);

	return 0;
}


//AddToNum.c
int main(void)
{
	int total = 0;
	int i, num;
	printf("0���� num���� ��, num��?");
	scanf_s("%d", &num);

	for (i = 0; i < num + 1;i++) {
		total += i;
	}

	printf("0���� %d���� �� : %d", num, total);

	return 0;
}


//TwoToNineForVer.c
int main(void)
{
	int cur, is;

	for (cur = 2;cur < 10;cur++) {
		for (is = 1;is < 10;is++)
			printf("%dx%d=%d\n", cur, is, cur * is);
		printf("\n");
	}
	return 0;
}


int main(void)
{
	int num;
	printf("���� �Է�: ");
	scanf_s("%d", &num);

	if (num < 0) printf("0���� �۴�.\n");
	if (num > 0) printf("0���� ũ��.\n");
	if (num == 0) printf("0�̴�.\n");

	return 0;
}


//CalOne.c
int main(void)
{
	int opt;
	double num1, num2;
	double result;

	printf("1. ���� 2. ���� 3. ���� 4. ������ \n����? : ");
	scanf_s("%d", &opt);
	printf("�� �Ǽ� �Է�: ");
	scanf_s("%lf %lf", &num1, &num2);

	if (opt == 1) result = num1 + num2;
	if (opt == 2) result = num1 - num2;
	if (opt == 3) result = num1 * num2;
	if (opt == 4) result = num1 / num2;

	printf("��� : %f\n", result);

	return 0;
	
}

//IfElseBasic.c
int main(void)
{
	int num;
	printf("���� �Է�: ");
	scanf_s("%d", &num);


	if (num < 0) printf("0���� �۴�.");
	else printf("0���� ���� �ʴ�.");

	return 0;
}


//CalTwo.c
int main(void)
{
	int opt;
	double num1, num2;
	double result;

	printf("1. ���� 2. ���� 3. ���� 4. ������ \n����? : ");
	scanf_s("%d", &opt);
	printf("�� �Ǽ� �Է�: ");
	scanf_s("%lf %lf", &num1, &num2);

	if (opt == 1) result = num1 + num2;
	else if (opt == 2) result = num1 - num2;
	else if (opt == 3) result = num1 * num2;
	else result = num1 / num2;

	printf("��� : %f\n", result);

	return 0;

}


//ThreeOperand.c
int main(void)
{
	int num, abs;
	printf("���� �Է�: ");
	scanf_s("%d", &num);

	abs = num > 0 ? num : num * (-1);
	printf("����: %d \n", abs);

	return 0;
}


//8-1-1
int main(void)
{
	int i = 0;
	while (i < 100) {
		if ((i % 7) == 0 || (i % 9) == 0) {
			printf("%d\n", i);
		}
		i++;
	}

	return 0;
}


//8-1-2
int main(void)
{
	int n1, n2;
	printf("�� ���� �Է�: ");
	scanf_s("%d %d", &n1, &n2);

	if (n1 > n2) printf("%d", n1 - n2);
	else printf("%d", n2 - n1);

	return 0;
}
*/

/*
//8-1-3
int main(void)
{
	int sub1, sub2, sub3;
	double avg = 0;
	printf("�� �� �� ���� �Է�: ");
	scanf_s("%d %d %d", &sub1, &sub2, &sub3);
	avg = (sub1 + sub2 + sub3)/3;

	if (avg > 90 || avg == 90) printf("A! ");
	else if (avg > 80 || avg == 80) printf("B! ");
	else if (avg > 70 || avg == 70) printf("C! ");
	else if (avg > 50 || avg == 50) printf("D! ");
	else printf("F! ");

	return 0;

}


//8-1-4
int main(void)
{
	int n1, n2;
	int ans;

	printf("�� ���� �Է�: ");
	scanf_s("%d %d", &n1, &n2);
	ans = (n1 > n2) ? (n1 - n2) : (n2 - n1);
	printf("%d", ans);	

	return 0;
}
*/

/*
//WhenOver5000.c
int main(void)
{
	int sum = 0, num = 0;
	while (1) {
		sum += num;
		if (sum > 5000) break;
		num++;
	}

	printf("sum: %d \n", sum);
	printf("num: %d \n", num);

	return 0;
}

//ExceptMul2Mul3.c
int main(void)
{
	int num;
	printf("start! ");

	for (num = 1;num < 20; num++) {
		if (num % 2 == 0 || num % 3 == 0) continue;
		printf("%d ", num);
	}
	printf("end! ");
	return 0;
}*/

/*
//8-2-1 �ٽ� Ȯ��!!
int main(void)
{
	int even = 2;
	int i = 1;
	while (even < 9) {
		printf("%d x %d = %2d", even, i, even * i);
		i++;
		if (i == even) continue;
		while (i )
	}

	return 0;
}*/


/*
//��������
int main(void)
{
	int score = 0;
	do {
		printf("������ �Է��ϼ��� : ");
		scanf_s("%d", &score);
	} while (score > 100 || score < 0);

	switch (score) {
	case 100: case 99: case 98:
	case 97: case 96: case 95:
		printf("%d : A+\n", score);
		break;
	case 94: case 93: case 92:
	case 91: case 90:
		printf("%d : A\n", score);
		break;
	case 89: case 88: case 87:
	case 86: case 85:
		printf("%d : B+\n", score);
		break;
	case 84: case 83: case 82:
	case 81: case 80:
		printf("%d : B\n", score);
		break;
	case 79: case 78: case 77:
	case 76: case 75:
		printf("%d : C+\n", score);
		break;
	case 74: case 73: case 72:
	case 71: case 70:
		printf("%d : C\n", score);
		break;
	case 69: case 68: case 67:
	case 66: case 65:
		printf("%d : D+\n", score);
		break;
	case 64: case 63: case 62:
	case 61: case 60:
		printf("%d : D\n", score);
		break;
	
	default: printf("%d : F", score);
	}
	return 0;
}


//SimpleAddFunc.c
int Add(int num1, int num2) {
	return  num1 + num2;
}
int main(void)
{
	int result;
	result = Add(3, 4);
	printf("������� 1: %d\n", result);
	result = Add(5, 8);
	printf("������� 2: %d\n", result);

	return 0;
}


//SmartAddFun.c
int Add(int num1, int num2)
{
	return num1 + num2;
}
void ShowAddResult(int num)
{
	printf("������� ���: %d \n", num);
}
int ReadNum(void)
{
	int num;
	scanf_s("%d", &num);
	return num;
}
void HowToUseThisProg(void)
{
	printf("�� �� ���� �Է��ϸ� ������� ���: \n��! �׷� �� �� ���� �Է�: \n");
}
int main(void)
{
	int result, num1, num2;
	HowToUseThisProg();
	num1 = ReadNum();
	num2 = ReadNum();
	result = Add(num1, num2);
	ShowAddResult(result);


	return 0;
}


//NumCompare.c
int NumCompare(int n1, int n2);

int main(void)
{
	printf("3�� 4�� ū �� %d\n", NumCompare(3, 4));
	printf("7�� 2�� ū �� %d\n", NumCompare(7, 2));
	return 0;
}

int NumCompare(int n1, int n2)
{
	if (n1 > n2) return n1;
	else return n2;
}


//AbsoCompare.c
int AbsoCompare(int num1, int num2);
int GetAbsoValue(int num);

int main(void)
{
	int num1, num2;
	printf("�� ���� �Է�: ");
	scanf_s("%d %d", &num1, &num2);
	printf("%d %d �� ���� ū ����: %d \n", num1, num2, AbsoCompare(num1, num2));

	return 0;
}

int AbsoCompare(int n1, int n2)
{
	GetAbsoValue(n1) > GetAbsoValue(n2) ? n1 : n2;
	
}

int GetAbsoValue(int n)
{
	n > 0 ? n : n * (-1);
}


//�̰� �ٽ� Ȯ��
//getMaxMin.c
int getMax(int n1, int n2, int n3);
int getMin(int n1, int n2, int n3);

int main(void)
{
	int n1;
	int n2;
	int n3;
	printf("�� ���� �Է�: ");
	scanf_s("%d %d %d", &n1, &n2, &n3);

	printf("%d %d %d �� ���� ū �� %d ���� ���� �� %d", n1, n2, n3, getMax(n1, n2, n3), getMin(n1, n2, n3));

	return 0;
}

int getMax(int n1, int n2, int n3)
{
	int max;
	max = (n1 > n2) ? n1 : n2;
	max > n3 ? max : n3;

	return max;
}

int getMin(int n1, int n2, int n3)
{
	int min;
	min = n1 < n2 ? n1 : n2;
	min < n3 ? min : n3;

	return min;
}


//GlobalV.c
void Add(int v);
int num;

int main(void)
{
	printf("num: %d \n", num);
	Add(3);
	printf("num: %d \n", num);
	num++;									//	�������� �� ����
	printf("num: %d \n", num);

	return 0;
}

void Add(int val)
{
	num += val;								//	�������� num�� val��ŭ ����
}


//LocalValHideGlobalVal.c
int Add(int val);
int num = 1;

int main(void)
{
	int num = 5;
	printf("num: %d\n", Add(3));
	printf("num: %d\n", num + 9);

	return 0;
}

int Add(int val)
{
	int num = 9;
	num += val;
	return num;
}


//StaticVal.c
void SimpleFunc(void)
{
	static int num1 = 0;
	int num2 = 0;
	num1++, num2++;
	printf("static : %d local : %d \n", num1, num2);
}

int main(void)
{
	int i;
	for (i = 0;i < 3;i++) SimpleFunc();
	return 0;
}


//9-2
int AddTotal(int n)
{
	static int total = 0;
	total += n;
	return total;
}
int main(void)
{
	int num, i;
	for (i = 0; i < 3;i++)
	{
		printf("�Է� %d ", i + 1);
		scanf_s("%d", &num);
		printf("����: %d\n", AddTotal(num));
	}

	return 0;
}


//ArrayAccess.c
int main(void)
{
	int arr[5];
	int sum = 0, i;

	//arr[0] = 10;
	//arr[1] = 20;
	//arr[2] = 30;
	//arr[3] = 40;
	//arr[4] = 50;
	for (i = 0; i < 5;i++) arr[i] = (i+1) * 10;

	for (i = 0;i < 5;i++) sum += arr[i];

	printf("�迭��� ��: %d", sum);

	return 0;
}


//ArrayInit.c
int main(void)
{
	int arr1[5] = { 1,2,3,4,5 };
	int arr2[] = { 1,2,3,4,5,6,7 };
	int arr3[5] = { 1,2 };
	int arr1Len, arr2Len, arr3Len, i;

	printf("�迭 arr1ũ�� : %d \n", sizeof(arr1));
	printf("�迭 arr2ũ�� : %d \n", sizeof(arr2));
	printf("�迭 arr3ũ�� : %d \n", sizeof(arr3));

	arr1Len = sizeof(arr1) / sizeof(int);
	//printf("!!!! %d %d!!!! \n", arr1Len, arr1Len+1); �Ǽ� Ȯ�ο�
	arr2Len = sizeof(arr2) / sizeof(int);
	arr3Len = sizeof(arr3) / sizeof(int);

	for (i = 0;i < arr1Len;i++) printf("%d ", arr1[i]);
	printf("\n");
	for (i = 0;i < arr2Len;i++) printf("%d ", arr2[i]);
	printf("\n");
	for (i = 0;i < arr3Len;i++) printf("%d ", arr3[i]);
	printf("\n");

	return 0;
}


//ArrayString.c
int main(void)
{
	char str[] = "Good morning!";
	printf("�迭 strũ�� : %d \n", sizeof(str));
	printf("�ι��� ������ ��� : %c \n", str[13]);
	printf("�ι��� ������ ��� : %d \n", str[13]);
	8
	str[12] = '?';
	printf("���ڿ� ��� : %s \n", str);

	return 0;
}


//PointerOperation.c
int main(void)
{
	int n1 = 100, n2 = 100;
	int* pn;

	pn = &n1;
	(*pn) += 30;

	pn = &n2;
	(*pn) -= 30;

	printf("n1: %d n2: %d", n1, n2);
	return 0;
}


int main(void)
{
	int num1 = 100, num2 = 100;
	int* pnum;

	pnum = &num1;
	(*pnum) += 30;
	printf("Address of num1 : %p\n", &num1);
	printf("value of pnum : %p\n", pnum);
	printf("Address of pnum : %p\n", &pnum);

	pnum = &num2;
	(*pnum) += 30;
	printf("Address of num2 : %p\n", &num2);
	printf("value of pnum : %p\n", pnum);
	printf("Address of pnum : %p\n", &pnum);

	printf("num1 : %d, num2 : %d\n", num1, num2);

	return 0;
}
*/
