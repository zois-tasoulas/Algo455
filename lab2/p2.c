/**
 * A positive integer n should be given as input to 
 * calculate the nth Fibonacci. 
 *
 * SIU CS 455, Advanced Algorithm Design & Analysis
 * Tuesday 11 September 2018
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint64_t fibonacci (int, uint64_t, uint64_t);
uint64_t slow_fibonacci (int);

int main(int argc, char **argv)
{
	int n;

	if (argc != 2) {
		printf("Provide exactly one arguments at "
		"input, the corresponding Fibonacci number "
		"you want to calculate.\n");
		return 1;
	}
	n = atoi(argv[1]);
	if(n <= 0) {
		printf("The number must be greater than "
		"zero.\n");
		return 1;
	}
	printf("The %dth Fibonacci number is %lu\n", n, 
		fibonacci(n, 0, 1));
	return 0;
}

uint64_t fibonacci (int a, uint64_t b, uint64_t c)
{
	if (a < 2) {
		return c;
	} else {
		return fibonacci(a - 1, c, b + c);
	}
}

uint64_t slow_fibonacci(int a)
{
	if ((a == 1) || (a == 2)) {
		return 1;
	} else {
		return (slow_fibonacci(a - 1) + 
			slow_fibonacci(a - 2));
	}
}
