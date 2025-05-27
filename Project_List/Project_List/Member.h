#define _CRT_SECURE_NO_WARNINGS
#pragma once
//ȸ�������� ���� �������
#ifndef ___Member
#define ___Member
#include <stdio.h>
#include <string.h> // strcmp ����� ����
//ȸ�� ������ ����ü
typedef struct {
	int no; // ��ȣ ����
	char name[20]; // �̸� �迭 ����
} Member; //�ش� ����ü �ڷ����� ��Ī Member�� ���� / ���� �±�(����ۼ��� LinkedList.h ó��)�� �Ƚ����Ƿ� ����ü ���ο��� Member�� �� ��(���� ���� �ȵ����ϱ�!)
//���ʿ� typedef�� ������ ��Ī�� �ʼ�(����!)

#define MEMBER_NO 1 //��ũ�κ����� ��ȣ�� 1�� ���� ====> 0001 (2)
#define MEMBER_NAME 2 //��ũ�κ����� �̸��� 2�� ���� ====> 0010 (2)
// �� ��ũ�� ������ ��Ʈ ������ �ϱ� ���� ��!

// ȸ�� ��ȣ�� ���ϴ� �Լ�
int MemberNoCmp(const Member* x, const Member* y) {
	return x->no < y->no ? -1 : (x->no > y->no ? 1 : 0);
	//call by reference�� x, y �� �޾ƿ� (�� x, y�� ����ü Member�ڷ���)
	//return ���� �ϳ��� ���� �� ����
	//x��ȣ�� y��ȣ ���ϸ� -1�� ��ȯ
	//�׷��� ������ (x ��ȣ�� �� ũ�� 1, �� ��ȣ�� ������ 0�� ��ȯ)
	//����: x��ȣ�� �� ũ��(1 ��ȯ), ����(0 ��ȯ), y��ȣ�� �� ũ��(-1 ��ȯ)
}
//ȸ�� �̸��� ���ϴ� �Լ�
int MemberNameCmp(const Member* x, const Member* y) {
	return strcmp(x->name, y->name);
	//strcmp �Լ��� �̿��ؼ� x�̸� ������ �ռ����� -1, ������ 0, x�̸��� �� �ڼ����� 1
}
// ȸ�� �����͸� ����ϴ� �Լ�
void PrintMember(const Member* x) {
	printf("%d %s", x->no, x->name);
	// �׳� �־��� Member�� ����ü(ȸ��)�� ��ȣ�� �̸� ���
}
// �ٹٲ� �ִ� �������� ȸ�� ������ ���
void PrintLnMember(const Member* x) {
	printf("%d %s\n", x->no, x->name);
}
//ȸ�� �����͸� �д� �Լ�
Member ScanMember(const char* message, int sw) {
	Member tmp;
	printf("%s �ϴ� �����͸� �Է��ϼ���.\n", message);
	if (sw & MEMBER_NO) { printf("��ȣ : "); scanf("%d", &tmp.no); }
	if (sw & MEMBER_NAME) { printf("�̸�: "); scanf("%s", &tmp.name); }
	return tmp;
}
#endif //___Member

