// 정렬된 데이터에 대한 선택정렬 - 성능측정
#include <stdio.h>
#include <time.h>
#include "selectionSort.h"
#define MAX_SIZE 2001

void main(void)
{
	int i, n, step = 10;
	int a[MAX_SIZE];
	double duration;
	clock_t start;
	FILE *fp;
	fopen_s(&fp, "out.txt", "w");

	// times for n = 0, 10, ..., 100, 200, ..., 2000
	fprintf(fp, "    n       repetitions        time\n");
	printf("    n       repetitions        time\n");
	
	for(n = 0; n <= 2000; n+= step)
	{
		// get time for size n
		long repetitions = 0;
		clock_t start = clock();
		do
		{
			repetitions++;

			// initialize with sorted data
			for ( i = 0; i < n; i++)
				a[i] = i;

			sort(a, n);
		}while( clock() - start < 1000 );
				// repeat until enough time has elapsed
					
		duration = ((double) (clock() - start)) / CLOCKS_PER_SEC;
		duration /= repetitions;
		
		fprintf(fp, "%6d      %9d     %f\n", n, repetitions, duration);
		printf("%6d      %9d     %f\n", n, repetitions, duration);
		if( n == 100 ) step = 100;
	}
}
