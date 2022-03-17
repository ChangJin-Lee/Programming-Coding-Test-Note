/***************************************************************
	- itterative merge sort
	****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct element
{
	int key;
}element;

element a[MAX_SIZE]; // a[0] is not used.

// Program 7.7: Merging two sorted lists
void merge(element initList[], element mergedList[], int i, int m, int n)
{ /* the sorted lists initList[i:m] and initList[m+1:n] are
       merged to obtain the sorted list mergedList[i:n] */
	int j, k, t;
	j = m+1;		/* index for the second sublist */
	k = i;			/* index for the merged list */

	while ( i <= m && j <= n)
	{
		if( initList[i].key <= initList[j].key )
			mergedList[ k++ ] = initList[ i++ ];
		else
			mergedList[ k++ ] = initList[ j++ ];
	}

	if( i > m )
	{ /* mergedList[k:n] = initList[j:n] */
		for ( t = j; t <= n; t++ )
			mergedList[t] = initList[t];
	}
	else
	{ /* mergedList[k:n] = initList[j:n] */
		for ( t = i; t <= m; t++ )
			mergedList[k+t-i] = initList[t];
	}
}

// Program 7.8: A merge pass
void mergePass(element initList[], element mergedList[], int n, int s)
{ /* perform one pass of the merged sort, merge adjacent
       pairs of sorted segments from initList[] into mergedList[],
	   n is the number of elements in the list, s is
	   the size of each sorted segment */
	int i, j;

	for( i = 1; i <= n - 2 * s + 1; i += 2 * s )
		merge( initList, mergedList, i, i + s - 1, i + 2 * s - 1);

	if( i + s - 1 < n )
		merge( initList, mergedList, i, i + s- 1, n);
	else
		for ( j = i; j <= n; j++ )
			mergedList[j] = initList[j];
}

void printList( element a[], int num )
{
	int i;
	for ( i = 1; i <= num; i++ )
		printf( "%3d ", a[i].key );
	printf("\n");
}

// Program 7.9: Merge sort
void mergeSort( element a[], int n )
{ /* sort a[1:n] using the merged sort method */
	int s = 1; /* current segment size */
	int i;
	element extra[MAX_SIZE];

	while ( s < n)
	{
		mergePass( a, extra, n, s);
		
		printf("segment size : %d\n", s);
		printf("%12s : ", "a");	printList( a, n);
		printf("%12s : ", "temp");printList( extra, n);
		printf("\n");


		s *= 2;

		mergePass(extra, a, n, s);

		printf("segment size : %d\n", s);
		printf("%12s : ", "temp");	printList(extra, n);
		printf("%12s : ", "a"); printList(a, n);
		printf("\n");

		s *= 2;

	}
}


int main(void)
{
	int num;
	int i;
	FILE *fp;
	
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

	printf("\n<<<<< executing itterative merge sort >>>>>\n");
	mergeSort( a, num );
	
	printf("<<<<<<<<<<<<< Sorted List >>>>>>>>>>>\n");
	printList(a, num);
	printf("\n");

	fclose(fp);
	return 0;
}
