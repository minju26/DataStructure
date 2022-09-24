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

Term* 