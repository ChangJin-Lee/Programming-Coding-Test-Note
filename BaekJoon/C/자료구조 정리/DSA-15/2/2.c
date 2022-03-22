#include <stdio.h>
#include <stdlib.h>

// max heap
#define MAX_ELEMENTS 200 /* maximum heap size+1 */
#define HEAP_FULL(n) ( n == MAX_ELEMENTS-1 )
#define HEAP_EMPTY(n) (!n)
typedef struct
{
	int key;		
	/* other fields */
}element;
element heap[MAX_ELEMENTS];
int n = 0;
void push(element item, int *n);  // insertion into a max heap
element pop( int *n );					// deletion from a max heap

int main(void)
{
	FILE *fp;	
	element item;
	int i;

	if(fopen_s(&fp, "input.txt", "r"))
	{
		fprintf(stderr, "cannot open the file");
		exit(EXIT_FAILURE);
	}
	
	printf("***** insertion into a max heap *****\n");
	fscanf_s(fp, "%d", &item.key);
	while( !feof(fp))
	{
		push( item, &n );
		for ( i = 1; i <= n; i++ )		
			printf( "%3d", heap[i].key );
		printf("\n");

		fscanf_s(fp, "%d", &item.key);
	}

	printf("***** deletion from a max heap ***** \n");
	while( n > 0)
	{
		item = pop(&n);	
		printf("delet data = %d\n", item);
		for ( i = 1; i <= n; i++ )		
			printf( "%3d", heap[i].key );
		printf("\n");		
	}


	return 0;
}

// Program 5.13: insertion into a max heap
void push(element item, int *n)
{ /* insert item into a max heap of current size *n */
	int i;
	if( HEAP_FULL(*n) )
	{
		fprintf(stderr, "The heap is full. \n");
		exit(EXIT_FAILURE);
	}
	
	i = ++(*n);

	while( (i != 1) && (item.key > heap[i/2].key ))
	{
		heap[i] = heap[i/2];
		i /= 2;
	}
	heap[i] = item;
}

// Program 5.14: Deletion from a max heap
element pop( int *n )
{	/* delete element with the highest key from the heap */
	int parent, child;
	element item, temp;
	if( HEAP_EMPTY(*n))
	{
		fprintf(stderr, "The heap is empty. \n");
		exit(EXIT_FAILURE);
	}

	/* save value of the element with the highest key */
	item = heap[1];

	/* use last elementin heap to adjust heap */
	temp = heap[(*n)--];
	parent = 1;
	child = 2;

	while( child <= *n )
	{ /* find the larger child of he current parent */
		if (( child < *n) && ( heap[child].key < heap[child+1].key))
			child++;
		if( temp.key >= heap[child].key) break;
		/* move to the next lower level */
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}

	heap[parent] = temp;
	return item;
}
