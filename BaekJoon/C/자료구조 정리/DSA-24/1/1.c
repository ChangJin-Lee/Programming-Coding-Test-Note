/***************************************************************
	- Bubble sort
	****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#define COMPARE(x, y) (((x)<(y)) ? -1 : ((x)==(y)) ? 0 : 1)

typedef struct element
{
	int key;
	char name[20];
	int grade;
}element;

void swap(element *p1, element *p2)
{
	element temp;

	temp.key = p1->key;
	strcpy_s(temp.name, sizeof(temp.name), p1->name);
	temp.grade = p1->grade;

	p1->key = p2->key;
	strcpy_s(p1->name, sizeof(temp.name), p2->name);
	p1->grade = p2->grade;

	p2->key = temp.key;
	strcpy_s(p2->name, sizeof(temp.name), temp.name);
	p2->grade = temp.grade;

}

void printList(element a[], int n)
{
	int i;
	for (i = 1; i <= n; i++)
		printf("( %d, %s, %d )\n", a[i].key, a[i].name, a[i].grade);
}

void bubble_sort(element list[], int n)
{
	int i, j;
	for (i = n; i>1; i--) {
		for (j = 1; j<i; j++) 	// compare and change
			if (list[j].key>list[j + 1].key)
				swap(&list[j], &list[j + 1]);
		printf("\n<<<<<<<<<<<<<Step %d :  Sorted List >>>>>>>>>>\n", n-i+1);
		printList(list, n);
	}
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
	
	for (i = 1; i <= num; i++)
		fscanf_s(fp, "%d%s%d", &pStd[i].key, pStd[i].name, sizeof(pStd[i].name), &pStd[i].grade);


	printf("<<<<<<<<<<<<< Input List >>>>>>>>>>>>>\n");
	printList(pStd, num);


	bubble_sort(pStd, num);
	printf("\n<<<<<<<<<<<<< Result Sorted List >>>>>>>>>>\n");
	printList(pStd, num);

	fclose(fp);
	return 0;
}
