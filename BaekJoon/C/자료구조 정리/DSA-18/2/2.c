/***************************************************************
	- adjacency list of an undirected graph
	- breadth first search
****************************************************************/
#include <stdio.h>
#include <stdlib.h>
//#define COMPARE(x, y) (((x)<(y)) ? -1 : ((x)==(y)) ? 0 : 1)
#define MALLOC(p, s) \
	if( !( (p) = malloc( s ) ) ){	\
		fprintf(stderr, "Insufficient memory");\
		exit(EXIT_FAILURE);\
	}
#define FALSE 0
#define TRUE 1
#define MAX 100

// linked queue 
typedef struct qNode *queuePointer;		
typedef struct qNode{								
	int vertex;
	queuePointer link;
}tQNode; // queue node
queuePointer front, rear;
void addq(int);
int deleteq();
int queueEmpty();

// adjacency list of an undirected graph
typedef struct node* nodePointer;
typedef struct node{
	int vertex;
	nodePointer link;
}node;
nodePointer graph[MAX] = { NULL }; 
int visited[MAX] = { FALSE };

void addNode(int u, int v);
void addEdge(int u, int v);
void printAdjList(int numVertex);
void dfs(int v);
void bfs(int v);

int main(void)
{
	nodePointer temp;
	int numVertex, numEdge;
	int i, j, u, v;
	FILE *fp;

	if(fopen_s(&fp, "input2.txt", "r"))
	{
		fprintf(stderr, "cannot open the file");
		exit(EXIT_FAILURE);
	}
	
	// create an adjacency list of the undirected graph
	fscanf_s(fp, "%d%d", &numVertex, &numEdge);
	for ( i = 0; i < numEdge; i++)
	{
		fscanf_s(fp, "%d%d", &u, &v);		
		addEdge(u, v);		
	}

	// print the adjacency list 
	printf("<<<<<<<<<<<<< Adjacency List >>>>>>>>>>>>>\n");
	printAdjList(numVertex);

	/*printf("\n<<<<<<<<<<<<< Depth First Search >>>>>>>>>>\n");
	// dfs(i) : depth first search for a starting vertex i 
	for ( i = 0; i < numVertex; i++)
	{
		printf("dfs(%d) : ", i);
		for ( j = 0; j <  numVertex; j++)
			visited[j] = FALSE;			
		dfs(i);
		printf("\n");
	}
	*/

	printf("\n<<<<<<<<<<<<< Breadth First Search >>>>>>>>>>\n");
	// bfs(i) : breadth first search for a starting vertex i 
	for ( i = 0; i < numVertex; i++)
	{
		printf("bfs(%d) : ", i);
		for ( j = 0; j <  numVertex; j++)
			visited[j] = FALSE;			
		bfs(i);
		printf("\n");
	}
	return 0;
}

/////////////////////// linked queue /////////////////////////////
// 4장의 다중큐를 단일 큐로 수정함

// Program 4.7 : Add to the rear of a linked queue
void addq(int item)
{ /* add item to the rear of queue */
	queuePointer temp;
	MALLOC(temp, sizeof(*temp));
	temp->vertex = item;
	temp->link = NULL;
	if( front)
		rear->link = temp;
	else
		front =  temp;
	rear = temp;	
}

// Program 4.8: Delete from the front of a linked queue
int deleteq()
{ /* delete an element from queue */
	queuePointer temp = front;
	int item;
	if(!temp)
		return queueEmpty();
	item = temp->vertex;
	front = temp->link;
	free(temp);
	return item;
}

int queueEmpty()
{
	int item;
	item = -1;// error key
	return item;
}

/////////////////////// adjacency list /////////////////////////////

void addNode(int u, int v)
{
	nodePointer temp;
	MALLOC( temp, sizeof (*temp) );
	temp->vertex = v;
	temp->link = graph[u];
	graph[u] = temp;
}

void addEdge(int u, int v)
{
	addNode(u, v); 
	addNode(v, u); 
}

void printAdjList(int numVertex)
{
	int i;
	nodePointer temp;

	for( i = 0 ; i < numVertex ; i++ )
	{
		printf("graph[%d] : ", i);
		temp = graph[i];		
		while(temp)
		{	
			printf("%3d ", temp->vertex);
			temp = temp->link;
		}
		printf("\n");
	}
}

// Program 6.1 : Depth first search
void dfs(int v)
{
	nodePointer w;
	visited[v] = TRUE;
	printf("%3d", v);
	for(w = graph[v] ; w ; w = w->link)
		if( !visited[w->vertex] )
			dfs(w->vertex);
}

// Program 6.2: Breadth first search of a graph
void bfs(int v)
{ /* breadth first traversal of a graph, startingat v
	   the global array visited is initialized to 0, the queue 
	   operations are similar to those described in Chaptr 4, 
	   front and rear are global */
	nodePointer w;
	front = rear = NULL; /* initialize queue */
	printf("%3d", v);
	visited[v] = TRUE;
	addq(v);
	while( front )
	{
		v = deleteq();
		for (w = graph[v]; w; w = w->link)
		{
			if( !visited[ w->vertex ] )
			{
				printf("%3d", w->vertex);
				addq(w->vertex);
				visited[w->vertex] = TRUE;
			}
		}
	}
}