// ���Ḯ��Ʈ - ���׽� ��� ���α׷� (���׽� �׵��� ���� ����Ʈ ǥ��)
// �ϳ��� ���׽��� ǥ���ϴ� ����ü Polynomial(name, first, size_���� ����)
// �ϳ��� ���� ǥ���ϴ� ����ü Term(coef_���, expo_����)

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

Polynomial* polys{ MAX_POLYS };		//polys�� ���׽ĵ鿡 ���� �������� �迭
int n = 0;		//����� ���׽��� ����

Term* 