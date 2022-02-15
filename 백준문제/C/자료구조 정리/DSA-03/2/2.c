#include <stdio.h>
#include <stdlib.h>

int** make2dArray(int, int);

int main()
{
	int **ipp;
	int i, j, rows, cols;

	printf("������ �迭�� ���� �Է��ϼ���: ");
	scanf_s("%d %d", &rows, &cols);

	ipp = make2dArray(rows, cols);
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			printf("ipp[%d] =%2d ", i, ipp[i][j]);

		}
	}

	return;
}


int** make2dArray(int R, int C)
{
	int **p = (int**)malloc(sizeof(int*)*R);  // ���Ұ� �������� �迭�� �����ּ�
	int i, j;

	for (i = 0; i < R; i++)
	{
		p[i] = (int*)malloc(sizeof(int)*C);
		for (j = 0; j < C; j++)
			p[i][j] = rand() % 100;
	}

	return p;
}
