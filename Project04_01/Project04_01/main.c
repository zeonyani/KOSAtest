#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "IntStack.h"
int main(void)
{
	IntStack s;
	if (Initialize(&s, 64) == -1) {
		puts("스택 생성 실패");
		return -1;
	}
	while (1) {
		int menu, x;
		int search;
		printf("현재 데이터 수: %d / %d\n", Size(&s), Capacity(&s));
		printf("(1) 푸시 (2) 팝 (3) 피크 (4) 클리어 (5) 데이터 수 (6) 빔? (7) 가득? (8) 검색 (9) 출력 (0) 종료 ");
		scanf("%d", &menu);

		if (menu == 0) break;
		switch (menu) {
		case 1:
			printf("데이터 : "); scanf("%d", &x);
			if (Push(&s, x) == -1) puts("\a오류: 푸시 실패\n");
			break;
		case 2:
			if (Pop(&s, &x) == -1) puts("\a오류: 팝 실패\n");
			else printf("팝 데이터는 %d\n", x);
			break;
		case 3:
			if (Peek(&s, &x) == -1) puts("\a오류 : 피크 실패\n");
			else printf("피크 데이터는 %d\n", x);
			break;
		case 4:
			puts("데이터 전부 삭제\n");
			Clear(&s);
			break;
		case 5:
			printf("데이터 수는 %d개\n", Size(&s));
			break;
		case 6:
			if ((IsEmpty(&s)) == 1) puts("비었다!\n");
			else puts("안 비었다!");
			break;
		case 7:
			if ((IsFull(&s)) == 1) puts("가득 찼다!\n");
			else puts("안 찼다!");
			break;
		case 8:
			if (s.ptr != 0) {
				puts("검색할 값은?");
				scanf("%d", &search);
				if (Search(&s, search) == -1) {
					puts("그 값은 현재 없습니다!");
				}
				else {
					printf("%d 인덱스에 있습니다.\n", Search(&s, search));
				}
			}
			else puts("비어있어요!");
			break;
		case 9:
			if (s.ptr != 0) Print(&s);
			else puts("비어있음!");
			break;
		}
	}
	Terminate(&s);
	return 0;
}