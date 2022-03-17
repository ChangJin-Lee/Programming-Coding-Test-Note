// polynomial addition using  singly linked circular lists
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define COMPARE(x, y) (((x)<(y)) ? -1 : ((x)==(y)) ? 0 : 1)
#define MALLOC(p, s) \
	if( !( (p) = malloc( s ) ) ){	\
		fprintf(stderr, "Insufficient memory");\
		exit(EXIT_FAILURE);\
	}

// linked list
typedef struct polyNode *polyPointer;
typedef struct polyNode {
	int coef;
	int expon;
	polyPointer link;
}polyNode;
polyPointer a = NULL, b = NULL, c = NULL;		// polynomial a, b, c : singly linked circular list with a header node
polyPointer lastA, lastB;											// last pointers of polynomial a and b
polyPointer avail = NULL;										// available space list : singly linked list, that is , chain

void erase( polyPointer *first );													
polyPointer getNode(void);													
void retNode(polyPointer node);												
void cerase(polyPointer *ptr);											
polyPointer cpadd(polyPointer a, polyPointer b);						
void attach(int coefficient, int exponent, polyPointer *ptr);		
void insertFront2(polyPointer *last, polyPointer node);				
void insertLast(polyPointer *last, polyPointer node);					
void printCList(polyPointer header);										

// create a polynomial from file
void inputPolyCL(char *filename, polyPointer *header, polyPointer *last);		

int main(void)
{

	inputPolyCL( "a.txt", &a, &lastA);
	inputPolyCL( "b.txt", &b, &lastB);	
	
	printf("%9s", "a : \n");	printCList(a);	
	printf("%9s", "b : \n");	printCList(b);			
	
	c = cpadd(a, b);	
	printf("%9s", "a+b=c : \n"); printCList(c);	

	cerase(&a);
	cerase(&b);
	cerase(&c);
	printf("%9s", "avail : \n");	printCList(avail);
	erase(&avail);

	return 0;
}

void erase( polyPointer *ptr )
{/* erase the polynomial pointed to by ptr */
	polyPointer temp;
	while (*ptr)
	{
		temp = *ptr;
		*ptr = (*ptr)->link;
		free(temp);
	}
}

polyPointer getNode(void)
{/* provide a node for use */
	polyPointer node;
	if(avail)
	{
		node = avail;
		avail = avail->link;
	}
	else
		MALLOC(node, sizeof(*node));
	return node;

}

void retNode(polyPointer node)
{/* return a node to the available list */
	node->link = avail;
	avail = node;
}

void cerase(polyPointer *ptr)
{ /* erase the circular list pointed to by ptr */
	polyPointer temp;
	if(*ptr)
	{
		temp =  (*ptr)->link;
		(*ptr)->link = avail;
		avail = temp;
		*ptr = NULL;
	}
}


polyPointer cpadd(polyPointer a, polyPointer b)
{ /* polynomials a and b are singly linked circular lists 
	   with a header node. Return a poly nomial wihch is 
	   the sum of a and b */
	polyPointer startA, c, lastC;
	int sum, done = FALSE;
	startA = a;			/* record start of a */
	a = a->link;			/* skip header node for a and b */
	b = b->link;
	c = getNode();		/* get a header node for sum */
	c->expon = -1; lastC = c;

	do
	{
		switch (COMPARE( a->expon, b->expon))
		{
			case -1: /* a->expon < b->expon */
				attach(b->coef, b->expon, &lastC);
				b = b->link;
				break;

			case 0 : /* a->expon = b->expon */
				if(startA == a)	
				{
					done = TRUE;
				}
				else
				{
						sum = a->coef + b->coef;
						if (sum) attach(sum, a->expon, &lastC);
						a = a->link; 	b = b->link; 
				}
				break;

			case 1 : /* a->expon > b->expon */
				attach(a->coef, a->expon, &lastC);
				a = a->link;			
		}
	}while (!done);

	lastC->link = c;
	
	return c;
}

void attach(int coefficient, int exponent, polyPointer *ptr)
{/* create a new node with coef = coefficient and 
	expon = exponent, attach it to the node pointed to by ptr.
	ptr is updated to point to this new node */
	polyPointer temp;
	temp = getNode();
	temp->coef = coefficient;
	temp->expon = exponent;
	(*ptr)->link = temp;
	*ptr = temp;
}

void insertFront2(polyPointer *last, polyPointer node)
{ /* insert node at the front of the circular list whose last node is last */
   /* the circular list has a header node */
	
	if(!(*last) )
	{ // list is empty, change last to point to new entry, that is, header node */
		*last = node;
		node->link = node;
	}
	else 
	{ 	// list is not empty, add new entry at the front, that is, next to header node */
		node->link = (*last)->link->link;
		(*last)->link->link = node;
		
		// for the first input data
		if((*last)->expon == -1 )
			*last = node;
	}
}

void insertLast(polyPointer *last, polyPointer node)
{ /* insert node at the last of the circular list whose last node is last */
	
	if(!(*last) )
	{ // list is empty, change last to point to new entry */
		*last = node;
		node->link = node;
	}
	else 
	{ 	// list is not empty, add new entry at the end */
		node->link = (*last)->link;
		(*last)->link = node;
		*last = node;
	}
}

void printCList(polyPointer header)
{
	polyPointer temp;

	if( header )
	{
		temp = header->link;
		printf("(%p : %+4dx^%d : %p) \n", header, header->coef, header->expon, header->link);
		while(temp != header)
		{
			printf("(%p : %+4dx^%d : %p) \n", temp, temp->coef, temp->expon, temp->link);
			temp = temp->link;			
		}
		printf("\n");
	}
}


void inputPolyCL(char *filename, polyPointer *header, polyPointer *last)
{
	polyPointer node;
	char order;				// a: ascending order, d: descending order 
	FILE *fp;	

	fopen_s(&fp, filename, "r");
	if(fp == NULL)
	{
		fprintf(stderr, "cannot open the file");
		exit(EXIT_FAILURE);
	}
	
	// zero polynomial with a header node ( Figure 4.15(a) ) and a last pointer
	*header = getNode(); 
	(*header)->expon = -1;
	*last = NULL;
	insertLast(last, *header); // or insertFront2(last, *header)
		
	fscanf_s(fp, "%c", &order, sizeof(order));		
	if( order == 'd' )
	{	
		node = getNode();	
		fscanf_s(fp, "%d%d", &node->coef, &node->expon);		
		while( !feof(fp) )
		{		
			insertLast(last, node);
			node = getNode();
			fscanf_s(fp, "%d%d", &node->coef, &node->expon);
		}
		retNode(node);
	}
	else // 'a'
	{
		insertFront2(last, *header);
		node = getNode();
		fscanf_s(fp, "%d%d", &node->coef, &node->expon);		
		while( !feof(fp) )
		{		
			insertFront2(last, node);
			node = getNode();
			fscanf_s(fp, "%d%d", &node->coef, &node->expon);
		}
		retNode(node);
	}

	fclose(fp);	
}