/**
 * The program finds recursivelly the minimum number of an
 * array. The size of the array should be given as an
 * argument by the user.
 *
 * SIU CS 455, Advanced Algorithm Design & Analysis
 * Wednesday 19 September 2018
 *
 * The recursive formula is T(n) = T(n-1) + 2 and the running time is O(n).
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int searchmin (int *, int, int);
void printarray(int *, int);

int main(int argc, char **argv)
{
	int i, l, *a;

	srand(time(NULL));
	if (argc != 2) {
		printf("Provide exactly one argument at input, the size "
			"of the array\n");
		return 1;
	}
	l = atoi(argv[1]);
	if(l <= 0) {
		printf("The size of the array must be a positive integer"
			"\n");
		return 1;
	}
	a = (int *) malloc(l * sizeof(int));
	for (i = 0; i < l; i++) {	
		//The array will contain numbers [0,99999999]
		a[i] = rand() % 100000000;
	}
	printarray(a, l);
	printf("The minimum number in the array is %d\n", searchmin(a, l - 1, -1));
	return 0;
}

int searchmin (int *a, int l, int min)
{
	if (min == -1) {
		min = a[l];
		return searchmin(a, l - 1, min);
	} else if (l < 0) {
		return min;
	} else {
		if (a[l] < min)
			min = a[l];
		return searchmin(a, l - 1, min);
	}
}

void printarray (int *a, int l)
{
	int i;
	for (i = 0; i < l; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}
