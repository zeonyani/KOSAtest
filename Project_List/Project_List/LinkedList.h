#pragma once
#ifndef ___LinkedList
#define ___LinkedList
#include <stdio.h>
#include <stdlib.h>
#include "Member.h"

// 노드 구조체 : 멤버 구조체와 다르게 __node라는 태그를 사용하였으므로 연결 리스트(내 내부에서 나를 부르는 게 가능!)
typedef struct __node {
	Member data;
	struct __node* next; //이렇게 쓰려고 태그한 거임! --> 의미 : 뒤쪽포인터(다음 노드에 대한 포인터)
} Node;
// 위의 노드 구조체는 단순한 노드구조체. 하지만 이것만으로는 전체 리스트의 상태를 관리할 수 없음

//그래서 만든 게 리스트 전체를 관리할 구조체!
//연결리스트
typedef struct {
	Node* head; //머리 노드에 대한 포인터
	//리스트의 시작점을 가리킨다. 이 포인터를 이용해서 리스트 전체 탐색 또는 초기화 가능.
	//새로운 노드를 추가, 삭제할 때 "기준"이 되는 포인터

	Node* crnt; //현재(current) 노드에 대한 포인터
	//사용자가 현재 어떤 노드에 위치해 있는지 추적하기 위한 포인터
}List;

//노드를 동적으로 생성
static Node* AllocNode(void) // static 이라서 해당 파일에서만 접근할 수 있음
{
	return (Node*)calloc(1, sizeof(Node)); // calloc은 malloc과 동일하나 0으로 초기화해주는 장점.
	// (Node*)로 명시적 형변환이 필요
	// 1개의 Node 크기만큼 메모리를 동적으로 할당
}

//n이 가리키는 노드의 각 멤버에 값을 설정
static void SetNode(Node* n, const Member* x, const Node* next)
{	
	// const 로 매개변수를 받는 이유?
	// 1. 해당 함수는 읽어오기만 하겠다고 명확히 표현하고자
	// 2. 혹시라도 함수 내에서 해당 변수를 바꿀 실수를 방지하고자
	// 3. const면 컴파일러가 데이터가 바뀌지 않음을 보장받고 최적화할 수 있음
	n->data = *x; // 노드 n의 data 변수에는 매개변수로 전달받은 x 값을 할당하고
	n->next =next; // 노드 n은 그 다음인 next 노드를 가리키도록 포인터 변수값을 next에 할당
}

//연결리스트를 초기화
void Initialize(List* list) {
	// List 구조체의 head, crnt변수는 포인터 변수이므로 ->로 접근
	// NULL 포인터의 의미 : 포인터가 유효한 메모리를 가리키는지 아닌지를 구분하고자
	list->head = NULL; // 머리노드가 가리키는 리스트가 현재 비어있음
	list->crnt = NULL; // 현재 노드 역시 가리키는 리스트가 비어있음
}

// compare함수를 이용한 x 검색 - 여기서 compare는 함수포인터(p.133) 원칙은 int (*compare) 이나 int compare 가능
// 주의사항: int * compare와 같이 쓰면 안 됨 
// compare 함수포인터는 Member.h의 회원 번호 및 회원 이름 비교해서 -1, 0, 1 리턴하는 함수에 대한 포인터이다.
Node* search(List* list, const Member* x, int compare(const Member* x, const Member* y))
{
	Node* ptr = list->head; // Node형의 주소를 가리킬 수 있는 포인터 변수인 ptr에는 매개변수로 받은 list내 head변수에 있는 값을 할당
	while (ptr != NULL) { // ptr이 NULL이 아닌 경우 즉, ptr이 노드 주소를 가리키고 있다면 <- NULL이면 스캔할 노드가 없다는 의미니까
		if (compare(&ptr->data, x) == 0) { //compare함수포인터는 Member 형을 레퍼런스 형태로 받으니까
			// 연산자 우선순위가 -> 다음 &니까
			// ptr이 가리키는 Node형 구조체에 있는 data 멤버변수에 접근해서 (-> 먼저)
			// 그 data변수의 주소를 가져와서 둘 다 Member * 꼴이 되므로 둘을 비교할 수 있다!
			list->crnt = ptr; // list 구조체에 현재 가리키고 있는 포인터 변수인 crnt에 ptr을 할당해서 그걸 리턴
			return  ptr;
		}
		ptr = ptr->next; // 근데 해당 조건에 안들어갔다는 건 둘이 다르다는 거니까 다음 노드를 계속 찾아보는 것
	}
	return NULL;
}

// 머리에 노드를 삽입
void InsertFront(List* list, const Member* x)
{
	Node* ptr = list->head;
	list->head = list->crnt = AllocNode(); // 오른쪽부터 왼쪽으로 대입이 이뤄진다.
	// 1. AllocNode() 호출 ---> 새로운 노드 포인터 반환(calloc 했잖아)
	// 2. 그 반환된 포인터를 매개변수로 받은 list 구조체의 crnt변수에 할당하고
	// 3. 그걸 head에도 할당
	// 그러면 머리도 현재도 모두 동일한 노드를 가리키고 있음
	SetNode(list->head, x, ptr); // static void SetNode(Node* n, const Member* x, const Node* next) 정의 형태
	// 참고 : list로 접근한 head는 Node *타입이라서 호출에 문제 없음
	// 1. ptr은 기존의 머리노드를 가리킨다.
	// 2. 여기에서 새롭게 삽입(할당)된 노드에 대해서! (사실은 새롭게 만들어진 노드가 되겠지)
	// 3. 각각 x, ptr을 통해 data, *next 에 대입!
}

