/**
 * A programm that finds the Longest Common Subsequence of
 * two strings using dynamic programming. The user should
 * give as input at the command line the length of each
 * string. The strings will be case sensitive, 'A' is not
 * considered the same as 'a'.
 *
 * SIU CS 455, Advanced Algorithm Design & Analysis
 * Wednesday 24 October 2018
 * 
 */

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int length;
	int prevchar;	//0 above, 1 left, 2 diagonal
} typedef dynamnd;

void printsolution (dynamnd **, int, int, int *);

int main(int argc, char **argv)
{
	int i, j, s1, s2, max;
	char c;
	dynamnd **LCS;	
	int *seq1, *seq2;

	if (argc != 3) {
		printf("Provide exactly two arguments at "
			"input, the length of each of the "
			"two strings.\n");
		return 1;
	}
	s1 = atoi(argv[1]);
	s2 = atoi(argv[2]);
	if ((s1 < 1) || (s2 < 1)) {
		printf("Invalid length numbers. The lengths"
			" should be greater or equal to 1."
			"\n");
		return 1;
	}
	seq1 = (int *) malloc(s1 * sizeof(int));	//String1 array
	seq2 = (int *) malloc(s2 * sizeof(int));	//String2 aray
	LCS = (dynamnd **) malloc((s1 + 1) * sizeof(dynamnd *));	//Solution array
	for (i = 0; i <= s1; i++) {
		LCS[i] = (dynamnd *) malloc((s2 + 1) * sizeof(dynamnd));
	}
	//Reading the input values, this can also be done by reading a file
	printf("Please provide strings with characters "
		"between '0-9', 'a-z' and 'A-Z'.\nNo spaces"
		" between the characters, press enter at "
		"the end of string 1.\n");
	printf("Input string 1:\n");
	for (i = 0; i < s1; i++) {
		scanf("%c", &c);
		seq1[i] = (int) c;
		if ((seq1[i] < 48) || (seq1[i] > 57 && 
		   seq1[i] < 65) || (seq1[i] > 90 && 
		   seq1[i] < 97) || (seq1[i] > 122)) {
			printf("Invalid character entered.\n");
			return 1;
		}
	}
	scanf("%c", &c);	//To get rid of the return key pressed
	printf("Input string 2:\n");
	for (i = 0; i < s2; i++) {
		scanf("%c", &c);
		seq2[i] = (int) c;
		if ((seq2[i] < 48) || (seq2[i] > 57 && 
		   seq2[i] < 65) || (seq2[i] > 90 && 
		   seq2[i] < 97) || (seq2[i] > 122)) {
			printf("Invalid character entered.\n");
			return 1;
		}
	}
	for (i = 0; i <= s1; i++) {		//check all characters of string 1
		for (j = 0; j <= s2; j++) {	//check all characters of string 2
			if ((i == 0) || (j == 0)) {
				LCS[i][j].length = 0;
				LCS[i][j].prevchar = -1;	//No previous character from this position
			} else if (seq1[i - 1] == seq2[j - 1]) {
				LCS[i][j].length = LCS[i - 1][j - 1].length + 1;
				LCS[i][j].prevchar = 2;
			} else {
				max = LCS[i][j - 1].length;
				LCS[i][j].prevchar = 1;
				if (max < LCS[i - 1][j].length) {
					max = LCS[i - 1][j].length;
					LCS[i][j].prevchar = 0;
				}
				LCS[i][j].length = max;
			}
		}
	}
	free(seq2);
	printsolution(LCS, s1, s2, seq1);
	for (i = 0; i < s1; i++) {
		free(LCS[i]);
	}
	free(LCS);
	free(seq1);
	
	return 0;
}

void printsolution (dynamnd **LCS, int s1, int s2, int *sequence1)
{
	int i, j, k;
	int *ComSeq;

	ComSeq = (int *) malloc(LCS[s1][s2].length * sizeof(int));
	printf("The length of the Longest Common "
		"Subsequence is %d\n", LCS[s1][s2].length);
	i = s1;
	j = s2;
	k = LCS[i][j].length - 1;
	while (k >= 0) {
		if (LCS[i][j].prevchar == 2) {
			ComSeq[k] = sequence1[i - 1];
			k -= 1;
			i -= 1;
			j -= 1;
		} else if (LCS[i][j].prevchar == 1) {
			j -= 1;
		} else {
			i -= 1;
		}
	}
	printf("The Longest Common Subsequence is: ");
	for (i = 0; i < LCS[s1][s2].length; i++) {
		printf("%c", (char) ComSeq[i]);
	}
	printf("\n");
}
