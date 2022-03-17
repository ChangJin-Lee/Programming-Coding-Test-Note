#include <stdio.h>

int add(int, int);
int multiple(int, int);

int main() {
	int a, b;
	printf("두 개의 정수 입력 >>");
	scanf_s("%d %d", &a, &b);

	printf("두수의 덧셈 결과 : %d\n", add(a, b));
	printf("두수의 곱셈 결과 : %d\n", multiple(a, b));
}

int add(int a, int b)
{
	return a + b;
}
int multiple(int a, int b)
{
	return a * b;
}