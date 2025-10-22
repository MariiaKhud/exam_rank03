
// Assignment name : permutations
// Expected files : *.c *.h
// Allowed functions : puts, malloc, calloc, realloc, free, write.
// ---------------------------------------------------------------

// Write a program that prints all the permutations of a string given as an
// argument.

// The solutions must be provided in alphabetical order.

// We will not test your program with strings containing duplicates (e.g. 'abccd')

// For example this should work:
// $> ./permutations a | cat -e
// a$

// $> ./permutations ab | cat -e
// ab$
// ba$

// $> ./permutations abc | cat -e
// abc$
// acb$
// bac$
// bca$
// cab$
// cab$


#include <stdio.h>
#include <unistd.h>

int	ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

void	swap(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

void	sort_string(char *s)
{
	int i = 0;
	int j;
	int len = ft_strlen(s);

	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (s[i] > s[j])
				swap(&s[i], &s[j]);
			j++;
		}
		i++;
	}
}

void solve(char *s, int start, int end)
{
	int i = start;

	if (start == end)
	{
		puts(s);
		return ;
	}
	while (i <= end)
	{
		swap(&s[start], &s[i]);
		solve(s, start + 1, end);
		swap(&s[start], &s[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	sort_string(argv[1]);
	solve(argv[1], 0, ft_strlen(argv[1]) - 1);
	return (0);
}
