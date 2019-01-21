/**
* Two numbers should be provided with the execution command,
* the size of the array and the number to be searched.
*
* SIU CS 455, Advanced Algorithm Design & Analysis
* Tuesday 4 September 2018
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

void printarray (int *, int);

int main(int argc, char **argv)
{
	int i, l, q, *a;
	struct timeval begin, end;
	double elapsed_time;

	srand(time(NULL));
	if (argc != 3) {
		printf("Provide exactly two arguments at input, the size of" 
			"the array and the number to be searched\n");
		return 1;
	}
	l = atoi(argv[1]);
	q = atoi(argv[2]);
	if((l <= 0) || (q < 0)) {
		printf("The size of the array must be a positive integer and "
			"the array consists of non negative integers\n");
		return 1;
	}
	a = (int *) malloc(l * sizeof(int));
	for (i = 0; i < l; i++) {
		a[i] = rand() % 1000000;	//The array will contain numbers [0,999999]
	}
	//printarray(a, l);
	gettimeofday(&begin, NULL);
	for (i = 0; i < l; i++) {
		if (q == a[i]) {
			printf("The provided number exists in the array :)\n");
			break;
		}
		if (i == (l - 1))
			printf("The provided number does not exist in the array :(\n");
	}
	gettimeofday(&end, NULL);
	elapsed_time = ((end.tv_sec - begin.tv_sec) * 1000000) + (end.tv_usec - begin.tv_usec);
	printf("The time elapsed for the search is %lf usec\n", elapsed_time);
	return 0;
}

void printarray (int *a, int l)
{
	int i;
	for (i = 0; i < l; i++)
		printf("%d ", a[i]);
	printf("\n");
}
