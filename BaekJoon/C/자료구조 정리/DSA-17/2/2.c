/***************************************************************
	- Graph : Adjacency Multilist
	- 하나의 간선이 두개의 리스트에 의해 공유됨
****************************************************************/
#include <stdio.h>
#include <stdlib.h>
//#define COMPARE(x, y) (((x)<(y)) ? -1 : ((x)==(y)) ? 0 : 1)
#define MALLOC(p, s) \
	if( !( (p) = malloc( s ) ) ){	\
		fprintf(stderr, "Insufficient memory");\
		exit(EXIT_FAILURE);\
	}

typedef enum { FALSE, TRUE } tBoolean;
typedef struct edge* tEdgePointer;
typedef struct edge
{
	tBoolean marked; // TRUE or FALSE
	int vertex1;
	int vertex2;
	tEdgePointer link1;
	tEdgePointer link2;
}tEdge;
tEdgePointer* adjMulList;

tEdgePointer createEdge(int ver1, int ver2);					// create an edge node
void addEdge(tEdgePointer temp, int ver1, int ver2);	// add the edge node into the adjacency multilists
void printMultilist(int numVertex, int choice);				// choice: 0 or 1

int main(void)
{
	FILE *fp;		
	int i;
	int numVertex, numEdge;
	int ver1, ver2, order, inputCase;
	tEdgePointer temp;

	if(fopen_s(&fp, "input1.txt", "r"))
	{
		fprintf(stderr, "cannot open the file");
		exit(EXIT_FAILURE);
	}	
	
	// create an adjacency multilist
	fscanf_s(fp, "%d%d", &numVertex, &numEdge);
	MALLOC(adjMulList, numVertex * sizeof(tEdgePointer));
	for ( i = 0; i < numVertex; i++ )
		adjMulList[i] = NULL;
	
	for ( i = 0; i < numEdge; i++ )
	{
		fscanf_s(fp, "%d%d", &ver1, &ver2);
		temp = createEdge(ver1, ver2);		
		addEdge(temp, ver1, ver2);
	}
		
	printf("<<<<<<<<<< edges incident to each vertex >>>>>>>>>>\n\n");
	puts("간선의 정점 출력 순서 - 입력데이터 순서대로");
	printMultilist(numVertex, 0);
	puts("\n간선의 정점 출력 순서 - 헤더노드 정점이  먼저 오게");
	printMultilist(numVertex, 1);

	return 0;
}

tEdgePointer createEdge(int ver1, int ver2) 
{
	tEdgePointer temp;
	
	MALLOC(temp, sizeof(*temp));
	temp->marked = FALSE;
	temp->vertex1 = ver1;
	temp->vertex2 = ver2;
	temp->link1 = NULL;
	temp->link2 = NULL;
	
	return temp;
}

void addEdge(tEdgePointer temp, int ver1, int ver2)
{
	tEdgePointer cur, prev=NULL;
	int order;

	// add to the first list sharing the edge (ver1, ver2) 
	// follow the header of ver1
	if ( adjMulList[ver1] == NULL )
	{
		adjMulList[ver1] = temp;
	}
	else
	{
		cur = adjMulList[ver1];
		while(cur)
		{
			prev = cur;
			if ( cur->vertex1 == ver1 )
			{
				cur = cur->link1;
				order = 0; // follow the first link pointer
			}
			else
			{
				cur = cur->link2;
				order = 1; // follow the second link pointer
			}
		}

		if ( order == 0 )
			prev->link1 = temp;
		else
			prev->link2 = temp;	
	}
	
	// add to the second list sharing edge (ver1, ver2) 
	// follow the header of ver2
	if ( adjMulList[ver2] == NULL )
	{
		adjMulList[ver2] = temp;
	}
	else
	{
		cur = adjMulList[ver2];
		while(cur)
		{
			prev = cur;
			if ( cur->vertex1 == ver2 )
			{
				cur = cur->link1;
				order = 0; // follow the first link pointer
			}
			else
			{
				cur = cur->link2;
				order = 1; // follow the second link pointer
			}
		}

		if ( order == 0 )
			prev->link1 = temp;
		else
			prev->link2 = temp;	
	}
}

// print the adjacency multilist
void printMultilist(int numVertex, int choice)
{
	tEdgePointer cur;
	int i;

	if ( choice == 0 )
	{ //간선의 정점 출력 순서 -  입력데이터 순서대로
		for ( i = 0; i < numVertex; i++ )
		{
			cur = adjMulList[i];
			printf("edges incident to vertex %d : ", i);
			while(cur)
			{
				printf("(%d, %d) ", cur->vertex1, cur->vertex2);
				if ( i == cur->vertex1)
					cur = cur->link1;
				else
					cur = cur->link2;
			}
			printf("\n");
		}	
	}
	else
	{ // 간선의 정점 출력 순서 - 헤더노드 정점이  먼저 오게
		for ( i = 0; i < numVertex; i++ )
		{
			cur = adjMulList[i];
			printf("edges incident to vertex %d : ", i);
			while(cur)
			{
				//if( !cur->marked )
				//	cur->marked = TRUE;

				if( i == cur->vertex1 )
				{
					printf("(%d, %d) ", cur->vertex1, cur->vertex2);
					cur = cur->link1;
				}
				else
				{
					printf("(%d, %d) ", cur->vertex2, cur->vertex1);
					cur = cur->link2;
				}
			}
			printf("\n");
		}	
	}
}
