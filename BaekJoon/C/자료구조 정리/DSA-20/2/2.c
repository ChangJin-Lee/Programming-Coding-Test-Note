#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

#define VERTICES 7
#define INF 1000L

int adj_mat[VERTICES][VERTICES];

int selected[VERTICES];
int dist[VERTICES];

// 최소 dist[v] 값을 갖는 정점을 반환
int get_min_vertex(int n)
{
  int v,i;
  for (i = 0; i <n; i++)
    if (!selected[i]) {
      v = i; 
	  break;
    }
  for (i = 0; i < n; i++)
    if ( !selected[i] && (dist[i] < dist[v])) v = i;
  return (v);
}
//
void prim(int s, int n)
{
	int i,j, u, v;

	for(u=0;u<n;u++)
		dist[u]=INF;
	dist[s]=0;
	for(i=0;i<n;i++){
		u = get_min_vertex(n);
		selected[u]=TRUE;
		if( dist[u] == INF ) return;
		for( v=0; v<n; v++)
			if( adj_mat[u][v]!= INF)
				if( !selected[v] && adj_mat[u][v]< dist[v] )
					dist[v] = adj_mat[u][v];
		printf("선택 vertex : %d,   distance : ", u);
		for(j=0; j<VERTICES; j++)
		{
			if (dist[j]==INF)
				printf("  INF");
			else printf("%5d", dist[j]);
		}
		printf("\n");
	}
}
//
main()
{
	FILE *fp;
	int i,row, col, val, num, sum=0;

	if(fopen_s(&fp, "input2.txt", "r"))
	{
		fprintf(stderr, "cannot open the file");
		exit(EXIT_FAILURE);
	}

	// create an adjacency matrix of the undirected graph
	for(row=0; row<VERTICES;row++)
		for(col=0; col<VERTICES;col++)
			if (row == col) 
				adj_mat[row][col]	= 0;
			else adj_mat[row][col]	= INF;

	fscanf_s(fp, "%d", &num);
	for ( i = 0; i < num; i++)
	{
		fscanf_s(fp, "%d%d%d", &row, &col, &val);
		adj_mat[row][col]	= val;
		adj_mat[col][row]	= val;
	}
	prim(0, VERTICES);
	for(i=0; i<VERTICES; i++)
		sum += dist[i];
	printf("최소 비용 : %d\n\n", sum);
}