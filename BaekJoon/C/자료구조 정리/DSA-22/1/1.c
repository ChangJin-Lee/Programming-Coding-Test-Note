/***************************************************************
	- insertion sort
	****************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct element
{
	int key;
	char name[20];
	int grade;
}element;

void insert(element e, element a[], int i)
{ /* insert e into the orderedd list a[1:i] such that the 
       resulting list a[1:i+1] is also ordered, the array a
	   must have space allocated for at least i+2 elements */
	a[0] = e;
	while (e.key < a[i].key)
	{
		a[i+1] = a[i];
		i--;
	}
	a[i+1] = e;
}

void insertionSort(element a[], int n)
{ /* sort a[1:n] into nondecreasing order */
	int j;
	for ( j = 2; j <= n; j++)
	{
		element temp = a[j];
		insert(temp, a, j-1); //1에서 j-1은 정렬 되어 있음.
	}
}

void printList(element a[], int n)
{
	int i;
	for ( i = 1; i <= n; i++)
		printf("( %d, %s, %d )\n", a[i].key, a[i].name, a[i].grade);
}

int main(void)
{
	int num;
	int i;
	element *pStd;
	FILE *fp;
	
	if(fopen_s(&fp, "input.txt", "r"))
	{
		fprintf(stderr, "cannot open the file");
		exit(EXIT_FAILURE);
	}
	
	fscanf_s(fp, "%d", &num);
	pStd = (element *)malloc((num+1)*sizeof(element));

	for ( i = 1; i <= num; i++)
		fscanf_s(fp, "%d%s%d", &pStd[i].key, pStd[i].name, sizeof(pStd[i].name), &pStd[i].grade);

	printf("<<<<<<<<<<<<<< Input List >>>>>>>>>>>>>\n");
	printList(pStd, num);

	printf("\n<<<<<<<<<<<<< Sorted List >>>>>>>>>>\n");
	insertionSort(pStd, num);
	printList(pStd, num);

	fclose(fp);
	return 0;
}
