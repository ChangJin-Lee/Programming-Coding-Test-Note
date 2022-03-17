#include <stdio.h>
#include <stdlib.h>


int *func1(void)
{
	int *pNum = (int *)malloc(sizeof(int));
	*pNum = 10;

	return pNum;
}

int func2(int  *pNum)
{
	*pNum = 100;
	return 0;
}

int func3(int  **ppNum)
{
	**ppNum = 200;
	return 0;
}

int main(void)
{


	int  *pNum;
	
	pNum = func1();  // int 크기 만큼 동적할당 받아 10을 지정 후 정수형 포인터 리턴
	printf("%d\n", *pNum);

	func2(pNum);// pNum이 가리키는 것을 100으로 수정
	printf("%d\n", *pNum); 

	func3(&pNum); // pNum이 가리키는 것을 200으로 수정
	printf("%d\n", *pNum);
	free(pNum);
	return 0;
}
