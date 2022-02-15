/***************************************************************
	- recursive merge sort
	****************************************************************/
#include <stdio.h>
#include <stdlib.h>
//#define COMPARE(x, y) (((x)<(y)) ? -1 : ((x)==(y)) ? 0 : 1)
//#define SWAP(x, y, temp) ((temp) = (x), (x) = (y), (y)=(temp))
#define MAX_SIZE 100

typedef struct element
{
	int key;
}element;

element a[MAX_SIZE]; // a[0] is not used.
element sorted[MAX_SIZE];   // additional space

void printList(element a[], int num)
{
	int i;
	for (i = 1; i <= num; i++)
		printf("%d ", a[i].key);
	printf("\n");
}

void merge(element list[], int left, int mid, int right)
{
	int i, j, k, l;
	i = left;  j = mid + 1;  k = left;

	/* merge of sorted lists */
	while (i <= mid && j <= right) {
		if (list[i].key <= list[j].key)
			sorted[k++].key = list[i++].key;
		else
			sorted[k++].key = list[j++].key;
	}
	if (i>mid)/* copy of remained elemnets */
		for (l = j; l <= right; l++)
			sorted[k++].key = list[l].key;
	else/* copy of remained elemnets */
		for (l = i; l <= mid; l++)
			sorted[k++].key = list[l].key;
	/* copy  sorted[] to  list[] */
	for (l = left; l <= right; l++)
		list[l].key = sorted[l].key;
}

void merge_sort(element list[], int left, int right, int num)
{
	int mid;
	if (left<right) {
		mid = (left + right) / 2;
	//	printf("call merge_sort(list, left=%d, mid=%d) \n", left, mid);
		merge_sort(list, left, mid, num);    /* sort partioned lists */
	//	printf("call merge_sort(list, mid+1=%d, right=%d) \n", mid + 1, right);
		merge_sort(list, mid + 1, right, num); /* sort partioned lists */
		printf("call merge(list, left=%d, mid=%d, right=%d) \n", left, mid, right);
		merge(list, left, mid, right);    /*merge */
		printf("result : ");
		printList(a, num);
		printf("\n");

	}
}





int main(void)
{
	int num;
	int i;
	FILE *fp;
	
	a[0].key=0;
	if(fopen_s(&fp, "input.txt", "r"))
	{
		fprintf(stderr, "cannot open the file");
		exit(EXIT_FAILURE);
	}
	
	printf("<<<<<<<<<<<<< Input List >>>>>>>>>>>>>\n");
	fscanf_s(fp, "%d", &num);

	for ( i = 1; i <= num; i++)
		fscanf_s(fp, "%d", &a[i].key);				
	printList(a, num);

	printf("\n<<<<< executing recursive merge sort >>>>>\n");
	merge_sort(a, 1, num, num);
	
	printf("<<<<<<<<<<<<< Sorted List >>>>>>>>>>>\n");
	printList(a, num);

	fclose(fp);
	return 0;
}
