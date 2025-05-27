#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "IntStack.h"
int main(void)
{
	IntStack s;
	if (Initialize(&s, 64) == -1) {
		puts("���� ���� ����");
		return -1;
	}
	while (1) {
		int menu, x;
		int search;
		printf("���� ������ ��: %d / %d\n", Size(&s), Capacity(&s));
		printf("(1) Ǫ�� (2) �� (3) ��ũ (4) Ŭ���� (5) ������ �� (6) ��? (7) ����? (8) �˻� (9) ��� (0) ���� ");
		scanf("%d", &menu);

		if (menu == 0) break;
		switch (menu) {
		case 1:
			printf("������ : "); scanf("%d", &x);
			if (Push(&s, x) == -1) puts("\a����: Ǫ�� ����\n");
			break;
		case 2:
			if (Pop(&s, &x) == -1) puts("\a����: �� ����\n");
			else printf("�� �����ʹ� %d\n", x);
			break;
		case 3:
			if (Peek(&s, &x) == -1) puts("\a���� : ��ũ ����\n");
			else printf("��ũ �����ʹ� %d\n", x);
			break;
		case 4:
			puts("������ ���� ����\n");
			Clear(&s);
			break;
		case 5:
			printf("������ ���� %d��\n", Size(&s));
			break;
		case 6:
			if ((IsEmpty(&s)) == 1) puts("�����!\n");
			else puts("�� �����!");
			break;
		case 7:
			if ((IsFull(&s)) == 1) puts("���� á��!\n");
			else puts("�� á��!");
			break;
		case 8:
			if (s.ptr != 0) {
				puts("�˻��� ����?");
				scanf("%d", &search);
				if (Search(&s, search) == -1) {
					puts("�� ���� ���� �����ϴ�!");
				}
				else {
					printf("%d �ε����� �ֽ��ϴ�.\n", Search(&s, search));
				}
			}
			else puts("����־��!");
			break;
		case 9:
			if (s.ptr != 0) Print(&s);
			else puts("�������!");
			break;
		}
	}
	Terminate(&s);
	return 0;
}