#include <stdio.h>
#include <stdlib.h>

int get_sum(int *subset, int max)
{
	int sum = 0;
	int i = 0;
	while (i < max)
		sum += subset[i++];
	return sum;
}

void powerset(int *list, int *subset, int goal, int start, int index, int max)
{
	int i = 0;

	if (start > max)
		return ;
	if (get_sum(subset, start) > goal)
		return ;
	if (get_sum(subset, start) == goal)
	{
		while (i < start)
		{
			printf("%d", subset[i++]);
			if (i < start)
				printf(" ");
		}
		printf("\n");
		//return ;
	}
	i = index;
	while (i < max)
	{
		subset[start] = list[i];
		powerset(list, subset, goal, start + 1, i + 1, max);
		i++;
	}
}

int main(int argc, char **argv)
{
	int i = 0;
	int *subset = calloc(argc - 2, sizeof(int));
	int *list = calloc(argc - 2, sizeof(int));
	while (argv[i + 2])
	{
		list[i] = atoi(argv[i + 2]);
		i++;
	}
	powerset(list, subset, atoi(argv[1]), 0, 0, argc - 2);
}
