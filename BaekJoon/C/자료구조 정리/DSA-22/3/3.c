/***************************************************************
	- quick sort
	****************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define SWAP(x, y, temp) ((temp) = (x), (x) = (y), (y)=(temp))

typedef struct element
{
	int key;
}element;

//element *ary;	// sorting data
int cnt = 0;		// calls of quickSort
int num;			// the number of keys to sort

void printList(element a[], int n);
void quickSort(element a[], int left, int right);

int main(void)
{
	int i;
	FILE *fp;
	element ary[12];

	if(fopen_s(&fp, "input.txt", "r"))
	{
		fprintf(stderr, "cannot open the file");
		exit(EXIT_FAILURE);
	}

	fscanf_s(fp, "%d", &num);
	//ary = (element *)malloc((num+1)*sizeof(element));

	for ( i = 1; i <= num; i++)
		fscanf_s(fp, "%d", &ary[i].key);				

	printf("<<<<<<<<<<<<< Input List >>>>>>>>>>>>>\n");
	printList(ary, num);

	printf("\nexecution of quick sort ... \n");
	quickSort(ary, 1, num);
	printf("\ncalls of quick sort: %d \n", cnt);

	printf("\n<<<<<<<<<<<<<< Sorted List >>>>>>>>>>\n");
	printList(ary, num);
	printf("\n");

	fclose(fp);
	return 0;
}


void printList(element a[], int n)
{
	int i;
	for ( i = 1; i <= n; i++)
		printf("%2d%s", a[i].key, (i != n) ? " ": "\n");
}


void quickSort(element a[], int left, int right)
{ /* sort a[left:right] into nondecreasing order
       on the key field; a[left].key is arbitrarily 
	   chosen as the pivot key; it is assumed that
	   a[left].key <= a[right+1].key */

	int pivot, i, j;
	element temp;
	
	cnt ++;  
	printf("pivot = %d : ", a[left].key);
	if (left < right)
	{
		i = left; j = right + 1;
		pivot = a[left].key;
		
		do { /* search for keys from the left and right
				   sublists, swapping out-of-order elements until
				   the left and right boundaries cross or meet */
			do i++; while (a[i].key < pivot);
			do j--; while (a[j].key > pivot);
			if (i < j) SWAP(a[i], a[j], temp);
		} while (i < j);
		SWAP(a[left], a[j], temp);
		printList(a, num);
		if (left < j-1)
			quickSort(a, left, j - 1);
		if (j+1 < right)
			quickSort(a, j + 1, right);
	}
	else
		printf("\n");
}

