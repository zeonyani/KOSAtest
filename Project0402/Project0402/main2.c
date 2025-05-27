#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "IntStack2.h"
int main(void)
{
    IntStack2 s;

    if (Initialize(&s, 12) == -1) {
        puts("���� ���� ����");
        return 1;
    }

    while (1) {
        int menu, x;
        int idx;

        printf("���� ������ ���� : A : %d B : %d / %d\n", Size(&s, StackA), Size(&s, StackB), Capacity(&s));
        printf("(1) A�� Push (2) A���� Pop (3) A���� Peek (4) A�� ��� (5) A���� �˻� (6) A�� �ʱ�ȭ\n"
            "(7) B�� Push (8) B���� Pop (9) B���� Peek (10) B�� ��� (11) B���� �˻� (12) B�� �ʱ�ȭ\n""(13) �� ���� / ���� �� ���� (0) ���� : ");

        scanf("%d", &menu);

        if (menu == 0) break;

        switch (menu) {
        case 1: // A�� Ǫ��
            printf("������ : ");
            scanf("%d", &x);
            if (Push(&s, StackA, x) == -1)
                puts("\a���� : Ǫ�� ����");
            break;

        case 2: // A���� ��
            if (Pop(&s, StackA, &x) == -1)
                puts("\a���� : �� ����");
            else
                printf("���� �����ʹ� %d�Դϴ�.\n", x);
            break;

        case 3: // A���� ��ũ
            if (Peek(&s, StackA, &x) == -1)
                puts("\a���� : ��ũ ����");
            else
                printf("��ũ�� �����ʹ� %d�Դϴ�.\n", x);
            break;

        case 4: // A ���
            Print(&s, StackA);
            break;

        case 5: // A���� �˻�
            printf("�˻� ������ : ");
            scanf("%d", &x);
            if ((idx = Search(&s, StackA, x) == -1))
                puts("\a���� : �˻� ����");
            else
                printf("�����ʹ� �ε��� %d�� �ֽ��ϴ�.\n", idx);
            break;

        case 6: // A �ʱ�ȭ
            Clear(&s, StackA);
            break;

        case 7: // B�� Ǫ��
            printf("������ : ");
            scanf("%d", &x);
            if (Push(&s, StackB, x) == -1)
                puts("\a���� : Ǫ�� ����");
            break;

        case 8: // B���� ��
            if (Pop(&s, StackB, &x) == -1)
                puts("\a���� : �� ����");
            else
                printf("���� �����ʹ� %d�Դϴ�.\n", x);
            break;

        case 9: // B���� ��ũ
            if (Peek(&s, StackB, &x) == -1)
                puts("\a���� : ��ũ ����");
            else
                printf("��ũ�� �����ʹ� %d�Դϴ�.\n", x);
            break;

        case 10: // B ���
            Print(&s, StackB);
            break;

        case 11: // B���� �˻�
            printf("�˻� ������ : ");
            scanf("%d", &x);
            if ((idx = Search(&s, StackB, x) == -1))
                puts("\a���� : �˻� ����");
            else
                printf("�����ʹ� �ε��� %d�� �ֽ��ϴ�.\n", idx);
            break;

        case 12: // B �ʱ�ȭ
            Clear(&s, StackB);
            break;

        case 13: // �� ���� / ���� �� ���� �Ǵ�
            printf("���� A�� ��� %s.\n", IsEmpty(&s, StackA) ? "�ֽ��ϴ�" : "���� �ʽ��ϴ�");
            printf("���� B�� ��� %s.\n", IsEmpty(&s, StackB) ? "�ֽ��ϴ�" : "���� �ʽ��ϴ�");
            printf("������ ���� %s.\n", IsFull(&s) ? "á���ϴ�" : "���� �ʾҽ��ϴ�");
            break;
        }

    }
    Terminate(&s);

    return 0;
}