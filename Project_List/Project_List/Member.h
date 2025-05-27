#define _CRT_SECURE_NO_WARNINGS
#pragma once
//회원데이터 관련 헤더파일
#ifndef ___Member
#define ___Member
#include <stdio.h>
#include <string.h> // strcmp 사용을 위함
//회원 데이터 구조체
typedef struct {
	int no; // 번호 변수
	char name[20]; // 이름 배열 변수
} Member; //해당 구조체 자료형은 별칭 Member로 정함 / 굳이 태그(노드작성된 LinkedList.h 처럼)를 안썼으므로 구조체 내부에서 Member형 못 씀(아직 정의 안됐으니까!)
//애초에 typedef을 쓰려면 별칭은 필수(문법!)

#define MEMBER_NO 1 //매크로변수로 번호는 1로 지정 ====> 0001 (2)
#define MEMBER_NAME 2 //매크로변수로 이름은 2로 지정 ====> 0010 (2)
// 이 매크로 변수는 비트 연산을 하기 위한 것!

// 회원 번호를 비교하는 함수
int MemberNoCmp(const Member* x, const Member* y) {
	return x->no < y->no ? -1 : (x->no > y->no ? 1 : 0);
	//call by reference로 x, y 를 받아옴 (그 x, y는 구조체 Member자료형)
	//return 값은 하나만 가질 수 있음
	//x번호가 y번호 이하면 -1을 반환
	//그렇지 않으면 (x 번호가 더 크면 1, 두 번호가 같으면 0을 반환)
	//정리: x번호가 더 크다(1 반환), 같다(0 반환), y번호가 더 크다(-1 반환)
}
//회원 이름을 비교하는 함수
int MemberNameCmp(const Member* x, const Member* y) {
	return strcmp(x->name, y->name);
	//strcmp 함수를 이용해서 x이름 순서가 앞순서면 -1, 같으면 0, x이름이 더 뒤순서면 1
}
// 회원 데이터를 출력하는 함수
void PrintMember(const Member* x) {
	printf("%d %s", x->no, x->name);
	// 그냥 주어진 Member형 구조체(회원)의 번호와 이름 출력
}
// 줄바꿈 있는 버전으로 회원 데이터 출력
void PrintLnMember(const Member* x) {
	printf("%d %s\n", x->no, x->name);
}
//회원 데이터를 읽는 함수
Member ScanMember(const char* message, int sw) {
	Member tmp;
	printf("%s 하는 데이터를 입력하세요.\n", message);
	if (sw & MEMBER_NO) { printf("번호 : "); scanf("%d", &tmp.no); }
	if (sw & MEMBER_NAME) { printf("이름: "); scanf("%s", &tmp.name); }
	return tmp;
}
#endif //___Member

