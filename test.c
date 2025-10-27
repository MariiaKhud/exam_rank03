#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_N 50

int is_safe(int *board, int row, int col)
{
	int i = 0;
	while (i < col)
	{
		if (board[i] == row || board[i] - row == i - col
			|| board[i] - row == col - i)
			return (0);
		i++;
	}
	return (1);
}

void solve(int *board, int board_size, int col)
{
	int row = 0;
	if (col == board_size)
	{
		int i = 0;
		while (i < board_size)
		{
			if (i > 0)
			{
				fprintf(stdout, " ");
			}
			fprintf(stdout, "%d", board[i]);
			i++;
		}
		fprintf(stdout, "\n");
		return ;
	}
	while (row < board_size)
	{
		if (is_safe(board, row, col))
		{
			board[col] = row;
			solve(board, board_size, col + 1);
		}
		row++;
	}
}

int main(int argc, char **argv)
{
	int board[MAX_N];
	int board_size = atoi(argv[1]);

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	if (board_size <= 3 || board_size > MAX_N)
	{
		write(1, "\n", 1);
		return (0);
	}
	solve(board, board_size, 0);
	return (0);
}