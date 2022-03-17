// Q1. 정적배열 vs. 동적배열 - 함수 전달 방법
#include <stdio.h>
#include <stdlib.h>

// 정적배열 전달, 첫 번째 파라미터 타입은 모두 int [3]* --> 디버거로 확인하기
int sumAry2D_f1(int ary[][3], int rows, int cols); // 배열 파라미터
int sumAry2D_f2(int(*ary)[3], int rows, int cols); // 배열 포인터
int sumAry2D_f3(int ary[2][3], int rows, int cols);

// 동적배열 전달
int sumAry2D_f4(int **ary, int rows, int cols);  // int **
int sumAry2D_f5(int ***ary, int rows, int cols); // int ***
int sumAry2D_f42(int **ary, int rows, int cols);  // int **

void freeAry2D(int **ary, int rows);


int main(void)
{
	// 정적배열(2행3열)
	int ary2D[][3] = { { 1, 2, 3 }, { 4, 5, 6 } };
	//동적배열(2행3열)
	int r, c, i;
	int **ary = (int **)malloc(sizeof(int*) * 2);

	printf("arr2D=%p, arr2D[0]=%p, &arr2D[0][0]=%p\n", ary2D, ary2D[0], &ary2D[0][0]);
	printf("&arr2D[0][1]=%p, &arr2D[0][2]=%p, \n", &ary2D[0][1], &ary2D[0][2]);
	printf("arr2D[1]=%p, arr2D+1=%p, &arr2D[1][0]=%p\n", ary2D[1], ary2D+1, &ary2D[1][0]);



	for (r = 0; r < 2; r++)
		ary[r] = (int *)malloc(sizeof(int) * 3);

	i = 1;
	for (r = 0; r < 2; r++)
		for (c = 0; c < 3; c++)
			ary[r][c] = i++;

	for (r = 0; r < 2; r++) {
		for (c = 0; c < 3; c++)
			printf("%d  ", ary[r][c]);
		printf("\n");
	}
	printf("ary=%p, &ary[0]=%p, &ary[0][0]=%p\n", ary, &ary[0], &ary[0][0]);
	printf("ary=%p, ary[0]=%p, &ary[0][0]=%p\n", ary, ary[0], &ary[0][0]  );
	printf("ary[1]=%p, *(ary+1)=%p, *ary[1]=%d\n", ary[1], *(ary+1), *ary[1]  );
	// printf("arr[2]=%p, arr+2=%p, &ary[1]=%p\n", ary[2], ary+2,  *ary[2]  );


	// 정적배열

	printf("sumAry2D_f1() %d\n", sumAry2D_f1(ary2D, 2, 3));
	printf("sumAry2D_f2() %d\n", sumAry2D_f2(ary2D, 2, 3));
	printf("sumAry2D_f3() %d\n", sumAry2D_f3(ary2D, 2, 3));

	// 동적배열
	printf("sumAry2D_f4() %d\n", sumAry2D_f4(ary, 2, 3));
	printf("sumAry2D_f5() %d\n", sumAry2D_f5(&ary, 2, 3));



	// 정적배열을 f4, f5로 전달할 수 있을까? 테스트해 보라!

	printf("sumAry2D_f3() %d\n", sumAry2D_f42(ary2D, 2, 3));

	printf("sumAry2D_f4~f5() %d\n", sumAry2D_f4((int **)ary2D, 2, 3)); 
	printf("hello\n");

	freeAry2D(ary, 2);

	return 0;
}


int sumAry2D_f1(int ary[][3], int rows, int cols)
{
	int sum = 0, i = 0, j = 0;

	for (i = 0; i< rows; i++)
	{
		for (j = 0; j< cols; j++)
		{
			sum += ary[i][j];
			//sum += *(*(ary+i)+j);
		}
	}

	return sum;
}

int sumAry2D_f2(int(*ary)[3], int rows, int cols)
{
	int sum = 0, i = 0, j = 0;

	for (i = 0; i< rows; i++)
	{
		for (j = 0; j< cols; j++)
		{
			sum += ary[i][j];
			//sum += *(*(ary+i)+j);
		}
	}

	return sum;
}

//주의: array[2][3] 원본 전체가 복사되는 것이 아님
int sumAry2D_f3(int ary[2][3], int rows, int cols)
{
	int sum = 0, i = 0, j = 0;

	for (i = 0; i< rows; i++)
	{
		for (j = 0; j< cols; j++)
		{
			sum += ary[i][j];
			//sum += *(*(ary+i)+j);
		}
	}

	return sum;
}

int sumAry2D_f4(int **ary, int rows, int cols)
{
	int sum = 0, i = 0, j = 0;

	for (i = 0; i< rows; i++)
	{
		for (j = 0; j< cols; j++)
		{
			sum += ary[i][j];
			//sum += *(*(ary+i)+j);
		}
	}

	return sum;
}

int sumAry2D_f42(int **ary, int rows, int cols)
{
	int sum = 0, i = 0, j = 0;


		for (j = 0; j < cols; j++)
		{
			sum += ary[i][j];
			//sum += *(*(ary+i)+j);
		}

	return sum;
}


int sumAry2D_f5(int ***ary, int rows, int cols)
{
	int sum = 0, i = 0, j = 0;

	for (i = 0; i< rows; i++)
	{
		for (j = 0; j< cols; j++)
		{
			sum += (*ary)[i][j];
		}
	}

	return sum;
}

void freeAry2D(int **ary, int rows)
{
	int r;

	for (r = 0; r < rows; r++)
		free(ary[r]);
	free(ary);

	puts("2d array - free!!!");
}