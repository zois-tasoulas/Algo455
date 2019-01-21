/**
 * The program calculates the sum of integers between 1 and
 * n, n is provided by the user as input.
 *
 * SIU CS 455, Advanced Algorithm Design & Analysis
 * Wednesday 19 September 2018
 *
 * The recursive formula is T(n) = T(n-1) + 1 and the running time is O(n).
 */

#include <stdio.h>
#include <stdlib.h>

int calcsum (int *, int, int);
void printarray(int *, int);

int main(int argc, char **argv)
{
	int i, l, *a;

	if (argc != 2) {
		printf("Provide exactly one argument at input, the number"
			" until which you want to calculate the sum\n");
		return 1;
	}
	l = atoi(argv[1]);
	if(l <= 0) {
		printf("The maximum number must be a positive integer"
			"\n");
		return 1;
	}
	a = (int *) malloc(l * sizeof(int));
	for (i = 0; i < l; i++) {	
		a[i] = i + 1;
	}
	printarray(a, l);
	printf("The minimum number in the array is %d\n", calcsum(a, l - 1, 0));
	return 0;
}

int calcsum (int *a, int l, int sum)
{
	if (l == -1) {
		return sum;
	} else {
		sum = sum + a[l];
		return calcsum(a, l - 1, sum);
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
