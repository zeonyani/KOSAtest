#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>  //동적할당을 위해
/*
//ComplexFileRead.c
int main(void)
{
	char name[10]; char sex; int age;

	FILE* fp = fopen("friend.txt", "wt");
	
	for (int i = 0;i < 3;i++) {
		printf("이름 성별 나이 순서 입력:");
		scanf("%s %c %d", name, &sex, &age);
		getchar();
		fprintf(fp, "%s %c %d", name, sex, age);
	}
	fclose(fp);

	return 0;
}


//StructFileWriteRead.c
typedef struct fren {
	char name[10]; char sex; int age;
} FND;
int main(void)
{
	FILE* fp;
	FND mf1, mf2;

	//파일 쓰기
	fp = fopen("friend.bin", "wb");
	printf("이름 성별 나이 순서 입력:"); scanf("%s %c %d", mf1.name, &(mf1.sex), &(mf1.age));
	fwrite((void*)&mf1, sizeof(mf1), 1, fp);
	fclose(fp);

	//파일 읽기
	fp = fopen("friend.bin", "rb");
	fread((void*)&mf2, sizeof(mf2), 1, fp);
	printf("%s %c %d\n", mf2.name, mf2.sex, mf2.age);
	fclose(fp);

	return 0;
}

//MoveFileReWrPos.c
int main(void)
{
	//파일생성
	FILE* fp = fopen("text.txt", "wt");
	fputs("123456789", fp);
	fclose(fp);

	//파일개방
	fp = fopen("text.txt", "rt");

	//SEEK_END 테스트
	fseek(fp, -2, SEEK_END);		// 맨뒤에서 거꾸로 두칸 (널, 9 다음이니까 8)
	putchar(getc(fp));

	//SEEK_SET 테스트
	fseek(fp, 2, SEEK_SET);			// 첨부터 오른쪽으로 두칸(1,2 지나고 3)
	putchar(getc(fp));

	//SEEK_CUR 테스트
	fseek(fp, 2, SEEK_CUR);			//	3다음인 4를 가리키고 있음(현재) 근데 거기서 오른쪽 2칸이동(6)
	putchar(getc(fp));

	fclose(fp);

	return 0;
}


//TellFileReWrPos.c
int main(void)
{
	long fpos;

	//파일생성
	FILE* fp = fopen("text.txt", "wt");
	fputs("1234-", fp);
	fclose(fp);

	//파일개방
	fp = fopen("text.txt", "rt");

	for (int i = 0;i < 4;i++) {
		putchar(getc(fp));
		fpos = ftell(fp);
		fseek(fp, -1, SEEK_END);
		putchar(getc(fp));
		fseek(fp, fpos, SEEK_SET);
	}
	fclose(fp);
	return 0;
}


//DynamicMemoryAlloc.c
int main(void)
{
	int* ptr1 = (int*)malloc(sizeof(int));
	int* ptr2 = (int*)malloc(sizeof(int) * 7);

	*ptr1 = 20;
	for (int i = 0;i < 7;i++) ptr2[i] = i+1;

	printf("%d\n", *ptr1);

	for (int i = 0;i < 7;i++) printf("%d   ", ptr2[i]);

	free(ptr1); free(ptr2);

	return 0;
}


//ReadStringRight.c
char* ReadUserName(void) {
	char* name = (char*)malloc(sizeof(char) * 30);
	printf("what's your name? ");
	gets(name);
	return name;
}

int main(void)
{
	char* name1; char* name2;
	name1 = ReadUserName(); printf("name1: %s\n", name1);
	name2 = ReadUserName(); printf("name2: %s\n", name2);

	printf("again name1: %s\n", name1);
	printf("again name2: %s\n", name2);

	free(name1); free(name2);

	return 0;
}


//25-2-1
int main(void)
{
	int n;
	char* str, * tmp;

	printf("문자열의 길이는? : ");
	scanf("%d%*c", &n);

	printf("문자열을 입력하시오 : ");
	str = (char*)malloc(sizeof(char) * n);
	fgets(str, n, stdin);

	tmp = (char*)malloc(sizeof(char) * n);
	for (int i = n - 1, cnt = 0; i >= -1; i--) {
		if (str[i] == ' ' || i == -1) {
			for (int j = cnt - 1; j >= 0; j--)
				printf("%c", tmp[j]);
			cnt = 0;
			printf(" ");
		}
		else {
			tmp[cnt++] = str[i];
		}
	}
	printf("\n");

	free(str);
	free(tmp);

	return 0;
}

//MacroConst.c
#define NAME "홍길동"
#define AGE 24
#define PRINT_ADDR puts("주소 : 경기도 용인시\n");

int main(void)
{
	printf("이름 : %s\n", NAME);
	printf("나이 : %d\n", AGE);
	PRINT_ADDR;

	return 0;
}


#define SQUARE(X) X*X
int main(void)
{
	int num = 20;

	printf("Suare of 'num' : %d\n", SQUARE(num));
	printf("Suare of '-5' : %d\n", SQUARE(-5));
	printf("Suare of '2.5' : %g\n", SQUARE(2.5)); //더블형은 %g

	//	비정상적 결과 출력 3+2*3+2 로 인식해서 11출력
	printf("\nSquare of 3+2 ? : %d\n", SQUARE(3 + 2));
	//printf("\nSquare of 3+2 ? : %d\n", SQUARE((3 + 2))); //정상

	return 0;
}


#define PI 3.14 //순서를 아래로 내려도 되더라!
#define PRODUCT(X,Y) ((X)*(Y))
#define CIRCLE_AREA(R) (PRODUCT((R), (R))*PI)

int main(void)
{
	double rad = 2.1;
	printf("%g 반지름인 원의 넓이: %g\n", rad, CIRCLE_AREA(rad));

	return 0;
}

//매크로로 정의하기 vs 함수로 정의하기
#define MACRODIFFABS(A,B) ((A) > (B)) ? ((A)-(B)):((B)-(A))
int funcDiffABS(int a, int b)
{
	if (a > b) return (a - b);
	else return (b - a);
}

int main(void)
{
	printf("%d\n", MACRODIFFABS(2, 7));
	printf("%d\n", funcDiffABS(7, 2));

	return 0;
}

//if_endif.c
#define ADD 1
#define MIN 0

int main(void)
{
	int num1, num2;
	printf("두 정수 입력: ");
	scanf("%d %d", &num1, &num2);

#if ADD	// ADD는 1이라 항상 참이라서 얘만 실행됨
	printf("%d + %d = %d\n", num1, num2, num1+num2);
#endif

#if MIN // MIN은 0이라서 절대 참이 될 수 없어서 실행되지 않음
	printf("%d - %d = %d\n", num1, num2, num1-num2);
#endif

	return 0;
}

//ifdef_endif.c
//#define ADD 1
#define MIN 0

int main(void)
{
	int num1, num2;
	printf("두 정수 입력: ");
	scanf("%d %d", &num1, &num2);

#ifdef ADD
	printf("%d + %d = %d\n", num1, num2, num1 + num2);
#endif

#ifdef MIN
	printf("%d - %d = %d\n", num1, num2, num1 - num2);
#endif

	return 0;
}


#define HIT_NUM 2
int main(void)
{
#if HIT_NUM == 5
	puts("현재 5");
#else
	puts("현재 5아님");
#endif

	return 0;
}


//elif_endif.c
#define HIT_NUM 100
int main(void)
{
#if HIT_NUM == 5
	puts("현재 5");
#elif HIT_NUM == 6
	puts("현재 6");
#elif HIT_NUM == 7
	puts("현재 7");
#else
	puts("현재 5,6,7은 아님");
#endif

	return 0;
}


//MacroOpToString.c
#define STRING_JOB(A, B) #A"의 직업은 "#B"입니다."

int main(void)
{
	printf("%s \n", STRING_JOB(이동춘, 나무꾼));
	printf("%s \n", STRING_JOB(한상순, 선녀));

	return 0;
}


//UnivStdNum.c
#define STNUM(Y, S, P) ((Y)*100000+(S)*1000+(P))

int main(void)
{
	printf("학번 : %d\n", STNUM(10, 65, 175));
	printf("학번 : %d\n", STNUM(10, 65, 075));

	return 0;
}


//UnivStdNum_ANOTHER.c
#define STNUM(Y, P) Y ## 65 ## P

int main(void)
{
	printf("학번 : %d\n", STNUM(11, 175));
	printf("학번 : %d\n", STNUM(10, 075));

	return 0;
}


//26-1-1
#define ADD(A, B, C) ((A)+(B)+(C))
#define MUL(A, B, C) ((A)*(B)*(C))

int main(void)
{
	int n1, n2, n3;
	printf("세 수 ?"); scanf("%d %d %d", &n1, &n2, &n3);
	printf("합: %d\n", ADD(n1, n2, n3));
	printf("곱: %d\n", MUL(n1, n2, n3));

	return 0;
}


//26-1-2
#define PI 3.14
#define C_AREA(R) (R)*(R)*(PI)

int main(void)
{
	int rad = 3;
	printf("%g가 원의 넓이", C_AREA(rad));

	return 0;
}


//26-1-3
#define MAX(A, B) ((A)>(B)) ? (A) : (B)

int main(void)
{
	int n1, n2;
	printf("두 수 입력: "); scanf("%d %d", &n1, &n2);
	printf("큰 수는 %d", MAX(n1, n2));

	return 0;
}

//SimpleOneFile.c
int num = 0;

void Increment(void) {
	num++;
}

int GetNum(void) {
	return num;
}

int main(void) {
	printf("num : %d\n", GetNum());
	Increment();

	printf("num : %d\n", GetNum());
	Increment();

	printf("num : %d\n", GetNum());
	return 0;
}


//헤더파일의 디자인과 활용
int main(void)
#include "header1.h"
#include "header2.h"


//arithMain.c
#include "areaArith.h"
#include "roundArith.h"

int main(void)
{
	printf("삼각형 넓이 밑변4 높이2 : %g\n",
		TriangleArea(4, 2));
	printf("원 넓이 반지름3 : %g\n",
		CircleArea(3));

	printf("직사각형 둘레 밑변2.5 높이5.2 : %g\n",
		RectangleRound(2.5, 5.2));
	printf("정사각형 둘레 변3 : %g\n",
		SquareRound(3));

	return 0;
}
*/