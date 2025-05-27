#ifndef __IntStack
#define __IntStack
#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int max;
    int ptr;
    int* stk;
} IntStack;

/*--- ���� �ʱ�ȭ ---*/
int Initialize(IntStack* s, int max)
{
    s->ptr = 0; // ������ ������ 0��
    if ((s->stk = (int*)calloc(max, sizeof(int))) == NULL) { // calloc�� void* ���̶� ����ȯ �����, malloc�� �����ϳ� 0���� �ʱ�ȭ���شٴ� ����
        s->max = 0; // �迭 ��������
        return -1;
    }
    s->max = max;  // ������ ��� ���� ũ��� �������ֱ�
    return 0;
}

/*--- ���ÿ� ������ Ǫ�� ---*/
int Push(IntStack* s, int x)
{
    if (s->ptr >= s->max) // ���� ������ ���� >= �ִ� �����Ͱ��� ==> push �Ұ�
        return -1;
    s->stk[s->ptr++] = x; // ���� �迭 ���� ��ġ�� �Է¹��� ������ ����
    return 0;
}

/*--- ���ÿ��� �����͸� �� ---*/
int Pop(IntStack* s, int* x)
{
    if (s->ptr <= 0) // ������ ��� ����
        return -1;
    *x = s->stk[--s->ptr]; // �ϳ� ������ ����Ű�� ���� ����� ����ؾ��ϴϱ� �� ���� ����
    return 0;
}

/*--- ���ÿ��� �����͸� ��ũ ---*/
int Peek(const IntStack* s, int* x)
{
    if (s->ptr <= 0)// ������ ��� ����
        return -1;
    *x = s->stk[s->ptr - 1];
    return 0;
}

/*--- ������ ��� ��� ����(Ŭ����) ---*/
void Clear(IntStack* s)
{
    s->ptr = 0;
}

/*--- ������ �ִ� �뷮 ---*/
int Capacity(const IntStack* s)
{
    return s->max;
}

/*--- ���ÿ� �׿� �ִ� ������ �� ---*/
int Size(const IntStack* s)
{
    return s->ptr;
}

/*--- ������ ��� �ִ°�? ---*/
int IsEmpty(const IntStack* s)
{
    return s->ptr <= 0; // ptr(�� ������ ����)�� 0�����̸� 1(���� �Ǵϱ�)��ȯ. �������� 0 ��ȯ
}

/*--- ������ ���� á�°�? ---*/
int IsFull(const IntStack* s)
{
    return s->ptr >= s->max; // ptr(������ ����)�� max(���� �ִ�뷮) �̻��̸� 1(���̴ϱ�) ��ȯ �ƴϸ� 0��ȯ
}

/*--- ���ÿ��� �˻� ---*/
int Search(const IntStack* s, int x)
{
    for (int i = s->ptr - 1; i >= 0; i--)   // �����(top) �� �ٴ�(bottom)���� ���� �˻�
        if (s->stk[i] == x)
            return i;       // �˻� ����
    return -1;              // �˻� ����
}

/*--- ��� ������ ��� ---*/
void Print(const IntStack* s)
{
    for (int i = 0; i < s->ptr; i++)        // �ٴ�(bottom) �� �����(top)�� ��ĵ
        printf("%d ", s->stk[i]);
    putchar('\n');
}

/*--- ���� ���� ---*/
void Terminate(IntStack* s)
{
    if (s->stk != NULL)
        free(s->stk);       // �迭�� ����
    s->max = s->ptr = 0;
}
#endif
