/**
 * A programm that solves with a greedy algorithm the 
 * activity selection problem. The user should give as an 
 * input the number of activities at the command
 * line. Acrtivities are described by their starting and 
 * ending time.
 *
 * SIU CS 455, Advanced Algorithm Design & Analysis
 * Tuesday 27 November 2018
 * 
 */

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int start_t;
	int end_t;
	int sol;	//A field to indicate whether an activity is scheduled or not
} typedef activnd;

int cmpfunc(const void *a, const void *b);
void printsolution (activnd *, int);

int main(int argc, char **argv)
{
	int i, s1, nxt_strt, acts;
	activnd *activity;	

	if (argc != 2) {
		printf("Provide exactly one arguments at "
			"input, the number of total "
			"activities available.\n");
		return 1;
	}
	s1 = atoi(argv[1]);
	if (s1 < 1) {
		printf("Invalid number of activities. The"
			" number of activities should be "
			"greater or equal to 1."
			"\n");
		return 1;
	}
	activity = (activnd *) malloc(s1 * sizeof(activnd));	//Activities array
	//Reading the activities' times, this can also be done by reading a file
	printf("Please provide the starting time followed "
		"by the ending time of each activity.\n");
	for (i = 0; i < s1; i++) {
		scanf("%d", &activity[i].start_t);
		if (activity[i].start_t < 0) {
			printf("Invalid starting time entered\n");
			free(activity);
			return 1;
		}
		scanf("%d", &activity[i].end_t);
		if (activity[i].end_t <= activity[i].start_t) {	//Assuming that an activity 
								//has to last at least one time token
			printf("Invalid ending time entered\n");
			free(activity);
			return 1;
		}
		activity[i].sol = -1;
	}
	qsort(activity, s1, sizeof(activnd), cmpfunc);	//Sorting activities by finishing time
	nxt_strt = activity[0].end_t;
	activity[0].sol = 0;
	acts = 1;
	for (i = 1; i < s1; i++) {
		if (activity[i].start_t >= nxt_strt) {
			nxt_strt = activity[i].end_t;
			activity[i].sol = 0;
			acts += 1;
		}	
	}
	printf("The maximum number of activities that can "
		"be scheduled are %d\n", acts);
	printsolution(activity, s1);
	free(activity);
	
	return 0;
}

int cmpfunc(const void *a, const void *b) 
{
	const activnd * mem1 = a;
	const activnd * mem2 = b;

	if (mem1->end_t < mem2->end_t) {
		return -1;
	} else if (mem1->end_t > mem2->end_t) {
		return 1;
	} else {
		return 0;
	}
}

void printsolution (activnd *activity, int s1)
{
	int i;

	printf("The scheduled activities are:\n");
	for (i = 0; i < s1; i++) {
		if (activity[i].sol == 0)
			printf("%d %d\n", activity[i].start_t, activity[i].end_t);
	}
}
