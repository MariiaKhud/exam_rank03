// Assignment name: brackets
// Expected files: brackets.c
// Allowed functions: write, malloc, free

// Write a program that checks whether the brackets
// in a string are properly closed and nested.

// The considered bracket pairs are: ()  []  {}

// $> ./brackets "(johndoe)"
// OK
// $> ./brackets "([)]"
// Error
// $> ./brackets "([])"
// OK
// $> ./brackets "([hello (world)])"
// OK
// $> ./brackets ""
// OK
// $> ./brackets
// <prints just a newline>

#include <unistd.h>
#include <stdlib.h>

static int	match(char open, char close)
{
	if (open == '(' && close == ')')
		return (1);
	if (open == '[' && close == ']')
		return (1);
	if (open == '{' && close == '}')
		return (1);
	return (0);
}

static int	check(const char *s)
{
	int		i = 0;
	int		top = 0;
	char	*stack;

	stack = malloc(10000);
	if (stack == 0)
		return (0);
	while (s[i])
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			stack[top++] = s[i];
		else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
		{
			if (top == 0 || !match(stack[top - 1], s[i]))
			{
				free(stack);
				return (0);
			}
			top--;
		}
		i++;
	}
	free(stack);
	return (top == 0);
}

int	main(int argc, char **argv)
{
	int	i = 1;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (i < argc)
	{
		if (check(argv[i]))
			write(1, "OK\n", 3);
		else
			write(1, "Error\n", 6);
		i++;
	}
	return (0);
}
