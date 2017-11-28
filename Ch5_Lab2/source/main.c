#include <stdio.h>
#include <stdlib.h>
#define STUDENTS 3
#define EXAMS 4

void minimum(int grades[][EXAMS], int pupils, int tests);
void maximum(int grades[][EXAMS], int pupils, int tests);
void average(int grades[][EXAMS], int pupils, int tests);
void printArray(int grades[][EXAMS], int pupils, int tests);
void printMenu(void);

int main()
{
	void(*processGrades[4])(int[][EXAMS], int, int)
		= { printArray,minimum,maximum,average };
	int choice = 0;

	int studentGrades[STUDENTS][EXAMS] = { {77,68,86,73},{96,87,89,78},{70,90,86,81} };

	while (choice != 4)
	{
		do {
			printMenu();
			scanf("%d", &choice);
		} while (choice < 0 || choice>4);

		if (choice != 4) {
			(*processGrades[choice])(studentGrades, STUDENTS, EXAMS);
		}
		else {
			printf("*Program Ended.\n");
		}
	}
	system("pause");
	return 0;
}


void minimum(int grades[][EXAMS], int pupils, int tests) {
	int i, j;
	int lowGrade = 100;

	for (i = 0; i <= pupils-1; i++) {
		for (j = 0; j <= tests-1; j++) {
			if (grades[i][j] < lowGrade) {
				lowGrade = grades[i][j];
			}
		}
	}
	printf("\n\tThe lowest grade is %d\n", lowGrade);
}

void maximum(int grades[][EXAMS], int pupils, int tests) {
	int i, j;
	int highGrade = 0;

	for (i = 0; i <= pupils-1; i++) {
		for (j = 0; j <= tests - 1; j++) {
			if (grades[i][j] > highGrade) {
				highGrade = grades[i][j];
			}
		}
	}
	printf("\n\tThe highest grade is %d\n", highGrade);
}

	void average(int grades[][EXAMS], int pupils, int tests) {
		int i, j,total;
		printf("\n");

		for (i = 0; i <= pupils - 1; i++) {
			total = 0;
			for (j = 0; j <= tests - 1; j++) {
				total += grades[i][j];
			}
			printf("\tThe average for student %d is %.1f\n", i + 1, (double)total / tests);
		}
	}

	void printArray(int grades[][EXAMS], int pupils, int tests) {
		int i, j;

		printf("\n\t               [0]    [1]    [2]    [3]");
		for (i = 0; i <= pupils-1; i++) {
			printf("\n\tstudentGrades[%d]", i);
			for (j = 0; j <= tests - 1; j++) {
				printf("%-7d", grades[i][j]);
			}
		}
		printf("\n");
	}

	void printMenu(void) {
		printf("\n\tEnter a choice:\n"
			"\t  0  Print the array of grades\n"
			"\t  1  Find the minimum grade\n"
			"\t  2  Find the maximum grade\n"
			"\t  3  Print the average on all"
			" tests for each students\n"
			"\t  4  End program\n"
			"\t?");
	}
