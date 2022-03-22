#include <stdio.h>
#include <stdlib.h>

int* make1dArray(int);

int main()
{
	int *ipp;
	int i, num;

	printf("일차원 배열의 수를 입력하세요: ");
	scanf_s("%d", &num);

	ipp = make1dArray(num);
	for (i = 0; i < num; i++) {
		printf("ipp[%d] =%2d ", i, ipp[i]);

		}
	return 0;
}



int* make1dArray(int R)
{
	int *p = (int*)malloc(sizeof(int)*R);  // 원소가 포인터인 배열의 시작주소
	int i;

	for (i = 0; i < R; i++)
	{
		p[i] = (int*)malloc(sizeof(int)*R);
		for (i = 0; i < R; i++)
			p[i] = rand() % 100;
	}

	return p;
}
