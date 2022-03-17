/***************************************************************

	- adjacency list of an undirected graph
	- depth first search
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

// adjacency list of an undirected graph
typedef struct node* nodePointer;
typedef struct node{
	int vertex;
	nodePointer link;
}node;
nodePointer graph[MAX] = { NULL };


int stack[MAX];
int top = -1;

int visited[MAX] = { FALSE };

void push(int item);
void stackFull();
int pop();
int peek();
int getAdjUnvisitedVertex(int item);


void addNode(int u, int v);
void addEdge(int u, int v);
void printAdjList(int numVertex);
void iter_dfs(int v);



int main(void)
{
	nodePointer temp;
	int numVertex, numEdge;
	int i, j, u, v;
	FILE *fp;

	if(fopen_s(&fp,"input.txt", "r"))
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
	
	printf("\n<<<<<<<<<<<<< Depth First Search >>>>>>>>>>\n");
	// dfs(i) : depth first search for a starting vertex i 
	for ( i = 0; i < numVertex; i++)
	{
		printf("dfs(%d) : ", i);
		for ( j = 0; j <  numVertex; j++)
			visited[j] = FALSE;			
		iter_dfs(i);
		printf("\n");
	}

	return 0;
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
void iter_dfs(int v)
{
	int unvisitedVertex;
	int popdata[MAX];
	int i, popcnt=0;

	visited[v] = TRUE;
	printf("%3d", v);
	push(v);


	while (top != -1)
	{
		//get the unvisited vertex of vertex which is at top of the stack
		unvisitedVertex = getAdjUnvisitedVertex(peek());

		//no adjacent vertex found
		if (unvisitedVertex == -1) {
		//	pop();
			popdata[popcnt++] = pop();
		}
		else {
			visited[unvisitedVertex] = TRUE;
			printf("%3d", unvisitedVertex);
			push(unvisitedVertex);
		}
	}

	printf("\nPop    : ");
	for(i=0; i<popcnt; i++)
		printf("%3d", popdata[i]);

	//stack is empty, search is complete, reset the visited flag        
	for (i = 0;i < MAX;i++) {
		visited[i] = FALSE;
	}
}

int pop()
{/* delete and return the top element from the stack */
	if (top == -1)
		return -1;	/* returns empty stack */
	return stack[top--];
}


void push(int item)
{/* add an item to the global stack */
	if (top >= MAX - 1)
		stackFull();
	stack[++top] = item;
}

void stackFull()
{
	int item;
	fprintf(stderr, "stack is full, cannot add element\n");
	exit(EXIT_FAILURE);
}

int peek()
{

	if (top == -1)
		return -1;	/* returns an error key */
	return stack[top];
}
int getAdjUnvisitedVertex(int item)
{
	nodePointer ptr;
	ptr = graph[item];
	for (;ptr;ptr = ptr->link)
		if (!visited[ptr->vertex])
			return ptr->vertex;
	return -1; // not find unvisited vertex.
}
