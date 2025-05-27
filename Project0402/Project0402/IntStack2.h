#define _CRT_SECURE_NO_WARNINGS
#ifndef __IntStack2
#define __IntStack2
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "IntStack2.h"
enum{StackA, StackB};
typedef struct {
    int max;
    int ptrA, ptrB;
    int* stk;

}IntStack2;

/*--- ���� �ʱ�ȭ ---*/
int Initialize(IntStack2* s, int max)
{
    s->ptrA = 0;
    if ((s->stk = (int*)calloc(max, sizeof(int))) == NULL) { //calloc�� ���� ����ȯ
        s->max = 0; // �迭 ������ ����
        s->ptrB = 0;
        return -1;
    }
    s->ptrB = max - 1; //�ڿ��� ���
    s->max = max;
    return 0;
}

/*--- ���ÿ� �����͸� Ǫ�� ---*/
int Push(IntStack2* s, int sw, int x)
{
    if (s->ptrA >= s->ptrB + 1) // ������ ���� ��
        return -1;

    switch (sw) {
    case StackA: s->stk[s->ptrA++] = x;  break;
    case StackB: s->stk[s->ptrB--] = x;  break;
    }
    return 0;
}


/*--- ���ÿ��� �����͸� �� ---*/
int Pop(IntStack2* s, int sw, int* x)
{
    switch (sw) {
    case StackA:
        if (s->ptrA <= 0)                       // ������ �����
            return -1;
        *x = s->stk[--s->ptrA];
        break;

    case StackB:
        if (s->ptrB >= s->max - 1)              // ������ �����
            return -1;
        *x = s->stk[++s->ptrB];
        break;
    }
    return 0;
}

/*--- ���ÿ��� �����͸� ��ũ ---*/
int Peek(const IntStack2* s, int sw, int* x)
{
    switch (sw) {
    case StackA:
        if (s->ptrA <= 0)                       // ������ �����
            return -1;
        *x = s->stk[s->ptrA - 1];
        break;

    case StackB:
        if (s->ptrB >= s->max - 1)              // ������ �����
            return -1;
        *x = s->stk[s->ptrB + 1];
        break;
    }
    return 0;
}

/*--- ���� ���� ---*/
void Clear(IntStack2* s, int sw)
{   //�迭�� ��Ҹ� ������ �ʿ� ���� ptr�� 0����
    switch (sw) {
    case StackA: s->ptrA = 0;          break;
    case StackB: s->ptrB = s->max - 1; break;
    }
}

/*--- ���� �뷮 ---*/
int Capacity(const IntStack2* s)
{
    return s->max; //���ϰ� ����
}

/*--- ���ÿ� �׿� �ִ� ������ ����---*/
int Size(const IntStack2* s, int sw)
{
    return (sw == StackA) ? s->ptrA : s->max - s->ptrB - 1;
}
//StackB : ptrB�� ������ ���� �ǹ��ϴ� ���� �ƴϹǷ� ���� �����͸� ������ �ε����� ����Ѵٰ� ��������!

/*--- ������ ��� �ִ°�? ---*/
int IsEmpty(const IntStack2* s, int sw)
{
    return (sw == StackA) ? (s->ptrA <= 0) : (s->ptrB >= s->max - 1);
}

/*--- ������ ���� á�°�? ---*/
int IsFull(const IntStack2* s)
{
    return s->ptrA >= s->ptrB + 1;
}

/*--- ���ÿ��� �˻� ---*/
int Search(const IntStack2* s, int sw, int x)
{
    switch (sw) {
    case StackA:
        for (int i = s->ptrA - 1; i >= 0; i--)      // �����(top) �� �ٴ�(bottom)���� ���� �˻�
            if (s->stk[i] == x)
                return i;       // �˻� ����
        return -1;              // �˻� ����

    case StackB:
        for (int i = s->ptrB + 1; i < s->max; i++)  // �����(top) �� �ٴ�(bottom)���� ���� �˻�
            if (s->stk[i] == x)
                return i;       // �˻� ����
        return -1;              // �˻� ����
    }
}

/*--- ��� ������ ��� ---*/
void Print(const IntStack2* s, int sw)
{
    switch (sw) {
    case StackA:
        for (int i = 0; i < s->ptrA; i++)           // �ٴ�(bottom) �� �����(top)�� ��ĵ
            printf("%d ", s->stk[i]);
        break;

    case StackB:
        for (int i = s->max - 1; i > s->ptrB; i--)  // �ٴ�(bottom) �� �����(top)�� ��ĵ
            printf("%d ", s->stk[i]);
        break;
    }
    putchar('\n');
}

/*--- ���� ���� ---*/
void Terminate(IntStack2* s)
{
    if (s->stk != NULL)
        free(s->stk);               // �迭�� ����
    s->max = s->ptrA = s->ptrB = 0;
}
#endif // !__IntStack2
