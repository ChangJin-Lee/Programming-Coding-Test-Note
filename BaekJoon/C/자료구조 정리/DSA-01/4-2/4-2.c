#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX_SIZE 101
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))
#define COMPARE(x, y) (((x) < (y)) ? -1: ((x) == (y)) ? 0: 1)

void sort(int[], int); /* selection sort*/
int binsearch(int list[], int searchnum, int left, int right); /* Searching an ordered list */

void main(void)
{
	int i, n, searchnum, searchResult;
	int list[MAX_SIZE];
	printf("Enter the number of numbers to generate: ");
	scanf_s("%d", &n);

	if (n < 1 || n > MAX_SIZE)
	{
		fprintf(stderr, "Improper value of n\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < n; i++)			/* randomly generate numbers */
	{
		list[i] = rand() % 1000;
		printf("%d  ", list[i]);
	}

	sort(list, n);

	printf("\n\nSorted array:\n");
	for (i = 0; i < n; i++)		/* print out sorted numbers */
		printf("%d  ", list[i]);
	printf("\n");

	printf("\nEnter the number to search: ");
	scanf_s("%d", &searchnum);

	searchResult = binsearch(list, searchnum, 0, n - 1);

	if (searchResult == -1)
		printf("The search number is not present\n");
	else
		printf("The search number is present in list[%d]\n", searchResult);
}

void sort(int list[], int n)
{
	int i, j, min, temp;

	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
			if (list[j] < list[min])
				min = j;
		SWAP(list[i], list[min], temp);
	}
}


int binsearch(int list[], int searchnum, int left, int right)

{
	int middle;
	while (left <= right)
	{
		middle = (left + right) / 2;
		switch (COMPARE(list[middle], searchnum))
		{
		case -1: return binsearch(list, searchnum, middle + 1, right);
			break;
		case 0: return middle;
		case 1: return binsearch(list, searchnum, left, middle - 1);
		}
	}
	return -1;
}

