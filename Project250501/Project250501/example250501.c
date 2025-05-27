#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
/*
//StructPointer.c
struct point {
	int xpos, ypos;
};

int main(void)
{
	struct point pos1 = { 1,2 };
	struct point pos2 = { 100,200 };
	struct point* pptr = &pos1;

	(*pptr).xpos += 4;
	(*pptr).ypos += 5;
	printf("[%d, %d] \n", pptr->xpos, pptr->ypos);


	pptr = &pos2;
	pptr->xpos += 1;
	pptr->ypos += 2;
	printf("[%d, %d] \n", (*pptr).xpos, (*pptr).ypos);

	return 0;
}


//StructPointerMem.c
struct point {
	int x, y;
};
struct circle {
	double rad;
	struct point* center;
};

int main(void)
{
	struct point cen = { 2,7 };
	double rad = 5.5;

	struct circle ring = { rad, &cen };
	printf("%g\n", ring.rad);
	printf("%d %d\n", (ring.center)->x, (ring.center)->y);

	return 0;
}


//PointRelation.c
struct point {
	int x, y;
	struct point* ptr;
};

int main(void)
{
	struct point p1 = { 1,1 };
	struct point p2 = { 2,2 };
	struct point p3 = { 3,3 };

	p1.ptr = &p2;
	p2.ptr = &p3;
	p3.ptr = &p1;

	printf("���� ������� . . .\n");
	printf("[%d , %d] �� [%d , %d] ����\n"
		, p1.x, p1.y, p1.ptr->x, p1.ptr->y);
	printf("[%d , %d] �� [%d , %d] ����\n"
		, p2.x, p2.y, p2.ptr->x, p2.ptr->y);
	printf("[%d , %d] �� [%d , %d] ����\n"
		, p3.x, p3.y, p3.ptr->x, p3.ptr->y);

	return 0;
}


//TypeNameTypedef.c
typedef int INT;
typedef int* PTR_INT;

typedef unsigned int UNIT;
typedef unsigned int* PTR_UNIT;

typedef unsigned char UCHAR;
typedef unsigned char* PTR_CHAR;

int main(void)
{
	INT num1 = 120;
	PTR_INT pn1 = &num1;

	UNIT num2 = 190;
	PTR_UNIT pn2 = &num2;

	UCHAR ch = 'Z';
	PTR_CHAR pch = &ch;

	printf("%d %u %c", *pn1, *pn2, *pch);

	return 0;
}


//StructTypedef.c
struct point {
	int x, y;
};

typedef struct point POINT;

typedef struct person {
	char name[20];
	char pNum[20];
	int age;
} PERSON;

int main(void)
{
	POINT pos = { 10,20 };
	PERSON man = { "�̽±�", "010-1111-2233", 21 };

	printf("%d %d\n", pos.x, pos.y);
	printf("%s %s %d\n", man.name, man.pNum, man.age);

	return 0;
}


//StructValAndFunction.c
typedef struct point {
	int x, y;
} Point;

void ShowPosition(Point ps) {
	printf("[%d, %d] \n", ps.x, ps.y);
}

Point GetCurrPos(void) {
	Point cen;
	printf("Input current pos: ");
	scanf("%d %d", &cen.x, &cen.y);

	return cen;
}

int main(void)
{
	Point curP = GetCurrPos();
	ShowPosition(curP);

	return 0;
}


//StructMemArrCopy.c
typedef struct person
{
	char name[20];
	char pNum[20];
	int age;
} PERSON;

void ShowPerson(PERSON man) {
	printf("name : %s\n", man.name);
	printf("pNum : %s\n", man.pNum);
	printf("age : %d\n", man.age);
}

PERSON ReadPINFO(void)
{
	PERSON man;
	printf("name?\n", man.name); scanf("%s", &man.name);
	printf("pNum?\n", man.pNum); scanf("%s", &man.pNum);
	printf("age?\n", man.age); scanf("%d", &man.age);

	return man;
}

int main(void)
{
	PERSON saram = ReadPINFO();
	ShowPerson(saram);

	return 0;
}


//StructFuctionCallBRef.c
typedef struct point {
	int xpos, ypos;
} POINT;

void OrgSymTrans(POINT* ptr) //������Ī
{
	ptr->xpos = (ptr->xpos) * -1;
	ptr->ypos = (ptr->ypos) * -1;
}

void ShowPosi(POINT ps) {
	printf("[%d %d]\n", ps.xpos, ps.ypos);
}

int main(void)
{
	POINT pos = { 7,-5 };
	OrgSymTrans(&pos);
	ShowPosi(pos);
	OrgSymTrans(&pos);
	ShowPosi(pos);

	return 0;
}


//23-1
typedef struct point {
	int xpos, ypos;
} POINT;

void SwapXY(int* p1, int* p2) {
	int tmp;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void ShowXY(int x, int y) {
	printf("[%d, %d]\n", x, y);
}

int main(void)
{
	POINT ps1 = { 2,4 };
	POINT ps2 = { 5,7 };

	ShowXY(ps1.xpos, ps1.ypos);
	ShowXY(ps2.xpos, ps2.ypos);

	SwapXY(&ps1.xpos, &ps2.xpos);
	SwapXY(&ps1.ypos, &ps2.ypos);

	printf("\n\n\n");
	ShowXY(ps1.xpos, ps1.ypos);
	ShowXY(ps2.xpos, ps2.ypos);


	return 0;
}


//23-2
typedef struct point {
	int xpos, ypos;
} POINT;

typedef struct rectangle {
	int height, width;
}REC;

int main(void)
{
	int tmpx, tmpy;
	POINT pt1 = { 0,0 }, pt2 = { 0,0 };
	REC Rec;

	printf("1��ǥ"); scanf("%d %d", &pt1.xpos, &pt1.ypos);
	printf("2��ǥ"); scanf("%d %d", &pt2.xpos, &pt2.ypos);
	
	if (pt1.xpos < pt2.xpos) {
		tmpx = pt1.xpos;
		pt1.xpos = pt2.xpos;
		pt2.xpos = tmpx;
	}
	Rec.width = pt1.xpos - pt2.xpos;

	if (pt1.ypos < pt2.ypos) {
		tmpy = pt1.ypos;
		pt1.ypos = pt2.ypos;
		pt2.ypos = tmpy;
	}
	Rec.height = pt1.ypos - pt2.ypos;
	
	printf("�ʺ� %d ���� %d ���̴� %d", Rec.width, Rec.height, Rec.width * Rec.height);

	return 0;
}

//����ü�� �ʿ伺
struct s_data {
	int d1;
	double d2;
	char d3;
} S;
union u_data {
	int d1;
	double d2;
	char d3;
} U;

int main(void)
{
	printf("%d\n", sizeof(S));
	printf("%d", sizeof(U));
	return 0;
}

//UnionValAccess.c
typedef union ubox {
	int mem1, mem2;
	double mem3;
} UB;

int main(void)
{
	UB ub;
	ub.mem1 = 20;
	printf("%d\n", ub.mem2);

	ub.mem3 = 7.15;
	printf("%d\n", ub.mem1); printf("%d\n", ub.mem2); printf("%g\n", ub.mem3);

	return 0;
}


//UsefulUnionAccess.c
typedef struct dbshort {
	unsigned short upper;
	unsigned short lower;
}DBShort;

typedef union rdbuf {
	int iBuf;
	char bBuf[4];
	DBShort sBuf;
} RDBuf;

int main(void)
{
	RDBuf bf;
	printf("���� �Է�: "); scanf("%d", &(bf.iBuf));

	printf("���� 2����Ʈ %u\n", bf.sBuf.upper);
	printf("���� 2����Ʈ %u\n", bf.sBuf.lower);
	printf("���� 1����Ʈ �ƽ�Ű�ڵ� %c\n", bf.bBuf[0]);
	printf("���� 1����Ʈ �ƽ�Ű�ڵ� %c\n", bf.bBuf[3]);

	return 0;
}


//EnumTypeTone.c
typedef enum syllable {
	Do=1,Re=2,Mi=3,Fa=4,So=5,La=6,Ti=7 //���� ���� �����ص� �������� 1�� �����ؼ� ���� �� �ʿ�x
}Syllable;

void Sound(Syllable sl)
{
	switch (sl) {
		case Do: puts("��~"); return;
		case Re: puts("��~"); return;
		case Mi: puts("��~"); return;
		case Fa: puts("��~"); return;
		case So: puts("��~"); return;
		case La: puts("��~"); return;
		case Ti: puts("��~"); return;
	}
	puts("�뷡�θ���~"); // ��µ��� ����
}

int main(void)
{
	Syllable tone;
	for (tone = Do;tone <= Ti;tone += 1) Sound(tone);

	return 0;
}


//FirstFileWrite.c
int main(void)
{
	FILE* fp = fopen("data.txt", "wt");
	if (fp == NULL) { // =�ƴϰ�== ��, NULL�� �� ���� ���� ���а� ������!
		puts("���Ͽ��� ����!");
		return -1; //������ ����
	}

	fputc('A', fp);
	fputc('B', fp);
	fputc('C', fp);
	fclose(fp);
	
	return 0;
}


//FirstFileRead.c
int main(void)
{
	int ch, i;
	FILE* fp = fopen("data.txt", "rt");
	if (fp == NULL) { // =�ƴϰ�== ��, NULL�� �� ���� ���� ���а� ������!
		puts("���Ͽ��� ����!");
		return -1; //������ ����
	}

	for (i = 0;i < 3;i++) {
		ch = fgetc(fp);
		printf("%c\n", ch);
	}

	fclose(fp);

	return 0;
}


//TextCharFileCopy.c
int main(void)
{
	FILE* src = fopen("src.txt", "rt");
	FILE* des = fopen("dst.txt", "wt");
	int ch;

	if (src == NULL || des == NULL) {
		puts("���Ͽ��� ����!");
		return -1;
	}

	while ((ch = fgetc(src)) != EOF) fputc(ch, des);

	if (feof(src) != 0) puts("���Ϻ��� �Ϸ�");
	else puts("���Ϻ��� ����");

	fclose(src);
	fclose(des);
	return 0;
}


//TextStringFileCopy.c
int main(void)
{
	FILE* src = fopen("src.txt", "rt");
	FILE* des = fopen("dst.txt", "wt");
	char str[50];

	if (src == NULL || des == NULL) {
		puts("���Ͽ��� ����!");
		return -1;
	}

	while (fgets(str, sizeof(str), src) != NULL) fputs(str, des);

	if (feof(src) != 0) puts("���Ϻ��� �Ϸ�");
	else puts("���Ϻ��� ����");

	fclose(src);
	fclose(des);
	return 0;
}


//BinaryFileCopy.c
int main(void)
{
	FILE* src = fopen("src.bin", "rb");
	FILE* des = fopen("dst.bin", "wb");
	char buf[20];
	int readCnt;

	if (src == NULL || des == NULL) {
		puts("���Ͽ��� ����!");
		return -1;
	}

	while (1) {
		readCnt = fread((void*)buf, 1, sizeof(buf), src);
		if (readCnt < sizeof(buf)) {
			if (feof(src) != 0) {
				fwrite((void*)buf, 1, readCnt, des);
				puts("���Ϻ��� �Ϸ�");
				break;
			}
			else {
				puts("���Ϻ��� ����");
			}
			break;
		}
		fwrite((void*)buf, 1, sizeof(buf), des);
	}
	

	fclose(src);
	fclose(des);
	return 0;
}
*/
/*
//24-1-1
int main(void)
{
	FILE* yoon = fopen("mystory.txt", "wt");
	if (yoon == NULL) {
		puts("���� ����!");
		return -1;
	}

	fputs("#�̸� : ������\n", yoon);
	fputs("#�ֹ� : 010101-001000\n", yoon);
	fputs("���� : 010-1111-2222\n", yoon);

	printf("���� �Ϸ�!");
	fclose(yoon);
	return 0;
}


//24-1-2
int main(void)
{
	FILE* yoon2 = fopen("mystory.txt", "at");

	if (yoon2 == NULL) {
		puts("���� ����!");
		return -1;
	}

	fputs("#��ŸԴ� ����: «��\n", yoon2); fputs("#��� : �౸\n", yoon2);

	printf("�߰� �Ϸ�!");
	fclose(yoon2);

	return 0;
}
*/