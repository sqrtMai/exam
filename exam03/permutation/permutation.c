#include "permutation.h"

int ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

void swap_and_print(char *str, int start)
{
	char temp;
	int i = start;
	while (str[i])
	{
		temp = str[start];
		str[start] = str[i];
		str[i] = temp;
		if (!str[start + 1])
			puts(str);
		else
			swap_and_print(str, start + 1);
		temp = str[start];
		str[start] = str[i];
		str[i] = temp;
		i++;
	}
	return ;
}

void invert_letter(char **str, int start, int new_letter)
{
	char temp = str[0][start];
	str[0][start] = str[0][new_letter];
	str[0][new_letter] = temp;
	puts(str[0]);
}

void permutation(char *str, int stop, int i, char *copy)
{
	swap_and_print(str, 0);
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return 1;
	//puts(argv[1]);
	char *copy = strdup(argv[1]);
	permutation(argv[1], 0, 1, copy);

}
