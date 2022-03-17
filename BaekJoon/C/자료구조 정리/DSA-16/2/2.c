/***************************************************************
- sorting by using winner tree
****************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 499
#define INF_NUM 9999

// min - winner tree 
int nums[MAX_SIZE + 1] = { 0 };						// keys to sort
int winTree[2 * MAX_SIZE] = { NULL };		// winner tree
int sorted[MAX_SIZE + 1] = { 0 };					// sorted result
void winner(int cur, int k, int winTree[]);
void inorder(int root, int k, int winTree[]);
void adjust(int ind, int winTree[]);

int main(void)
{
	unsigned int seed;
	int cnt, i, j;
	int k;
	int minNum;
	int *min;

	printf("<<<<<<<<<<<<< sorting with winner tree >>>>>>>>>>>>>>\n\n");

	printf("%s", "the number of keys ( 4, 8, 16, or 32 as a power of 2 )  >> ");
	scanf_s("%d", &k);

	printf("value of seed >>  ");
	scanf_s("%u", &seed);
	srand(seed);

	for (i = 1; i <= k; i++) // ignore index 0
	{
		nums[i] = 1 + rand() % MAX_SIZE;
		printf("%5d%s", nums[i], i != k ? "" : "\n");
	}

	printf("\ninitialization of min-winner tree\n");
	for (cnt = k, i = 1; i <= k; cnt++, i++)
		winTree[cnt] = nums[i];

	winner(1, k, winTree);  // ( root index , the numbers of keys, winTree )
	printf("\ninorder traversal for min-winner tree\n");
	inorder(1, k, winTree);

	for (i = 1; i <= k; i++)
	{
		sorted[i] = winTree[1];
		if (i != k) {
			for (j = k; j < 2 * k; j++)
				if (sorted[i] == winTree[j]) {
					winTree[j] = INF_NUM;
					break;
				}
			adjust(j, winTree);
		}

		if (i == 2) {
			printf("\nWinner Tree inoder traversal after find 2 winners...\n");
			inorder(1, k, winTree);
		}


	}

	printf("\n\nsorting with min-winner tree...\n");
	printf("\nsorted result\n");
	for (i = 1; i <= k; i++)
		printf("%5d%s", sorted[i], i != k ? "" : "\n");

	return 0;
}

void adjust(int ind, int winTree[])
{
	int i, cmp;
	i = ind;
	while (i != 1) {
		if (i % 2)
			cmp = i - 1;
		else
			cmp = i + 1;
		if (winTree[i] <= winTree[cmp])
			winTree[i / 2] = winTree[i];
		else
			winTree[i / 2] = winTree[cmp];
		i = i / 2;
	}
}

void winner(int cur, int k, int winTree[])
{
	int i, j, parent, start;

	start = k + k-1;
	parent = start / 2;

	while (parent >= 1)
	{

		if (winTree[start] > winTree[start - 1])
			winTree[parent] = winTree[start - 1];
		else
			winTree[parent] = winTree[start];
		start = start - 2;
		parent = start / 2;

	}

	for (i = 1; i < 2 * k; i++)
		printf("%5d", winTree[i]);
}


// Inorder traversal of a  winner tree
void inorder(int root, int k, int winTree[])
{
	if (root < 2 * k)
	{
		inorder(2 * root, k, winTree);
		printf("%5d", winTree[root]);
		inorder(2 * root + 1, k, winTree);
	}
}
