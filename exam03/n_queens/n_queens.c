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

void print_solution(char **board, int start, int n)
{
	int y = 0;
	int cross = 0;

	reset_board(board, n);
	while (board[y])
	{
		if (y > 0)
			start = 0;
		while (board[y][start])
		{
			if (board[y][start] != '1' && check_diagonal(board, start, y, n) && check_line(board, start, y, n))
			{
				board[y][start] = '1';
				cross++;
				if (cross == n)
					printf("%d", start);
				else
					printf("%d ", start);
			}
			start++;
		}
		y++;
	}
	printf("\n");
}

void print_board(char **board)
{
	int i = 0;
	int y;

	while (board[i])
	{
		y = 0;
		while (board[i][y])
			printf("%c ", board[i][y++]);
		printf("\n");
		i++;
	}
	printf("\n");
	printf("\n");
	printf("\n");
}

void n_queens(int n, int start, char **board)
{
	reset_board(board, n);
	int i = 0;
	int cross = 0;
	int y = 0;
	int start_copy = start;
	if (start == n)
		return;
	while (board[y])
	{
		if (y > 0)
			start = 0;
		else
			start = start_copy;
		while (board[y][start])
		{
			if (board[y][start] != '1' && check_diagonal(board, start, y, n) && check_line(board, start, y, n))
			{
				board[y][start] = '1';
				cross++;
			}
			start++;
		}
		y++;
	}
	//print_board(board);
	//printf("%d\n", cross);
	if (cross == n)
		print_solution(board, start_copy, n);
	n_queens(n, start_copy + 1, board);
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return 1;
	int n = atoi(argv[1]);
	if (n <= 2)
		return 1;
	printf("N EST EGAL A = %d\n", n);
	char **board = malloc_board(n);
	n_queens(n, 0, board);
}
