/**
 * The program implements the bubble sort algorithm and
 * sorts an array of random natural numbers.
 *
 * SIU CS 455, Advanced Algorithm Design & Analysis
 * Wednesday 3 October 2018
 *
 * The algorithm is a stable sorting algorithm because on
 * the comparison check, line 60 inside the bubblesort
 * function, only if an element is greater than the next
 * one, the two elements are swapped.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubblesort (int *, int);
void swap (int *, int, int);
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
		//The array will contain numbers [1,99999999]
		a[i] = rand() % 100000000 + 1;
	}
	//printarray(a, l);
	bubblesort(a, l);
	//printf("The sorted array is:\n");
	//printarray(a, l);
	return 0;
}

void bubblesort (int *a, int l)
{
	int i, passcheck, uplimit;

	passcheck = 1;
	uplimit = l - 1;
	while (passcheck != 0) {
		passcheck = 0;
		for (i = 0; i < uplimit; i++) {
			if (a[i] > a[i + 1]) {
				swap(a, i, i + 1);
				passcheck = 1;
			}
		}
		uplimit -= 1;
	}
}

void swap (int *a, int num1, int num2)
{
	int swap;

	swap = a[num1];
	a[num1] = a[num2];
	a[num2] = swap;
}

void printarray (int *a, int l)
{
	int i;

	for (i = 0; i < l; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}
