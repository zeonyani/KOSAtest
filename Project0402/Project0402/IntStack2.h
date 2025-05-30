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

/*--- 스택 초기화 ---*/
int Initialize(IntStack2* s, int max)
{
    s->ptrA = 0;
    if ((s->stk = (int*)calloc(max, sizeof(int))) == NULL) { //calloc에 대한 형변환
        s->max = 0; // 배열 생성에 실패
        s->ptrB = 0;
        return -1;
    }
    s->ptrB = max - 1; //뒤에서 출발
    s->max = max;
    return 0;
}

/*--- 스택에 데이터를 푸시 ---*/
int Push(IntStack2* s, int sw, int x)
{
    if (s->ptrA >= s->ptrB + 1) // 스택은 가득 참
        return -1;

    switch (sw) {
    case StackA: s->stk[s->ptrA++] = x;  break;
    case StackB: s->stk[s->ptrB--] = x;  break;
    }
    return 0;
}


/*--- 스택에서 데이터를 팝 ---*/
int Pop(IntStack2* s, int sw, int* x)
{
    switch (sw) {
    case StackA:
        if (s->ptrA <= 0)                       // 스택은 비었음
            return -1;
        *x = s->stk[--s->ptrA];
        break;

    case StackB:
        if (s->ptrB >= s->max - 1)              // 스택은 비었음
            return -1;
        *x = s->stk[++s->ptrB];
        break;
    }
    return 0;
}

/*--- 스택에서 데이터를 피크 ---*/
int Peek(const IntStack2* s, int sw, int* x)
{
    switch (sw) {
    case StackA:
        if (s->ptrA <= 0)                       // 스택은 비었음
            return -1;
        *x = s->stk[s->ptrA - 1];
        break;

    case StackB:
        if (s->ptrB >= s->max - 1)              // 스택은 비었음
            return -1;
        *x = s->stk[s->ptrB + 1];
        break;
    }
    return 0;
}

/*--- 스택 비우기 ---*/
void Clear(IntStack2* s, int sw)
{   //배열의 요소를 변경할 필요 없이 ptr을 0으로
    switch (sw) {
    case StackA: s->ptrA = 0;          break;
    case StackB: s->ptrB = s->max - 1; break;
    }
}

/*--- 스택 용량 ---*/
int Capacity(const IntStack2* s)
{
    return s->max; //단일과 동일
}

/*--- 스택에 쌓여 있는 데이터 개수---*/
int Size(const IntStack2* s, int sw)
{
    return (sw == StackA) ? s->ptrA : s->max - s->ptrB - 1;
}
//StackB : ptrB가 데이터 수를 의미하는 것이 아니므로 다음 데이터를 삽입할 인덱스를 기억한다고 생각하자!

/*--- 스택은 비어 있는가? ---*/
int IsEmpty(const IntStack2* s, int sw)
{
    return (sw == StackA) ? (s->ptrA <= 0) : (s->ptrB >= s->max - 1);
}

/*--- 스택은 가득 찼는가? ---*/
int IsFull(const IntStack2* s)
{
    return s->ptrA >= s->ptrB + 1;
}

/*--- 스택에서 검색 ---*/
int Search(const IntStack2* s, int sw, int x)
{
    switch (sw) {
    case StackA:
        for (int i = s->ptrA - 1; i >= 0; i--)      // 꼭대기(top) → 바닥(bottom)으로 선형 검색
            if (s->stk[i] == x)
                return i;       // 검색 성공
        return -1;              // 검색 실패

    case StackB:
        for (int i = s->ptrB + 1; i < s->max; i++)  // 꼭대기(top) → 바닥(bottom)으로 선형 검색
            if (s->stk[i] == x)
                return i;       // 검색 성공
        return -1;              // 검색 실패
    }
}

/*--- 모든 데이터 출력 ---*/
void Print(const IntStack2* s, int sw)
{
    switch (sw) {
    case StackA:
        for (int i = 0; i < s->ptrA; i++)           // 바닥(bottom) → 꼭대기(top)로 스캔
            printf("%d ", s->stk[i]);
        break;

    case StackB:
        for (int i = s->max - 1; i > s->ptrB; i--)  // 바닥(bottom) → 꼭대기(top)로 스캔
            printf("%d ", s->stk[i]);
        break;
    }
    putchar('\n');
}

/*--- 스택 종료 ---*/
void Terminate(IntStack2* s)
{
    if (s->stk != NULL)
        free(s->stk);               // 배열을 해제
    s->max = s->ptrA = s->ptrB = 0;
}
#endif // !__IntStack2
