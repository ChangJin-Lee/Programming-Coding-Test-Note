/***************************************************************
	- adjacency list of an undirected graph and a directed graph
****************************************************************/
#include <stdio.h>
#include <stdlib.h>
//#define COMPARE(x, y) (((x)<(y)) ? -1 : ((x)==(y)) ? 0 : 1)
#define MALLOC(p, s) \
	if( !( (p) = malloc( s ) ) ){	\
		fprintf(stderr, "Insufficient memory");\
		exit(EXIT_FAILURE);\
	}
#define MAX 100

// adjacency list of an undirected graph
typedef struct node* tNodePointer;
typedef struct node{
	int vertex;
	tNodePointer link;
}tNode;
tNodePointer adjList[MAX] = { NULL }; 

void addNode(int u, int v);
void addUndirGraphEdge(int u, int v);	// undirected graph
void addDirGraphEdge(int u, int v);		// directed graph
void printAdjList(int numVertex);

int main(void)
{
	//tNodePointer temp;
	char option;
	int numVertex, numEdge;
	int i, u, v;
	FILE *fp;

	if(fopen_s(&fp,"input1.txt", "r"))
	{
		fprintf(stderr, "cannot open the file");
		exit(EXIT_FAILURE);
	}
	
	// create an adjacency list of an undirected graph
	fscanf_s(fp, "%c %d%d", &option, sizeof(int), &numVertex, &numEdge);
	
	switch( option )
	{
	case 'u':	// undirected graph
		for ( i = 0; i < numEdge; i++)
		{
			fscanf_s(fp, "%d%d", &u, &v);		
			addUndirGraphEdge(u, v);		
		}
		break;

	case 'd':	// directed graph
		for ( i = 0; i < numEdge; i++)
		{
			fscanf_s(fp, "%d%d", &u, &v);		
			addDirGraphEdge(u, v);		
		}
		break;
	}

	// print the adjacency list 
	printf("<<<<<<<<<<<<< Adjacency List >>>>>>>>>>>>>\n");
	printAdjList(numVertex);
	
	return 0;
}

/////////////////////// adjacency list /////////////////////////////

void addNode(int u, int v)
{
	tNodePointer temp;
	MALLOC( temp, sizeof (*temp) );
	temp->vertex = v;
	temp->link = adjList[u];
	adjList[u] = temp;
}

void addUndirGraphEdge(int u, int v)
{
	addNode(u, v); 
	addNode(v, u); 
}

void addDirGraphEdge(int u, int v)
{
	addNode(u, v); 
}

void printAdjList(int numVertex)
{
	int i;
	tNodePointer cur;

	for( i = 0 ; i < numVertex ; i++ )
	{
		printf("adjList[%d] : ", i);
		cur = adjList[i];		
		while(cur)
		{	
			printf("%3d ", cur->vertex);
			cur = cur->link;
		}
		printf("\n");
	}
}
