#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Member.h"
#include "LinkedList.h"

// enum을 별칭인 Menu를 이용해서 정의 -> 나중에 해당 단어 사용시 앞에 enum 계속 붙이기 귀찮으니까
typedef enum {
	TERMINATE, INS_FRONT, INS_REAR, RMV_FRONT, RMV_REAR, PRINT_CRNT, RMV_CRNT, SRCH_NO, SRCH_NAME, PRINT_ALL, CLEAR
} Menu;

// 메뉴 선택
Menu SelectMenu(void)
{
	int ch;
	char* mstring[] = {
		"머리에 노드 삽입", "꼬리에 노드 삽입", "머리 노드 삭제",
		"꼬리 노드 삭제", "선택 노드 출력", "선택 노드 삭제",
		"번호 검색", "이름으로 검색", "모든 노드 출력", " 모든 노드 삭제"
	};
	do {
		for (int i = TERMINATE;i < CLEAR;i++) {
			printf("(%2d) %-18.18s ", i + 1, mstring[i]); // 이것도 서식 맞춘 거 오니쪽 정렬
			if (i % 3 == 2) putchar('\n'); // 그냥 예쁘게 출력할 건데 3개씩만 한 줄에 출력하도록
		}
		printf("(0) 종료 : "); scanf("%d", &ch); // 마지막 꺼는 :도 표시되도록
	} while (ch<TERMINATE || ch > CLEAR); // 0부터 10의 범위를 넘어가지 않는 경우에 대해(정상이니까) 반복
	return(Menu)ch;
}
int main(void)
{
	Menu menu;
	List list;
	Initialize(&list);
	do {
		Member x;
		switch (menu = SelectMenu()) {
		case INS_FRONT: // 머리에 노드 삽입
			x = ScanMember("머리에 삽입", MEMBER_NO | MEMBER_NAME);
			// 첫 인자: "머리에 삽입 하는 데이터를 입력하세요" 가 출력됨
			// 두번쨰 인자: MEMBER_NO만 들어오면 번호만, NAME만 들어오면 NAME만 둘 다 들어오면 정상값으로 번호와 이름을 모두 받아와서
			// 그걸 비트연산으로 합하면 0011이 되므로 ScanMember함수에서 번호, 이름을 모두 출력 (0001 이면 번호만 0010이면 이름만)
			InsertFront(&list, &x); // 연결리스트 구현한 함수를 호출
			break;
		case INS_REAR: // 꼬리에 노드 삽입
			x = ScanMember("꼬리에 삽입", MEMBER_NO | MEMBER_NAME);
			InsertRear(&list, &x);
			break;
		case RMV_FRONT: // 머리 노드 삭제
			RemoveFront(&list);
			break;
		case RMV_REAR: // 꼬리 노드 삭제
			RemoveRear(&list);
			break;
		case PRINT_CRNT: // 선택 노드 데이터 출력
			PrintLnCurrent(&list);
			break;
		case RMV_CRNT: // 선택 노드 삭제
			RemoveCurrent(&list);
			break;
		case SRCH_NO: // 번호로 검색
			x = ScanMember("검색(번호)", MEMBER_NO); // 바로 이런 상황에는 번호만 궁금한 거니까! sw에 번호만 넘기는 것!
			if (search(&list, &x, MemberNoCmp) != NULL) PrintLnCurrent(&list);
			else puts("그 번호의 데이터가 없습니다.");
			break;
		case SRCH_NAME: // 이름으로 검색
			x = ScanMember("검색(이름)", MEMBER_NAME); // 이건 이름만 넘겨서
			if (search(&list, &x, MemberNameCmp) != NULL) PrintLnCurrent(&list);
			else puts("그 이름의 데이터가 없습니다.");
			break;
		case PRINT_ALL: // 모든 노드 내 데이터 출력
			Print(&list); break;
		case CLEAR:// 모든 노드 삭제
			Clear(&list); break;
		}
	} while (menu != TERMINATE); // 0값을 받는 게 아닐 때까지
	Terminate(&list); // 0값 받았으면 종료

	return 0;
} 