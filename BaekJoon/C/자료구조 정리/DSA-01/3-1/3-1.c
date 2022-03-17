#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i, *pi;
	float f, *pf;

	if ((pi = (int*)malloc(sizeof(int))) == NULL ||
		(pf = (float *)malloc(sizeof(float))) == NULL)
	{
		fprintf(stderr, "Insufficient memory");
		exit(EXIT_FAILURE);
	}

	*pi = 1024;
	*pf = 3.14;
	printf("an integer = %d, a float = %f\n", *pi, *pf);

	free(pi);
	free(pf);

	return 0;
}
