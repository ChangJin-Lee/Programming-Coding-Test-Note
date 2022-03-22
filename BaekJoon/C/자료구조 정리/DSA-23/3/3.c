/***************************************************************
	- heap sort
	****************************************************************/
#include <stdio.h>
#include <stdlib.h>
//#define COMPARE(x, y) (((x)<(y)) ? -1 : ((x)==(y)) ? 0 : 1)
#define SWAP(x, y, temp) ((temp) = (x), (x) = (y), (y)=(temp))
#define MAX_SIZE 100

typedef struct element
{
	int key;
}element;

element a[MAX_SIZE]; // a[0] is not used.

// Program 7.12: Adjusting a max heap
int adjust( element a[], int root, int n)
{ /* adjust the binary tree to establish the heap */

	int child, rootkey;
	element temp;
	temp = a[root];
	rootkey = a[root].key;
	child = 2 * root;					/* left child */
	while( child <= n )
	{
		if(( child < n ) && ( a[child].key < a[child+1].key ))
			child++;

		if( rootkey > a[child].key ) /* compare root and max.child */
			break;
		else
		{
			a[child / 2] = a[child]; /* move to parent */
			child *= 2;
		}
	}
	a[child / 2] = temp;
}

void printList( element a[], int num )
{
	int i;
	for ( i = 1; i <= num; i++ )
		printf( "%d ", a[i].key );
	printf("\n");
}

// Program 7.13: heap sort
void heapSort( element a[], int n )
{ /* perform a heap sort on a[1:n] */
	int i, j;
	element temp;

	for( i = n/2; i > 0; i-- )
		adjust(a, i, n );
	
	printf("after initialization of max heap...\n");
	printList(a, n); 
	printf("\n");

	for ( i = n -1; i > 0; i-- )
	{
		SWAP(a[1], a[i+1], temp);
		adjust(a, 1, i );

		printf("\nstep %2d: ", n-i);

		printf("Ãâ·Â %d : ", a[i+1].key);
		for(j=1; j<= i; j++)
			printf("%4d",a[j].key);

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

	printf("\n<<<<<<< executing heap sort >>>>>>>>>>\n");
	heapSort( a, num );
	
	printf("\n<<<<<<<<<<<<< Sorted List >>>>>>>>>>>\n");
	printList(a, num);
	printf("\n");

	fclose(fp);
	return 0;
}
