#include <stdio.h>
#include <time.h>
#include "selectionSort.h"
//#define MAX_SIZE 1001
#define MAX_SIZE 2001

void main()
{
	int i, n, step = 10;
	int a[MAX_SIZE];
	double duration;
	clock_t start;
	FILE *fp;
	fopen_s(&fp, "out.txt", "w");

	// times for n = 0, 10, ..., 100, 200, ..., 2000
	fprintf(fp, "      n         time\n");
	printf("      n         time\n");

	for (n = 0; n <= 2000; n += step)
	{// get time for size n 

	 // initialize with worst-case data
		for (i = 0; i < n; i++)
			a[i] = n - i;

		start = clock();
		sort(a, n);
		duration = ((double)(clock() - start)) / CLOCKS_PER_SEC;

		fprintf(fp, "%6d       %f\n", n, duration);
		printf("%6d       %f\n", n, duration);
		if (n == 100) step = 100;
	}

	fclose(fp);
}