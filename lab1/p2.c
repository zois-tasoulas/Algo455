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
int cmpfnc (const void *, const void *);
int binarysrch(int *, int, int, int);

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
	a = (int *) malloc((l + 1) * sizeof(int));
	for (i = 1; i < (l + 1); i++) {
		a[i] = rand() % 1000000;	//The array will contain numbers [0,999999]
	}
	qsort(&a[1], l, sizeof(int), cmpfnc);
	//printarray(a, l);
	gettimeofday(&begin, NULL);
	if (binarysrch(a, 1, l, q) == 1) {
		printf("The provided number exists in the array :)\n");
	} else {
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
	for (i = 1; i < (l + 1); i++)
		printf("%d ", a[i]);
	printf("\n");
}

int cmpfnc (const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int binarysrch(int *arr, int a, int b, int q)
{
	int median, dif;
	
	dif = b - a;
	median = a + (dif / 2);
	if (dif == 1 ) {
		if ((arr[a] == q) || (arr[b] == q)) {
			return 1;
		} else {
			return 0;
		}
	} else if ((q < arr[a]) || (q > arr[b])) {
		return 0;
	} else if (arr[median] == q) {
		return 1;
	} else if (arr[median] > q){
		return binarysrch(arr, a, median, q);
	} else {
		return binarysrch(arr, median, b, q);
	}
}
