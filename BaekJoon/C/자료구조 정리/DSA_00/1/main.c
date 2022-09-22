#include <stdio.h>
#define _CRT_SECUER_NO_WARNINGS

int add(int, int);
int multiple(int, int);

int main()
{
	int a, b;
	printf("�� ���� ���� �Է� >>");
	scanf_s("%d %d", &a, &b);

	printf("�μ��� ���� ��� : %d\n", add(a, b));
	printf("�μ��� ���� ��� : %d\n", multiple(a, b));
}

int add(int a, int b)
{
	return a + b;
}
int multiple(int a, int b)
{
	return a * b;
}