/***************************************************************
	- LSD Radix - r sort	
****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct element{
	int key;
}element;
element a[MAX_SIZE];
int link[MAX_SIZE] = {0};

void printList(element a[], int link[], int first, int n);
void saveList(element a[], int link[], int first, int n);
int digit(element e, int i, int d, int r);
void radixSort(element a[], int link[], int d, int r, int n);
void printQueues(int front[], int rear[], int r);

int main(void)
{
	int d;						// digits
	const int r = 10;		// radix
	int n, i, first;	
	FILE *fp;

	if(fopen_s(&fp, "input.txt", "r"))
	{
		fprintf(stderr, "cannot open the file");
		exit(EXIT_FAILURE);
	}
	
	fscanf_s(fp, "%d%d", &d, &n);
	for ( i = 1; i <= n; i++)
		fscanf_s(fp, "%d", &a[i].key);		
	
	radixSort( a, link, d, r, n);

	fclose(fp);
	return 0;
}

void printList(element a[], int link[], int first, int n)
{
	int i , current;

	printf("%7s ", "");
	for ( i = 1; i <= n; i++ )
		printf(" [%2d]%s", i, i==n ? "\n" : "" );
	
	printf("%7s:", "link");
	for ( i = 1; i <= n; i++ )
		printf("%5d%s", link[i], i==n ? "\n" : "" );
	
	printf("%7s:", "a");
	for ( i = 1; i <= n; i++ )
		printf("%5d%s", a[i].key, i==n ? "\n" : "" );

	printf("%7s:%5d\n", "first", first );

	current = first;		
	printf("%s%7s:", "\n", "result");
	while( current != 0 ) 
	{
		printf("%5d", a[current].key );
		current = link[current];
	}
	printf("\n");
	
}


int digit(element e, int i, int d, int r)
{
	int m, quotient;

	quotient = e.key;
	for ( m = 0; m < d-i-1 ; m++ )
		quotient = quotient / r;
	
	return  quotient % r;
}

// Program 7.14: LSD radix sort
void radixSort(element a[], int link[], int d, int r, int n)
{ /* sort a[1:n] using a d-digit radix-r sort, digit(a[i], j, d, r) 
	returns the jth radix-r digit (from the left) of a[i]'s key. 
	each digit is in the range is [0,r); sorting within a digit 
	is done using a bin sort */

	int *front, *rear;		/* queue front and rear pointers */
	int i, bin, current, first, last;

	front = (int *) malloc( sizeof (int) * r );
	rear =  (int *) malloc( sizeof (int) * r );
	
	/* create initial chain of records startng at first */
	first = 1;
	for ( i = 1; i < n; i++) 
		link[i] = i +1;
	link[n] = 0;

	printf("************************* initial chain *************************\n");
	printList(a, link, first, n);	

	for ( i = d-1; i >=0; i--)
	{ /* sort on digit i */
		
		/* initialize bins to empty queues */
		for ( bin = 0; bin < r; bin++)
		{
			front[bin] = 	rear[bin] = 0;
		}
		
		for ( current = first; current; current = link[current] )
		{/* put records into queues/bins */
			bin = digit(a[current], i, d, r);
			if( front[bin] == 0) 
				front[bin] = current;
			else 
				link[rear[bin]] = current;
			rear[bin] = current;
		}

		/* find first nonempty queue/bin */
		for ( bin = 0; !front[bin]; bin++) ;
		first = front[bin]; 
		last = rear[bin];		

		/* concatenate remaining queues */
		for( bin++; bin <r; bin++)
		{
			if(front[bin])
			{
				link[last] = front[bin];
				last = rear[bin];
			}
		}
		link[last] = 0;

		printf("\n**************************** pass %d *****************************\n", d-i);
		printList(a, link, first, n);
		printQueues(front, rear, r);
	}

	free(front); 
	free(rear);

	return;
}

void printQueues(int front[], int rear[], int r)
{
	int i ;

	printf("%s%7s ", "\n", "");
	for ( i = 0; i < r; i++ )
		printf(" [%2d]%s", i, i==r-1 ? "\n" : "" );
	
	printf("%7s:", "rear");
	for ( i = 0; i < r; i++ )
		printf("%5d%s", rear[i], i==r-1 ? "\n" : "" );	

	printf("%7s:", "front");
	for ( i = 0; i < r; i++ )
		printf("%5d%s", front[i], i==r-1 ? "\n" : "" );
	
}
