/**
 * A dynamic programming solution for an assembly line 
 * problem. Multiple lines can be used, more than two.
 *
 * SIU CS 455, Advanced Algorithm Design & Analysis
 * Monday 22 October 2018
 * 
 * The number of lines and the number of stations per line 
 * must be provided with the execution command.
 */

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int cost;
	int prevline;
} typedef dynamnd;

void printsolution (dynamnd **, int, int);

int main(int argc, char **argv)
{
	int i, j, k, l, s, prevln, mincost, cost1;
	dynamnd **a;	
	int *e, *x, **S, ***t;

	if (argc != 3) {
		printf("Provide exactly two arguments at "
			"input, the number of the assembly" 
			" lines followed by the number of "
			"stations for each line.\n");
		return 1;
	}
	l = atoi(argv[1]);
	s = atoi(argv[2]);
	if((l <= 1) || (s <=1)) {
		printf("Both number of lines and number of " 
			"stations per line need to be "
			"greater than one.\n");
		return 1;
	}
	a = (dynamnd **) malloc(l * sizeof(dynamnd *));	//Solution array
	S = (int **) malloc(l * sizeof(int *));		//Station cost array
	t = (int ***) malloc(l * sizeof(int **));	//Transition cost array
	e = (int *) malloc(l * sizeof(int));		//Entrance costs
	x = (int *) malloc(l * sizeof(int));		//Exit costs
	for (i = 0; i < l; i++) {
		a[i] = (dynamnd *) malloc((s + 1) * sizeof(dynamnd));
		S[i] = (int *) malloc(s * sizeof(int));		
		t[i] = (int **) malloc(l * sizeof(int *));	
		for (j = 0; j < l; j++) {
			t[i][j] = (int *) malloc((s - 1) * 
					sizeof(int));
		}
	}
	//Reading the input values, this can also be done by reading a file
	for (i = 0; i < l; i++) {
		printf("Input entrance cost for line %d"
			"\n", (i + 1));
		scanf("%d", &e[i]);
		printf("Input exit cost for line %d"
			"\n", (i + 1));
		scanf("%d", &x[i]);
		printf("Input costs per station for line %d"
			"\n", (i + 1));
		for (j = 0; j < s; j++) {
			scanf("%d", &S[i][j]);
		}
		for (k = 0; k < l; k++) {
			if (k != i) {
				printf("Input costs per "
					"transition from "
					"line %d to line "
					"%d\n", (i + 1), 
					(k + 1));
				for (j = 0; j < (s - 1); j++) {
					scanf("%d", &t[i][k][j]);
				}
			} else {	//There are no transitions to the same line
				t[i][k][j] = -1;
			}
		}
	}
	for (j = 0; j <= s; j++) {		//check every station
		for (i = 0; i < l; i++) {	//check every line
			if (j == 0) {
				a[i][j].cost = e[i] + S[i][j];
				a[i][j].prevline = i;	//Not really needed
			} else if (j == s) {
				a[i][j].cost = a[i][j - 1].cost + x[i];
				a[i][j].prevline = i;
			} else {
				mincost = a[i][j - 1].cost + S[i][j];
				prevln = i;
				for (k = 0; k < l; k++) {	//check transition from every line
					if (k != i) {	//if k == i, do nothing
						cost1 = (a[k][j - 1].cost + t[k][i][j - 1] + S[i][j]);
						if (cost1 < mincost) {
							mincost = cost1;
							prevln = k;
						}
					}
				}
				a[i][j].cost = mincost;
				a[i][j].prevline = prevln;
			}
		}
	}
	free(e);
	free(x);
	printsolution(a, l, s);
	for (i = 0; i < l; i++) {
		free(a[i]);
		free(S[i]);
		for (j = 0; j < l; j++) {
			free(t[i][j]);
		}
		free(t[i]);
	}
	free(a);
	free(S);
	free(t);
	
	return 0;
}

void printsolution (dynamnd **a, int lines, int stations)
{
	int i, lastline, min;
	int *route;

	route = (int *) malloc(stations * sizeof(int));

	min = a[0][stations].cost;	//Initialize with line 0
	lastline = 0;
	for (i = 1; i < lines; i++) {
		if (a[i][stations].cost < min) {
			min = a[i][stations].cost;
			lastline = i;
		}
	}
	printf("The minimum cost for the assembly line is "
		"%d\n", min);
	for (i = (stations - 1); i >= 0; i--) {
		if (i != (stations - 1)) {
			route[i] = a[route[i + 1]][i + 1].prevline;
		} else {
			route[i] = a[lastline][i + 1].prevline;
		}
	}
	for (i = 0; i < stations; i++) {
		printf("%d ", (route[i] + 1));
	}
	printf("\n");
	free(route);
}
