#include <stdio.h>
/*
//10-1
int main(void) {
    int dec;
    do {
        printf("10���� ���� �Է��ϼ���.(���� �Է� �Ұ�) : ");
        scanf_s("%d", &dec);
    } while (dec < 0);
    printf("%8d�� 16�����δ� %8x", dec, dec);
    return 0;
}
*/


//10-2
void changeNum(int n1, int n2);
void multiTable(int n1, int n2);

int main(void)
{
    int num1, num2;

    do {
        printf("���� �ΰ� �Է��ϼ���. (�������� ���� ��)");
        scanf_s("%d %d", &num1, &num2);
    } while (num1 > 9 || num1 < 2 || num2 > 9 || num2 < 2);

    if ((num1 - num2) > 0) {
        //changeNum(num2, num2);
        multiTable(num2, num1);
    }
    else multiTable(num1, num2);

    return 0;
}
void changeNum(int n1, int n2)
{
    int tmp;
    tmp = n1;
    n1 = n2;
    n2 = tmp;
}
void multiTable(int n1, int n2)
{
    for (;n1 < n2 + 1;n1++) {
        for (int i = 0;i < 9;i++) {
            printf("%d x %d = %2d\n", n1, i + 1, n1 * (i + 1));
        }
        printf("\n");
    }

}


/*
//10-3
int main(void)
{
    int num1, num2;
    printf("�� �� ���� �Է�: ");
    scanf_s("%d %d", &num1, &num2);

    return 0;
}
*/