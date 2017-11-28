#include <stdio.h>
#include <stdlib.h>
#define ISSUES 5
#define RATINGS 10

void recordResponse(int i, int response);
void highestRatings();
void lowestRatings();
float averageRating(int issue);
void displayResults();

int response[ISSUES][RATINGS];
const char *topics[ISSUES] = { "Global Warming","The Economy","War","Health Care","Education" };

int main(void)
{
	int response;
	int i;

	do
	{
		printf("Please rate the following topic on a scale from 1 - 10\n 1 - least important, 10 = most impartant\n");

		for (i = 0; i < ISSUES; i++)
		{
			do
			{
				printf("%s", topics[i]);
				printf("? ");
				scanf_s("%d", &response);
			} while (response < 1 || response>10);
			recordResponse(i, response);
		}

		printf("Enter 1 to stop. Enter 0 to rate the issues again. ");
		scanf_s("%d", &response);
	} while (response != 1);

	displayResults();
	system("pause");
	return 0;
}

void recordResponse(int issue, int rating)
{
	response[issue][rating - 1]++;
}

void highestRatings(void)
{
	int highRating = 0;
	int highTopic = 0;
	int i;
	int j;

	for (i = 0; i < ISSUES; i++)
	{
		int topicRating = 0;

		for (j = 0; j < RATINGS; j++)
		{
			topicRating += response[i][j] * (j + 1);
		}
		if (highRating < topicRating)
		{
			highRating = topicRating;
			highTopic = i;
		}
	}
	printf("The highest rated topic was ");
	printf("%s", topics[highTopic]);
	printf(" with a total rating of %d\n", highRating);
}

void lowestRatings(void)
{
	int lowRating;
	int lowTopic = 0;
	int i;
	int j;

	for (i = 0; i < ISSUES; i++)
	{
		int topicRating = 0;

		for (j = 0; j < RATINGS; j++)
		{
			topicRating += response[i][j] * (j + 1);
		}
		if (i == 0)
		{
			lowRating = topicRating;
		}
		if (lowRating > topicRating)
		{
			lowRating = topicRating;
			lowTopic = i;
		}
	}
	printf("The lowest rated topic was ");
	printf("%s", topics[lowTopic]);
	printf(" with a total rating of %d\n", lowRating);
}

float averageRating(int issue)
{
	float total = 0;
	int counter = 0;
	int j;

	for (j = 0; j < RATINGS; j++)
	{
		if (response[issue][j] != 0)
		{
			total += response[issue][j] * (j + 1);
			counter += response[issue][j];
		}
	}
	return total / counter;
}

void displayResults()
{
	int i;
	int j;

	printf("%20s", "Topic");
	for (i = 1; i <= RATINGS; i++)
	{
		printf("%4d", i);
	}
	printf("%20s", "Average Rating");

	for (i = 0; i < ISSUES; i++)
	{
		printf("%20s", topics[i]);

		for (j = 0; j < RATINGS; j++)
		{
			printf("%4d", response[i][j]);
		}
		printf("%20.2f", averageRating(i));
	}
	highestRatings();
	lowestRatings();
}