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
	
	pNum = func1();  // int ũ�� ��ŭ �����Ҵ� �޾� 10�� ���� �� ������ ������ ����
	printf("%d\n", *pNum);

	func2(pNum);// pNum�� ����Ű�� ���� 100���� ����
	printf("%d\n", *pNum); 

	func3(&pNum); // pNum�� ����Ű�� ���� 200���� ����
	printf("%d\n", *pNum);
	free(pNum);
	return 0;
}
