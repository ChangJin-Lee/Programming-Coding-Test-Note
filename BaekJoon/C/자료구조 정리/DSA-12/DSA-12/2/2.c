#include <stdio.h>
#include <stdlib.h>
//#define COMPARE(x, y) (((x)<(y)) ? -1 : ((x)==(y)) ? 0 : 1)
#define MAX_QUEUE_SIZE 100
#define MALLOC(p, s) \
	if( !( (p) = malloc( s ) ) ){	\
		fprintf(stderr, "Insufficient memory");\
		exit(EXIT_FAILURE);\
	}

// tree node & root
typedef struct node *treePointer;
typedef struct node
{
	char data;		
	treePointer leftChild, rightChild;
}node;
treePointer root = NULL;

// linear queue
treePointer queue[MAX_QUEUE_SIZE];
int rear = -1;
int front = -1;
void addq(treePointer item);
void queueFull();
treePointer deleteq();
treePointer queueEmpty();
treePointer getFront(); // 큐의 가장 선두항목 값을 반환. 큐의 항목을 삭제하지 않음

// complete binary tree
treePointer createNode( char data );
treePointer createCompBinTree(FILE *fp);
int hasBothChild(treePointer pNode);
void insert( treePointer *pRoot, treePointer pNode );

// binary tree traversals
void inorder(treePointer ptr);
void preorder(treePointer ptr);
void postorder(treePointer ptr);

void main(void)
{
	char data;
	FILE *fp ;
	
	if(fopen_s(&fp,"input.txt", "r") )
	{
		fprintf(stderr, "cannot open the file");
		exit(EXIT_FAILURE);
	}
	
	printf("creating a complete binary tree\n\n");
	root = createCompBinTree(fp);

	printf("three binary tree traversals\n");
	printf("%-20s : ", "inorder traversal");
	inorder(root); 	printf("\n");

	printf("%-20s : ","preorder traversal");
	preorder(root);	printf("\n");

	printf("%-20s : ","postorder traversal");
	postorder(root);	printf("\n\n");

	fclose(fp);
}

/////////////////////////////////////// linear queue ////////////////////////////////////////

void addq(treePointer item)
{/* add an item to the queue */
	if ( rear == MAX_QUEUE_SIZE-1 )
		queueFull();
	queue[++rear] = item;
}

void queueFull()
{		
	fprintf(stderr, "queue is full, cannot add element\n");
	exit(1);
}

treePointer deleteq()
{/* remove element at the front of the queue */
	if ( front == rear )
		return queueEmpty();	/* returns an error key */
	return queue[++front];
}

treePointer queueEmpty()
{
		fprintf(stderr, "queue is empty, cannot delete element\n");
		return NULL;
}

treePointer getFront()
{
	return queue[front+1];
}

/////////////////////////// complete binary tree //////////////////////////////////////

treePointer createNode( char data )
{
	treePointer pNode;

	MALLOC(pNode, sizeof(*pNode));
	pNode->data = data;
	pNode->leftChild = NULL;
	pNode->rightChild = NULL;
	
	return pNode;
}


treePointer createCompBinTree( FILE * fp)
{
	treePointer pNode;
	char data;

	fscanf_s(fp,"%c", &data, sizeof(char));
	pNode = createNode(data);
		
	while(!feof(fp))
	{
		insert( &root, pNode);
		fscanf_s(fp, "%c", &data, sizeof(char));
		pNode = createNode(data);
	}
	free(pNode); 

	return root;
}

int hasBothChild(treePointer pNode)
{
	return pNode->leftChild && pNode->rightChild;
}

void insert( treePointer *pRoot, treePointer pNode )
{
	if( !*pRoot )
	{
		*pRoot = pNode;
	}
	else
	{
		treePointer pfront = getFront();

		if( !pfront->leftChild )
			pfront->leftChild = pNode;
		else if( !pfront->rightChild )
			pfront->rightChild = pNode;

		if( hasBothChild( pfront ) )
			deleteq();
	}

	addq(pNode);
}

///////////////////// binary tree traversals //////////////////////////////

// Program 5.1 : Inorder traversal of a binary tree
void inorder(treePointer ptr)
{ 
	if(ptr)
	{
		inorder(ptr->leftChild);
		printf("%c", ptr->data);
		inorder(ptr->rightChild);
	}
}

// Program 5.2 : preorder traversal of a binary tree
void preorder(treePointer ptr)
{ 
	if(ptr)
	{
		printf("%c", ptr->data);
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}

// Program 5.3 : postorder traversal of a binary tree
void postorder(treePointer ptr)
{ 
	if(ptr)
	{
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		printf("%c", ptr->data);
	}
}
