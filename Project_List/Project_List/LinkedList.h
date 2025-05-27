#pragma once
#ifndef ___LinkedList
#define ___LinkedList
#include <stdio.h>
#include <stdlib.h>
#include "Member.h"

// ��� ����ü : ��� ����ü�� �ٸ��� __node��� �±׸� ����Ͽ����Ƿ� ���� ����Ʈ(�� ���ο��� ���� �θ��� �� ����!)
typedef struct __node {
	Member data;
	struct __node* next; //�̷��� ������ �±��� ����! --> �ǹ� : ����������(���� ��忡 ���� ������)
} Node;
// ���� ��� ����ü�� �ܼ��� ��屸��ü. ������ �̰͸����δ� ��ü ����Ʈ�� ���¸� ������ �� ����

//�׷��� ���� �� ����Ʈ ��ü�� ������ ����ü!
//���Ḯ��Ʈ
typedef struct {
	Node* head; //�Ӹ� ��忡 ���� ������
	//����Ʈ�� �������� ����Ų��. �� �����͸� �̿��ؼ� ����Ʈ ��ü Ž�� �Ǵ� �ʱ�ȭ ����.
	//���ο� ��带 �߰�, ������ �� "����"�� �Ǵ� ������

	Node* crnt; //����(current) ��忡 ���� ������
	//����ڰ� ���� � ��忡 ��ġ�� �ִ��� �����ϱ� ���� ������
}List;

//��带 �������� ����
static Node* AllocNode(void) // static �̶� �ش� ���Ͽ����� ������ �� ����
{
	return (Node*)calloc(1, sizeof(Node)); // calloc�� malloc�� �����ϳ� 0���� �ʱ�ȭ���ִ� ����.
	// (Node*)�� ����� ����ȯ�� �ʿ�
	// 1���� Node ũ�⸸ŭ �޸𸮸� �������� �Ҵ�
}

//n�� ����Ű�� ����� �� ����� ���� ����
static void SetNode(Node* n, const Member* x, const Node* next)
{	
	// const �� �Ű������� �޴� ����?
	// 1. �ش� �Լ��� �о���⸸ �ϰڴٰ� ��Ȯ�� ǥ���ϰ���
	// 2. Ȥ�ö� �Լ� ������ �ش� ������ �ٲ� �Ǽ��� �����ϰ���
	// 3. const�� �����Ϸ��� �����Ͱ� �ٲ��� ������ ����ް� ����ȭ�� �� ����
	n->data = *x; // ��� n�� data �������� �Ű������� ���޹��� x ���� �Ҵ��ϰ�
	n->next =next; // ��� n�� �� ������ next ��带 ����Ű���� ������ �������� next�� �Ҵ�
}

//���Ḯ��Ʈ�� �ʱ�ȭ
void Initialize(List* list) {
	// List ����ü�� head, crnt������ ������ �����̹Ƿ� ->�� ����
	// NULL �������� �ǹ� : �����Ͱ� ��ȿ�� �޸𸮸� ����Ű���� �ƴ����� �����ϰ���
	list->head = NULL; // �Ӹ���尡 ����Ű�� ����Ʈ�� ���� �������
	list->crnt = NULL; // ���� ��� ���� ����Ű�� ����Ʈ�� �������
}

