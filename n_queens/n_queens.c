// Assignement name : n_queens

// Expected files : *.c *.h

// Allowed functions : atoi, fprintf, write

// -------------------------------------------------------------------------

// Write a program that will print all the solutions to the n queens problem
// for a n given as argument.
// We will not test with negative values.
// The order of the solutions is not important.

// You will display the solutions under the following format :
// <p1> <p2> <p3> ... \n
// where pn are the line index of the queen in each colum starting from 0.

// For example this should work :
// $> ./n_queens 2 | cat -e

// $> ./n_queens 4 | cat -e
// 1 3 0 2$
// 2 0 3 1$

// $> ./n_queens 7 | cat -e
// 0 2 4 6 1 3 5$
// 0 3 6 2 5 1 4$
// etc...


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_N 20

int check_is_safe(int *board, int row, int col)
{
	int i = 0;

	while (i < col)
	{
		if (board[i] == row || board[i] - row == i - col
			|| board[i] - row == col - i)
			return 0;
		i++;
	}
	return 1;
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
				fprintf(stdout, " ");
			fprintf(stdout, "%d", board[i]);
			i++;
		}
		fprintf(stdout, "\n");
		return ;
	}
	while (row < board_size)
	{
		if (check_is_safe(board, row, col))
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
		return 0;
	}
	if (board_size <= 3 || board_size > MAX_N)
	{
		write(1, "\n", 1);
		return 0;
	}
	solve(board, board_size, 0);
	return 0;
}
