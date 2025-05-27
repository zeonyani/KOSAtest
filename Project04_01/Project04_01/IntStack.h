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

/*--- 스택 초기화 ---*/
int Initialize(IntStack* s, int max)
{
    s->ptr = 0; // 데이터 개수는 0개
    if ((s->stk = (int*)calloc(max, sizeof(int))) == NULL) { // calloc은 void* 형이라서 형변환 해줘야, malloc과 동일하나 0으로 초기화해준다는 차이
        s->max = 0; // 배열 생성실패
        return -1;
    }
    s->max = max;  // 정상인 경우 스택 크기는 보정해주기
    return 0;
}

/*--- 스택에 데이터 푸시 ---*/
int Push(IntStack* s, int x)
{
    if (s->ptr >= s->max) // 현재 데이터 개수 >= 최대 데이터개수 ==> push 불가
        return -1;
    s->stk[s->ptr++] = x; // 현재 배열 다음 위치에 입력받은 데이터 저장
    return 0;
}

/*--- 스택에서 데이터를 팝 ---*/
int Pop(IntStack* s, int* x)
{
    if (s->ptr <= 0) // 스택이 비어 있음
        return -1;
    *x = s->stk[--s->ptr]; // 하나 이전을 가리키고 팝한 결과를 출력해야하니까 그 값을 저장
    return 0;
}

/*--- 스택에서 데이터를 피크 ---*/
int Peek(const IntStack* s, int* x)
{
    if (s->ptr <= 0)// 스택이 비어 있음
        return -1;
    *x = s->stk[s->ptr - 1];
    return 0;
}

/*--- 스택의 모든 요소 삭제(클리어) ---*/
void Clear(IntStack* s)
{
    s->ptr = 0;
}

/*--- 스택의 최대 용량 ---*/
int Capacity(const IntStack* s)
{
    return s->max;
}

/*--- 스택에 쌓여 있는 데이터 수 ---*/
int Size(const IntStack* s)
{
    return s->ptr;
}

/*--- 스택은 비어 있는가? ---*/
int IsEmpty(const IntStack* s)
{
    return s->ptr <= 0; // ptr(즉 데이터 개수)이 0이하이면 1(참이 되니까)반환. 나머지는 0 반환
}

/*--- 스택은 가득 찼는가? ---*/
int IsFull(const IntStack* s)
{
    return s->ptr >= s->max; // ptr(데이터 개수)가 max(스택 최대용량) 이상이면 1(참이니까) 반환 아니면 0반환
}

/*--- 스택에서 검색 ---*/
int Search(const IntStack* s, int x)
{
    for (int i = s->ptr - 1; i >= 0; i--)   // 꼭대기(top) → 바닥(bottom)으로 선형 검색
        if (s->stk[i] == x)
            return i;       // 검색 성공
    return -1;              // 검색 실패
}

/*--- 모든 데이터 출력 ---*/
void Print(const IntStack* s)
{
    for (int i = 0; i < s->ptr; i++)        // 바닥(bottom) → 꼭대기(top)로 스캔
        printf("%d ", s->stk[i]);
    putchar('\n');
}

/*--- 스택 종료 ---*/
void Terminate(IntStack* s)
{
    if (s->stk != NULL)
        free(s->stk);       // 배열을 삭제
    s->max = s->ptr = 0;
}
#endif
