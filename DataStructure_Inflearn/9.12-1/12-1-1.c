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

//poly�� ����Ű�� ���׽Ŀ� ���ο� �ϳ��� �� (c_���, e_����)�� �߰��ϴ� �Լ�
//�߰��Ϸ��� �װ� ���� ������ ���� �̹� �ִ� ��� : ���� ���� ����� ����
//else : ���ο� �� ����, �׵��� �׻� ������������ ����

void add_term(int c, int e, Polynomial* poly)
{
	if (c == 0)
	{
		return;
	}

	// ���Ḯ��Ʈ�� �߰��� ��� ������ ���� �� ���� ������ ���
	Term* p = poly->first, * q = NULL;
	while (p != NULL && p->expo > e)
	{
		q = p;
		p = p->next;
	}

	if (p != NULL && p->expo == e)		//���� ������ ���� �̹� ����
	{
		p->coef += c;

		if (p->coef == 0)		//���ߴµ� ����� 0 => ����
		{
			if (q == NULL)		//�����ؾ��ϴ� ��尡 ù ��° ����� ���
			{
				poly->first = p->next;
			}
			else
			{
				q->next = p->next;
			}
			poly->size--;		//�� �ϳ� �����Ǿ����ϱ� size 1 ����
			free(p);
		}
		return;
	}

	Term* term = creat_polynomial_instance();		//term ��ü ����
	term->coef = c;
	term->expo = e;

	if (q == NULL)		//�� �տ� �����ϴ� ���(�߰��Ϸ��� ���� �ְ�����)
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
