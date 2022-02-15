#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100
#define INF 1000

int parent[MAX_VERTICES];	// 부모 노드
int num[MAX_VERTICES];	// 각 집합의 크기
// 초기화
typedef struct {
	int key;	// 간선의 가중치
	int u;		// 정점 1
	int v;		// 정점 2
} element;

#define MAX_ELEMENT 100
typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;


void set_init(int n)
{
	int i;
	for(i=0;i<n;i++){
		parent[i] = -1;
		num[i] = 1;
	}
}
// vertex가 속하는 집합을 반환한다.
int set_find(int vertex)
{
	int p, s, i=-1;
	for(i=vertex;(p=parent[i])>=0;i=p)// 루트 노드까지 반복
		;
	s = i;			// 집합의 대표 원소
	for(i=vertex;(p=parent[i])>=0;i=p)
		parent[i] = s;	// 집합의 모든 원소들의 부모를 p로 설정
	return s;
}
// 두개의 원소가 속한 집합을 합친다.
void set_union(int s1, int s2)
{
	if( num[s1] < num[s2] ){
		parent[s1] = s2;
		num[s2] += num[s1];
	}
	else {
		parent[s2] = s1;
		num[s1] += num[s2];
	}
}

// 초기화 함수
void init(HeapType *h)
{
	h->heap_size =0;
}
// 히프 내용 출력 함수
void print_heap(HeapType *h)
{
	int i;
	int level=1;
	printf("\n===================");
	for(i=1;i<=h->heap_size;i++){
		if( i == level ) {
			printf("\n");
			level *= 2;
		}
		printf("\t%d", h->heap[i].key);
	}
	printf("\n===================");
}
// 삽입 함수
void insert_min_heap(HeapType *h, element item) 
{ 
    int i; 
    i = ++(h->heap_size); 

    //  트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
    while((i != 1) && (item.key < h->heap[i/2].key)){ 
	   h->heap[i] = h->heap[i/2]; 
       i /= 2; 
    } 
    h->heap[i] = item;     // 새로운 노드를 삽입
} 
// 삭제 함수
element delete_min_heap(HeapType *h) 
{ 
    int parent, child; 
    element item, temp;

    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1;	
    child = 2;
    while( child <= h->heap_size ){
	  // 현재 노드의 자식노드중 더 작은 자식노드를 찾는다.
	  if( ( child < h->heap_size ) && 
	      (h->heap[child].key) > h->heap[child+1].key)
	      child++;
	  if( temp.key <= h->heap[child].key ) break;
	  // 한단계 아래로 이동
	  h->heap[parent] = h->heap[child];
	  parent = child;
	  child *= 2;
    }
    h->heap[parent] = temp;
    return item;
} 
void insert_heap_edge(HeapType *h, int u, int v, int weight)
{
	element e;
	e.u = u;
	e.v = v;
	e.key = weight;
	insert_min_heap(h, e);
}
// 인접 행렬이나 인접 리스트에서 간선들을 읽어서 최소 히프에 삽입 
// 현재는 예제 그래프의 간선들을 삽입한다.
void insert_all_edges(HeapType *h)
{
	FILE *fp;
	int i,row, col, val, num, sum=0;

	if(fopen_s(&fp, "input.txt", "r"))
	{
		fprintf(stderr, "cannot open the file");
		exit(EXIT_FAILURE);
	}

	fscanf_s(fp, "%d", &num);
	for ( i = 0; i < num; i++)
	{
		fscanf_s(fp, "%d%d%d", &row, &col, &val);
		insert_heap_edge(h,row,col,val);
	}
}
// kruskal의 최소 비용 신장 트리 프로그램
void kruskal(int n)
{
	int sum = 0;
	int edge_accepted=0;	// 현재까지 선택된 간선의 수	
	HeapType h;				// 최소 히프
	int uset, vset;			// 정점 u와 정점 v의 집합 번호
	element e;				// 히프 요소
	
	init(&h);					// 히프 초기화
	insert_all_edges(&h);		// 히프에 간선들을 삽입
	set_init(n);				// 집합 초기화
	while( edge_accepted < (n-1) )	// 간선의 수 < (n-1)
	{
		e = delete_min_heap(&h);	//	최소 히프에서 삭제
		uset = set_find(e.u);		// 정점 u의 집합 번호 
		vset = set_find(e.v);		// 정점 v의 집합 번호
		if( uset != vset ){			// 서로 속한 집합이 다르면
			printf("(%d,%d) %d \n",e.u, e.v, e.key);
			edge_accepted++;
			set_union(uset, vset);	// 두개의 집합을 합친다.
			sum += e.key;
		}
	}
	printf("\n최소비용 : %d\n\n", sum);
}
//
main()
{

	kruskal(7);
}