#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define TRUE	1
#define FALSE	0
#define INF 	999	/* ���� ��(������ ���� ���) */
#define NODE_MAX 	100

int cost[NODE_MAX][NODE_MAX];
int distance[NODE_MAX];/* ���۳��κ����� �ִܰ�� �Ÿ� */
int path[NODE_MAX];	/* ���� ���  */
int found[NODE_MAX];		/* �湮�� ��� ǥ�� */

void print_distance(int vertex)
{
	int i;
	for(i=0;i< vertex;i++){
		printf("%5d ", distance[i]);
	}
	printf("\n");
}

int choose(int distance[], int n, int found[])
{
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for(i=0;i<n;i++)
		if( distance[i]< min && ! found[i] ){
			min = distance[i];
			minpos=i;
		}
	return minpos;
}

void shortest_path(int start, int cost[][NODE_MAX],
				   int distance[], int n, int found[]) /* ���۳�� start  */
{  
   int i, u, w, j;
   for(i=0; i<n; i++) /* �ʱ�ȭ */
   {
	  distance[i] = cost[start][i];
	  path[i] = start;
	  found[i] = FALSE;
   }
   found[start] = TRUE;    /* ���۳�� �湮 ǥ�� */
   distance[start] = 0;
   for(i=0; i<n; i++){
//	  print_distance();
	  u = choose(distance, n, found);
	  found[u] = TRUE;
	  for(w=0;w<n; w++) 
		   if(!found[w])
			   if( distance[u]+cost[u][w] < distance[w] ) {
					distance[w] = distance[u]+cost[u][w];	
					path[w] = u;		/* ������� ���� */
		   }
	  if(u > -1) {
		  printf("%d : ", u);
		  for (j = 0;j < n; j++)
			  printf("%5d", distance[j]);
		  printf("\n");
	  }
   }
}

void print_path(int start, int end)
{
	int top = -1;
	struct edges {
		int from;
		int to;

	} stack[NODE_MAX];

	while (path[end] != start) {
		//push(path[end], end)
		stack[top++].from = path[end];
		stack[top].to = end;
		end = path[end];
	}
	//push(path[end], end)
	stack[top++].from = path[end];
	stack[top].to = end;
	while(top >= 0)
		printf("<%d->%d> ", stack[top].from, stack[top--].to);

}


void main()
{

	FILE *fp;
	int i,row, col, val, vertex, num;
	int start;

	if(fopen_s(&fp, "input.txt", "r"))
	{
		fprintf(stderr, "cannot open the file");
		exit(EXIT_FAILURE);
	}
	fscanf_s(fp, "%d %d", &vertex, &num);
	// create an adjacency matrix of the undirected graph
	for(row=0; row< vertex;row++)
		for(col=0; col< vertex;col++)
			if (row == col) 
				cost[row][col]	= 0;
			else cost[row][col]	= INF;
	


	for ( i = 0; i < num; i++)
	{
		fscanf_s(fp, "%d%d%d", &row, &col, &val);
		cost[row][col]	= val;
		cost[col][row]	= val;
	}

	start=0; // ���� ���
	shortest_path(start, cost, distance, vertex, found);


	printf("\n");
	for(i=0; i< vertex; i++){
		if(i != start) {
			printf("distance[%d-%d]=%-3d : ", start, i, distance[i]);
			print_path(start,i);
			printf("\n");	
		}
		
	}
	fclose(fp);
}