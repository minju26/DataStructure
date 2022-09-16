// 3개의 노드로 연결된 리스트 만들기

#include <stdio.h>

struct node {
	char* data;
	struct node* next;
};

typedef struct node Node;

Node* head = NULL;		// 연결 리스트의 첫 번째 노드의 주소를 저장 할 포인터

int main()
{
	//첫 번째 노드 생성
	Node* head = (Node*)malloc(sizeof(Node));	//노드 생성, 유일한 노드이므로 헤드 노드
	head->data = "Tuesday";
	head->next = NULL;

	//두 번째 노드 생성(Tuseday 뒤에 연결)
	Node* q = (Node*)malloc(sizeof(Node));
	q->data = "Thursday";
	q->next = NULL;
	head->next = q;		//Tuesday 노드(첫 번째 노드) 뒤에 Thursday 노드(두 번째 노드) 연결

	//세 번째 노드 생성(Tuesday 앞에 연결)
	q = (Node*)malloc(sizeof(Node));
	q->data = "Monday";
	q->next = head;		//Monday 노드(세 번째 생성 노드) 뒤에 Tuesday(두 번째 생성 노드) 노드 연결
						//현재 head는 Tuesday의 주소이므로 q의 다음으로 head를 연결한것임
	head = q;   //head는 첫 번째 노드의 주소를 연결하는 역할을 하므로 q(Monday노드주소)로 바꿔주기
	
	//저장된 노드를 화면에 출력하기
	Node* p = head;		//첫 번째 노드를 가리키는 p 포인터 생성
						//그대로 head를 써도 되지만, 첫 번째 노드를 가리키는 head의 임무 지켜주기

	while (p != NULL)
	{
		printf("%s\n", p->data); //data 출력
		p = p->next;		// p를 다음 노드를 가리키도록 바꿔주기
		
	}

}