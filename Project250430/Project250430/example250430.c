#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


/*
//WriteString.c
int main(void)
{
	char* str = "Simple String";

	printf("1. puts test -----\n");
	puts(str);					//	puts�Լ��� ȣ��. ���ڿ��� ����� ��ġ���� ���ڿ��� �ּҰ� ��ȯ�ǹǷ� ���ڿ� �ּҰ� ����
	puts("So simple String");	//	puts�Լ��� ȣ��. ���ڿ��� ����� ��ġ���� ���ڿ��� �ּҰ� ��ȯ�ǹǷ� ���ڿ� �ּҰ� ����

	printf("2. fputs test -----\n");
	fputs(str, stdout);			//	fputs �Լ� ȣ��. stdout�� ���޵Ǿ ����ͷ� ���.
	printf("\n");				//	���๮�ڸ� �� ����
	fputs("So simple String", stdout);
	printf("\n");

	printf("3. end of main -----\n");

	return 0;
}


//ReadString.c
int main(void)
{
	char str[7];
	int i;

	for (i = 0;i < 3;i++) {
		fgets(str, sizeof(str), stdin);			//	���๮�ڸ� ���������� �о����. �׷��� �ٹٲ޿� �ִ� �� �˾Ƽ� �����ؾ� scanf�� ����
		//	���鵵 �ν�(scanf���� ����)
		printf("Read : %d %s\n", i + 1, str);
	}

	return 0;
}


//NeedInputButFlush.c
void ClearBuffer(void);
int main(void)
{
	char perID[7];
	char name[10];

	fputs("�ֹι�ȣ 6�ڸ� : ", stdout);
	fgets(perID, sizeof(perID), stdin);
	ClearBuffer();						//	�� �Լ� ���̴� 6�ڸ� ���� �� "����Ű�� ���๮��"�� �̸����� �ν��ع�����!

	//fflush(stdin);					//	�̰� ����ȵǴ� ������ �����Ʃ��� 15�̻���ʹ� �ȵȴٰ� ��

	fputs("�̸� : ", stdout);
	fgets(name, sizeof(name), stdin);

	printf("�ֹι�ȣ�� %s\n", perID);
	printf("�̸��� %s\n", name);

	return 0;
}
void ClearBuffer(void)
{
	while ((getchar()) != '\n');
}


int main(int argc, char* argv[])
{
	int i;
	float f;
	char c, str[32];

	scanf("%d ", &i);		printf("1: %d\n", i);
	scanf("%f", &f);		printf("2: %f\n", f);
	//scanf("%f\n", &f);		printf("����Ű �Դ� �� ���� ù��° ���\n"); //����Ű �Է� ��ü�� ���� 3�� ���ڷ� �νĵǴ� �� ����
	//scanf("%c", &c);		printf("3: %c\n", c);
	scanf("%*c%c", &c);		printf("�� ��° ���\n"); printf("3: %c\n", c);
	//scanf("%f\n", &f);		printf("����Ű ������(ù��° ���)\n");
	scanf("%s", str);		printf("4: %s\n", str);	

	return 0;
}


//RemoveBSN.c
void RemoveBSN(char str[]);
int main(void)
{
	char str[100];
	printf("���ڿ� �Է� : ");
	fgets(str, sizeof(str), stdin);
	printf("����: %d ����: %s\n", strlen(str), str);

	RemoveBSN(str);
	printf("���� %d ���� %s\n", strlen(str), str);

	return 0;
}

void RemoveBSN(char str[])					//	�齽������ �����!
{
	int len = strlen(str);
	str[len - 1] = 0;
}


//StringCoipyCase.c
int main(void)
{
	char str1[20] = "1234567890";
	char str2[20];
	char str3[5];

	//case 1
	strcpy(str2, str1);
	puts(str2);

	//case 2
	strncpy(str3, str1, sizeof(str3));
	puts(str3);

	//case 3
	strncpy(str3, str1, sizeof(str3) - 1);
	str3[sizeof(str3) - 1] = 0;
	puts(str3);

	return 0;
}


//StringConcatCase.c
int main(void)
{
	char str1[20] = "First~";
	char str2[20] = "Second";

	char str3[20] = "Simple num";
	char str4[20] = "1234567890";

	//case 1
	strcat(str1, str2);
	puts(str1);

	//case2
	strncat(str3, str4, 7);
	puts(str3);

	return 0;
}


//StringCompCase.c
int main(void)
{
	char str1[20];
	char str2[20];
	
	printf("���ڿ� �Է�1: ");
	scanf("%s", str1);

	printf("���ڿ� �Է�2: ");
	scanf("%s", str2);

	if (!strcmp(str1, str2)) puts("���� ����");
	else {
		puts("�������� ����");
		if (!strncmp(str1, str2, 3)) puts("�׷��� �� 3���ڴ� ����");
	}
	(
	return 0;
}


//ConvString.c
int main(void)
{
	char str[20];
	printf("���� �Է�: ");
	scanf("%s", str);
	printf("%d\n", atoi(str));

	printf("�Ǽ� �Է�: ");
	scanf("%s", str);
	printf("%g\n", atof(str));

	return 0;
}


//21-2-1
int main(void)
{
	char str[BUFSIZ], tmp[BUFSIZ];
	long sum = 0, cnt = 0;

	printf("Input some string : ");
	scanf("%s", str);

	for (int i = 0; i <= strlen(str); i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			tmp[cnt++] = str[i];
		}
		else if (cnt != 0) {
			tmp[cnt] = '\0';
			printf("%s+", tmp);
			sum += atoi(tmp);
			cnt = 0;
		}
	}
	printf("\b=%ld\n", sum);

	return 0;
}


//21-2-2
void ClearBuffer(void);
int main(void)
{
	char str1[20];
	char str2[20];
	char str3[40];

	printf("str1 �Է� ");
	fgets(str1, sizeof(str1), stdin);
	//ClearBuffer();

	printf("str2 �Է� ");
	fgets(str2, sizeof(str2), stdin);

	strncpy(str3, str1, sizeof(str3));
	
	strcat(str3, str2);
	puts(str3);

	return 0;
}

void ClearBuffer(void)
{
	while ((getchar()) != '\n');
}


//21-2-3 worll 12 world 12�� ���� ������� ����ϴ� ���� �ذ��ϱ�
int main(void)
{
	char name1[BUFSIZ], name2[BUFSIZ];
	int age1, age2;

	printf("1 �̸� ���� �Է�");
	scanf("%s %d", name1, &age1);
	printf("2 �̸� ���� �Է�");
	scanf("%s %d", name2, &age2);

	
	if (age1 == age2) {
		for (int i = 0;i < strlen(name1);i++) {
			if (name1[i] == name2[i]) {
				if (strlen(name1) == strlen(name2)) {
					printf("���� ���� ���� ���");
					break;
				}
				else {
					printf("���� ���� �ٸ� ���");
					break;
				}
			}
		}
	}
	else printf("���� �ٸ�");
	return 0;
}


//TwoPointerDistance.c
struct point
{
	int xpos;
	int ypos;
};

int main(void)
{
	struct point ps1, ps2;
	double dis;

	fputs("pos1: ", stdout);
	scanf("%d %d", &ps1.xpos, &ps1.ypos);

	fputs("pos1: ", stdout);
	scanf("%d %d", &ps2.xpos, &ps2.ypos);

	dis = sqrt((double)((ps1.xpos - ps2.xpos) * (ps1.xpos-ps2.xpos)
		+ (ps1.ypos - ps2.ypos)*(ps1.ypos - ps2.ypos)));

	printf("�Ÿ��� %g\n", dis);

	return 0;
}


//TelephoneInfo.c
struct person {
	char name[20];
	char phoneNum[20];
	int age;
};

int main(void)
{
	struct person man1, man2;
	strcpy(man1.name, "�ȼ���");
	strcpy(man1.phoneNum, "010-1234-1234");
	man1.age = 23;


	printf("�̸�: "); scanf("%s", man2.name);
	printf("��ȣ: "); scanf("%s", man2.phoneNum);
	printf("����: "); scanf("%d", &(man2.age));

	printf("�̸�: %s\n", man1.name);
	printf("��ȣ: %s\n", man1.phoneNum);
	printf("����: %d\n", man1.age);

	printf("�̸�: %s\n", man2.name);
	printf("��ȣ: %s\n", man2.phoneNum);
	printf("����: %d\n", man2.age);

	return 0;
}


//22-1
struct employee {
	char name[BUFSIZ];
	char perID[BUFSIZ];
	int money;
};

int main(void)
{
	struct employee e1;

	printf("������ �̸�: "); scanf("%s", e1.name);
	printf("�ֹε�� ��ȣ: "); scanf("%s", e1.perID);
	printf("�޿� ����(���� ����): "); scanf("%d", &(e1.money));

	printf("%s\n", e1.name);
	printf("%s\n", e1.perID);
	printf("%d\n", e1.money);

	return 0;
}


//InitStructVal.c
struct point {
	int xpos;
	int ypos;
};
struct person {
	char name[20];
	char phoneNum[20];
	int age;
};
int main(void)
{
	struct point pos = { 10,20 };
	struct person man = { "�̽±�", "010-1111-2222", "21" };
	printf("%d %d\n\n", pos.xpos, pos.ypos);
	printf("%s %s %d\n\n", man.name, man.phoneNum, man.age);

	return 0;
}


//22-2
struct employee {
	char name[BUFSIZ];
	char phone[BUFSIZ];
	int money;
};

int main(void)
{
	struct employee arr[3];
	for (int i = 0;i < 3;i++) {
		printf("�̸�: "); scanf("%s", arr[i].name);
		printf("��ȣ: "); scanf("%s", arr[i].phone);
		printf("����: "); scanf("%d", &(arr[i].money));

		//printf("%d", arr[i].money);
	}
	printf("\n\n\n");

	for (int i = 0;i < 3;i++) {
		printf("%s\n", arr[i].name);
		printf("%s\n", arr[i].phone);
		printf("%d", arr[i].money);
	}
}
*/