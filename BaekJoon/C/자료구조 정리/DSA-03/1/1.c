#include <stdio.h>
#include <stdlib.h>

int* make1dArray(int);

int main()
{
	int *ipp;
	int i, num;

	printf("������ �迭�� ���� �Է��ϼ���: ");
	scanf_s("%d", &num);

	ipp = make1dArray(num);
	for (i = 0; i < num; i++) {
		printf("ipp[%d] =%2d ", i, ipp[i]);

		}
	return 0;
}



int* make1dArray(int R)
{
	int *p = (int*)malloc(sizeof(int)*R);  // ���Ұ� �������� �迭�� �����ּ�
	int i;

	for (i = 0; i < R; i++)
	{
		p[i] = (int*)malloc(sizeof(int)*R);
		for (i = 0; i < R; i++)
			p[i] = rand() % 100;
	}

	return p;
}
