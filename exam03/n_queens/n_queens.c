#include "n_queens.h"

void reset_board(char **board, int n)
{
	int i = 0;
	int j = 0;

	while (i < n)
	{
		j = 0;
		while (j < n)
			board[i][j++] = '0';
		i++;
	}
}

char **malloc_board(int n)
{
	char **board = NULL;
	int i = 0;

	board = malloc((sizeof(char *) * (n + 1)));
	board[n] = 0;
	while (i < n)
	{
		board[i] = malloc(n + 1);
		board[i++][n] = 0;
	}
	return board;
}

int check_line(char **board, int x, int y, int size)
{
	int y_copy = y;
	int x_copy = x;

	while (y < size)
	{
		y++;
		if (y < size && board[y][x] == '1')
			return (0);
	}
	y = y_copy;
	while (y >= 0)
	{
		y--;
		if (y >= 0 && board[y][x] == '1')
			return (0);
	}
	y = y_copy;
	while (x < size)
	{
		x++;
		if (x < size && board[y][x] == '1')
			return (0);
	}
	x = x_copy;
	while (x >= 0)
	{
		x--;
		if (x >= 0 && board[y][x] == '1')
			return (0);
	}
	return (1);
}

int check_diagonal(char **board, int x, int y, int size)
{
	int y_copy = y;
	int x_copy = x;

	while (x < size && y < size)
	{
		x++;
		y++;
		if (x < size && y < size && board[y][x] == '1')
			return (0);
	}
	x = x_copy;
	y = y_copy;
	while (x >= 0 && y >= 0)
	{
		x--;
		y--;
		if (x >= 0 && y >= 0 && board[y][x] == '1')
			return (0);
	}
	x = x_copy;
	y = y_copy;
	while (x < size && y >= 0)
	{
		if (x < size && y >= 0 && board[y][x] == '1')
			return (0);
		x++;
		y--;
	}
	x = x_copy;
	y = y_copy;
	while (x >= 0 && y < size)
	{
		x--;
		y++;
		if (x >= 0 && y < size && board[y][x] == '1')
			return (0);
	}
	return (1);
}

void print_solution(char **board, int n)
{
	int line = 0;
	int y = 0;
	int cross = 0;
	while (board[line])
	{
		y = 0;
		while (board[line][y])
		{
			if (board[line][y] == '1')
			{
				cross++;
				if (cross == n)
					printf("%d", y);
				else
					printf("%d ", y);
			}
			y++;
		}
		line++;
	}
	printf("\n");
}

void n_queens(int n, int line, char **board, int cross)
{
	int x = 0;
	if (line == n)
	{
		if (cross == n)
			print_solution(board, n);
		return;
	}
	while (board[line][x])
	{
		if (board[line][x] != '1' && check_diagonal(board, x, line, n) && check_line(board, x, line, n))
		{
			board[line][x] = '1';
			n_queens(n, line + 1, board, cross + 1);
			board[line][x] = '0';
		}
		x++;
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return 1;
	int n = atoi(argv[1]);
	if (n <= 2)
		return 1;
	int cross = 0;
	char **board = malloc_board(n);
	reset_board(board, n);
	n_queens(n, 0, board, cross);
}