// compare�Լ��� �̿��� x �˻� - ���⼭ compare�� �Լ�������(p.133) ��Ģ�� int (*compare) �̳� int compare ����
// ���ǻ���: int * compare�� ���� ���� �� �� 
// compare �Լ������ʹ� Member.h�� ȸ�� ��ȣ �� ȸ�� �̸� ���ؼ� -1, 0, 1 �����ϴ� �Լ��� ���� �������̴�.
Node* search(List* list, const Member* x, int compare(const Member* x, const Member* y))
{
	Node* ptr = list->head; // Node���� �ּҸ� ����ų �� �ִ� ������ ������ ptr���� �Ű������� ���� list�� head������ �ִ� ���� �Ҵ�
	while (ptr != NULL) { // ptr�� NULL�� �ƴ� ��� ��, ptr�� ��� �ּҸ� ����Ű�� �ִٸ� <- NULL�̸� ��ĵ�� ��尡 ���ٴ� �ǹ̴ϱ�
		if (compare(&ptr->data, x) == 0) { //compare�Լ������ʹ� Member ���� ���۷��� ���·� �����ϱ�
			// ������ �켱������ -> ���� &�ϱ�
			// ptr�� ����Ű�� Node�� ����ü�� �ִ� data ��������� �����ؼ� (-> ����)
			// �� data������ �ּҸ� �����ͼ� �� �� Member * ���� �ǹǷ� ���� ���� �� �ִ�!
			list->crnt = ptr; // list ����ü�� ���� ����Ű�� �ִ� ������ ������ crnt�� ptr�� �Ҵ��ؼ� �װ� ����
			return  ptr;
		}
		ptr = ptr->next; // �ٵ� �ش� ���ǿ� �ȵ��ٴ� �� ���� �ٸ��ٴ� �Ŵϱ� ���� ��带 ��� ã�ƺ��� ��
	}
	return NULL;
}

// �Ӹ��� ��带 ����
void InsertFront(List* list, const Member* x)
{
	Node* ptr = list->head;
	list->head = list->crnt = AllocNode(); // �����ʺ��� �������� ������ �̷�����.
	// 1. AllocNode() ȣ�� ---> ���ο� ��� ������ ��ȯ(calloc ���ݾ�)
	// 2. �� ��ȯ�� �����͸� �Ű������� ���� list ����ü�� crnt������ �Ҵ��ϰ�
	// 3. �װ� head���� �Ҵ�
	// �׷��� �Ӹ��� ���絵 ��� ������ ��带 ����Ű�� ����
	SetNode(list->head, x, ptr); // static void SetNode(Node* n, const Member* x, const Node* next) ���� ����
	// ���� : list�� ������ head�� Node *Ÿ���̶� ȣ�⿡ ���� ����
	// 1. ptr�� ������ �Ӹ���带 ����Ų��.
	// 2. ���⿡�� ���Ӱ� ����(�Ҵ�)�� ��忡 ���ؼ�! (����� ���Ӱ� ������� ��尡 �ǰ���)
	// 3. ���� x, ptr�� ���� data, *next �� ����!
}

// ������ ��带 ����
void InsertRear(List* list, const Member* x)
{
	if (list->head == NULL) InsertFront(list, x); // ����ִ� ����� ������� ������ ��ǻ� �����״� �Ӹ� ��� ���԰� ����
	else { // �׷����� ������� �ʴٸ� ���� ������ ã���� ������ �Ѵ�.
		Node* ptr = list->head; // ����Ʈ ���� �ϳ� ��Ƽ� �װ� �Ӹ� ����� �ϰ�
		while (ptr->next != NULL) ptr = ptr->next; // �ϳ��� ��� ���� �ɷ� �Ѿ�鼭 �װ� NULL ��, ������ ����Ű�� �� ���� ������(�װ� ������尡 �Ǵϱ�)
		ptr->next = list->crnt = AllocNode(); // ���� ������带 ã������
		// 1. ���� ��带 �ϳ� �����
		// 2. crnt������ �Ҵ��ؼ�
		// 3. Node ����ü ���� next������ ������ �Ҵ�
		SetNode(ptr->next, x, NULL); // �׸��� �׷��� ���Ӱ� ���� ���� ��带 ���� ���� �������
	}
}

// �Ӹ���带 ���� -> ���� ù ��带 �����Ϸ��� �Ӹ��� ����Ű�� �����Ϳ� ���� ��ġ�� ����Ű�� �����͸� ��� ���� ��带 ����Ű���� �ؾ�!
void RemoveFront(List* list)
{
	if (list->head != NULL) { // �ƿ� ��尡 ���ٴ� �Ŵϱ�(����ִµ� ��� ������ �ϴ�) : ����Ʈ�� �ƿ� ���ٴ� ��
		Node* ptr = list->head->next; // ���� ���(p.328)�� ptr ������ �����ϰ�
		free(list->head); // ���� �Ӹ� ��忡 ���ؼ� �޸� ����
		list->head = list->crnt = ptr; // ���� ��忴�� �Ÿ� ������� �Ӹ���尡 ��� ����ų �� �ֵ���! -> �갡 ���� ���ο� �Ӹ� ���!
	}
}

