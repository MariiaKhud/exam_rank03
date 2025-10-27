
// Assignment name : infin_add
// Expected files : *.c *.h
// Allowed functions : write, malloc, free.
// ---------------------------------------------------------------

// Write a program that take as a parameter two strings that represent
// two numbers that are potentially infinit, and displays on stdout the result of
// the addition of those two numbers, followed by a \n.

// A negative number will always be prefixed by one and only one -. The only characters
// thtat can be part of the strings are digits and sign '-'.

// Both parameters will always be well formatted and you will always have exactly
// two parameters, no tricks.

// Examples:
// $> ./infin_add "879879087" "67548976597" | cat -e
// 68428855684$

// $> ./infin_add "-876435" "987143265" | cat -e
// 986266830$

// $> ./infin_add "-807965" "-34532" | cat -e
// -842497$



#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	reverse(char *str)
{
	int i = 0;
	int j = strlen(str) - 1;
	char tmp;

	while (i < j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
}

char	*add_positive(char *a, char *b)
{
	int len_a = strlen(a);
	int len_b = strlen(b);
	int max_len;
	int i = 0;
	int carry = 0;

	if (len_a > len_b)
		max_len = len_a;
	else
		max_len = len_b;

	char *res = malloc(max_len + 2);
	if (!res)
		return (NULL);
	res[max_len + 1] = '\0';

	reverse(a);
	reverse(b);

	while (i < max_len)
	{
		int digit_a = 0;
		int digit_b = 0;

		if (i < len_a)
			digit_a = a[i] - '0';
		if (i < len_b)
			digit_b = b[i] - '0';

		int sum = digit_a + digit_b + carry;
		res[i] = (sum % 10) + '0';
		carry = sum / 10;
		i++;
	}

	if (carry)
	{
		res[i] = carry + '0';
		i++;
	}
	res[i] = '\0';
	reverse(res);
	return (res);
}

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}

	char *a = argv[1];
	char *b = argv[2];

	if (*a == '-' || *b == '-')
	{
		write(1, "Negative numbers not yet handled\n", 33);
		return (0);
	}

	char *result = add_positive(a, b);
	ft_putstr(result);
	write(1, "\n", 1);
	free(result);
	return (0);
}
