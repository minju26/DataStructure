/*�� ���� ���� �Է��ϰ� �ִ��� ���մϴ�.*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int a, b, c;
	int max; /*�ִ�*/
	printf("a�� ��: ");
	scanf("%d", &a);
	printf("b�� ��: ");
	scanf("%d", &b);
	printf("c�� ��: ");
	scanf("%d", &c);

	max = a;
	if (b > max)
	{
		max = b;
	}
	if (c > max)
	{
		max = c;
	}

	printf("�ִ��� %d�Դϴ�.", max);

	return 0;

}