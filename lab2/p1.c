/**
 * A non negative integer should be given as input to 
 * calculate its factorial. 
 *
 * SIU CS 455, Advanced Algorithm Design & Analysis
 * Tuesday 11 September 2018
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint64_t factorial (int);

int main(int argc, char **argv)
{
	int n;

	if (argc != 2) {
		printf("Provide exactly one arguments at "
		"input, the factorial you want to be "
		"calucalted.\n");
		return 1;
	}
	n = atoi(argv[1]);
	if(n < 0) {
		printf("The number must be non negative."
		"\n");
		return 1;
	}
	printf("%d! = %lu\n", n, factorial(n));
	return 0;
}

uint64_t factorial (int a)
{
	if ((a == 0) || (a == 1)) {
		return 1;
	} else {
		return (a * factorial(a - 1));
	}
}
