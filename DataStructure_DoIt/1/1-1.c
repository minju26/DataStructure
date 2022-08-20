/*세 정수 값을 입력하고 최댓값을 구합니다.*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int a, b, c;
	int max; /*최댓값*/
	printf("a의 값: ");
	scanf("%d", &a);
	printf("b의 값: ");
	scanf("%d", &b);
	printf("c의 값: ");
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

	printf("최댓값은 %d입니다.", max);

	return 0;

}