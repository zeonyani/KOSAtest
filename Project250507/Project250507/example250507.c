#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdarg.h>
//with intDiv.c
/*
typedef struct div
{
	int quo; //	��
	int remai;	//	������
} Div;

extern Div IntDiv(int n1, int n2);	//	������ ����ִ� �� ���Ͽ��� intDiv.c�� ����� InDiv�� ����(static�ƴϴϱ� ���� ����)

int main(void)
{
	Div val = IntDiv(5, 2);
	printf("��: %d\n", val.quo);
	printf("������: %d\n", val.remai);
}


//with intDiv2.c
#include "stdiv.h"
extern Div IntDiv2(int n1, int n2);

int main(void)
{
	Div val = IntDiv2(5, 2);
	printf("��: %d\n", val.quo);
	printf("������: %d\n", val.remai);

	return 0;
}


//chap 28-1
#include <string.h>

typedef struct _bookinfo {
    char title[32];
    char author[32];
    int page;
} BookInfo;

int main(void)
{
    BookInfo info[10] = { 0 };

    for (int i = 0; i < 3; i++) {
        printf("���� : ");
        fgets(info[i].author, 32, stdin);
        info[i].author[strlen(info[i].author) - 1] = '\0';
        printf("���� : ");
        fgets(info[i].title, 32, stdin);
        info[i].title[strlen(info[i].title) - 1] = '\0';
        printf("�������� : ");
        scanf_s("%d%*c", &info[i].page);
    }

    printf("\n���� ���� ���\n");
    for (int i = 0; i < 3; i++) {
        printf("book %d\n", i+1);
        printf("���� : %s\n", info[i].author);
        printf("���� : %s\n", info[i].title);
        printf("�������� : %d\n", info[i].page);
    }

    return 0;
}


//28-2 �����ͷ� �����ϴ� ����� �� ��! ȭ��ǥ�� �̿��� ����
#include <string.h>
#include <stdlib.h>

typedef struct _bookinfo {
    char title[32];
    char author[32];
    int page;
} BookInfo;

int main(void)
{
    BookInfo* info;
    info = (BookInfo*)malloc(sizeof(BookInfo) * 3);

    for (int i = 0; i < 3; i++) {
        printf("����: ");
        fgets((info + i)->author, 32, stdin);
        info[i].author[strlen((info + i)->author) - 1] = '\0';
        printf("����: ");
        fgets((info + i)->title, 32, stdin);
        info[i].title[strlen((info + i)->title) - 1] = '\0';
        printf("��������: ");
        scanf_s("%d%*c", &(info + i)->page);
    }

    printf("\n���� ���� ���\n");
    for (int i = 0; i < 3; i++) {
        printf("book %d\n", i);
        printf("���� : %s\n", (info + i)->author);
        printf("���� : %s\n", (info + i)->title);
        printf("�������� : %d\n", (info + i)->page);
    }

    free(info);

    return 0;
}


//28-3 (���Ҽ� ����, ���� ���� �Լ� �����ؾ�!)
typedef struct complexNum {
    float real;
    float fake;
} CNum;

int main(void)
{
    struct complexNum CNum1, CNum2;
    printf("���Ҽ� �Է�1 :");
    scanf_s("%f %f", &CNum1.real, &CNum1.fake);
    //printf("%f %f", CNum1.real, CNum1.fake);
    printf("���Ҽ� �Է�2 :");
    scanf_s("%f %f", &CNum2.real, &CNum2.fake);

    printf("���� ���] �Ǽ�: %f ���: %f\n", CNum1.real + CNum2.real, CNum1.fake + CNum2.fake);
    printf("���� ���] �Ǽ�: %f ���: %f\n", CNum1.real * CNum2.real - CNum1.fake * CNum2.fake, CNum1.real * CNum2.fake + CNum1.fake * CNum2.real);

    return 0;
}


typedef struct {
    float realNum;
    float imgNum;
} ComplexType;

ComplexType add(ComplexType p1, ComplexType p2)
{
    ComplexType result;
    result.realNum = p1.realNum + p2.realNum;
    result.imgNum = p1.imgNum + p2.imgNum;
    return result;
}

ComplexType mul(ComplexType p1, ComplexType p2)
{
    ComplexType result;
    result.realNum = p1.realNum * p2.realNum - p1.imgNum * p2.imgNum;
    result.imgNum = p1.realNum * p2.imgNum + p1.imgNum * p2.realNum;
    return result;
}

int main(void)
{
    ComplexType p1, p2, result;

    printf("���Ҽ� �Է�1[�Ǽ� ���]: ");
    scanf_s("%f %f", &p1.realNum, &p1.imgNum);
    printf("���Ҽ� �Է�2[�Ǽ� ���]: ");
    scanf_s("%f %f", &p2.realNum, &p2.imgNum);
    result = add(p1, p2);
    printf("���� ���] �Ǽ�: %.6f, ��� : %.6f\n", result.realNum, result.imgNum);
    result = mul(p1, p2);
    printf("���� ���] �Ǽ�: %.6f, ��� : %.6f\n", result.realNum, result.imgNum);

    return 0;
}


//28-4
#include <string.h>

int main(int argc, char** argv)
{
    int a_cnt = 0, p_cnt = 0;
    char str[32];
    FILE* fp;

    if (argc < 1) {
        fprintf(stderr, "Usage : %s filename\n", argv[0]);
        return -1;
    }

    fp = fopen(argv[1], "rt");

    while (!feof(fp)) {
        str[0] = '\0';
        fscanf(fp, "%s", str);
        if (str[0] == 'A' || str[0] == 'a')
            a_cnt++;
        else if (str[0] == 'P' || str[0] == 'p')
            p_cnt++;
    }

    printf("Count of words with A start: %d\n", a_cnt);
    printf("Count of words with P start: %d\n", p_cnt);

    fclose(fp);

    return 0;
}
*/

int Sum(int n, ...);

int main(void)
{
    printf("1+2=%d\n", Sum(2, 1, 2));
    printf("1+2+3=%d\n", Sum(3, 1, 2, 3));
    printf("1+2+3+4=%d\n", Sum(4, 1, 2, 3, 4));

    return 0;
}

int Sum(int n, ...)
{
    int sum = 0;
    int i;
    va_list vlist;

    va_start(vlist, n);
    for (i = 0;i < n;i++) {
        sum += va_arg(vlist, int);
    }

    va_end(vlist);
    return sum;
}