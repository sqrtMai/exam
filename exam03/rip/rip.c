#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_remove
{
	int remove_open;
	int remove_close;
}	t_remove;

void get_remove_nbr(char *str, t_remove *remove)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] == '(')
			remove->remove_open++;
		if (str[i] == ')')
		{
			if (remove->remove_open > 0)
				remove->remove_open--;
			else
				remove->remove_close++;
		}
		i++;
	}
}

int is_valid(char *str)
{
	int i = 0;
	int open = 0;
	int close = 0;
	while (str[i])
	{
		if (str[i] == '(')
			open++;
		if (str[i] == ')')
		{
			if (open > 0)
				open--;
			else
				close++;
		}
		i++;
	}
	if (open == 0 && close == 0)
		return 1;
	return 0;
}

void rip(char *str, int remove_open, int remove_close)
{
	char temp;
	int i = 0;

	while (str[i] && (remove_open || remove_close))
	{
		if (str[i] == '(' && remove_open)
		{
			temp = str[i];
			str[i] = ' ';
			rip(str, remove_open - 1, remove_close);
			str[i] = temp;
		}
		if (str[i] == ')' && remove_close)
		{
			temp = str[i];
			str[i] = ' ';
			rip(str, remove_open, remove_close - 1);
			str[i] = temp;
		}
		i++;
	}
	if (is_valid(str))
		puts(str);
	return ;
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return 1;
	t_remove remove;
	remove.remove_close = 0;
	remove.remove_open = 0;
	get_remove_nbr(argv[1], &remove);
	rip(argv[1], remove.remove_open, remove.remove_close);
}
