// 3���� ���� ����� ����Ʈ �����

#include <stdio.h>

struct node {
	char* data;
	struct node* next;
};

typedef struct node Node;

Node* head = NULL;		// ���� ����Ʈ�� ù ��° ����� �ּҸ� ���� �� ������

int main()
{
	//ù ��° ��� ����
	Node* head = (Node*)malloc(sizeof(Node));	//��� ����, ������ ����̹Ƿ� ��� ���
	head->data = "Tuesday";
	head->next = NULL;

	//�� ��° ��� ����(Tuseday �ڿ� ����)
	Node* q = (Node*)malloc(sizeof(Node));
	q->data = "Thursday";
	q->next = NULL;
	head->next = q;		//Tuesday ���(ù ��° ���) �ڿ� Thursday ���(�� ��° ���) ����

	//�� ��° ��� ����(Tuesday �տ� ����)
	q = (Node*)malloc(sizeof(Node));
	q->data = "Monday";
	q->next = head;		//Monday ���(�� ��° ���� ���) �ڿ� Tuesday(�� ��° ���� ���) ��� ����
						//���� head�� Tuesday�� �ּ��̹Ƿ� q�� �������� head�� �����Ѱ���
	head = q;   //head�� ù ��° ����� �ּҸ� �����ϴ� ������ �ϹǷ� q(Monday����ּ�)�� �ٲ��ֱ�
	
	//����� ��带 ȭ�鿡 ����ϱ�
	Node* p = head;		//ù ��° ��带 ����Ű�� p ������ ����
						//�״�� head�� �ᵵ ������, ù ��° ��带 ����Ű�� head�� �ӹ� �����ֱ�

	while (p != NULL)
	{
		printf("%s\n", p->data); //data ���
		p = p->next;		// p�� ���� ��带 ����Ű���� �ٲ��ֱ�
		
	}

}