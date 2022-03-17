#include <stdio.h>
#include <stdlib.h>
#define MALLOC(p, s) \
	if( !( (p) = malloc( s ) ) ){	\
		fprintf(stderr, "Insufficient memory");\
		exit(EXIT_FAILURE);\
	}

// linked list
typedef struct listNode *listPointer;
typedef struct listNode {
	int data;
	listPointer link;
}listNode;
listPointer first = NULL;

void insert(listPointer *first, int data);				// insert data into ordered list first after node x
void delete( listPointer *first, listPointer trail, listPointer x); // 주의 : delete 는 c++ 의 keyword!, 소스파일 확장자가 cpp이면 컴파일 에러임
void printList(listPointer first);

int main(void)
{
	int data;
	listPointer x, trail, curr, ffirst;
	
	// data input for each node
	FILE *fp;	
	fopen_s(&fp, "input.txt", "r");
	if( fp == NULL )
	{
		fprintf(stderr, "cannot open the file");
		exit(EXIT_FAILURE);
	}
	
	fscanf_s(fp, "%d", &data);	

	x = NULL;
	while( !feof(fp) )
	{
		insert(&first, data);		// insert data first after node x. 
		fscanf_s(fp, "%d", &data);	
	}
	printList(first->link);	

	if(first)
		curr= first->link;
	else
	{
		printf("no data !!\n");
		exit(0);
	}
	
	ffirst = trail = first;

	while (curr != NULL )
	{
		if (curr->data % 2) {
			x = curr;
			curr = curr->link;
			delete(&first, trail, x);
			if (ffirst != first) {
				break;
			}
		}
		else
		 {
			trail = curr;
			curr = curr->link;
		}
		if (trail == first)
				break;
	}

	printf("\nAfter deleting nodes with odd value \n\n");
	printList(first->link);	
	
	fclose(fp);
	
	return 0;
}


void insert(listPointer *first, int data)
{ /* insert a new node with a data into the chain first after node x */
	listPointer temp;
	MALLOC(temp, sizeof(*temp));
	temp->data = data;

	if(*first == NULL)  
	{// add to empty list
		temp->link = temp;
		*first = temp;
	}
	else
	{
		temp->link = (*first)->link;
		(*first)->link = temp;
		*first = temp;
		}
}

void delete( listPointer *first, listPointer trail, listPointer x)
{ /* delete x from the list, trail is the preceding node 
	   and *first is the front of the list */
	if (*first == x)
		*first = trail;
	trail->link = x->link;
	free(x);
}

void printList(listPointer first)
{
	int count;
	listPointer temp;
	temp = first;
	printf("The Circularly Linked List contains: \n");
	for (count = 1; first; count++) {
		printf("(%p, %4d, %p )%s", first, first->data, first->link, count % 3 ? "" : "\n");
		first = first->link;
		if (temp == first)
			break;
	}
	printf("\n");
}