// 꼬리에 노드를 삽입
void InsertRear(List* list, const Member* x)
{
	if (list->head == NULL) InsertFront(list, x); // 비어있는 경우라면 꼬리라는 개념이 사실상 없을테니 머리 노드 삽입과 동일
	else { // 그렇지만 비어있지 않다면 이제 꼬리를 찾으러 떠나야 한다.
		Node* ptr = list->head; // 포인트 변수 하나 잡아서 그걸 머리 노드라고 하고
		while (ptr->next != NULL) ptr = ptr->next; // 하나씩 계속 다음 걸로 넘어가면서 그게 NULL 즉, 다음걸 가리키는 게 없을 때까지(그게 꼬리노드가 되니까)
		ptr->next = list->crnt = AllocNode(); // 만약 꼬리노드를 찾았으면
		// 1. 새로 노드를 하나 만들고
		// 2. crnt변수에 할당해서
		// 3. Node 구조체 안의 next포인터 변수에 할당
		SetNode(ptr->next, x, NULL); // 그리고 그렇게 새롭게 만든 다음 노드를 꼬리 노드로 만들어줌
	}
}

// 머리노드를 삭제 -> 가장 첫 노드를 삭제하려면 머리를 가리키는 포인터와 현재 위치를 가리키는 포인터를 모두 다음 노드를 가리키도록 해야!
void RemoveFront(List* list)
{
	if (list->head != NULL) { // 아예 노드가 없다는 거니까(비어있는데 어떻게 삭제를 하니) : 리스트가 아예 없다는 뜻
		Node* ptr = list->head->next; // 다음 노드(p.328)를 ptr 변수에 저장하고
		free(list->head); // 지금 머리 노드에 대해서 메모리 해제
		list->head = list->crnt = ptr; // 다음 노드였던 거를 현재노드와 머리노드가 모두 가리킬 수 있도록! -> 얘가 이제 새로운 머리 노드!
	}
}

// 꼬리노드를 삭제
void RemoveRear(List* list)
{
	if ((list->head)->next == NULL) RemoveFront(list); // 머리노드 하나만 존재하는 꼴이므로  그냥 머리노드를 지우면 된다.
	else { // 노드가 여러 개 있는 경우
		Node* ptr = list->head; // 머리노드를 ptr이 가리키게 하고
		Node* pre = list->head; // pre를 초기화하지 않았더니 컴파일 오류나서 그냥 아무거나로 초기화만 해줌
		while (ptr->next != NULL) { // 다음이 없을 때까지
			pre = ptr; // ptr이 가리키는 걸 pre가 가리키도록 하고
			ptr = ptr->next; // ptr은 그 다음 거로 넘겨서 끝을 찾는 것
		}
		pre->next = NULL; // while 문을 탈출하는 건 다음 노드가 없을 때 즉, 맨 마지막 노드일 때니까 pre에 그걸 대입해주고
		free(ptr); // 기존 ptr은 지워버림(그래야 꼬리노드가 삭제)
		list->crnt = pre; // pre를 현재 포인터가 가리키도록
	}
}

// 선택한 노드를 삭제하는 함수
void RemoveCurrent(List* list)
{
	if (list->head != NULL) { // 노드가 하나라도 있을 때
		if (list->crnt == list->head) RemoveFront; // 현재 노드랑 머리노드랑 같으면 머리노드에 있는 거 삭제
		else { // 현재 노드는 뒤로 이동했을 때
			Node* ptr = list->head; // ptr 은 머리노드를 가리키고
			while (ptr->next != list->crnt) ptr = ptr->next; // 현재노드가 다음 노드가 될 때까지 계속 다음 노드로 이동
			ptr->next = list->crnt->next; // 현재 다음노드를 ptr이 가리키게 하고
			free(list->crnt); // 현재노드는 없앤다
			list->crnt = ptr; // 그러면 그 사이가 텅빌테니 ptr이 가리키고 있는 걸 현재가 가리키도록
		}
	}
}

// 모든 노드 삭제
void Clear(List* list) {
	while (list->head != NULL) RemoveFront(list); // 아무 노드도 없을 때까지 앞부터 삭제
	list->crnt = NULL; // 아무것도 없으니까 현재노드도 아무것도 가리키면 안 됨
}

// 선택한 노드의 데이터를 출력
void PrintCurrent(const List* list)
{
	if (list->crnt == NULL) printf("선택한 노드가 없습니다."); // 아무 노드도 없다는 거니까
	else PrintMember(&list->crnt->data); // data 값을 출력 (Member.h 에 있음)
}

// 선택한 노드의 데이터를 출력(줄바꿈 문자 적용된 거)
void PrintLnCurrent(const List* list)
{
	PrintCurrent(list); // 방금 전 출력하는 함수 쓰되
	putchar('\n'); // 한 줄 띄어쓰기
}

// 모든 노드의 데이터를 리스트 순으로 출력하는 함수
void Print(const List* list)
{
	if (list->head == NULL) puts("노드가 없습니다.");
	else {
		Node* ptr = list->head;
		puts(" <<< 모두 보기 >>> ");
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