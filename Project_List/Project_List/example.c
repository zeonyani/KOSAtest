#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Member.h"
#include "LinkedList.h"

// enum�� ��Ī�� Menu�� �̿��ؼ� ���� -> ���߿� �ش� �ܾ� ���� �տ� enum ��� ���̱� �������ϱ�
typedef enum {
	TERMINATE, INS_FRONT, INS_REAR, RMV_FRONT, RMV_REAR, PRINT_CRNT, RMV_CRNT, SRCH_NO, SRCH_NAME, PRINT_ALL, CLEAR
} Menu;

// �޴� ����
Menu SelectMenu(void)
{
	int ch;
	char* mstring[] = {
		"�Ӹ��� ��� ����", "������ ��� ����", "�Ӹ� ��� ����",
		"���� ��� ����", "���� ��� ���", "���� ��� ����",
		"��ȣ �˻�", "�̸����� �˻�", "��� ��� ���", " ��� ��� ����"
	};
	do {
		for (int i = TERMINATE;i < CLEAR;i++) {
			printf("(%2d) %-18.18s ", i + 1, mstring[i]); // �̰͵� ���� ���� �� ������ ����
			if (i % 3 == 2) putchar('\n'); // �׳� ���ڰ� ����� �ǵ� 3������ �� �ٿ� ����ϵ���
		}
		printf("(0) ���� : "); scanf("%d", &ch); // ������ ���� :�� ǥ�õǵ���
	} while (ch<TERMINATE || ch > CLEAR); // 0���� 10�� ������ �Ѿ�� �ʴ� ��쿡 ����(�����̴ϱ�) �ݺ�
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
		case INS_FRONT: // �Ӹ��� ��� ����
			x = ScanMember("�Ӹ��� ����", MEMBER_NO | MEMBER_NAME);
			// ù ����: "�Ӹ��� ���� �ϴ� �����͸� �Է��ϼ���" �� ��µ�
			// �ι��� ����: MEMBER_NO�� ������ ��ȣ��, NAME�� ������ NAME�� �� �� ������ �������� ��ȣ�� �̸��� ��� �޾ƿͼ�
			// �װ� ��Ʈ�������� ���ϸ� 0011�� �ǹǷ� ScanMember�Լ����� ��ȣ, �̸��� ��� ��� (0001 �̸� ��ȣ�� 0010�̸� �̸���)
			InsertFront(&list, &x); // ���Ḯ��Ʈ ������ �Լ��� ȣ��
			break;
		case INS_REAR: // ������ ��� ����
			x = ScanMember("������ ����", MEMBER_NO | MEMBER_NAME);
			InsertRear(&list, &x);
			break;
		case RMV_FRONT: // �Ӹ� ��� ����
			RemoveFront(&list);
			break;
		case RMV_REAR: // ���� ��� ����
			RemoveRear(&list);
			break;
		case PRINT_CRNT: // ���� ��� ������ ���
			PrintLnCurrent(&list);
			break;
		case RMV_CRNT: // ���� ��� ����
			RemoveCurrent(&list);
			break;
		case SRCH_NO: // ��ȣ�� �˻�
			x = ScanMember("�˻�(��ȣ)", MEMBER_NO); // �ٷ� �̷� ��Ȳ���� ��ȣ�� �ñ��� �Ŵϱ�! sw�� ��ȣ�� �ѱ�� ��!
			if (search(&list, &x, MemberNoCmp) != NULL) PrintLnCurrent(&list);
			else puts("�� ��ȣ�� �����Ͱ� �����ϴ�.");
			break;
		case SRCH_NAME: // �̸����� �˻�
			x = ScanMember("�˻�(�̸�)", MEMBER_NAME); // �̰� �̸��� �Ѱܼ�
			if (search(&list, &x, MemberNameCmp) != NULL) PrintLnCurrent(&list);
			else puts("�� �̸��� �����Ͱ� �����ϴ�.");
			break;
		case PRINT_ALL: // ��� ��� �� ������ ���
			Print(&list); break;
		case CLEAR:// ��� ��� ����
			Clear(&list); break;
		}
	} while (menu != TERMINATE); // 0���� �޴� �� �ƴ� ������
	Terminate(&list); // 0�� �޾����� ����

	return 0;
} 