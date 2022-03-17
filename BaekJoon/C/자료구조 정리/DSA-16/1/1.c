/***************************************************************
	
	- binary search tree
****************************************************************/
#include <stdio.h>
#include <stdlib.h>
//#define COMPARE(x, y) (((x)<(y)) ? -1 : ((x)==(y)) ? 0 : 1)
#define MALLOC(p, s) \
	if( !( (p) =(tNode *) malloc( s ) ) ){	\
		fprintf(stderr, "Insufficient memory");\
		exit(EXIT_FAILURE);\
	}
#define MAX_SIZE 500

// binary search tree
typedef int iType;
typedef struct{
	int key;
	iType item;
}element;
typedef struct node *treePointer;
typedef struct node{
	element data;
	treePointer leftChild, rightChild;
}tNode;
treePointer tree;
element* iterSearch(treePointer tree, int k);
treePointer modifiedSearch(treePointer node, int k);
void insert( treePointer *node, int k, iType theItem);

// binary tree traversal
void inorder(treePointer ptr);

int main(void)
{
	unsigned int seed;
	int n;	// the number of nodes in BST
	int cnt;
	int numbers [MAX_SIZE+1 ] = {0};
	int key;
	element *ptr;
	
	printf("random number generation (1 ~ %d)\n", MAX_SIZE);
	printf("%s","the number of nodes in BST (less than and equal to 50) : " );	
	scanf_s("%d", &n);
	printf("%s", "seed : " );	
	scanf_s("%u", &seed);

	printf("\ncreating a BST from random numbers\n");
	srand(seed);

	cnt = 0;
	printf("generating number : ");
	while( cnt < n)
	{
		key = 1 + rand()%MAX_SIZE;
		if ( !numbers[ key ] ) // unique random number
		{
			numbers[ key ] ++; 
			printf("%4d", key);
			insert(&tree, key, (iType)key);			
			cnt++;
		}		
	}
	printf("\n");
	
	printf("the key to search : ");
	scanf_s("%d", &n);
	printf("the search process : ");
	ptr = iterSearch(tree, n);
	printf("\n");
	
	if ( ptr )
		printf("the element is in BST \n");
	else
		printf("there is no such an element\n");

	printf("\ninorder traversal of the BST shows the sorted sequence\n");
	inorder(tree);
	printf("\n");
	return 0;
}

void inorder(treePointer ptr)
{ 
	if(ptr)
	{
		inorder(ptr->leftChild);
		printf("%4d", ptr->data.key);
		inorder(ptr->rightChild);
	}
}

element* iterSearch(treePointer tree, int k)
{ /* return a pointer to the element whose key is k, 
	if there is no such element, return NULL. */
	while (tree)
	{
		printf("%d => ", tree->data);
		if (k == tree->data.key) return &(tree->data);
		if (k < tree->data.key)
			tree = tree->leftChild;
		else
			tree = tree->rightChild;
	}
	return NULL;
}

treePointer modifiedSearch(treePointer node, int k)
{ /*	if  the BST(*tree) is empty or k is present return NULL
	else return the pointer to the last node of the tree	that 	was 
	encountered during the search */
	treePointer temp=NULL;
	if ( !node ) return NULL;		// empty BST
	while (node)
	{
		temp = node;
		if (k == node->data.key) return NULL; // k is present
		if (k < node->data.key)
			node = node->leftChild;
		else
			node = node->rightChild;
	}
	return temp;	
}

void insert( treePointer *node, int k, iType theItem)
{ /* if k is in the tree pointed at by node do nothing;
      otherwise add a new node with data = (k, theItem) */
	treePointer ptr, temp = modifiedSearch(*node, k);
	if(temp || !(*node))
	{
		/* k is not inthe tree */
		MALLOC(ptr, sizeof(*ptr));
		ptr->data.key = k;
		ptr->data.item = theItem;
		ptr->leftChild = ptr->rightChild = NULL;
		
		if (*node) /* insert as child of temp */
		{
			if( k < temp->data.key) 
				temp->leftChild = ptr;
			else 
				temp->rightChild = ptr;
		}
		else /* insert into empty BST */
		{
			*node = ptr;
		}
	}
}
