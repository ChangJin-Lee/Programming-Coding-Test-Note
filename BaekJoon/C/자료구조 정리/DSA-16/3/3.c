
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 499
#define INF_NUM 999

// min - winner tree 
int nums[ MAX_SIZE+1 ][11] = { 0 };			// keys to sort
int winTree[ 2*MAX_SIZE ] = { 0 };		// winner tree
int sorted[ MAX_SIZE*10+1 ] = { 0 };		// sorted result
int sortedIdx[MAX_SIZE + 1] = { 0 };		// sorted index of each record
void initWinner(int cur, int k, int winTree[]);
void  adjustWinner(int min, int k, int winTree[]);


int main(void)
{
	unsigned int seed;
	int cnt, i, j;
	int k;
	int min; // the smallest number's index
	
	printf("<<<<<<<<<<<<< sorting with winner tree >>>>>>>>>>>>>>\n\n");
	
	printf("%s","the number of runs (4, 8, 16, or 32 as a power of 2 )  >> " );	
	scanf_s("%d", &k);
	
	printf("seed value >> ");
	scanf_s("%u", &seed);
	srand(seed);

	printf("initial records: \n");
	for ( i = 1; i <= k; i++ ) // ignore index 0
	{
		printf("%d-th run: \n", i);
		nums[i][1] =  1 + rand()%MAX_SIZE;   	
		for (j = 2; j <= 10; j++) {
			nums[i][j] = nums[i][j-1] + 1;
		}
		
		for (j = 1; j <= 10; j++)
			printf("%4d ", nums[i][j]);
		printf("\n");
	}

//	printf("\ninitialization of min-winner tree\n");	
	for ( cnt = k, i = 1; i <= k; cnt++, i++ )						
			winTree[cnt] = i;
	for ( i = 1; i <= k; i++)
		sortedIdx[i] = 1;

	initWinner(1, k, winTree);  // ( root index , the numbers of keys, winTree )
//	printf("\ninorder traversal for min-winner tree\n");

	printf("\n\nsorting with min-winner tree...\n");
	for ( i = 1; i <= k * 10; i++ )						
	{
		min = winTree[1];		// minimum key's index in array nums[]
		sorted[i] = nums[min][sortedIdx[min]];

		//nums[min] = INF_NUM;
		// 해당 레코드의 원소가가 정렬되었으면, 다음 원소를 정렬해야합니다.
		sortedIdx[min]++;

		// 해당 레코드의 모든 원소가 정렬되었으면, 다음번에 정렬되지 않도록
		// INF_NUM 값으로 치환합니다.
		if (sortedIdx[min] > 10) {
			sortedIdx[min]--;
			nums[min][sortedIdx[min]] = INF_NUM;
		}
		adjustWinner(min, k, winTree);
	}

	printf("\nsorted result\n");
	for ( i = 1; i <= k * 10; i++ )						
		printf("%3d%s", sorted[i], i % k ?  " " : "\n"  );

	return 0;
}


void initWinner(int cur, int k, int winTree[])
{
	int i, j, parent, start;

	start = k + k - 1;
	parent = start / 2;

	while (parent >= 1)
	{
		if (nums[winTree[start]][1] > nums[winTree[start-1]][1])
			winTree[parent] = winTree[start - 1];
		else
			winTree[parent] = winTree[start];
		start = start - 2;
		parent = start / 2;
	}

//	for (i = 1; i < 2 * k; i++)
//		printf("%5d%(%d)  ", winTree[i], nums[winTree[i]][1]);
}

// adjusting winner tree for a substituted key
void  adjustWinner(int min, int k, int winTree[])
{
	int  sibling;
	int sub = k-1+min;   // index in winner tree for a substituted key
	int parent = sub / 2;
	
	while( parent >= 1 )
	{
		if ( sub % 2 )				// odd index
			sibling = 2 * parent; // or sibling = sub - 1;
		else				
			sibling = 2 * parent + 1;  // or sibling = sub + 1
	
		///< modified by jsjang
		if( nums[ winTree[sibling] ][sortedIdx[winTree[sibling]]] < nums[ winTree[sub] ][sortedIdx[winTree[sub]]])
			winTree[parent] = winTree[sibling];
		else
			winTree[parent] = winTree[sub];

		parent /= 2;
		sub /= 2;
	}
}


