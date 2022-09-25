// 연결리스트 - 다항식 계산 프로그램 (다항식 항들의 연결 리스트 표현)
// 하나의 다항식을 표현하는 구조체 Polynomial(name, first, size_항의 개수)
// 하나의 항을 표현하는 구조체 Term(coef_계수, expo_지수)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct term {
	int coef;
	int expo;
	struct term* next;
};

typedef struct term Term;

typedef struct polynomial {
	char name;
	Term* first;
	int size;		//int size = 0; ??
}Polynomial;

Polynomial* polys{ MAX_POLYS };		//polys는 다항식들에 대한 포인터의 배열
int n = 0;		//저장된 다항식의 개수

Term* creat_term_instance() 
{
	Term* t = (Term*)malloc(sizeof(Term));
	t->coef = 0;
	t->expo = 0;
	return t;
}

Polynomial* creat_polynomial_instance(char name)
{
	Polynomial* ptr_poly = (Polynomial*)malloc(sizeof(Polynomial));
	ptr_poly->name = name;
	ptr_poly->size = 0;
	ptr_poly->first = NULL;
	return ptr_poly;
}

//poly가 가리키는 다항식에 새로운 하나의 항 (c_계수, e_차수)를 추가하는 함수
//추가하려는 항과 동일 차수의 항이 이미 있는 경우 : 기존 항의 계수만 변경
//else : 새로운 항 삽입, 항들은 항상 내림차순으로 정렬

void add_term(int c, int e, Polynomial* poly)
{
	if (c == 0)
	{
		return;
	}

	// 연결리스트의 중간에 노드 삽입을 위해 두 개의 포인터 사용
	Term* p = poly->first, * q = NULL;
	while (p != NULL && p->expo > e)
	{
		q = p;
		p = p->next;
	}

	if (p != NULL && p->expo == e)		//동일 차수의 항이 이미 존재
	{
		p->coef += c;

		if (p->coef == 0)		//더했는데 계수가 0 => 삭제
		{
			if (q == NULL)		//삭제해야하는 노드가 첫 번째 노드인 경우
			{
				poly->first = p->next;
			}
			else
			{
				q->next = p->next;
			}
			poly->size--;		//항 하나 삭제되었으니까 size 1 감소
			free(p);
		}
		return;
	}

	Term* term = creat_polynomial_instance();		//term 객체 생성
	term->coef = c;
	term->expo = e;

	if (q == NULL)		//맨 앞에 삽입하는 경우(추가하려는 항이 최고차항)
	{
		term->next = poly->first;
		poly->first = term;
	}
	else
	{
		term->next = p;
		q->next = term;
	}
	poly->size++;
}