// ������带 ����
void RemoveRear(List* list)
{
	if ((list->head)->next == NULL) RemoveFront(list); // �Ӹ���� �ϳ��� �����ϴ� ���̹Ƿ�  �׳� �Ӹ���带 ����� �ȴ�.
	else { // ��尡 ���� �� �ִ� ���
		Node* ptr = list->head; // �Ӹ���带 ptr�� ����Ű�� �ϰ�
		Node* pre = list->head; // pre�� �ʱ�ȭ���� �ʾҴ��� ������ �������� �׳� �ƹ��ų��� �ʱ�ȭ�� ����
		while (ptr->next != NULL) { // ������ ���� ������
			pre = ptr; // ptr�� ����Ű�� �� pre�� ����Ű���� �ϰ�
			ptr = ptr->next; // ptr�� �� ���� �ŷ� �Ѱܼ� ���� ã�� ��
		}
		pre->next = NULL; // while ���� Ż���ϴ� �� ���� ��尡 ���� �� ��, �� ������ ����� ���ϱ� pre�� �װ� �������ְ�
		free(ptr); // ���� ptr�� ��������(�׷��� ������尡 ����)
		list->crnt = pre; // pre�� ���� �����Ͱ� ����Ű����
	}
}

// ������ ��带 �����ϴ� �Լ�
void RemoveCurrent(List* list)
{
	if (list->head != NULL) { // ��尡 �ϳ��� ���� ��
		if (list->crnt == list->head) RemoveFront; // ���� ���� �Ӹ����� ������ �Ӹ���忡 �ִ� �� ����
		else { // ���� ���� �ڷ� �̵����� ��
			Node* ptr = list->head; // ptr �� �Ӹ���带 ����Ű��
			while (ptr->next != list->crnt) ptr = ptr->next; // �����尡 ���� ��尡 �� ������ ��� ���� ���� �̵�
			ptr->next = list->crnt->next; // ���� ������带 ptr�� ����Ű�� �ϰ�
			free(list->crnt); // ������� ���ش�
			list->crnt = ptr; // �׷��� �� ���̰� �ֺ��״� ptr�� ����Ű�� �ִ� �� ���簡 ����Ű����
		}
	}
}

// ��� ��� ����
void Clear(List* list) {
	while (list->head != NULL) RemoveFront(list); // �ƹ� ��嵵 ���� ������ �պ��� ����
	list->crnt = NULL; // �ƹ��͵� �����ϱ� �����嵵 �ƹ��͵� ����Ű�� �� ��
}

// ������ ����� �����͸� ���
void PrintCurrent(const List* list)
{
	if (list->crnt == NULL) printf("������ ��尡 �����ϴ�."); // �ƹ� ��嵵 ���ٴ� �Ŵϱ�
	else PrintMember(&list->crnt->data); // data ���� ��� (Member.h �� ����)
}

// ������ ����� �����͸� ���(�ٹٲ� ���� ����� ��)
void PrintLnCurrent(const List* list)
{
	PrintCurrent(list); // ��� �� ����ϴ� �Լ� ����
	putchar('\n'); // �� �� ����
}

// ��� ����� �����͸� ����Ʈ ������ ����ϴ� �Լ�
void Print(const List* list)
{
	if (list->head == NULL) puts("��尡 �����ϴ�.");
	else {
		Node* ptr = list->head;
		puts(" <<< ��� ���� >>> ");
		while (ptr != NULL) {
			PrintLnMember(&ptr->data);
			ptr = ptr->next;
		}
	}
}

void Terminate(List* list)
{
	Clear(list);
}
#endif //___LinkedList